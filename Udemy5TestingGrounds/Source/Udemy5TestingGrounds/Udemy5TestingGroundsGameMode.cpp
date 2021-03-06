// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Udemy5TestingGroundsGameMode.h"
#include "Udemy5TestingGroundsHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUdemy5TestingGroundsGameMode::AUdemy5TestingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Character/Behavior/BP_Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUdemy5TestingGroundsHUD::StaticClass();
}
