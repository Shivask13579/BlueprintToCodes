#include "BTTask_Attack.h"
#include "AIController.h"
#include "BP_EnemyAI.h"

UBTTask_Attack::UBTTask_Attack()
{
    NodeName = "Attack";
    bNotifyTick = true;
    ElapsedTime = 0.f;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (AController* Controller = OwnerComp.GetAIOwner())
    {
        if (ABP_EnemyAI* Enemy = Cast<ABP_EnemyAI>(Controller->GetPawn()))
        {
            Enemy->Attack();
            bIsWaiting = true;
            ElapsedTime = 0.f;
            return EBTNodeResult::InProgress;
        }
    }
    return EBTNodeResult::Failed;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    if (!bIsWaiting) return;

    ElapsedTime += DeltaSeconds;
    if (ElapsedTime >= Duration)
    {
        bIsWaiting = false;
        FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    }
}
