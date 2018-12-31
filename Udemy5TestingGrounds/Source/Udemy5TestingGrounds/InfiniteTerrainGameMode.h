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
	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPoolComponent* NavMeshBoundsVolumePool;

private:
	void AddToPool(ANavMeshBoundsVolume* VolumeToAdd);
};
