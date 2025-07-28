#include "WBP_HUD.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UWBP_HUD::NativeConstruct()
{
    Super::NativeConstruct();

    // Optional: Initialization logic here.
}

void UWBP_HUD::SetProgressBar(float CurrentHealth, float MaxHealth)
{
    if (!ProgressBar_Health || !TextBlock_Health || MaxHealth <= 0.0f)
    {
        return;
    }

    const float Percent = FMath::Clamp(CurrentHealth / MaxHealth, 0.0f, 1.0f);
    ProgressBar_Health->SetPercent(Percent);

    const FText HealthText = FText::Format(FText::FromString("{0}/{1}"),
        FText::AsNumber(FMath::RoundToInt(CurrentHealth)),
        FText::AsNumber(FMath::RoundToInt(MaxHealth)));

    TextBlock_Health->SetText(HealthText);
}
