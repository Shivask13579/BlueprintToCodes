#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_ChasePlayer.generated.h"

UCLASS()
class F_Zombie_API UBTTask_ChasePlayer : public UBTTask_MoveTo
{
    GENERATED_BODY()

public:
    UBTTask_ChasePlayer();
};
