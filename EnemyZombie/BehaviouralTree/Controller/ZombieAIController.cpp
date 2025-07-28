#include "ZombieAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "Kismet/GameplayStatics.h"

AZombieAIController::AZombieAIController()
{
    static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("/Game/AI/BT_Zombie"));
    static ConstructorHelpers::FObjectFinder<UBlackboardData> BB(TEXT("/Game/AI/BB_Zombie"));

    if (BT.Succeeded()) BehaviorTreeAsset = BT.Object;
    if (BB.Succeeded()) BlackboardAsset = BB.Object;
}

void AZombieAIController::BeginPlay()
{
    Super::BeginPlay();

    if (UseBlackboard(BlackboardAsset, Blackboard))
    {
        RunBehaviorTree(BehaviorTreeAsset);

        // Set SelfActor to this pawn
        APawn* ControlledPawn = GetPawn();
        if (ControlledPawn)
        {
            Blackboard->SetValueAsObject(TEXT("SelfActor"), ControlledPawn);
        }
    }
}
