// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleDurability.h"

// Sets default values for this component's properties
UVehicleDurability::UVehicleDurability()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MaxDurability = 100.0f;
}


// Called when the game starts
void UVehicleDurability::BeginPlay()
{
	Super::BeginPlay();
	CurDurability = MaxDurability;
}

void UVehicleDurability::IncreaseCurDurability(float val)
{
	if (CurDurability < MaxDurability)
	{
		CurDurability += val;
	}
}

void UVehicleDurability::DecreaseCurDurability(float val)
{
	if (CurDurability > 0)
	{
		CurDurability -= val;
	}
}

void UVehicleDurability::IncreaseMaxDurability(float val)
{
	OldMax = MaxDurability;
	MaxDurability += val;
}

void UVehicleDurability::DecreaseMaxDurability(float val)
{
	if (MaxDurability > 0)
	{
		MaxDurability -= val;
	}
}


// Called every frame
void UVehicleDurability::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

