#include "EndActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "MainCharacterClass.h"

AEndActor::AEndActor()
{
    PrimaryActorTick.bCanEverTick = true;

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AEndActor::OnOverlapBegin);

    Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
    Door->SetupAttachment(RootComponent);

    TimelineAlpha = 0.0f;
    bRotateDoor = false;
    bGateOpened = false;

    CurrentItemsCollected = 0;
    RequiredItems = 6; 
}

void AEndActor::BeginPlay()
{
    Super::BeginPlay();

    InitialRotation = Door->GetComponentRotation();
    TargetRotation = InitialRotation + FRotator(0.f, 120.f, 0.f); 

    // Open gate after 1s delay (BeginPlay Delay)
    GetWorldTimerManager().SetTimerForNextTick([this]()
    {
        bGateOpened = true;
    });
}

void AEndActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bRotateDoor && TimelineAlpha < 1.0f)
    {
        TimelineAlpha += DeltaTime / 10.0f; // 1s duration
        FRotator NewRotation = FMath::Lerp(InitialRotation, TargetRotation, TimelineAlpha);
        Door->SetWorldRotation(NewRotation);
    }
}

void AEndActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
                                bool bFromSweep, const FHitResult& SweepResult)
{
    MainCharacterClass* Player = Cast<MainCharacterClass>(OtherActor);
    if (Player)
    {
        if (Sound)
        {
            UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
        }

        if (WeaponMontage)
        {
            Player->PlayAnimMontage(WeaponMontage);
        }

        // Fade out and open level
        APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
        if (PC)
        {
            PC->PlayerCameraManager->StartCameraFade(0.f, 1.f, 1.f, FLinearColor::Black);
        }

        GetWorldTimerManager().SetTimerForNextTick([this]()
        {
            OpenLevel();
        });
    }
}

void AEndActor::CollectItem()
{
    CurrentItemsCollected++;

    if (!bGateOpened && CurrentItemsCollected >= RequiredItems)
    {
        bGateOpened = true;
        bRotateDoor = true;
        TimelineAlpha = 0.0f;
    }
}

void AEndActor::OpenLevel()
{
    if (!LevelToOpen.IsNone())
    {
        UGameplayStatics::OpenLevel(this, GameEnd);
    }
}
