#include "WP_Pause.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/PlayerController.h"
#include "YourGame/MainCharacter.h"

void UWP_Pause::NativeConstruct()
{
    Super::NativeConstruct();

    if (ExitButton)
        ExitButton->OnClicked.AddDynamic(this, &UWP_Pause::OnExitClicked);

    if (ResumeButton)
        ResumeButton->OnClicked.AddDynamic(this, &UWP_Pause::OnResumeClicked);

    if (MainMenuButton)
        MainMenuButton->OnClicked.AddDynamic(this, &UWP_Pause::OnMainMenuClicked);
}

void UWP_Pause::OnExitClicked()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

void UWP_Pause::OnResumeClicked()
{
    APlayerController* PC = GetOwningPlayer();
    if (!PC) return;

    UGameplayStatics::SetGamePaused(this, false);

    PC->bShowMouseCursor = false;

    FInputModeGameOnly InputMode;
    PC->SetInputMode(InputMode);

    // Optional: Enable input for character if needed
    if (AMainCharacter* Character = Cast<AMainCharacter>(PC->GetPawn()))
    {
        Character->SetInputEnabled(true);
    }

    this->RemoveFromParent();
}

void UWP_Pause::OnMainMenuClicked()
{
    APlayerController* PC = GetOwningPlayer();
    if (!PC) return;

    static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetClass(TEXT("/Game/UI/WP_MainMenu.WP_MainMenu_C"));
    if (MainMenuWidgetClass.Succeeded())
    {
        UUserWidget* MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass.Class);
        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();
        }
    }
}
