#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WP_GameOver.generated.h"

class UButton;

UCLASS()
class F_Zombie_API UWP_GameOver : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void OnRespawnClicked();

    UFUNCTION()
    void OnMainMenuClicked();

    void LoadLevelDelayed(FName LevelName);

    UPROPERTY(meta = (BindWidget))
    UButton* RespawnButton;

    UPROPERTY(meta = (BindWidget))
    UButton* MainMenuButton;
};
