// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"

AMyGameStateBase::AMyGameStateBase(){
    UE_LOG(LogTemp, Warning, TEXT("AMyGameStateBase()"));
//    myCharacter = Cast<AElementCollectorCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}
void AMyGameStateBase::UpgradeTest()
{
    
    myCharacter = Cast<AElementCollectorCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    myGameInstance = Cast<UMyGameInstance>(GetGameInstance());
    if((myCharacter->AnemoValue>=myGameInstance->AnemoGoal)&&(myCharacter->GeoValue>=myGameInstance->GeoGoal)&&(myCharacter->ElectroValue>=myGameInstance->ElectroGoal)){
        LevelClear=true;
    }else{
        LevelClear=false;
    }
}
