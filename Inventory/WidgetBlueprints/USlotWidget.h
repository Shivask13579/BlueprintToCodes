#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemStructure.h"
#include "SlotWidget.generated.h"

class UTextBlock;
class UImage;

UCLASS()
class F_Zombie_API USlotWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    void SetItem(const FItemStructure& NewItem);

protected:
    UPROPERTY(meta = (BindWidget))
    UImage* ItemImage;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ItemQuantity;

    FItemStructure Item;
};
