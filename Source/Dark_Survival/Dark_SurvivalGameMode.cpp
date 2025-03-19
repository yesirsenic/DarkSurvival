// Copyright Epic Games, Inc. All Rights Reserved.

#include "Dark_SurvivalGameMode.h"
#include "Dark_SurvivalCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADark_SurvivalGameMode::ADark_SurvivalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
