// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroPlayerController.h"

#include "SecretPathGameMode.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

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

void AHeroPlayerController::OnDestroyEffect_Implementation(const FVector& ParticleSpawnLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("actor destroyed [multicast] at %f %f %f"), ParticleSpawnLocation.X, ParticleSpawnLocation.Y, ParticleSpawnLocation.Z);

	FTransform Transform;

	Transform.SetLocation(ParticleSpawnLocation);
	Transform.SetScale3D({20, 20, 20});

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystemOnDeath, Transform);

	UE_LOG(LogTemp, Warning, TEXT("Particles spawned"));

}

void AHeroPlayerController::OnDestroy_Implementation(AActor* DestroyedActor)
{
	OnDestroyEffect(DestroyedActor->GetActorLocation());

	ASecretPathGameMode* GameMode = Cast<ASecretPathGameMode>(GetWorld()->GetAuthGameMode());

	if(!GameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("No game mode"));
		return;
	}

	FTransform Transform;
	Transform.SetLocation({0, 0, 1500.0f});
	GameMode->RespawnRequested(this, DestroyedActor->GetClass(), Transform);

	BindRespawnOnDestroyCharacterEvent();
}

