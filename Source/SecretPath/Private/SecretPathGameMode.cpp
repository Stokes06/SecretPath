// Copyright Epic Games, Inc. All Rights Reserved.

#include "SecretPathGameMode.h"
#include "SecretPathCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASecretPathGameMode::ASecretPathGameMode()
{
	// set default pawn class to our Blueprinted character
	// static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	// if (PlayerPawnBPClass.Class != NULL)
	// {
	// 	DefaultPawnClass = PlayerPawnBPClass.Class;
	// }
}
