// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CusCamera.generated.h"

UCLASS()
class PROJECT3_API ACusCamera : public ACameraActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACusCamera();
	ACusCamera(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
