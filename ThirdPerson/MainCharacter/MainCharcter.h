#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sound/SoundBase.h"
#include "MainCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UUserWidget;
class UTextBlock;
class USpotLightComponent;

UCLASS()
class F_Zombie_API AMainCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMainCharacter();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // UI
    UFUNCTION(BlueprintCallable)
    void UpdateMission(const FString& NewMission);

    UFUNCTION(BlueprintCallable)
    void ToggleFlashlight();

protected:
    // Camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UCameraComponent* FollowCamera;

    // Flashlight
    UPROPERTY(VisibleAnywhere)
    USpotLightComponent* Flashlight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bFlashlightActive;

    // Stats
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentHealth;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxHealth;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Stamina;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsRunning;

    // Mission System
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CurrentMission;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USoundBase* MissionUpdateSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UUserWidget* MissionWidget;

    // Widgets
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UUserWidget* PauseMenuWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UUserWidget* FadeWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UUserWidget* OptionsWidget;
};
