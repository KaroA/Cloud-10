// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"


/**
 * 
 */
UENUM(BlueprintType)
enum TCustomMovementMode
{
	MOVE_Diving UMETA(DisplayName = "Diving"),
	MOVE_Walking UMETA(DisplayName = "Walking")
};

UCLASS()
class PROJECT3_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(VisibleAnywhere,Category = MovementMode, BlueprintReadOnly)
	TEnumAsByte<enum TCustomMovementMode> NewCustomMovementMode;

	virtual bool DoJump(bool bReplayingMoves) override;

	UFUNCTION(BlueprintImplementableEvent, Category = Dive)
	bool DoDive();
	// Called every frame
	//virtual void Tick(float DeltaSeconds) override;

	//BEGIN UMovementComponent Interface
	virtual float GetMaxSpeed() const override;
	virtual void StopActiveMovement() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Dive)
	bool IsDiving() const;

protected:
	//virtual void InitializeComponent() override;
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;
	//??
	void PhysCustomDive(float deltaTime, int32 Iterations);
	void PhysCustomWalk(float deltaTime, int32 Iterations);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
};
