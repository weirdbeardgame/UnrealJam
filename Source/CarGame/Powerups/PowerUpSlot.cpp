// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpSlot.h"

// Sets default values for this component's properties
UPowerUpSlot::UPowerUpSlot()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPowerUpSlot::BeginPlay()
{
	Super::BeginPlay();	
}

void UPowerUpSlot::ActivatePowerup()
{
	if (PowerUp != nullptr)
	{
		PowerUp->ActivatePowerup();
	}
}

void UPowerUpSlot::EquipPowerUp(UPowerUpData* pwr)
{
	if (PowerUp != pwr)
	{
		PowerUp = pwr;
	}
}

// Called every frame
void UPowerUpSlot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

