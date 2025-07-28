#include "AudioTriggerActor.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

AAudioTriggerActor::AAudioTriggerActor()
{
    PrimaryActorTick.bCanEverTick = false;

    TriggerAudio = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerAudio"));
    RootComponent = TriggerAudio;

    TriggerAudio->OnComponentBeginOverlap.AddDynamic(this, &AAudioTriggerActor::OnOverlapBegin);
    TriggerAudio->OnComponentEndOverlap.AddDynamic(this, &AAudioTriggerActor::OnOverlapEnd);
}

void AAudioTriggerActor::BeginPlay()
{
    Super::BeginPlay();
}

void AAudioTriggerActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->ActorHasTag("MainCharacter"))
    {
        if (SoundToPlay)
        {
            // Spawn a 2D sound and fade in
            Audio = UGameplayStatics::SpawnSound2D(this, SoundToPlay, 1.0f, 1.0f, 0.0f, nullptr, true);
            if (Audio)
            {
                Audio->FadeIn(FadeDuration);
            }
        }
    }
}

void AAudioTriggerActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor->ActorHasTag("MainCharacter"))
    {
        if (Audio)
        {
            Audio->FadeOut(FadeDuration, 0.0f);
        }
    }
}
