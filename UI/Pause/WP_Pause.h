#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WP_Pause.generated.h"

class UButton;

UCLASS()
class F_Zombie_API UWP_Pause : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void OnExitClicked();

    UFUNCTION()
    void OnResumeClicked();

    UFUNCTION()
    void OnMainMenuClicked();

    UPROPERTY(meta = (BindWidget))
    UButton* ExitButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ResumeButton;

    UPROPERTY(meta = (BindWidget))
    UButton* MainMenuButton;
};
