// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimerManager.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/AudioComponent.h"
#include "PowerUpData.generated.h"


// This needs an Actor to make it equipable to car
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CARGAME_API UPowerUpData : public UActorComponent
{

	GENERATED_BODY()

private:
	UPROPERTY(Category = PowerUp, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString Name;

	UPROPERTY(Category = PowerUp, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh;
	
	UPROPERTY(Category = PowerUp, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UAudioComponent* Sound;
	
	UPROPERTY(Category = PowerUp, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UAnimationAsset* Anim;

public:
	UPowerUpData();

	UFUNCTION(BlueprintNativeEvent)
	void ActivatePowerup();
};
