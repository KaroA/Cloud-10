// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "MyCharacterMovementComp.h"
#include "Cloud10Character.generated.h"

class UMyCharacterMovementComponent;

UCLASS(config=Game)
class ACloud10Character : public ACharacter
{
	GENERATED_BODY()

	//URotatingMovementComponent *rotateMovementComp;


	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ACloud10Character(const FObjectInitializer& ObjectInitializer);

	/** Returns CharacterMovement subobject **/
	//class UMyCharacterMovementComp* GetCharacterMovement() const override;

	UMyCharacterMovementComp* CustomCharMovementComp;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Default)
		float dive;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Default)
		bool isDiving;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		float momentum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		float jumpVelocity;

	UFUNCTION(BlueprintCallable, Category = Default)
		void bounceJump();

	UFUNCTION(BlueprintCallable, Category = Default)
		void DiveForward(float Value, float deltaSeconds);

	UFUNCTION(BlueprintCallable, Category = Default)
		void DiveRight(float Value, float deltaSeconds);

	virtual void Tick(float DeltaSeconds) override;

protected:

	float rotationRate;
	float minPitch, maxPitch, minRoll, maxRoll, minYaw, maxYaw;
	//float curPitchAmt, curRollAmt, curYawAmt;
	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void DiveMode();
	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	void LookUp(float Value);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

