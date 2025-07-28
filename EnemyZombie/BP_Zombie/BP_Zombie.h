#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BP_Zombie.generated.h"

class UPawnSensingComponent;
class UAudioComponent;
class USoundCue;

UCLASS()
class YOURGAME_API ABP_Zombie : public ACharacter
{
    GENERATED_BODY()

public:
    ABP_Zombie();

protected:
    virtual void BeginPlay() override;

    // Called when pawn sees a player
    UFUNCTION()
    void OnSeePawn(APawn* Pawn);

    // Attack logic
    UFUNCTION(BlueprintCallable)
    void AttackPlayer();

    // Death logic
    void HandleDeath();

    // Timers
    void ResetAttack();

    // Sound
    void PlayChaseAudio();

protected:
    // --- COMPONENTS ---
    UPROPERTY(VisibleAnywhere)
    UPawnSensingComponent* PawnSensing;

    UPROPERTY(VisibleAnywhere)
    USceneComponent* AttackTracePoint;

    // --- VARIABLES ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    bool bAttacking;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float BoxDuration = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundCue* ChaseAudio;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
    bool bZombieDead = false;

private:
    FTimerHandle AttackResetTimer;
};
