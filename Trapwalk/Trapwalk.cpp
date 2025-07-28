#include "Trapwalk.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ATrapwalk::ATrapwalk()
{
    PrimaryActorTick.bCanEverTick = false;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    TriggerBox->SetupAttachment(RootComponent);
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATrapwalk::OnTriggerOverlap);
}

void ATrapwalk::BeginPlay()
{
    Super::BeginPlay();
}

void ATrapwalk::OnTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (!bTrapEnabled || !OtherActor) return;

    // Replace "ABP_Character" with your player character base class
    if (OtherActor->IsA(ABP_Character::StaticClass()))
    {
        FTimerHandle TimerHandle;
        GetWorldTimerManager().SetTimer(TimerHandle, [this, OtherActor]()
            {
                ExecuteTrap(OtherActor);
            }, TrapDelay, false);
    }
}

void ATrapwalk::ExecuteTrap(AActor* Target)
{
    if (TrapSound)
    {
        UGameplayStatics::PlaySound2D(this, TrapSound);
    }

    if (Target)
    {
        Target->Destroy();
    }
}
