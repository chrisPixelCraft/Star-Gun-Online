// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "MyBTService_playerLocationIfseen.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UMyBTService_playerLocationIfseen : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	

public:
	UMyBTService_playerLocationIfseen();

protected:

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);


};
