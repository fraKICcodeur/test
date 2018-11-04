// Fill out your copyright notice in the Description page of Project Settings.

//#include "ChooseNextWaypointTask.h"
#include "../Public/ChooseNextWaypointTask.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Public/patrollingRoute.h"
#include "Engine/TargetPoint.h"
EBTNodeResult::Type UChooseNextWaypointTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	if (!OwnerComp.GetAIOwner())
	{
		return EBTNodeResult::Succeeded;
	}
	APawn* character= OwnerComp.GetAIOwner()->GetPawn();
	if (character)
	{
		UpatrollingRoute* route = Cast<UpatrollingRoute>( character->GetComponentByClass(UpatrollingRoute::StaticClass()));
		if (route)
		{
			const TArray<ATargetPoint*>& tPoints = route->GetTargetPoints();
			int nbPoints = tPoints.Num();
			if (nbPoints > currentIndex)
			{
				ATargetPoint* nextPoint = tPoints[currentIndex];
				UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
				if (BlackboardComp && nextPoint)
				{
					BlackboardComp->SetValueAsObject(waypointKey.SelectedKeyName, nextPoint);
					currentIndex = nbPoints <= 0 ? 0 : (currentIndex + 1) % nbPoints;
				}
			}
		}
	}
	return EBTNodeResult::Succeeded;
}
