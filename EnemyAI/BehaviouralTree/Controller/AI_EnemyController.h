#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_EnemyController.generated.h"

UCLASS()
class F_Zombie_API AAI_EnemyController : public AAIController
{
    GENERATED_BODY()

public:
    AAI_EnemyController();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditDefaultsOnly)
    class UBehaviorTree* BehaviorTreeAsset;

    UPROPERTY(EditDefaultsOnly)
    class UBlackboardData* BlackboardAsset;
};
