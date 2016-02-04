// Fill out your copyright notice in the Description page of Project Settings.

#include "Project3.h"
#include "MyCharacterMovementComponent.h"


UMyCharacterMovementComponent::UMyCharacterMovementComponent(const FObjectInitializer &ObjectInitializer) 
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{

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

/*void UMyCharacterMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();
}*/

void UMyCharacterMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//custome component ticking
}