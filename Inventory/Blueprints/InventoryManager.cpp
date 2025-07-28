#include "InventoryManager.h"

void AInventoryManager::CollectItem(const FItemStructure& Item)
{
    for (auto& I : Inventory)
    {
        if (I.Name.EqualTo(Item.Name) && I.bStackable)
        {
            I.Quantity += Item.Quantity;
            return;
        }
    }

    Inventory.Add(Item);
}

const TArray<FItemStructure>& AInventoryManager::GetInventory() const
{
    return Inventory;
}
