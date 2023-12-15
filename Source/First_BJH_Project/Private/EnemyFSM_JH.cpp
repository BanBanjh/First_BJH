// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFSM_JH.h"
#include <Kismet/GameplayStatics.h>
#include "Player_JH.h"
#include "Enemy_JH.h"
// Sets default values for this component's properties
UEnemyFSM_JH::UEnemyFSM_JH()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}


// Called when the game starts
void UEnemyFSM_JH::BeginPlay()
{
	Super::BeginPlay();

    me = Cast<AEnemy_JH>(GetOwner());
    target = Cast<APlayer_JH>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayer_JH::StaticClass()));

}


// Called every frame
void UEnemyFSM_JH::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (target != nullptr)
    {
        switch (mState)
        {
        case EEnemyState::Idle:
            IdleState();
            break;
        case EEnemyState::Move:
            MoveState();
            break;
        case EEnemyState::Attack:
            AttackState();
            break;
        case EEnemyState::Damage:
            DamageState();
            break;
        case EEnemyState::Die:
            DieState();
            break;
        default:
            break;
        }
    }
}

void UEnemyFSM_JH::IdleState()
{
    currentTime += GetWorld()->DeltaTimeSeconds;
    if (currentTime > idleDelayTime)
    {
        mState = EEnemyState::Move;
        currentTime = 0;
    }
}

void UEnemyFSM_JH::MoveState()
{
    //FString DebugMessage = FString::Printf(TEXT("Move!!"));
   //GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, DebugMessage);
    
    FVector Direction = target->GetActorLocation() - me->GetActorLocation();
    float distance = Direction.Length();
    Direction.Normalize(); 

    me->AddMovementInput(Direction);

    if (distance < attackRange) //설정한 attackRange의 값보다 거리가 좁아진다면
    {
       // mState = EEnemyState::Attack; //공격상태로 전환
    }

    //FVector P = me->GetActorLocation() + Direction * speed * GetWorld()->DeltaTimeSeconds;
    //me->SetActorLocation(P); 

    //Direction.Z = 0;
    //me->SetActorRotation(Direction.Rotation());

}

void UEnemyFSM_JH::AttackState()
{

}

void UEnemyFSM_JH::DamageState()
{

}

void UEnemyFSM_JH::DieState()
{

}