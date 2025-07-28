#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WBP_GameDetails.generated.h"

class UButton;

UCLASS()
class F_Zombie_API UWBP_GameDetails : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

protected:
    UFUNCTION()
    void OnStartButtonClicked();

    UFUNCTION()
    void DelayedLoadLevel();

    UPROPERTY(meta = (BindWidget))
    UButton* Button_53;

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UUserWidget> LoadingScreenClass;

    UPROPERTY(EditAnywhere, Category = "Level")
    FName LevelToLoad = "Zombie";

private:
    FTimerHandle DelayHandle;
};
