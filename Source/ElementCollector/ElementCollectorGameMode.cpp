// Copyright Epic Games, Inc. All Rights Reserved.

#include "ElementCollectorGameMode.h"
#include "ElementCollectorCharacter.h"
#include "UObject/ConstructorHelpers.h"

AElementCollectorGameMode::AElementCollectorGameMode()
{
    UE_LOG(LogTemp, Warning, TEXT("AElementCollectorGameMode()"));
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
    PlayerControllerClass = AMyPlayerController::StaticClass();
    GameStateClass = AMyGameStateBase::StaticClass();
}
