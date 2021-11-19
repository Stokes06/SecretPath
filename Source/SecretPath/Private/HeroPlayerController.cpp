// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroPlayerController.h"

#include "SecretPathGameMode.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"

void AHeroPlayerController::BeginPlay()
{
	Super::BeginPlay();

	BindRespawnOnDestroyCharacterEvent();
}

void AHeroPlayerController::BindRespawnOnDestroyCharacterEvent()
{
	APawn* ControlledPawn = GetPawn();

	if(ControlledPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("controlled pawn found"))
		ControlledPawn->OnDestroyed.AddDynamic(this, &AHeroPlayerController::OnDestroy);
	}
}

void AHeroPlayerController::OnDestroy_Implementation(AActor* DestroyedActor)
{
	UE_LOG(LogTemp, Warning, TEXT("actor destroyed"));

	ASecretPathGameMode* GameMode = Cast<ASecretPathGameMode>(GetWorld()->GetAuthGameMode());

	if(!GameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("No game mode"));
		return;
	}

	FTransform Transform;
	Transform.SetLocation({0, 0, 250.0f});
	GameMode->RespawnRequested(this, DestroyedActor->GetClass(), Transform);

	BindRespawnOnDestroyCharacterEvent();
}

