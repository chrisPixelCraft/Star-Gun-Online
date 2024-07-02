// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter3AI.h"
#include "Kismet/GameplayStatics.h"
//#include "Classes/AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooter3AI::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	//if line sight 
	

	if (AIBehavior != nullptr) {
		RunBehaviorTree(AIBehavior);

		//GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		//GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());
		//if (LineOfSightTo(PlayerPawn)) {
		//	//SetFocus(PlayerPawn);
		//	//MoveToActor(PlayerPawn, 200);
		//	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		//	GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());

		//}
		//else {
		//	//ClearFocus(EAIFocusPriority::Gameplay);
		//	//StopMovement();
		//	GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));

		//}
	}
}

void AShooter3AI::BeginPlay()
{
	Super::BeginPlay();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	SetFocus(PlayerPawn);
	
}
