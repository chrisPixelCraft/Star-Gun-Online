// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTaskNode_shoot.h"
#include "AIController.h"
#include "shooter3.h"

UMyBTTaskNode_shoot::UMyBTTaskNode_shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UMyBTTaskNode_shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr) return EBTNodeResult::Failed;
	
	Ashooter3* shooter= Cast<Ashooter3>(OwnerComp.GetAIOwner()->GetPawn());
	if (shooter == nullptr)  return EBTNodeResult::Failed;

	shooter->Shoot();

	return EBTNodeResult::Succeeded;
}
