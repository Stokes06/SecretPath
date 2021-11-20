// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HeroPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SECRETPATH_API AHeroPlayerController : public APlayerController
{
	GENERATED_BODY()


	virtual void BeginPlay() override;

	UFUNCTION()
	void BindRespawnOnDestroyCharacterEvent();

	UFUNCTION(Server, Reliable, Category="On Destroy")
	void OnDestroy(AActor* DestroyedActor);

	UFUNCTION(NetMulticast, Reliable, Category="On Destroy")
	void OnDestroyEffect(const FVector& Vector);


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="On Destroy")
	UParticleSystem* ParticleSystemOnDeath;
	
};
