#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_Damage.generated.h"

class UBoxComponent;

UCLASS()
class F_Zombie_API ABP_Damage : public AActor
{
    GENERATED_BODY()

public:
    ABP_Damage();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

private:
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* BoxComponent;

    UPROPERTY(EditAnywhere)
    float BaseDamage = 15.0f;
};
