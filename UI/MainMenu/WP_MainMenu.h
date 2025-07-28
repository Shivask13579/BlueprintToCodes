#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WP_MainMenu.generated.h"

class UButton;

UCLASS()
class F_Zombie_API UWP_MainMenu : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void OnPlayClicked();

    UFUNCTION()
    void OnQuitClicked();

    UPROPERTY(meta = (BindWidget))
    UButton* Button_Play;

    UPROPERTY(meta = (BindWidget))
    UButton* Button_Quit;
};
