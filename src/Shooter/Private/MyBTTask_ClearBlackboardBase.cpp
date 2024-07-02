// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_ClearBlackboardBase.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTTask_ClearBlackboardBase::UMyBTTask_ClearBlackboardBase()
{
	NodeName = TEXT("Clear Blackboard Value");

}

EBTNodeResult::Type UMyBTTask_ClearBlackboardBase::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	//GetSelectedBlackboardKey();
	return EBTNodeResult::Succeeded;
}

