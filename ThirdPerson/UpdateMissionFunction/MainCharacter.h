UCLASS()
class YOURGAME_API AMainCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void UpdateMission(const FString& NewMission);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    FString CurrentMission;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    class USoundBase* MissionSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    class UUserWidget* MissionWidget;

    // Must point to widget type with a MissionText field (e.g., UTextBlock*)
};
