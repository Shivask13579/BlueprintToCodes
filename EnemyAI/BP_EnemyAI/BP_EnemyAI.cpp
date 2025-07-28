#include "BP_EnemyAI.h"
#include "Perception/PawnSensingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "DrawDebugHelpers.h"

ABP_EnemyAI::ABP_EnemyAI()
{
    PrimaryActorTick.bCanEverTick = true;

    // Components
    PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
    AttackTracePoint = CreateDefaultSubobject<USceneComponent>(TEXT("AttackTracePoint"));
    AttackTracePoint->SetupAttachment(RootComponent);

    bAttacking = false;
}

void ABP_EnemyAI::BeginPlay()
{
    Super::BeginPlay();

    if (PawnSensing)
    {
        PawnSensing->OnSeePawn.AddDynamic(this, &ABP_EnemyAI::OnSeePawn);
    }
}

void ABP_EnemyAI::OnSeePawn(APawn* Pawn)
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController && AIController->GetBlackboardComponent())
    {
        AIController->GetBlackboardComponent()->SetValueAsBool(TEXT("SeeingPlayer"), true);
    }
}

void ABP_EnemyAI::Attack()
{
    if (bAttacking) return;

    bAttacking = true;

    // Play anim or sound here...

    PerformAttackTrace();

    GetWorldTimerManager().SetTimer(AttackResetTimer, this, &ABP_EnemyAI::ResetAttack, AttackCooldown, false);
}

void ABP_EnemyAI::PerformAttackTrace()
{
    FVector Start = AttackTracePoint->GetComponentLocation();
    FVector Forward = GetActorForwardVector();
    FVector End = Start + Forward * AttackRange;

    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Pawn, Params);

#if WITH_EDITOR
    DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.0f, 0, 1.5f);
#endif

    if (bHit && Hit.GetActor())
    {
        UGameplayStatics::ApplyDamage(Hit.GetActor(), AttackDamage, GetController(), this, nullptr);
    }
}

void ABP_EnemyAI::ResetAttack()
{
    bAttacking = false;
}
