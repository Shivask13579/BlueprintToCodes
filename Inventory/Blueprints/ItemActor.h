#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemStructure.h"
#include "ItemActor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class F_Zombie_API AItemActor : public AActor
{
    GENERATED_BODY()

public:
    AItemActor();

protected:
    virtual void BeginPlay() override;
    virtual void OnConstruction(const FTransform& Transform) override;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FItemStructure Item;

protected:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* StaticMesh;

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* Trigger;
};
