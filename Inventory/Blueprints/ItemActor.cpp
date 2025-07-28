#include "ItemActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "MainCharacter.h"
#include "InventoryManager.h"

AItemActor::AItemActor()
{
    PrimaryActorTick.bCanEverTick = false;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(RootComponent);

    Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
    Trigger->SetupAttachment(RootComponent);
    Trigger->SetCollisionProfileName("Trigger");
    Trigger->OnComponentBeginOverlap.AddDynamic(this, &AItemActor::OnOverlapBegin);
}

void AItemActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    if (Item.Mesh)
    {
        StaticMesh->SetStaticMesh(Item.Mesh);
        StaticMesh->SetSimulatePhysics(true);
    }
}

void AItemActor::BeginPlay()
{
    Super::BeginPlay();
}

void AItemActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    AMainCharacter* MainChar = Cast<AMainCharacter>(OtherActor);
    if (MainChar)
    {
        AInventoryManager* Manager = Cast<AInventoryManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AInventoryManager::StaticClass()));
        if (Manager)
        {
            Manager->CollectItem(Item);
            Destroy();
        }
    }
}
