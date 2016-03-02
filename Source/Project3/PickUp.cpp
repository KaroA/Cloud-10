// Fill out your copyright notice in the Description page of Project Settings.

#include "Project3.h"
#include "PickUp.h"

APickUp::APickUp()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Sets default values
APickUp::APickUp(const FObjectInitializer &ObjectInitializer):Super(ObjectInitializer)
{
 	
	//pick up is valid
	bIsActive = true;

	//Create the root SphereComponent to handle pickup collision
	BaseCollisionComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));

	//set sphereComponent as root component
	RootComponent = BaseCollisionComponent;

	//Create static mesh component
	PickupMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));
	
	//Turn physics on for the static mesh
	PickupMesh->SetSimulatePhysics(true);

	//Attach StaticMeshComponent to the root component
	PickupMesh->AttachTo(RootComponent);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APickUp::OnPickedUp_Implementation()
{
	//There is no default behavior
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUp::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

