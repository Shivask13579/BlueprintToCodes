#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndActor.generated.h"

UCLASS()
class F_Zombie_API AEndActor : public AActor
{
    GENERATED_BODY()

public:
    AEndActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void CollectItem();

private:
    void RotateDoor(float DeltaTime);
    void OpenLevel();

    UPROPERTY(EditAnywhere)
    class UBoxComponent* TriggerBox;

    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* Door;

    UPROPERTY(EditAnywhere)
    USoundBase* Sound;

    UPROPERTY(EditAnywhere)
    UAnimMontage* WeaponMontage;

    UPROPERTY(EditAnywhere)
    FName LevelToOpen;

    FRotator InitialRotation;
    FRotator TargetRotation;

    float TimelineAlpha;
    bool bRotateDoor;

    int32 CurrentItemsCollected;
    int32 RequiredItems;
    bool bGateOpened;
};
