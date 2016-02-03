// Fill out your copyright notice in the Description page of Project Settings.

#include "Project3.h"
#include "BatteryPickup.h"

ABatteryPickup::ABatteryPickup(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	//set base pwer level
	powerLevel = 150.f;

}

void ABatteryPickup::OnPickedUp_Implementation()
{
	//call parent class, PickUp, on PickedUp Event
	Super::OnPickedUp_Implementation();

	Destroy();
}


