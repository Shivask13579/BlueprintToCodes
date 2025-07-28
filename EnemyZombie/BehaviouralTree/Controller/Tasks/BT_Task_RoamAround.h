#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RoamAround.generated.h"

UCLASS()
class F_Zombie_API UBTTask_RoamAround : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_RoamAround();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
