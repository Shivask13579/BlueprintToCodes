#include "MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

void AMainCharacter::UpdateMission(const FString& NewMission)
{
    CurrentMission = NewMission;

    if (MissionWidget)
    {
        UTextBlock* MissionText = Cast<UTextBlock>(MissionWidget->GetWidgetFromName(TEXT("MissionText")));
        if (MissionText)
        {
            MissionText->SetText(FText::FromString(CurrentMission));
        }
    }

    if (MissionSound)
    {
        UGameplayStatics::PlaySound2D(this, MissionSound);
    }
}
