// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class PROJECT3_API ASpawnVolume : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();
	ASpawnVolume(const FObjectInitializer& ObjectInitializer);

	//specify spawning area in level
	UPROPERTY(VisibleDefaultsOnly, Category = Spawning)
		UBoxComponent *spawnLocation;
	//pickup to spawn
	UPROPERTY(EditAnywhere, Category = Spawning)
		class APickUp *spawnType;
	//min spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
	float spawnDelayRangeLow;
	//max spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = Spawning)
	float spawnDelayRangeHigh;

	//chooses random point in box component
	UFUNCTION(BlueprintPure, Category = Spawning)
		FVector GetRandomPointInVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	//calculates random spawn delay
	float GetRandomSpawnDelay();

	//current spawn delay
	float spawnDelay;

	//spawns the new pickup
	void spawnPickup();
	
};
