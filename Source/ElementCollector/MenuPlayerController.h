// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MenuPlayerController.generated.h"

/**
 *
 */
UCLASS()
class ELEMENTCOLLECTOR_API AMenuPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    AMenuPlayerController();
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "UI")
    TSubclassOf<UUserWidget> widget;
    UUserWidget* myWidget;
    void BeginPlay();
};
