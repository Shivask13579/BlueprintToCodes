#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WBP_Blood.generated.h"

class UWidgetAnimation;

UCLASS()
class F_Zombie_API UWBP_Blood : public UUserWidget
{
    GENERATED_BODY()

public:
    // Called by C++ or Blueprint to trigger the blood hit animation
    UFUNCTION(BlueprintCallable)
    void PlayHitAnimation();

protected:
    virtual void NativeConstruct() override;

    // Animation reference
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* GetHit;
};
