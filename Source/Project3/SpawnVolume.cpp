// Fill out your copyright notice in the Description page of Project Settings.

#include "Project3.h"
#include "SpawnVolume.h"
#include "PickUp.h"


// Sets default values
ASpawnVolume::ASpawnVolume(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spawnLocation = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("spawnLocation"));

	RootComponent = spawnLocation;

	spawnDelayRangeLow = 1.0f;
	spawnDelayRangeHigh = 4.5f;
	spawnDelay = GetRandomSpawnDelay();
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolume::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASpawnVolume::spawnPickup()
{
	if (spawnType != NULL)
	{
		//checks if game world is created & playing
		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			//get random location to spawn at
			FVector spawnLocation = GetRandomPointInVolume();

			FRotator spawnRotation;

			//spawn pickup
			/*This needs to be fixed!!*/
			//APickUp* const SpawnedPickup = World->SpawnActor<APickUp>(spawnType, spawnLocation, spawnRotation, SpawnParams);
		}
	}
}

float ASpawnVolume::GetRandomSpawnDelay()
{
	return FMath::FRandRange(spawnDelayRangeLow, spawnDelayRangeHigh);
}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector randomLocation;
	float minX, minY, minZ;
	float maxX, maxY, maxZ;

	FVector origin;
	FVector boxExtent;
	origin = spawnLocation->Bounds.Origin;
	boxExtent = spawnLocation->Bounds.BoxExtent;

	minX = origin.X - boxExtent.X / 2.0f;
	minY = origin.Y - boxExtent.Y / 2.0f;
	minZ = origin.Z - boxExtent.Z / 2.0f;

	maxX = origin.X + boxExtent.X / 2.0f;
	maxY = origin.Y + boxExtent.Y / 2.0f;
	maxZ = origin.Z + boxExtent.Z / 2.0f;

	//get a random spawn location fro pickup between x,y,z ranges
	randomLocation = FVector(FMath::FRandRange(minX, maxX), FMath::FRandRange(minY, maxY), FMath::FRandRange(minZ, maxZ));

	//return random spawn location
	return randomLocation;
}
