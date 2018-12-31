// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrainGameMode.h"
#include "Navmesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "ActorPoolComponent.h"

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPoolComponent>(TEXT("ActorPoolComponent"));

}


void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	TActorIterator<ANavMeshBoundsVolume> actorIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (actorIterator)
	{
		AddToPool(*actorIterator);
		++actorIterator;
	}

}

void AInfiniteTerrainGameMode::AddToPool(ANavMeshBoundsVolume* VolumeToAdd)
{

	NavMeshBoundsVolumePool->Add(VolumeToAdd);

}

