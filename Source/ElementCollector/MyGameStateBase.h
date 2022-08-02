// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ElementCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameStateBase.generated.h"

/**
 *
 */
UCLASS()
class ELEMENTCOLLECTOR_API AMyGameStateBase : public AGameStateBase
{
    GENERATED_BODY()
    
private:
    AElementCollectorCharacter* myCharacter;
public:
    AMyGameStateBase();
    void UpgradeTest();
    bool LevelClear=false;
    UMyGameInstance* myGameInstance;
};
