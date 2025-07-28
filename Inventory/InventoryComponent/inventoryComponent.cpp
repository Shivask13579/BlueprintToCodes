#include "InventoryComponent.h"
#include "InventoryWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

UInventoryComponent::UInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();

    if (InventoryWidgetClass)
    {
        InventoryWidget = CreateWidget<UInventoryWidget>(UGameplayStatics::GetPlayerController(this, 0), InventoryWidgetClass);
    }
}

void UInventoryComponent::AddItem(const FItemStructure& NewItem)
{
    for (FItemStructure& Item : Items)
    {
        if (Item.Name.EqualTo(NewItem.Name) && Item.bStackable)
        {
            Item.Quantity += NewItem.Quantity;
            RefreshUI();
            return;
        }
    }

    Items.Add(NewItem);
    RefreshUI();
}

void UInventoryComponent::RemoveItemByName(const FText& ItemName)
{
    for (int32 i = 0; i < Items.Num(); ++i)
    {
        if (Items[i].Name.EqualTo(ItemName))
        {
            Items.RemoveAt(i);
            RefreshUI();
            return;
        }
    }
}

void UInventoryComponent::ToggleInventory()
{
    if (!InventoryWidget) return;

    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC) return;

    bool bIsVisible = InventoryWidget->IsInViewport();

    if (bIsVisible)
    {
        InventoryWidget->RemoveFromParent();
        PC->bShowMouseCursor = false;
        PC->SetInputMode(FInputModeGameOnly());
    }
    else
    {
        InventoryWidget->AddToViewport();
        PC->bShowMouseCursor = true;
        PC->SetInputMode(FInputModeGameAndUI());
        RefreshUI();
    }
}

void UInventoryComponent::RefreshUI()
{
    if (InventoryWidget)
    {
        InventoryWidget->LoadInventory(Items);
    }
}
