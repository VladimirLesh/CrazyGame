// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	InitialLocation = FVector(0, 0, 0);
	PlacedLocation = FVector(0, 0, 0);
	WorldOrigin = FVector(0, 0, 0);
	InitialDirection = FVector(0, 0, 0);
	
	bInitializedFloaterLocation = true;
	bIsShouldFloat = false;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	PlacedLocation = GetActorLocation();
	
	if (bInitializedFloaterLocation)
	{
		SetActorLocation(InitialLocation);
	}
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsShouldFloat)
	{
		FHitResult HitResult;
		AddActorLocalOffset(InitialDirection, false, &HitResult);
	}

}

