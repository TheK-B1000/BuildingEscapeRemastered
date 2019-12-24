// K-B Enterprises

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnitedPlanetsGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API AUnitedPlanetsGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
