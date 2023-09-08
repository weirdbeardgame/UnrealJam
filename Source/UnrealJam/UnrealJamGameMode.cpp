// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealJamGameMode.h"
#include "UnrealJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealJamGameMode::AUnrealJamGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
