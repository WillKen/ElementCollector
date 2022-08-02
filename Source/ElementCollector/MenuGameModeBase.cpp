// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameModeBase.h"

AMenuGameModeBase::AMenuGameModeBase()
{
    UE_LOG(LogTemp, Warning, TEXT("AMenuGameModeBase()"));
    // set default pawn class to our Blueprinted character
    DefaultPawnClass = NULL;
    PlayerControllerClass = AMenuPlayerController::StaticClass();
    GameStateClass = AMyGameStateBase::StaticClass();
}
