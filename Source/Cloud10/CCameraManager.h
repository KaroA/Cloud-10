// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CCameraManager.generated.h"

USTRUCT(BlueprintType)
struct FActiveCamera
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "ActiveCamera")
		bool mainCamera;
	UPROPERTY(BlueprintReadWrite, Category = "ActiveCamera")
		bool diveCamera;
	UPROPERTY(BlueprintReadWrite, Category = "ActiveCamera")
		bool edgeCamera;
	UPROPERTY(BlueprintReadWrite, Category = "ActiveCamera")
		bool dashCamera;
	
	FActiveCamera()
	{
		diveCamera = false;
		edgeCamera = false;
		dashCamera = false;
		mainCamera = true;
	}
};

UCLASS()
class CLOUD10_API ACCameraManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACCameraManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
