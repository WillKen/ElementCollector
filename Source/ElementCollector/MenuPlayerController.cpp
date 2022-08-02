// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"

AMenuPlayerController::AMenuPlayerController()
{
    UE_LOG(LogTemp, Warning, TEXT("AMenuPlayerController()"));
    static ConstructorHelpers::FClassFinder<UUserWidget> Element(TEXT("WidgetBlueprint'/Game/UI/WidgetMenu.WidgetMenu_C'"));
    if (Element.Succeeded()){
        widget = Element.Class;
    }else{
        UE_LOG(LogTemp, Warning, TEXT("Widget Not Found!"));
    }
}

void AMenuPlayerController::BeginPlay()
{
    myWidget = CreateWidget<UUserWidget>(GetWorld(), widget);
    if(myWidget) {
        myWidget->AddToViewport();
    }
    bShowMouseCursor = true;
}
