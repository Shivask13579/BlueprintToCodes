#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameEndTrigger.generated.h"

class ALevelSequenceActor;
class ULevelSequencePlayer;

UCLASS()
class F_Zombie_API AGameEndTrigger : public AActor
{
    GENERATED_BODY()

public:
    AGameEndTrigger();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

    UPROPERTY(EditAnywhere, Category = "Trigger")
    class ATriggerVolume* TriggerVolume;

    UPROPERTY(EditAnywhere, Category = "Sequence")
    class ALevelSequenceActor* LevelSequenceActor;

    UPROPERTY(EditAnywhere, Category = "Sequence")
    class ULevelSequencePlayer* LevelSequencePlayer;

    UPROPERTY(EditAnywhere, Category = "GameEnd")
    FName LevelToLoad = "MainMenuMap";
};
