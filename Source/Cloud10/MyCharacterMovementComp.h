// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComp.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum TCustomMovementMode
{
	TMOVE_Diving UMETA(DisplayName = "Diving"),
	TMOVE_Walking UMETA(DisplayName = "Walking")
};

UCLASS()
class CLOUD10_API UMyCharacterMovementComp : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = Enum, BlueprintReadWrite)
		TEnumAsByte<enum TCustomMovementMode> NewCustomMovementMode;

	virtual bool DoJump(bool bReplayingMoves) override;

	// Called every frame
	//virtual void Tick(float DeltaSeconds) override;

	//BEGIN UMovementComponent Interface
	//virtual float GetMaxSpeed() const override;
	//virtual void StopActiveMovement() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Dive)
		bool IsDiving;

	//UFUNCTION(BlueprintImplementableEvent, Category = Character)
	//void startBounceJump();
protected:

	//UFUNCTION(BlueprintImplementableEvent, Category = Dive)
	//void DoDive();
	//virtual void InitializeComponent() override;
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;
	//??
	void PhysCustomDive(float deltaTime, int32 Iterations);
	void PhysCustomWalk(float deltaTime, int32 Iterations);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	
};
