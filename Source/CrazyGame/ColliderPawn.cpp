// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderPawn.h"

#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AColliderPawn::AColliderPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->InitSphereRadius(40.f);
	SphereComponent->SetCollisionProfileName("Pawn");

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshComponentAsset(TEXT("D:/Fork/CrazyGame/Content/StarterContent/Shapes/Shape_Sphere.uasset"));

    if (MeshComponentAsset.Succeeded())
    {
	    MeshComponent->SetStaticMesh(MeshComponentAsset.Object);
    }
}

// Called when the game starts or when spawned
void AColliderPawn::BeginPlay()
{
	Super::BeginPlay();

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshComponentAsset(TEXT("D:/Fork/CrazyGame/Content/StarterContent/Shapes/Shape_Sphere.uasset"));

	if (MeshComponentAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshComponentAsset.Object);
		UE_LOG(LogTemp, Warning, TEXT("MeshComponentAsset is found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MeshComponentAsset is not found"));
	}
	
}

// Called every frame
void AColliderPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AColliderPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

