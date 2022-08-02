// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 *
 */
UCLASS()
class ELEMENTCOLLECTOR_API UMySaveGame : public USaveGame
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly)
    int32 ElementOverall;
    UPROPERTY(BlueprintReadOnly)
    int32 AnemoValueOverall;
    UPROPERTY(BlueprintReadOnly)
    int32 GeoValueOverall;
    UPROPERTY(BlueprintReadOnly)
    int32 ElectroValueOverall;
    UPROPERTY(BlueprintReadOnly)
    int32 AnemoValue;
    UPROPERTY(BlueprintReadOnly)
    int32 GeoValue;
    UPROPERTY(BlueprintReadOnly)
    int32 ElectroValue;
    UPROPERTY(BlueprintReadOnly)
    FName CurrentLevel;
    UPROPERTY(BlueprintReadOnly)
    TArray<FString> ActorName;
    UPROPERTY(VisibleAnywhere, Category = Basic)
    FString SaveSlotName;
    UMySaveGame();
};
