// K-B Enterprises

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Barrel_refpoint.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UBarrel_refpoint : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBarrel_refpoint();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
