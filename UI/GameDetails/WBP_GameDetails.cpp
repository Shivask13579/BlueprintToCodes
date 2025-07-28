#include "WBP_GameDetails.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "TimerManager.h"

void UWBP_GameDetails::NativeConstruct()
{
    Super::NativeConstruct();

    if (StartButton)
    {
        StartButton->OnClicked.AddDynamic(this, &UWBP_GameDetails::OnStartButtonClicked);
    }
}

void UWBP_GameDetails::OnStartButtonClicked()
{
    // Add loading screen
    if (LoadingScreenClass)
    {
        if (UUserWidget* LoadingScreen = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenClass))
        {
            LoadingScreen->AddToViewport();
        }
    }

    // Delay before level load
    GetWorld()->GetTimerManager().SetTimer(DelayHandle, this, &UWBP_GameDetails::DelayedLoadLevel, 1.0f, false);
}

void UWBP_GameDetails::DelayedLoadLevel()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PC)
    {
        PC->bShowMouseCursor = false;
        PC->SetInputMode(FInputModeGameOnly());
    }

    UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad);
}
