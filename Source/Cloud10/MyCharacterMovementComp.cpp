// Fill out your copyright notice in the Description page of Project Settings.

#include "Cloud10.h"
#include "MyCharacterMovementComp.h"
#include "Engine.h"


UMyCharacterMovementComp::UMyCharacterMovementComp(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UMyCharacterMovementComp>(ACharacter::CharacterMovementComponentName))
{

}

/*void UMyCharacterMovementComp::DoDive()
{
if (&UMyCharacterMovementComp::IsDiving)
{

}
}*/

bool UMyCharacterMovementComp::DoJump(bool bReplayingMoves)
{
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
}



