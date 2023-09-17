// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimerManager.h"
#include "PowerUpData.generated.h"

UCLASS()
class CARGAME_API UPowerUpData : public UActorComponent
{

	GENERATED_BODY()

private:
	FTimerManager timer;


public:
	UPowerUpData();

	UFUNCTION(BlueprintImplementableEvent)
	void PowerActivate();
};
