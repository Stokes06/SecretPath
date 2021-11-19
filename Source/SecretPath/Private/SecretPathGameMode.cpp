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

void ASecretPathGameMode::RespawnRequested_Implementation(APlayerController* PlayerController,UClass* CharacterClass, FTransform SpawnTransform)
{
	if(PlayerController){

		if(HasAuthority()){

			FActorSpawnParameters Parameters = FActorSpawnParameters();
			ASecretPathCharacter* Character = GetWorld()->SpawnActor<ASecretPathCharacter>(CharacterClass, SpawnTransform, Parameters);

			if(!Character)
			{
				UE_LOG(LogTemp, Warning, TEXT("failed to spawn"));
				
			} else
			{
				PlayerController->Possess(Character);
			}
			
			
		} else{

			UE_LOG(LogTemp, Warning, TEXT("Cannot spawn because no authority"));
			
		}
		
	}
}
