// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 *
 */
UCLASS()
class ELEMENTCOLLECTOR_API UMyGameInstance : public UGameInstance
{
    GENERATED_BODY()
public:
    UMyGameInstance();
    
    UPROPERTY(BlueprintReadWrite)
    int32 ElementOverall;
    
    UPROPERTY(BlueprintReadWrite)
    int32 AnemoValueOverall;
    UPROPERTY(BlueprintReadWrite)
    int32 GeoValueOverall;
    UPROPERTY(BlueprintReadWrite)
    int32 ElectroValueOverall;
    
    UPROPERTY(BlueprintReadWrite)
    int32 AnemoValue=0;
    UPROPERTY(BlueprintReadWrite)
    int32 GeoValue=0;
    UPROPERTY(BlueprintReadWrite)
    int32 ElectroValue=0;
    
    UPROPERTY(BlueprintReadOnly)
    int32 AnemoGoal;
    UPROPERTY(BlueprintReadOnly)
    int32 GeoGoal;
    UPROPERTY(BlueprintReadOnly)
    int32 ElectroGoal;
    
    UPROPERTY(BlueprintReadWrite)
    bool loaded=false;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FString> ActorName;
    
    FName CurrentLevel;
};
