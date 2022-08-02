// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MySaveGame.h"
#include "ElementActor.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"
#include "MyPlayerController.generated.h"

/**
 *
 */
UCLASS()
class ELEMENTCOLLECTOR_API AMyPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    AMyPlayerController();
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "UI")
    TSubclassOf<UUserWidget> widget;
    UUserWidget* myWidget;
    void BeginPlay();

    UMySaveGame* mySaveGame;
    UMyGameInstance* myGameInstance;
    
    virtual void SetupInputComponent() override;
    void save();
    void autoSave();
};
