// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Cloud10.h"
#include "Cloud10Character.h"
#include "MyCharacterMovementComp.h"
#include "Engine.h"

//////////////////////////////////////////////////////////////////////////
// ACloud10Character

UMyCharacterMovementComp* CustomCharMovementComp;

bool diving;

ACloud10Character::ACloud10Character(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CustomCharMovementComp = Cast<UMyCharacterMovementComp>(GetCharacterMovement());
	if (CustomCharMovementComp)
	{
		CustomCharMovementComp->bOrientRotationToMovement = true;
		//set custom diving movement on key press
		CustomCharMovementComp->SetMovementMode(MOVE_Custom, TMOVE_Walking);
	}

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	rotationRate = 50.f;

	minPitch = -30.f;
	maxPitch = 30.f;
	minRoll = -30.f;
	maxRoll = 30.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->AttachTo(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ACloud10Character::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAxis("MoveForward", this, &ACloud10Character::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACloud10Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ACloud10Character::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ACloud10Character::LookUpAtRate);

	// handle touch devices
	InputComponent->BindTouch(IE_Pressed, this, &ACloud10Character::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &ACloud10Character::TouchStopped);
}

void ACloud10Character::Dive()
{
	//if player already diving, turn dive mode off on button press
	if (diving == true)
	{
		diving = false;
		if (CustomCharMovementComp->IsMovingOnGround())
		{
			CustomCharMovementComp->SetMovementMode(MOVE_Custom, TMOVE_Walking);
		}
		else
		{
			CustomCharMovementComp->SetMovementMode(MOVE_Falling);
		}
	}
	else
	{
		diving = true;
		CustomCharMovementComp->SetMovementMode(MOVE_Custom, TMOVE_Diving);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Dive Mode"));
	}
}

void ACloud10Character::bounceJump()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("bounceJump"));
	const FVector ForwardDir = GetActorForwardVector();

	float momentum = 100;
	float jumpVelocity = 800;
	const FVector AddForce = ForwardDir * momentum + FVector(0, 0, 1) * jumpVelocity;
	LaunchCharacter(AddForce, false, true);
	jumpVelocity = 600;
}

void ACloud10Character::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	// jump, but only on the first touch
	if (FingerIndex == ETouchIndex::Touch1)
	{
		Jump();
	}
}

void ACloud10Character::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		StopJumping();
	}
}

void ACloud10Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACloud10Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ACloud10Character::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
	if (diving)
	{
		//roll character in an angle front and back
		curRollAmt = Value;
	}

}

void ACloud10Character::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
	if (diving)
	{
		float val = 30;
		float axisVal;
		UStaticMeshComponent* smc = Cast<UStaticMeshComponent>(RootComponent);
		
		axisVal = Value * val;
		//add tilting movement control on left & right
		FRotator Rotation = GetActorRotation();
		Rotation.Roll = Value;
		AddActorLocalRotation(Rotation);

		// find out which way is right
		
		/*const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		//smc->SetPhysicsLinearVelocity(Direction * axisVal);
		AddControllerYawInput((Direction * axisVal));*/
	}
}

void ACloud10Character::LookUp(float Value)
{
	//get rotation from player controller which = camera/mouse
	FRotator Rotation = Controller->GetControlRotation();
	Rotation.Pitch = Value;
	AddActorLocalRotation(Rotation);
}

void ACloud10Character::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (diving)
	{
		//add gravity to pawn to increase acceleration

		//add tilting movement control on left & right
		FRotator dRotation = GetActorRotation();
		//clamp roll amt and set roll based on input value
		dRotation.Roll = FMath::ClampAngle(rotationRate * deltaSeconds, minRoll, maxRoll);
		dRotation.Pitch = FMath::ClampAngle(rotationRate * deltaSeconds, minPitch, maxPitch);
		AddActorLocalRotation(dRotation);
		//pitch movement control on up & down
	}
}