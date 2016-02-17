// Fill out your copyright notice in the Description page of Project Settings.

#include "Cloud10.h"
#include "CCameraManager.h"


// Sets default values
ACCameraManager::ACCameraManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACCameraManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACCameraManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

