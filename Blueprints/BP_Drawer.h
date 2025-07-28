#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_Drawer.generated.h"

class UBoxComponent;
class ACharacter;

UCLASS()
class F_Zombie_API ABP_Drawer : public AActor
{
    GENERATED_BODY()

public:
    ABP_Drawer();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    void ToggleDrawer();

    void MoveToLocation(const FVector& Location, const FRotator& Rotation);

    // Input binding
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

    UPROPERTY(EditAnywhere)
    FVector InsideLocation;

    UPROPERTY(EditAnywhere)
    FRotator InsideRotation;

    UPROPERTY(EditAnywhere)
    FVector OutsideLocation;

    UPROPERTY(EditAnywhere)
    FRotator OutsideRotation;

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* TriggerBox;

    UPROPERTY()
    ACharacter* PlayerCharacter;

    bool bInside;
    bool bCanToggle;
};
