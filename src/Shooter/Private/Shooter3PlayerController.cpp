// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter3PlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Pawn.h"



void AShooter3PlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
	
	//FGenericPlatformMisc::RequestExit(true);

	//AShooter3PlayerController* fpc = GetController<AShooter3PlayerController>();
	//LoseScreen != nullptr
	
	/*if (UUserWidget* LoseScreen = CreateWidget<class UUserWidget>(this, LoseScreenClass)) {
		LoseScreen->AddToPlayerScreen();
	}*/

	
	//UE_LOG(LogTemp, Warning, TEXT("We have finished"));

}
