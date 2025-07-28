#include "WB_StaminaBar.h"
#include "Kismet/GameplayStatics.h"
#include "MainCharacter.h" // Make sure this matches your class name

float UWB_StaminaBar::GetStaminaPercent() const
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (AMainCharacter* MainChar = Cast<AMainCharacter>(PlayerPawn))
    {
        return MainChar->Stamina / 100.0f;
    }

    return 0.0f;
}
