// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_JH.h"
#include "Camera/CameraComponent.h"
#include "PlayerMove.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PlayerController_JH.h"
#include <Components/CapsuleComponent.h>
#include "NavigationSystem.h"

// Sets default values
APlayer_JH::APlayer_JH()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	springArm->SetupAttachment(GetCapsuleComponent());

	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	cameraComp->SetupAttachment(springArm);

	bUseControllerRotationYaw = false;
	springArm->bUsePawnControlRotation = true;
	cameraComp->bUsePawnControlRotation = false;
	

	moveComp = CreateDefaultSubobject<UPlayerMove>(TEXT("MoveComponent"));
	
}

// Called when the game starts or when spawned
void APlayer_JH::BeginPlay()
{
	Super::BeginPlay();
	auto pc = Cast<APlayerController_JH>(GetController()); //Local Player 넣을 플레이어 컨트롤러 선언
	if (pc) //방어 코드
	{
		//parmeter 안에 Player Controller의 Local Player(Local Player Instance)를 넣어줘야 한다.
		auto subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());
		if (subSystem)
		{
			subSystem->AddMappingContext(imc, 0); //MappingContext 추가
		}
	}
	
}

// Called every frame
void APlayer_JH::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void APlayer_JH::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	auto pInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	if (pInput)
	{
		pInput->BindAction(ia_Move, ETriggerEvent::Triggered, this, &APlayer_JH::Move);
		pInput->BindAction(ia_Clicked, ETriggerEvent::Triggered, this, &APlayer_JH::OnRightClick);
	}
	
}

void APlayer_JH::Move(const FInputActionValue& value)
{
	//UE_LOG(LogTemp, Warning, TEXT("Move!!"));
	
	FVector2D mValue = value.Get<FVector2D>();
	this->AddMovementInput(this->GetActorRightVector(), mValue.X);
	this->AddMovementInput(this->GetActorForwardVector(), mValue.Y);
	
	if (mValue.Y != 0)
	{
		FRotator newRotation = GetActorRotation();
		newRotation.Yaw = mValue.Y > 0 ? 0 : 180;
		SetActorRotation(newRotation);
	}
}

void APlayer_JH::OnRightClick()
{
	//FString DebugMessage = FString::Printf(TEXT("Clicked!!"));;
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, DebugMessage);
}