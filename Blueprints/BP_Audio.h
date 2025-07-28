#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioTriggerActor.generated.h"

UCLASS()
class F_Zombie_API AAudioTriggerActor : public AActor
{
    GENERATED_BODY()

public:
    AAudioTriggerActor();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
    UPROPERTY(EditAnywhere)
    class UBoxComponent* TriggerAudio;

    UPROPERTY(EditAnywhere)
    USoundBase* SoundToPlay;

    UPROPERTY()
    UAudioComponent* Audio;

    float FadeDuration = 0.5f;
};
