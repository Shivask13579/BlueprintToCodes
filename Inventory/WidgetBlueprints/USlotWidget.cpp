#include "SlotWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void USlotWidget::SetItem(const FItemStructure& NewItem)
{
    Item = NewItem;

    if (ItemImage && Item.Thumbnail)
    {
        ItemImage->SetBrushFromTexture(Item.Thumbnail);
    }

    if (ItemQuantity)
    {
        if (Item.Quantity > 1)
        {
            ItemQuantity->SetText(FText::AsNumber(Item.Quantity));
            ItemQuantity->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            ItemQuantity->SetVisibility(ESlateVisibility::Hidden);
        }
    }
}
