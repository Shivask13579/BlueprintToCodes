#include "BP_Drawer.h"
#include "Components/BoxComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"

ABP_Drawer::ABP_Drawer()
{
    PrimaryActorTick.bCanEverTick = false;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    TriggerBox->SetupAttachment(RootComponent);
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ABP_Drawer::OnTriggerBeginOverlap);

    bInside = false;
    bCanToggle = false;
}

void ABP_Drawer::BeginPlay()
{
    Super::BeginPlay();

    PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    EnableInput(UGameplayStatics::GetPlayerController(this, 0));
    if (InputComponent)
    {
        InputComponent->BindAction("Interact", IE_Pressed, this, &ABP_Drawer::ToggleDrawer);
    }
}

void ABP_Drawer::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor == PlayerCharacter)
    {
        bCanToggle = true;
    }
}

void ABP_Drawer::ToggleDrawer()
{
    if (!bCanToggle) return;

    if (bInside)
    {
        MoveToLocation(OutsideLocation, OutsideRotation);
    }
    else
    {
        MoveToLocation(InsideLocation, InsideRotation);
    }

    bInside = !bInside;
}

void ABP_Drawer::MoveToLocation(const FVector& Location, const FRotator& Rotation)
{
    SetActorLocation(Location);
    SetActorRotation(Rotation);
}
