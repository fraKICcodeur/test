// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "patrollingRoute.generated.h"

class ATargetPoint;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTGIT_API UpatrollingRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UpatrollingRoute();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = AI_path)
		TArray<ATargetPoint*> targetPoints;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	const TArray<ATargetPoint*>& GetTargetPoints() const { return targetPoints; }

};
