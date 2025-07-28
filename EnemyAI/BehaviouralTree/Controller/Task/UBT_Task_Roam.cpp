#include "BTTask_Roam.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "GameFramework/Pawn.h"

UBTTask_Roam::UBTTask_Roam()
{
    NodeName = "Roam Randomly";
}

EBTNodeResult::Type UBTTask_Roam::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (AAIController* Controller = OwnerComp.GetAIOwner())
    {
        APawn* Pawn = Controller->GetPawn();
        if (!Pawn) return EBTNodeResult::Failed;

        FVector Origin = Pawn->GetActorLocation();
        FNavLocation NavLoc;
        UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());

        if (NavSys && NavSys->GetRandomReachablePointInRadius(Origin, 3000.f, NavLoc))
        {
            Controller->MoveToLocation(NavLoc.Location, 120.f);
            return EBTNodeResult::Succeeded;
        }
    }
    return EBTNodeResult::Failed;
}
