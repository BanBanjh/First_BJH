// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyFSM_JH.generated.h"

UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Idle UMETA(DisplayName = "Idle State"),
	Move,
	Attack,
	Damage,
	Die
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRST_BJH_PROJECT_API UEnemyFSM_JH : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyFSM_JH();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FSM")
	EEnemyState mState = EEnemyState::Idle;
	UPROPERTY(EditAnywhere)
	float idleDelayTime = 2;
	float currentTime = 0;

	UPROPERTY()
	class AEnemy_JH* me;
	UPROPERTY() //아래 AMyPlayer 포인터를 사용하기 때문에 UPROPERTY를 붙여주는 모습
	class APlayer_JH* target;
	UPROPERTY(EditAnywhere)
	float speed = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float attackRange = 200;
public:
	void IdleState();
	void MoveState();
	void AttackState();
	void DamageState();
	void DieState();
};
