// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
#include "Engine/World.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn)
{
	FVector Min(0.f, -2000.f, 0.f);
	FVector Max(4000.f, 2000.f, 0.f);
	FBox Box(Min, Max);

	int NumberOfActors = FMath::RandRange(MinSpawn, MaxSpawn);

	for (int i = 0; i < NumberOfActors; i++)
	{
		FVector Location = FMath::RandPointInBox(Box);
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ToSpawn);
		SpawnedActor->SetActorRelativeLocation(Location);
		SpawnedActor->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	}
	

}