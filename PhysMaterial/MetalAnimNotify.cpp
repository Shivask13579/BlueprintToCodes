#include "MetalFootstepAnimNotify.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

bool UMetalFootstepAnimNotify::Received_Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) const
{
    if (!MeshComp || !MeshComp->GetWorld())
    {
        return false;
    }

    const FVector Start = MeshComp->GetSocketLocation(FName("foot_l"));  // Adjust socket if needed
    const FVector End = Start - FVector(0.f, 0.f, TraceDistance);

    FHitResult Hit;
    FCollisionQueryParams Params(FName("FootstepMetalTrace"), true, MeshComp->GetOwner());

    bool bHit = MeshComp->GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params);

#if WITH_EDITOR
    DrawDebugLine(MeshComp->GetWorld(), Start, End, FColor::Silver, false, 1.0f, 0, 1.0f);
#endif

    if (bHit && Hit.PhysMaterial.IsValid())
    {
        EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());

        if (SurfaceType == SurfaceTypeToCheck)
        {
            USoundBase* SelectedSound = FMath::RandBool() ? MetalSound1 : MetalSound2;

            if (SelectedSound)
            {
                UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(), SelectedSound, Hit.Location);
                return true;
            }
        }
    }

    // Fallback to default
    if (DefaultSound)
    {
        UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(), DefaultSound, MeshComp->GetComponentLocation());
        return true;
    }

    return false;
}
