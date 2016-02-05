// Fill out your copyright notice in the Description page of Project Settings.

#include "Project3.h"
#include "MyCharacterMovementComponent.h"
#include "Engine.h"


UMyCharacterMovementComponent::UMyCharacterMovementComponent(const FObjectInitializer &ObjectInitializer) 
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	
}

bool UMyCharacterMovementComponent::DoDive()
{
	if (UMyCharacterMovementComponent::IsDiving)
	{

	}
}

bool UMyCharacterMovementComponent::DoJump(bool bReplayingMoves)
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

void UMyCharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	switch (CustomMovementMode)
	{
	case MOVE_Diving:
		PhysCustomDive(deltaTime, Iterations);
		break;
	case MOVE_Walking:
		PhysCustomWalk(deltaTime, Iterations);
		break;
	}
}

void UMyCharacterMovementComponent::PhysCustomDive(float deltaTime, int32 Iterations)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Dive"));
	
}

void UMyCharacterMovementComponent::PhysCustomWalk(float deltaTime, int32 Iterations)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Walk"));

}

void UMyCharacterMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}