#include "WP_GameOver.h"
#include "Components/Button.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "GameFramework/PlayerController.h"

void UWP_GameOver::NativeConstruct()
{
    Super::NativeConstruct();

    if (RespawnButton)
        RespawnButton->OnClicked.AddDynamic(this, &UWP_GameOver::OnRespawnClicked);

    if (MainMenuButton)
        MainMenuButton->OnClicked.AddDynamic(this, &UWP_GameOver::OnMainMenuClicked);
}

void UWP_GameOver::OnRespawnClicked()
{
    // Remove all widgets
    UWidgetBlueprintLibrary::RemoveAllWidgets(this);

    // Create and add loading screen
    if (UClass* LoadingWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Game/UI/WB_LoadingScreen.WB_LoadingScreen_C")))
    {
        if (UUserWidget* LoadingScreen = CreateWidget<UUserWidget>(GetWorld(), LoadingWidgetClass))
        {
            LoadingScreen->AddToViewport();
        }
    }

    // Delay and load "Zombie" level
    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
        {
            APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
            if (PC)
            {
                PC->bShowMouseCursor = false;
                FInputModeGameOnly InputMode;
                PC->SetInputMode(InputMode);
            }

            UGameplayStatics::OpenLevel(this, FName("Zombie"));

        }, 1.0f, false);
}

void UWP_GameOver::OnMainMenuClicked()
{
    UGameplayStatics::OpenLevel(this, FName("MainMenuMap"));
}
