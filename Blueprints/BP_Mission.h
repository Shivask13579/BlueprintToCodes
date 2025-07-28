#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_Mission.generated.h"

class UBoxComponent;
class AMainCharacter;
struct FMissionData; // Replace with your actual struct type

UCLASS()
class F_Zombie_API ABP_Mission : public AActor
{
    GENERATED_BODY()

public:
    ABP_Mission();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

private:
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* MissionTrigger;

    UPROPERTY(EditAnywhere)
    FMissionData NewMission;

    bool bActivated = false;
};
