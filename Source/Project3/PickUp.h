// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

UCLASS()
class PROJECT3_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	APickUp();
	// Sets default values for this actor's properties
	APickUp(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
		bool bIsActive;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Pickup")
		USphereComponent* BaseCollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Pickup")
		UStaticMeshComponent* PickupMesh;
	
	//virtual allows function to be called in child class
	UFUNCTION(BlueprintNativeEvent)
		void OnPickedUp();
	virtual void OnPickedUp_Implementation();
};
