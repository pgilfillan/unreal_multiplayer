// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DICE_May_19GameMode.h"
#include "DICE_May_19Character.h"
#include "UObject/ConstructorHelpers.h"

ADICE_May_19GameMode::ADICE_May_19GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
