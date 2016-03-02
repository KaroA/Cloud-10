// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Project3.h"
#include "Project3Character.h"
#include "BatteryPickup.h"
#include "MyCharacterMovementComponent.h"
#include "Engine.h"
//////////////////////////////////////////////////////////////////////////
// AProject3Character

float modifyGrav;
float forceY = 0;
float airTime = 2.0f;;
float jumpSpeed = 6.0f;;
float gravity = 20.0f;
float gravityForce = 3.0f;
bool diving;
bool bounce;
UMyCharacterMovementComponent* CustomCharMovementComp;

AProject3Character::AProject3Character(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//set custom character movement component
	CustomCharMovementComp = Cast<UMyCharacterMovementComponent>(GetCharacterMovement());
	if (CustomCharMovementComp)
	{
		CustomCharMovementComp->bOrientRotationToMovement = true;
		//set custom diving movement on key press
		CustomCharMovementComp->SetMovementMode(MOVE_Custom,TMOVE_Walking);
	}
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

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


	powerLevel = 2000.f;
	speedFactor = 0.75f;
	baseSpeed = 10.0f;

	//create object collection volume
	CollectionSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("CollectionSphere"));
	CollectionSphere->AttachTo(RootComponent);
	CollectionSphere->SetSphereRadius(200.f);
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	//a modified gravity that will allow player to jump in a curve.  As this value decreases, so will the player's height

	modifyGrav = gravity * airTime;
}

void Tick(float deltaSeconds)
{

}

//////////////////////////////////////////////////////////////////////////
// Input

void AProject3Character::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("Dive", IE_Pressed, this, &AProject3Character::Dive);

	InputComponent->BindAction("CollectObjects", IE_Pressed, this, &AProject3Character::CollectBatteries);

	InputComponent->BindAxis("MoveForward", this, &AProject3Character::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AProject3Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AProject3Character::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AProject3Character::LookUpAtRate);

	// handle touch devices
	InputComponent->BindTouch(IE_Pressed, this, &AProject3Character::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &AProject3Character::TouchStopped);
}

void AProject3Character::Dive()
{
	//if player already diving, turn dive mode off on button press
	if (diving == true)
	{
		diving = false;
		if (CustomCharMovementComp->IsMovingOnGround())
		{
			CustomCharMovementComp->SetMovementMode(MOVE_Custom,TMOVE_Walking);
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
	}
}

void AProject3Character::BounceJump()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("bounceJump"));
	const FVector ForwardDir = GetActorForwardVector();

	float momentum = 100;
	float jumpVelocity = 800;
	const FVector AddForce = ForwardDir * momentum + FVector(0, 0, 1) * jumpVelocity;
	LaunchCharacter(AddForce, false, true);
	jumpVelocity = 600;
}

void AProject3Character::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	// jump, but only on the first touch
	if (FingerIndex == ETouchIndex::Touch1)
	{
		Jump();
	}
}

void AProject3Character::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		StopJumping();
	}
}

void AProject3Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AProject3Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AProject3Character::MoveForward(float Value)
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
}

void AProject3Character::MoveRight(float Value)
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
}

void AProject3Character::CollectBatteries()
{
	float batteryPower = 0;
	TArray<AActor*> collectedActors;
	//gets a list of actors that overlap/collide with collection sphere and sets in array
	CollectionSphere->GetOverlappingActors(collectedActors);

	//check each actor and find which are batteries
	for (int32 i = 0; i < collectedActors.Num(); i++)
	{
		//Cast collected actor to ABatteryPickup
		ABatteryPickup* const testBattery = Cast<ABatteryPickup>(collectedActors[i]);

		//if Cast is successful, and the battery is valid and active
		if (testBattery && !testBattery->IsPendingKill() && testBattery->bIsActive)
		{
			//store battery power to add to character power based upon batteries power level
			batteryPower = batteryPower * testBattery->powerLevel;
			//called picked up function to say battery has been picked up and do something
			testBattery->OnPickedUp();
			//deacctive battery b/c is picked up
			testBattery->bIsActive = false;
		}
	}
	if (batteryPower > 0.0f)
	{
		PowerUp(batteryPower);
	}
}

void AProject3Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//set character speed
	//CharacterMovement->MaxWalkSpeed = speedFactor * powerLevel + baseSpeed;
	/*if (bPressedJump)
		JumpMaxHoldTime = 4.0f;*/
	if (diving){}
		
	/*if (!CharacterMovement->IsFalling)
	{
		forceY = false;
		modifyGrav = gravity * airTime;
		//jump
		forceY = jumpSpeed;

		if (CharacterMovement->IsFalling && forceY != 0)
		{
			modifyGrav -= DeltaSeconds;
			forceY += modifyGrav*DeltaSeconds;
		}
		forceY -= gravity*DeltaSeconds*gravityForce;
		//FVector Direction = GetActorLocation();
		FVector Direction = GetActorForwardVector();
		float tempVelocity = CharacterMovement->Velocity.Normalize();
		CharacterMovement->JumpZVelocity = tempVelocity * forceY;

	}*/

}
