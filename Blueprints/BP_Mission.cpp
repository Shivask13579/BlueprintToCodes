#include "BP_Mission.h"
#include "Components/BoxComponent.h"
#include "MainCharacter.h" // Make sure this includes UpdateMission()
#include "Kismet/GameplayStatics.h"

ABP_Mission::ABP_Mission()
{
    PrimaryActorTick.bCanEverTick = false;

    MissionTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("MissionTrigger"));
    RootComponent = MissionTrigger;

    MissionTrigger->OnComponentBeginOverlap.AddDynamic(this, &ABP_Mission::OnTriggerBeginOverlap);
}

void ABP_Mission::BeginPlay()
{
    Super::BeginPlay();
}

void ABP_Mission::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (bActivated) return;

    AMainCharacter* MainChar = Cast<AMainCharacter>(OtherActor);
    if (MainChar)
    {
        bActivated = true;

        MainChar->UpdateMission(NewMission); // Assumes UpdateMission(FMissionData)
        Destroy();
    }
}
