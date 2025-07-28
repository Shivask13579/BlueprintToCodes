#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WBP_GameCompleted.generated.h"

UCLASS()
class F_Zombie_API UWBP_GameCompleted : public UUserWidget
{
    GENERATED_BODY()

protected:
    UFUNCTION()
    void OnPlayAgainClicked();

    UFUNCTION()
    void HandleLevelLoad();

    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    class UButton* PlayAgain;

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UUserWidget> LoadingScreenClass;

private:
    FTimerHandle DelayHandle;
};
