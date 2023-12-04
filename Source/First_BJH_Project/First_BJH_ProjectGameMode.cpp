// Copyright Epic Games, Inc. All Rights Reserved.

#include "First_BJH_ProjectGameMode.h"
#include "First_BJH_ProjectPlayerController.h"
#include "First_BJH_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFirst_BJH_ProjectGameMode::AFirst_BJH_ProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AFirst_BJH_ProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}