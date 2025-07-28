#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_Chasing.generated.h"

UCLASS()
class F_Zombie_API UBTTask_Chasing : public UBTTask_MoveTo
{
    GENERATED_BODY()

public:
    UBTTask_Chasing();
};
