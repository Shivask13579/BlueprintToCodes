#include "WBP_Blood.h"

void UWBP_Blood::NativeConstruct()
{
    Super::NativeConstruct();
    // Initialization logic here if needed
}

void UWBP_Blood::PlayHitAnimation()
{
    if (GetHit)
    {
        PlayAnimation(GetHit, 0.f, 1, EUMGSequencePlayMode::Forward, 1.f, false);
    }
}
