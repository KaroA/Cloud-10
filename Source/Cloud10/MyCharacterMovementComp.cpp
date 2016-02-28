// Fill out your copyright notice in the Description page of Project Settings.

#include "Cloud10.h"
#include "Cloud10Character.h"
#include "MyCharacterMovementComp.h"
#include "Engine.h"


UMyCharacterMovementComp::UMyCharacterMovementComp(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UMyCharacterMovementComp>(ACharacter::CharacterMovementComponentName))
{

}

void UMyCharacterMovementComp::InitializeComponent()
{
	Super::InitializeComponent();
	airTime = 2.f;
	forceY = 0.f;

}
/*void UMyCharacterMovementComp::DoDive()
{
if (&UMyCharacterMovementComp::IsDiving)
{

}
}*/

bool UMyCharacterMovementComp::DoJump(bool bReplayingMoves)
{
	if (CharacterOwner->CanJump())
	{
		forceY = JumpZVelocity;
		//CharacterOwner->bPressedJump = true;
	}

	if (forceY != 0)
	{
		
	}
	if (&UCharacterMovementComponent::IsFalling)
	{

	}
	/*if (!IsFalling)
	{
	forceY = false;
	modifyGrav = gravity * airTime;
	//jump
	forceY = jumpSpeed;

	if (IsFalling && forceY != 0)
	{

	}
	}*/

	return false;
}


void UMyCharacterMovementComp::PhysCustom(float deltaTime, int32 Iterations)
{
	switch (CustomMovementMode)
	{
	case TMOVE_Diving:
		PhysCustomDive(deltaTime, Iterations);
		break;
	case TMOVE_Walking:
		PhysCustomWalk(deltaTime, Iterations);
		break;
	}
}

void UMyCharacterMovementComp::PhysCustomDive(float deltaTime, int32 Iterations)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Dive"));

}

void UMyCharacterMovementComp::PhysCustomWalk(float deltaTime, int32 Iterations)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Walk"));

}


void UMyCharacterMovementComp::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CharacterOwner->bPressedJump)
	{
		if (forceY != 0)
		{
			invertGrav = DeltaTime;
			forceY += invertGrav*DeltaTime;
		}
	}
	else
	{
		invertGrav = GravityScale * airTime;
		forceY = 0;

	}
	if(IsFalling)
	{
		forceY -= GravityScale * DeltaTime * 3.f;
		FRotator Rotation = CharacterOwner->GetActorRotation();
		Velocity.Y = forceY;
	}
	/*
	FVector moveDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);
	moveDirection.Y = forceY;
	CharacterOwner->AddControllerYawInput(moveDirection.Y * DeltaTime);
	*/
}



