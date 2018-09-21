// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypointBTTNode.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypointBTTNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get Patrol Points
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	APatrollingGuard* PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	TArray<AActor*> PatrolPoints = PatrollingGuard->PatrolPointsCpp;

	if (PatrolPoints.Num() != 0)
	{
		// Set next waypoint
		UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
		int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
		BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

		// Cycle the index
		int32 NextIndex = (Index + 1) % PatrolPoints.Num();
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	}

	return EBTNodeResult::Succeeded;
}

