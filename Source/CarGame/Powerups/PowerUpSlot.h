// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerUpData.h"
#include "PowerUpSlot.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARGAME_API UPowerUpSlot : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Category = PowerUp, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UPowerUpData* PowerUp = nullptr;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Sets default values for this component's properties
	UPowerUpSlot();

	UFUNCTION(BlueprintCallable)
	void EquipPowerUp(UPowerUpData* Power);

	void ActivatePowerup();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
