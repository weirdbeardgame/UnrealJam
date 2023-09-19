// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VehicleDurability.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARGAME_API UVehicleDurability : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(Category = PowerUp, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float MaxDurability;

	float OldMax;
	float CurDurability;

public:	
	// Sets default values for this component's properties
	UVehicleDurability();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float GetCurDurability() { return CurDurability; }

	UFUNCTION(BlueprintCallable)
	void IncreaseCurDurability(float val);
	
	UFUNCTION(BlueprintCallable)
	void DecreaseCurDurability(float val);
	
	UFUNCTION(BlueprintCallable)
	void IncreaseMaxDurability(float val);
	
	UFUNCTION(BlueprintCallable)
	void DecreaseMaxDurability(float val);

	UFUNCTION(BlueprintCallable)
	void ResetMaxDurability() { MaxDurability = OldMax; }
};
