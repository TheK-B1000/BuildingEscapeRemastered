// K-B Enterprises


#include "GunParent.h"
#include "FPSCamera.h"
#include "Barrel_refpoint.h"

// Sets default values
AGunParent::AGunParent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGunParent::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGunParent::StartShooting()
{
	bIsFiring = true;
}

void AGunParent::StopShooting()
{
	bIsFiring = false;
}

// Called every frame
void AGunParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGunParent::FireBullet()
{
	auto GetParentActor = GetOwner()->GetParentActor();
	auto FirstPersonCharacter = GetParentActor->FindComponentByClass<UFPSCamera>();
	auto FPSCamera = FirstPersonCharacter->FirstPersonCamera;
	auto WorldRotation = FPSCamera->GetOwner()->GetActorRotation();
	auto Barrel_refpoint = FindComponentByClass<UBarrel_refpoint>();
	auto WorldLocation = Barrel_refpoint;


}

