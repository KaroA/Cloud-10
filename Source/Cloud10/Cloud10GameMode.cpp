// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Cloud10.h"
#include "Cloud10GameMode.h"
#include "Cloud10Character.h"

ACloud10GameMode::ACloud10GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
