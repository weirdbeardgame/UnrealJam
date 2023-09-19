// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpData.h"

UPowerUpData::UPowerUpData()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Sound = CreateDefaultSubobject<UAudioComponent>(TEXT("PowerUpSound"));
}

void UPowerUpData::ActivatePowerup_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PEW PEW"));
	Mesh->PlayAnimation(Anim, true);
	Sound->Play();
}