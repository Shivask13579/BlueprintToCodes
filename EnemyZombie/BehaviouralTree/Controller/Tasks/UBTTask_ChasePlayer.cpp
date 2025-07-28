#include "BTTask_ChasePlayer.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UBTTask_ChasePlayer::UBTTask_ChasePlayer()
{
    NodeName = "Chase Player";

    bUseBlackboardKey = false;
    bObserveBlackboardValue = false;
    AcceptanceRadius = 120.f;
    bStopOnOverlap = false;

    ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (PlayerCharacter)
    {
        TargetActor = PlayerCharacter;
    }
}
