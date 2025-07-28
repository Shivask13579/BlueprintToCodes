#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WB_StaminaBar.generated.h"

UCLASS()
class F_Zombie_API UWB_StaminaBar : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UI")
    float GetStaminaPercent() const;
};
