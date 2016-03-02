// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PickUp.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT3_API ABatteryPickup : public APickUp
{
	GENERATED_BODY()

	public:
		
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Power)
		float powerLevel;

	ABatteryPickup();
	ABatteryPickup(const FObjectInitializer& ObjectInitializer);

	virtual void OnPickedUp_Implementation() override;
};
