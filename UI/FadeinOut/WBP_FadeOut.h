#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WBP_FadeOut.generated.h"

UCLASS()
class F_Zombie_API UWBP_FadeOut : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void FadeIn();

    UFUNCTION(BlueprintCallable)
    void FadeOut();

protected:
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* Fade_In;

    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* Fade_Out;
};
