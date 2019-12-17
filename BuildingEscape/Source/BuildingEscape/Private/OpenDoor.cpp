// K-B Enterprises

#include "GameFramework/Actor.h"
#include "OpenDoor.h"
#include "Math/Rotator.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();


	InitialYaw;
	CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	TargetYaw = CurrentYaw + InitialYaw;

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f "), GetOwner()->GetActorRotation().Yaw);

	float StartingYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator OpenDoor = FRotator(0.0f, TargetYaw, 0.0f);
	OpenDoor.Yaw = FMath::Lerp(StartingYaw, TargetYaw, 0.1f);
	GetOwner()->SetActorRotation(OpenDoor);


}

