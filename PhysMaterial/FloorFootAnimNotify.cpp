#include "FloorFootAnimNotify.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Animation/AnimSequenceBase.h"
#include "Engine/World.h"

bool UFloorFootAnimNotify::Received_Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) const
{
    if (!MeshComp || !MeshComp->GetOwner()) return false;

    FVector Start = MeshComp->GetSocketLocation(FName("foot_l")); // or use "foot_r" depending on notify
    FVector End = Start - FVector(0, 0, TraceDistance);

    FHitResult Hit;
    FCollisionQueryParams Params(TEXT("FootstepTrace"), false, MeshComp->GetOwner());

    if (MeshComp->GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
    {
        EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());

        USoundBase* SoundToPlay = Sound_Default;

        switch (SurfaceType)
        {
        case SurfaceType1: // STONE
            SoundToPlay = Sound_Stone;
            break;
        case SurfaceType2: // DIRT
            SoundToPlay = Sound_Dirt;
            break;
        case SurfaceType3: // METAL
            SoundToPlay = Sound_Metal;
            break;
        default:
            break;
        }

        if (SoundToPlay)
        {
            UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(), SoundToPlay, Hit.Location);
        }
    }

    return true;
}
