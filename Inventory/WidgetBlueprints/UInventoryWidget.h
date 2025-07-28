#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemStructure.h"
#include "InventoryWidget.generated.h"

class UWrapBox;
class USlotWidget;

UCLASS()
class F_Zombie_API UInventoryWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void LoadInventory(const TArray<FItemStructure>& Items);

protected:
    UPROPERTY(meta = (BindWidget))
    UWrapBox* WrapBox;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<USlotWidget> SlotWidgetClass;
};
