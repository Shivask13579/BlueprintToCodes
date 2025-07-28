#include "BP_Damage.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

ABP_Damage::ABP_Damage()
{
    PrimaryActorTick.bCanEverTick = false;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    RootComponent = BoxComponent;

    BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ABP_Damage::OnBoxBeginOverlap);
}

void ABP_Damage::BeginPlay()
{
    Super::BeginPlay();
}

void ABP_Damage::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this)
    {
        UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, nullptr, this, nullptr);
    }
}
