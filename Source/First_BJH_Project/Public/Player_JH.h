// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Player_JH.generated.h"

UCLASS()
class FIRST_BJH_PROJECT_API APlayer_JH : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayer_JH();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "MySettings")
		class UCapsuleComponent* collisionComp;
	UPROPERTY(EditDefaultsOnly, Category = "MySettings")
		class UCameraComponent* cameraComp;
	UPROPERTY(EditDefaultsOnly, Category = "MySettings")
		class USpringArmComponent* springArm;
	UPROPERTY(EditAnywhere, Category = "MySettings|Inputs")
		TArray<class UInputAction*> inputActions;
	
	UPROPERTY(EditDefaultsOnly, Category = "MySettings")
		class UInputAction* ia_Move;
	UPROPERTY(EditDefaultsOnly, Category = "MySettings")
		class UInputMappingContext* imc;
	UPROPERTY()
		class UPlayerMove* moveComp;

private:
	UFUNCTION()
	void Move(const FInputActionValue& value);

};
