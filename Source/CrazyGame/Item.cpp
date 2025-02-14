// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "MovieSceneTracksComponentTypes.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	IdleParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("IdleParticleComponent"));
	RootComponent = Mesh;

	SphereCollision->SetupAttachment(Mesh);
	IdleParticleComponent->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnBeginOverlap);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &AItem::OnEndOverlap);
	
	// SphereCollision->SetHiddenInGame(false);
}

void AItem::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnBeginOverlap"));

	if (OverlapParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticle, GetActorLocation(), FRotator(0.f), true);
	}

	Destroy();
}

void AItem::OnEndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OnEndOverlap"));
}


// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

