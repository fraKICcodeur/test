// Fill out your copyright notice in the Description page of Project Settings.

//#include "ChooseNextWaypointTask.h"
#include "../Public/ChooseNextWaypointTask.h"

EBTNodeResult::Type UChooseNextWaypointTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("execute task"));
	return EBTNodeResult::Succeeded;
}
