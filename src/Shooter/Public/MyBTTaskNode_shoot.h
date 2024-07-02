// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTaskNode_shoot.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UMyBTTaskNode_shoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UMyBTTaskNode_shoot();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

};
