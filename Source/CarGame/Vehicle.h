// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Vehicle.generated.h"

UCLASS()
class CARGAME_API AVehicle : public AWheeledVehiclePawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CarProperties, meta = (AllowPrivateAccess = "true"))
	float Acceleration;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CarProperties, meta = (AllowPrivateAccess = "true"))
	float Deceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComp;


	TObjectPtr<class UChaosVehicleMovementComponent> movement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	AVehicle();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Accelerate(float Val);

	void Decellerate(float Val);

};
