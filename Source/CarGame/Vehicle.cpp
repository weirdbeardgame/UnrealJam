// Fill out your copyright notice in the Description page of Project Settings.

#include "Vehicle.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ChaosVehicleMovementComponent.h"

// Sets default values
AVehicle::AVehicle()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RearSpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("RearSpringArmComponent"));
	RearSpringArmComp->SetupAttachment(RootComponent);
	RearSpringArmComp->TargetArmLength = 650.0f;
	RearSpringArmComp->bUsePawnControlRotation = true;

	RearCam = CreateDefaultSubobject<UCameraComponent>(TEXT("RearCam"));
	RearCam->SetupAttachment(RearSpringArmComp, USpringArmComponent::SocketName);
	RearCam->bUsePawnControlRotation = false;

	FrontSpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("FrontSpringArmComponent"));
	FrontSpringArmComp->SetupAttachment(RootComponent);
	FrontSpringArmComp->TargetArmLength = 0.0f;
	FrontSpringArmComp->bUsePawnControlRotation = true;

	FrontCam = CreateDefaultSubobject<UCameraComponent>(TEXT("FrontCam"));
	FrontCam->SetupAttachment(FrontSpringArmComp, USpringArmComponent::SocketName);
	FrontCam->bUsePawnControlRotation = false;

	PowerUpSlot = CreateDefaultSubobject<UPowerUpSlot>(TEXT("PowerUpSlot"));
	Health = CreateDefaultSubobject<UVehicleDurability>(TEXT("Health"));
}

// Called when the game starts or when spawned
void AVehicle::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called every frame
void AVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVehicle::ActivatePowerup()
{
	PowerUpSlot->ActivatePowerup();
}

// Called to bind functionality to input
void AVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AVehicle::Turn);
		EnhancedInputComponent->BindAction(AccelerateAction, ETriggerEvent::Triggered, this, &AVehicle::Accelerate);
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &AVehicle::Brake);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &AVehicle::Fire);
		EnhancedInputComponent->BindAction(ActivatePowerAction, ETriggerEvent::Triggered, this, &AVehicle::ActivatePowerup);
	}
}