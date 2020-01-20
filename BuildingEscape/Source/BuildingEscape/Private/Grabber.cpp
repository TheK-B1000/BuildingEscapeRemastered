// K-B Enterprises


#include "Grabber.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Math/Color.h"
#include "CollisionQueryParams.h"


#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (PhysicsHandle)
	{
		// Physics Handle Found
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle Component is not attached to: %s"),  *PhysicsHandle->GetName());
	}

	if (InputComponent)
	{
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get Players Viewpoint
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint
	(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	// Draw Debug Line

	FVector LineTraceDirection = PlayerViewPointRotation.Vector();
	FVector LineTraceEnd = PlayerViewPointLocation + (LineTraceDirection * Reach);
	
	DrawDebugLine
	(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor().Green,
		false,
		0.0f,
		10,
		5.0f
	);

	FHitResult  Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	// Ray-cast out to a certain distance (Reach)
	GetWorld()->LineTraceSingleByObjectType
	(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams

	);
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab Pressed"));
}


void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab Released"));
}