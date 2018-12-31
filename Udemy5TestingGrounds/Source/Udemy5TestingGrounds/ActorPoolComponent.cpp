// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorPoolComponent.h"

// Sets default values for this component's properties
UActorPoolComponent::UActorPoolComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


AActor* UActorPoolComponent::Checkout()
{
	if (Pool.Num() == 0)
	{
		return nullptr;
	}
	return Pool.Pop();
}

void UActorPoolComponent::Return(AActor* ActorToReturn)
{
	if (ActorToReturn != nullptr)
		Pool.Push(ActorToReturn);
}

void UActorPoolComponent::Add(AActor* ActorToAdd)
{
	if (ActorToAdd != nullptr)
		Pool.Push(ActorToAdd);
}
