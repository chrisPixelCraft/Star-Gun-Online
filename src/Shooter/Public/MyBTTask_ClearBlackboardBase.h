// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_ClearBlackboardBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UMyBTTask_ClearBlackboardBase : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UMyBTTask_ClearBlackboardBase();

protected:
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
