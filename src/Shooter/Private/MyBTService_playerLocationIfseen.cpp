// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_playerLocationIfseen.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"


UMyBTService_playerLocationIfseen::UMyBTService_playerLocationIfseen()
{
	NodeName = TEXT("Update Player Location If Seen");
}

void UMyBTService_playerLocationIfseen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr) return;

	if (OwnerComp.GetAIOwner() == NULL) return;

	if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn)) {
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
	else {
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}





}
