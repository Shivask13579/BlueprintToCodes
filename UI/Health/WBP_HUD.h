#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WBP_HUD.generated.h"

class UProgressBar;
class UTextBlock;

UCLASS()
class F_Zombie_API UWBP_HUD : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void SetProgressBar(float CurrentHealth, float MaxHealth);

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* ProgressBar_Health;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TextBlock_Health;
};
