#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemStructure.generated.h"

USTRUCT(BlueprintType)
struct FItemStructure
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStackable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Quantity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UTexture2D* Thumbnail;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UStaticMesh* Mesh;
};
