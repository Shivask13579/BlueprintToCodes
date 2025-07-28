#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SpringArmComponent.h"
#include "Components/SpotLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

AMainCharacter::AMainCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Camera Boom
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);

    // Camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom);

    // Flashlight
    Flashlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Flashlight"));
    Flashlight->SetupAttachment(FollowCamera);
    Flashlight->SetVisibility(false);

    // Defaults
    MaxHealth = 100.0f;
    CurrentHealth = MaxHealth;
    Stamina = 100.0f;
    bFlashlightActive = false;
    bIsDead = false;
    bIsRunning = false;
}

void AMainCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (MissionWidget)
    {
        MissionWidget->AddToViewport();
    }

    if (PauseMenuWidget)
    {
        PauseMenuWidget->AddToViewport();
        PauseMenuWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (FadeWidget)
    {
        FadeWidget->AddToViewport();
    }

    if (OptionsWidget)
    {
        OptionsWidget->AddToViewport();
        OptionsWidget->SetVisibility(ESlateVisibility::Hidden);
    }
}

void AMainCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Add custom tick behavior if needed
}

void AMainCharacter::UpdateMission(const FString& NewMission)
{
    CurrentMission = NewMission;

    if (MissionWidget)
    {
        UTextBlock* MissionText = Cast<UTextBlock>(MissionWidget->GetWidgetFromName("MissionText"));
        if (MissionText)
        {
            MissionText->SetText(FText::FromString(CurrentMission));
        }
    }

    if (MissionUpdateSound)
    {
        UGameplayStatics::PlaySound2D(this, MissionUpdateSound);
    }
}

void AMainCharacter::ToggleFlashlight()
{
    bFlashlightActive = !bFlashlightActive;

    if (Flashlight)
    {
        Flashlight->SetVisibility(bFlashlightActive);
    }
}
