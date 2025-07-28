#include "BTTask_RoamAround.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_RoamAround::UBTTask_RoamAround()
{
    NodeName = "Roam Around";
}

EBTNodeResult::Type UBTTask_RoamAround::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* Controller = OwnerComp.GetAIOwner();
    APawn* AIPawn = Controller ? Controller->GetPawn() : nullptr;

    if (!AIPawn) return EBTNodeResult::Failed;

    FVector Origin = AIPawn->GetActorLocation();
    UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());

    if (!NavSys) return EBTNodeResult::Failed;

    FNavLocation Result;
    if (NavSys->GetRandomReachablePointInRadius(Origin, 3000.0f, Result))
    {
        Controller->MoveToLocation(Result.Location, 120.0f);
        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}
