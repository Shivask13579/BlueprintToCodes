#include "InventoryWidget.h"
#include "Components/WrapBox.h"
#include "SlotWidget.h"

void UInventoryWidget::LoadInventory(const TArray<FItemStructure>& Items)
{
    WrapBox->ClearChildren();

    for (const FItemStructure& Item : Items)
    {
        USlotWidget* Slot = CreateWidget<USlotWidget>(GetWorld(), SlotWidgetClass);
        if (Slot)
        {
            Slot->SetItem(Item);
            WrapBox->AddChild(Slot);
        }
    }
}
