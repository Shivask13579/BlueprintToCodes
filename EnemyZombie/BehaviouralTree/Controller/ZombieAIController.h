#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ZombieAIController.generated.h"

UCLASS()
class F_Zombie_API AZombieAIController : public AAIController
{
    GENERATED_BODY()

public:
    AZombieAIController();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly)
    class UBehaviorTree* BehaviorTreeAsset;

    UPROPERTY(EditDefaultsOnly)
    class UBlackboardData* BlackboardAsset;
};
