#include "BTTask_AttackPlayer.h"
#include "AIController.h"
#include "BP_Zombie.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

UBTTask_AttackPlayer::UBTTask_AttackPlayer()
{
    bNotifyTick = true;
    NodeName = "Attack Player";
    ElapsedTime = 0.f;
    bWaiting = false;
}

EBTNodeResult::Type UBTTask_AttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* Controller = OwnerComp.GetAIOwner();
    if (!Controller) return EBTNodeResult::Failed;

    ABP_Zombie* Zombie = Cast<ABP_Zombie>(Controller->GetPawn());
    if (!Zombie) return EBTNodeResult::Failed;

    Zombie->AttackPlayer();

    if (Zombie->AttackSound)
    {
        UGameplayStatics::PlaySound2D(this, Zombie->AttackSound);
    }

    bWaiting = true;
    ElapsedTime = 0.f;

    return EBTNodeResult::InProgress;
}

void UBTTask_AttackPlayer::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    if (!bWaiting) return;

    ElapsedTime += DeltaSeconds;
    if (ElapsedTime >= DelayDuration)
    {
        FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    }
}
