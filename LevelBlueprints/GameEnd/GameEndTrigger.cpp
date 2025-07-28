#include "GameEndTrigger.h"
#include "Engine/TriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

AGameEndTrigger::AGameEndTrigger()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AGameEndTrigger::BeginPlay()
{
    Super::BeginPlay();

    if (TriggerVolume)
    {
        TriggerVolume->OnActorBeginOverlap.AddDynamic(this, &AGameEndTrigger::OnOverlapBegin);
    }
}

void AGameEndTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (OtherActor == PlayerChar)
    {
        APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
        if (PC)
        {
            PC->DisableInput(PC);
        }

        if (LevelSequencePlayer)
        {
            LevelSequencePlayer->Play();
        }

        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
            {
                UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad);
            }, 3.0f, false); // Delay as needed
    }
}
