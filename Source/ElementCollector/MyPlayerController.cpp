// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
    UE_LOG(LogTemp, Warning, TEXT("AMyPlayerController()"));
    static ConstructorHelpers::FClassFinder<UUserWidget> Element(TEXT("WidgetBlueprint'/Game/UI/WidgetInfo.WidgetInfo_C'"));
    if (Element.Succeeded()){
        widget = Element.Class;
    }else{
        UE_LOG(LogTemp, Warning, TEXT("Widget Not Found!"));
    }
    InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("inputs"));
}

void AMyPlayerController::BeginPlay(){
    myWidget = CreateWidget<UUserWidget>(GetWorld(), widget);
    if(myWidget) {
        myWidget->AddToViewport();
    }
    
    mySaveGame=Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
    if (GetGameInstance()){
        myGameInstance = Cast<UMyGameInstance>(GetGameInstance());
    }
    if(myGameInstance->loaded==true){
        UE_LOG(LogTemp, Warning, TEXT("GameLoaded"));
        TArray<AActor*> ElementActors;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(),AElementActor::StaticClass(),ElementActors);
        for(AActor* eleActor:ElementActors){
            AElementActor* eleA=Cast<AElementActor>(eleActor);
            eleA->Died=true;
        }
        for(FString name:myGameInstance->ActorName){
            for(AActor* eleActor:ElementActors){
                AElementActor* eleA=Cast<AElementActor>(eleActor);
                if(eleA->GetName()==name){
                    eleA->Died=false;
                }
            }
        }
        myGameInstance->loaded=false;
    }

}


void AMyPlayerController::SetupInputComponent()
{
    InputComponent->BindAction("Q", IE_Pressed, this, &AMyPlayerController::save);
}

void AMyPlayerController::save()
{
    UE_LOG(LogTemp, Warning, TEXT("Q_Pressed!"));
    mySaveGame->ElementOverall=myGameInstance->ElementOverall;
    mySaveGame->AnemoValueOverall=myGameInstance->AnemoValueOverall;
    mySaveGame->GeoValueOverall=myGameInstance->GeoValueOverall;
    mySaveGame->ElectroValueOverall=myGameInstance->ElectroValueOverall;
    mySaveGame->AnemoValue=myGameInstance->AnemoValue;
    mySaveGame->GeoValue=myGameInstance->GeoValue;
    mySaveGame->ElectroValue=myGameInstance->ElectroValue;
    mySaveGame->CurrentLevel=myGameInstance->CurrentLevel;
    TArray<AActor*> ElementActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),AElementActor::StaticClass(),ElementActors);
    for(AActor* eleActor:ElementActors){
        AElementActor* eleA=Cast<AElementActor>(eleActor);
        UE_LOG(LogTemp, Warning, TEXT("Survive:%s"),*eleA->GetName());
        mySaveGame->ActorName.Add(eleA->GetName());
    }
    bool flag=UGameplayStatics::SaveGameToSlot(mySaveGame, TEXT("willken"), 0);
    if(flag){
        UE_LOG(LogTemp, Warning, TEXT("Game_Saved!"));
//        ConsoleCommand("quit");
        UGameplayStatics::OpenLevel(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(), FName("Level_Menu"));
    }
}

void AMyPlayerController::autoSave()
{
    UE_LOG(LogTemp, Warning, TEXT("AutoSave!"));
    mySaveGame->ElementOverall=myGameInstance->ElementOverall;
    mySaveGame->AnemoValueOverall=myGameInstance->AnemoValueOverall;
    mySaveGame->GeoValueOverall=myGameInstance->GeoValueOverall;
    mySaveGame->ElectroValueOverall=myGameInstance->ElectroValueOverall;
    mySaveGame->AnemoValue=myGameInstance->AnemoValue;
    mySaveGame->GeoValue=myGameInstance->GeoValue;
    mySaveGame->ElectroValue=myGameInstance->ElectroValue;
    mySaveGame->CurrentLevel=myGameInstance->CurrentLevel;
    TArray<AActor*> ElementActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),AElementActor::StaticClass(),ElementActors);
    for(AActor* eleActor:ElementActors){
        AElementActor* eleA=Cast<AElementActor>(eleActor);
        UE_LOG(LogTemp, Warning, TEXT("Survive:%s"),*eleA->GetName());
        mySaveGame->ActorName.Add(eleA->GetName());
    }
    bool flag=UGameplayStatics::SaveGameToSlot(mySaveGame, TEXT("willken"), 0);
    if(flag){
        UE_LOG(LogTemp, Warning, TEXT("Game_Saved!"));
    }
}
