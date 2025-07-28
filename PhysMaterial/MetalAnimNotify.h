#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "MetalFootstepAnimNotify.generated.h"

UCLASS()
class F_Zombie_API UMetalFootstepAnimNotify : public UAnimNotify
{
    GENERATED_BODY()

public:
    virtual bool Received_Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) const override;

protected:
    UPROPERTY(EditAnywhere, Category = "Footstep")
    float TraceDistance = 50.0f;

    UPROPERTY(EditAnywhere, Category = "Footstep")
    USoundBase* DefaultSound;

    UPROPERTY(EditAnywhere, Category = "Footstep")
    USoundBase* MetalSound1;

    UPROPERTY(EditAnywhere, Category = "Footstep")
    USoundBase* MetalSound2;

    UPROPERTY(EditAnywhere, Category = "Footstep")
    TEnumAsByte<EPhysicalSurface> SurfaceTypeToCheck = SurfaceType3; // Customizable in-editor
};
