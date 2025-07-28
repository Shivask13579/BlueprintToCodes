#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WB_OptionsMenu.generated.h"

class UButton;

UCLASS()
class F_Zombie_API UWB_OptionsMenu : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    // Button callbacks
    UFUNCTION()
    void On720pClicked();
    UFUNCTION()
    void On1080pClicked();
    UFUNCTION()
    void On2kClicked();

    UFUNCTION()
    void OnLowQualityClicked();
    UFUNCTION()
    void OnMediumQualityClicked();
    UFUNCTION()
    void OnHighQualityClicked();

    UFUNCTION()
    void OnShadowLowClicked();
    UFUNCTION()
    void OnShadowMediumClicked();
    UFUNCTION()
    void OnShadowHighClicked();

    // Buttons
    UPROPERTY(meta = (BindWidget)) UButton* Button_720p;
    UPROPERTY(meta = (BindWidget)) UButton* Button_1080p;
    UPROPERTY(meta = (BindWidget)) UButton* Button_2k;

    UPROPERTY(meta = (BindWidget)) UButton* Button_Low;
    UPROPERTY(meta = (BindWidget)) UButton* Button_Medium;
    UPROPERTY(meta = (BindWidget)) UButton* Button_High;

    UPROPERTY(meta = (BindWidget)) UButton* Button_ShadowLow;
    UPROPERTY(meta = (BindWidget)) UButton* Button_ShadowMedium;
    UPROPERTY(meta = (BindWidget)) UButton* Button_ShadowHigh;
};
