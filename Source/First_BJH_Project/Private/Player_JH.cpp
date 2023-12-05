// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_JH.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayer_JH::APlayer_JH()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

}

// Called when the game starts or when spawned
void APlayer_JH::BeginPlay()
{
	Super::BeginPlay();
	
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

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &APlayer_JH::MoveForward);
	
}

void APlayer_JH::MoveForward(float value)
{
	//value = GetActorForwardVector * 500
}
