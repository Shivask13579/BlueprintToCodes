#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Roam.generated.h"

UCLASS()
class F_Zombie_API UBTTask_Roam : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_Roam();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
