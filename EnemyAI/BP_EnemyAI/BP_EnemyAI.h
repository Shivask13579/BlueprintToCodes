#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BP_EnemyAI.generated.h"

class UPawnSensingComponent;
class USceneComponent;
class UAnimMontage;

UCLASS()
class F_Zombie_API ABP_EnemyAI : public ACharacter
{
    GENERATED_BODY()

public:
    ABP_EnemyAI();

protected:
    virtual void BeginPlay() override;

    // Perception
    UFUNCTION()
    void OnSeePawn(APawn* Pawn);

    // Attack logic
    UFUNCTION(BlueprintCallable)
    void Attack();

    // Handle damage or trace
    void PerformAttackTrace();

    // Timer reset
    void ResetAttack();

protected:
    // --- COMPONENTS ---
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UPawnSensingComponent* PawnSensing;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USceneComponent* AttackTracePoint;

    // --- VARIABLES ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    bool bAttacking;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float AttackCooldown = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float AttackRange = 200.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float AttackDamage = 20.f;

private:
    FTimerHandle AttackResetTimer;
};
