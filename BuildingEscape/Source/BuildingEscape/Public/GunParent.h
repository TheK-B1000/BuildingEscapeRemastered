// K-B Enterprises

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunParent.generated.h"

UCLASS()
class BUILDINGESCAPE_API AGunParent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunParent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void StartShooting();

	void StopShooting();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		bool bIsFiring;

	UPROPERTY(EditAnywhere)
		int AmmoCurrent;

	UPROPERTY(EditAnywhere)
		int AmmoMax = 100;

	UPROPERTY(EditAnywhere)
		int ClipSize = 15;

	UPROPERTY(EditAnywhere)
		float FireRate = 0.15;

	UPROPERTY(EditAnywhere)
		USceneComponent* WorldRotation;

	UPROPERTY(EditAnywhere)
		USceneComponent* WorldLocation;

	UPROPERTY(EditAnywhere)
		USceneComponent* FirstPersonCharacter;

	UFUNCTION(BlueprintCallable)
		void FireBullet();



};
