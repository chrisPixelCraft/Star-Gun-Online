// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "Components/TextBlock.h"
#include "Shooter3PlayerController.generated.h"

/**
 * 
 */

UCLASS()
class SHOOTER_API AShooter3PlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false)override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	float RestartDelay = 1;

	FTimerHandle RestartTimer;


};
	