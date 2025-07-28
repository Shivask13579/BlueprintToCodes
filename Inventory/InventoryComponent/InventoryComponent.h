#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemStructure.h"
#include "InventoryComponent.generated.h"

class UInventoryWidget;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class F_Zombie_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    virtual void BeginPlay() override;

    // Inventory logic
    UFUNCTION(BlueprintCallable)
    void AddItem(const FItemStructure& Item);

    UFUNCTION(BlueprintCallable)
    void RemoveItemByName(const FText& ItemName);

    UFUNCTION(BlueprintCallable)
    void ToggleInventory();

    const TArray<FItemStructure>& GetItems() const { return Items; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TSubclassOf<UInventoryWidget> InventoryWidgetClass;

    UPROPERTY()
    UInventoryWidget* InventoryWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<FItemStructure> Items;

private:
    void RefreshUI();
};
