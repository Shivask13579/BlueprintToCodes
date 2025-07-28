#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IntroSequenceManager.generated.h"

class ULevelSequencePlayer;
class ALevelSequenceActor;

UCLASS()
class F_Zombie_API AIntroSequenceManager : public AActor
{
    GENERATED_BODY()

public:
    AIntroSequenceManager();

protected:
    virtual void BeginPlay() override;

    void OnSequenceFinished();

    UPROPERTY(EditAnywhere, Category = "Sequence")
    ALevelSequenceActor* SequenceActor;

    UPROPERTY(EditAnywhere, Category = "Sequence")
    ULevelSequencePlayer* SequencePlayer;

    UPROPERTY(EditAnywhere, Category = "Timing")
    float AdditionalDelay = 0.0f;
};
