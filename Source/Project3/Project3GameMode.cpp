// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Project3.h"
#include "Project3GameMode.h"
#include "Project3Character.h"

AProject3GameMode::AProject3GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
