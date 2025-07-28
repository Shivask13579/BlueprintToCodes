#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AttackPlayer.generated.h"

UCLASS()
class F_Zombie_API UBTTask_AttackPlayer : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_AttackPlayer();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
    virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
    virtual void OnGameplayTaskActivated(UGameplayTask& Task) override {}

private:
    float ElapsedTime;
    float DelayDuration = 2.63f;
    bool bWaiting;
};
