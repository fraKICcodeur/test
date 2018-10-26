// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "testGitGameMode.h"
#include "testGitHUD.h"
#include "testGitCharacter.h"
#include "UObject/ConstructorHelpers.h"

AtestGitGameMode::AtestGitGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AtestGitHUD::StaticClass();
}
