// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SecretPathGameMode.generated.h"

UCLASS(minimalapi)
class ASecretPathGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASecretPathGameMode();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void RespawnRequested(AController* PlayerController, UClass* CharacterClass, FTransform SpawnTransform);
	
};



