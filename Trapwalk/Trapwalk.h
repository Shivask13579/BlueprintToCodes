#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trapwalk.generated.h"

class UBoxComponent;
class USoundBase;

UCLASS()
class F_Zombie_API ATrapwalk : public AActor
{
    GENERATED_BODY()

public:
    ATrapwalk();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    void ExecuteTrap(AActor* Target);

protected:
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* TriggerBox;

    UPROPERTY(EditAnywhere, Category = "Trap")
    bool bTrapEnabled = true;

    UPROPERTY(EditAnywhere, Category = "Trap")
    float TrapDelay = 0.25f;

    UPROPERTY(EditAnywhere, Category = "Trap")
    USoundBase* TrapSound;
};
