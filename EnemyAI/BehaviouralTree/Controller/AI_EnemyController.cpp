#include "AI_EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "UObject/ConstructorHelpers.h"

AAI_EnemyController::AAI_EnemyController()
{
    static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("/Game/AI/BT_AI"));
    static ConstructorHelpers::FObjectFinder<UBlackboardData> BB(TEXT("/Game/AI/BB_AI"));

    if (BT.Succeeded()) BehaviorTreeAsset = BT.Object;
    if (BB.Succeeded()) BlackboardAsset = BB.Object;
}

void AAI_EnemyController::BeginPlay()
{
    Super::BeginPlay();

    if (UseBlackboard(BlackboardAsset, Blackboard))
    {
        RunBehaviorTree(BehaviorTreeAsset);
        Blackboard->SetValueAsObject(TEXT("SelfActor"), GetPawn());
    }
}
