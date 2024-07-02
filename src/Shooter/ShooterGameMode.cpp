// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterGameMode.h"
#include "ShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuHUD.h"
#include "MenuPlayerController.h"

AShooterGameMode::AShooterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}



