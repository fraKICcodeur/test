// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "ChooseNextWaypointTask.generated.h"
/**
 * 
 */
UCLASS()
class TESTGIT_API UChooseNextWaypointTask : public UBTTaskNode
{
	GENERATED_BODY()
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:
	UPROPERTY(EditAnywhere, Category = "Settings")
	FBlackboardKeySelector waypointKey;
private:
	int32 currentIndex = 0;
};
