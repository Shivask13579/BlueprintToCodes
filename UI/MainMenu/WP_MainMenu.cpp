#include "WP_MainMenu.h"
#include "Components/Button.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void UWP_MainMenu::NativeConstruct()
{
    Super::NativeConstruct();

    if (Button_Play)
        Button_Play->OnClicked.AddDynamic(this, &UWP_MainMenu::OnPlayClicked);

    if (Button_Quit)
        Button_Quit->OnClicked.AddDynamic(this, &UWP_MainMenu::OnQuitClicked);

    // Setup Input UI only
    if (APlayerController* PC = GetOwningPlayer())
    {
        PC->bShowMouseCursor = true;

        FInputModeUIOnly InputMode;
        InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        InputMode.SetWidgetToFocus(TakeWidget());
        PC->SetInputMode(InputMode);
    }
}

void UWP_MainMenu::OnPlayClicked()
{
    // Remove all widgets
    UWidgetBlueprintLibrary::RemoveAllWidgets(this);

    // Load and show GameDetails widget
    static ConstructorHelpers::FClassFinder<UUserWidget> GameDetailsClass(TEXT("/Game/UI/WB_GameDetails.WB_GameDetails_C"));
    if (GameDetailsClass.Succeeded())
    {
        UUserWidget* GameDetailsWidget = CreateWidget<UUserWidget>(GetWorld(), GameDetailsClass.Class);
        if (GameDetailsWidget)
        {
            GameDetailsWidget->AddToViewport();
        }
    }
}

void UWP_MainMenu::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
