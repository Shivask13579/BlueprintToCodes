#include "WBP_GameCompleted.h"
#include "Components/Button.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void UWBP_GameCompleted::NativeConstruct()
{
    Super::NativeConstruct();

    if (PlayAgain)
    {
        PlayAgain->OnClicked.AddDynamic(this, &UWBP_GameCompleted::OnPlayAgainClicked);
    }
}

void UWBP_GameCompleted::OnPlayAgainClicked()
{
    // Remove existing UI
    UWidgetBlueprintLibrary::RemoveAllWidgets(GetWorld());

    // Show loading screen
    if (LoadingScreenClass)
    {
        UUserWidget* Loading = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenClass);
        if (Loading) Loading->AddToViewport();
    }

    // Delay then load level
    GetWorld()->GetTimerManager().SetTimer(DelayHandle, this, &UWBP_GameCompleted::HandleLevelLoad, 1.0f, false);
}

void UWBP_GameCompleted::HandleLevelLoad()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PC)
    {
        PC->bShowMouseCursor = false;
        PC->SetInputMode(FInputModeGameOnly());
    }

    UGameplayStatics::OpenLevel(GetWorld(), "Zombie");
}
