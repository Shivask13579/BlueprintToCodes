#include "BP_Zombie.h"
#include "Perception/PawnSensingComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Sound/SoundCue.h"
#include "GameFramework/CharacterMovementComponent.h"

ABP_Zombie::ABP_Zombie()
{
    PrimaryActorTick.bCanEverTick = true;

    PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
    AttackTracePoint = CreateDefaultSubobject<USceneComponent>(TEXT("AttackTracePoint"));
    AttackTracePoint->SetupAttachment(RootComponent);

    bAttacking = false;
    bZombieDead = false;
    BoxDuration = 3.0f;
}

void ABP_Zombie::BeginPlay()
{
    Super::BeginPlay();

    if (PawnSensing)
    {
        PawnSensing->OnSeePawn.AddDynamic(this, &ABP_Zombie::OnSeePawn);
    }
}

void ABP_Zombie::OnSeePawn(APawn* Pawn)
{
    if (!Pawn || bZombieDead) return;

    // Set blackboard value for AI to chase player
    AAIController* AI = Cast<AAIController>(GetController());
    if (AI && AI->GetBlackboardComponent())
    {
        AI->GetBlackboardComponent()->SetValueAsBool("seeingPlayer", true);
    }

    PlayChaseAudio();
}

void ABP_Zombie::AttackPlayer()
{
    if (bAttacking || bZombieDead) return;

    bAttacking = true;

    // Play attack animation or sound
    UGameplayStatics::PlaySoundAtLocation(this, ChaseAudio, GetActorLocation());

    // Damage logic would go here...

    // Reset attack state after delay
    GetWorldTimerManager().SetTimer(AttackResetTimer, this, &ABP_Zombie::ResetAttack, BoxDuration, false);
}

void ABP_Zombie::ResetAttack()
{
    bAttacking = false;
}

void ABP_Zombie::HandleDeath()
{
    if (bZombieDead) return;

    bZombieDead = true;

    // Stop AI logic or animations
    AController* AI = GetController();
    if (AI)
    {
        AI->UnPossess();
    }

    // Play death sound, animation, destroy actor later, etc.
}

void ABP_Zombie::PlayChaseAudio()
{
    if (ChaseAudio)
    {
        UGameplayStatics::PlaySoundAtLocation(this, ChaseAudio, GetActorLocation());
    }
}
