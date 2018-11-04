// Fill out your copyright notice in the Description page of Project Settings.

//#include "ChooseNextWaypointTask.h"
#include "../Public/ChooseNextWaypointTask.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "../TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypointTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	if (!OwnerComp.GetAIOwner())
	{
		return EBTNodeResult::Succeeded;
	}
	ATP_ThirdPersonCharacter* character = Cast<ATP_ThirdPersonCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (character)
	{
		const TArray<ATargetPoint*>& tPoints = character->GetTargetPoints();
		int nbPoints = tPoints.Num();
		if (nbPoints > currentIndex)
		{
			ATargetPoint* nextPoint = tPoints[currentIndex];
			UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
			if (BlackboardComp && nextPoint)
			{
				UE_LOG(LogTemp, Warning, TEXT("black board comp: %s | going to reach: %s"), *BlackboardComp->GetName(), *nextPoint->GetName());
				BlackboardComp->SetValueAsObject(waypointKey.SelectedKeyName, nextPoint);
				currentIndex = nbPoints <= 0 ? 0 : (currentIndex + 1) % nbPoints;
			}
		}
	}
	return EBTNodeResult::Succeeded;
}
