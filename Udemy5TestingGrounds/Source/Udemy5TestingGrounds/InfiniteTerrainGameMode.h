// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Udemy5TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
class ANavMeshBoundsVolume;

UCLASS()
class UDEMY5TESTINGGROUNDS_API AInfiniteTerrainGameMode : public AUdemy5TestingGroundsGameMode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

private:
	void AddToPool(ANavMeshBoundsVolume* VolumeToAdd);
};
