// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/PlayerCameraManager.h"
#include "CusCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT3_API ACusCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
protected:
	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void ResetCamera();
	
	
};
