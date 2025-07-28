#include "IntroSequenceManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "MovieSceneSequencePlayer.h"
#include "TimerManager.h"

AIntroSequenceManager::AIntroSequenceManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AIntroSequenceManager::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC || !SequenceActor)
    {
        return;
    }

    if (!SequencePlayer)
    {
        UE_LOG(LogTemp, Warning, TEXT("SequencePlayer not assigned"));
        return;
    }

    PC->DisableInput(PC);
    SequencePlayer->Play();

    float Duration = SequencePlayer->GetDuration().AsSeconds() + AdditionalDelay;

    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AIntroSequenceManager::OnSequenceFinished, Duration, false);
}

void AIntroSequenceManager::OnSequenceFinished()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PC)
    {
        PC->EnableInput(PC);
    }
}
