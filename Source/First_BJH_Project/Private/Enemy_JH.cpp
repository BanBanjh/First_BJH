// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_JH.h"
#include <Components/CapsuleComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include "EnemyFSM_JH.h"

// Sets default values
AEnemy_JH::AEnemy_JH()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	// FSM
	enemyFSM = CreateDefaultSubobject<UEnemyFSM_JH>(TEXT("EnemyFSM"));

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AEnemy_JH::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy_JH::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy_JH::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

