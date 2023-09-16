// Fill out your copyright notice in the Description page of Project Settings.


#include "CarBase.h"

// Sets default values
ACarBase::ACarBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACarBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACarBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

