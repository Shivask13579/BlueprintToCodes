#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "FloorFootAnimNotify.generated.h"

UCLASS()
class F_Zombie_API UFloorFootAnimNotify : public UAnimNotify
{
    GENERATED_BODY()

public:
    virtual bool Received_Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) const override;

protected:
    UPROPERTY(EditAnywhere, Category = "Footstep")
    float TraceDistance = 50.0f;

    UPROPERTY(EditAnywhere, Category = "Footstep")
    USoundBase* Sound_Default;

    UPROPERTY(EditAnywhere, Category = "Footstep")
    USoundBase* Sound_Stone;

    UPROPERTY(EditAnywhere, Category = "Footstep")
    USoundBase* Sound_Dirt;

    UPROPERTY(EditAnywhere, Category = "Footstep")
    USoundBase* Sound_Metal;
};
