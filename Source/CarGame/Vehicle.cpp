// Fill out your copyright notice in the Description page of Project Settings.

#include "Vehicle.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AVehicle::AVehicle()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RearSpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("RearSpringArmComponent"));
	RearSpringArmComp->SetupAttachment(RootComponent);
	RearSpringArmComp->TargetArmLength = 650.0f;
	RearSpringArmComp->bUsePawnControlRotation = true;

	bUseControllerRotationYaw = true;

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

	//StaticMeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	//StaticMeshComp->SetupAttachment(RootComponent);
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
	Move(DeltaTime);
}

void AVehicle::Accelerate(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::SanitizeFloat(Value.Get<float>()));
	CurAccel += Value.Get<float>();
	if (CurSpeed < MaxSpeed)
	{
		CurSpeed += (CurAccel);
	}
}

void AVehicle::Brake(const FInputActionValue& Value)
{
	GetMovementComponent()->Velocity.X -= Value.Get<float>();;
	CurSpeed -= Value.Get<float>();
	CurAccel -= Value.Get<float>();
}

void AVehicle::ApplyGravity(float DeltaTime)
{
	FVector AppliedGravity;
	AppliedGravity.Z += Gravity * DeltaTime;	
}

void AVehicle::Move(float DeltaTime)
{
	FVector MovementVector;

	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	// get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	GetMovementComponent()->Velocity.X = CurSpeed;
}

void AVehicle::Turn(const FInputActionValue& Value)
{
	Steer += Value.Get<float>();
	AddControllerYawInput(Steer);
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
	}
}