#include "BTTask_Chasing.h"
#include "Kismet/GameplayStatics.h"

UBTTask_Chasing::UBTTask_Chasing()
{
    NodeName = "Chase Player";

    bUseBlackboardKey = false;
    AcceptanceRadius = 120.f;
    bStopOnOverlap = false;

    AActor* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (Player)
    {
        TargetActor = Player;
    }
}
