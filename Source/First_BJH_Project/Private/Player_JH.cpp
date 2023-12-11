// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_JH.h"
#include "Camera/CameraComponent.h"
#include "PlayerMove.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
APlayer_JH::APlayer_JH()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	cameraComp->SetupAttachment(springArm);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true; 

	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	springArm->SetupAttachment(RootComponent);

	moveComp = CreateDefaultSubobject<UPlayerMove>(TEXT("MoveComponent"));
	
}

// Called when the game starts or when spawned
void APlayer_JH::BeginPlay()
{
	Super::BeginPlay();
	auto pc = Cast<APlayerController>(GetController()); //Local Player 넣을 플레이어 컨트롤러 선언
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
	}
	
}

void APlayer_JH::Move(const FInputActionValue& value)
{
	//UE_LOG(LogTemp, Warning, TEXT("Move!!"));
	FVector2D mValue = value.Get<FVector2D>();
	this->AddMovementInput(this->GetActorRightVector(), mValue.X);
	this->AddMovementInput(this->GetActorForwardVector(), mValue.Y);
}
