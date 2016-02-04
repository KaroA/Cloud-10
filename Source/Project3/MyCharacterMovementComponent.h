// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"


/**
 * 
 */
UCLASS()
class PROJECT3_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()

public:
	virtual bool DoJump(bool bReplayingMoves) override;
	// Called every frame
	//virtual void Tick(float DeltaSeconds) override;

protected:
	//Init
	//virtual void InitializeComponent() override;
	//Tick
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
};
