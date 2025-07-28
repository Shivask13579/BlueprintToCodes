#include "WBP_FadeOut.h"

void UWBP_FadeOut::FadeIn()
{
    if (Fade_In)
    {
        PlayAnimation(Fade_In);
    }
}

void UWBP_FadeOut::FadeOut()
{
    if (Fade_Out)
    {
        PlayAnimation(Fade_Out);
    }
}
