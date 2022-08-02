// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalActor.h"

// Sets default values
APortalActor::APortalActor()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
    SetRootComponent(Root);
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(Root);
    
    Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
    Box->SetupAttachment(Root);
    
    
}

// Called when the game starts or when spawned
void APortalActor::BeginPlay()
{
    Super::BeginPlay();
    Box->OnComponentBeginOverlap.AddDynamic(this, &APortalActor::OnOverlapBegin);
    if (GetGameInstance()){
        myGameInstance = Cast<UMyGameInstance>(GetGameInstance());
        myGameInstance->CurrentLevel=CurrentLevel;
        if(CurrentLevel==TEXT("Level_00")){
            UE_LOG(LogTemp, Warning, TEXT("CurrentLevel:0"));
            myGameInstance->AnemoGoal=2;
            myGameInstance->GeoGoal=2;
            myGameInstance->ElectroGoal=2;
        }else if(CurrentLevel==TEXT("Level_01")){
            UE_LOG(LogTemp, Warning, TEXT("CurrentLevel:1"));
            myGameInstance->AnemoGoal=4;
            myGameInstance->GeoGoal=4;
            myGameInstance->ElectroGoal=4;
        }else if(CurrentLevel==TEXT("Level_02")){
            UE_LOG(LogTemp, Warning, TEXT("CurrentLevel:2"));
            myGameInstance->AnemoGoal=5;
            myGameInstance->GeoGoal=5;
            myGameInstance->ElectroGoal=5;
        }else{
            UE_LOG(LogTemp, Warning, TEXT("CurrentLevel:error"));
            myGameInstance->AnemoGoal=0;
            myGameInstance->GeoGoal=0;
            myGameInstance->ElectroGoal=0;
        }
        
    }
    if (GetWorld()->GetGameState()){
        myGameStateBase = Cast<AMyGameStateBase>(GetWorld()->GetGameState());
    }
}

// Called every frame
void APortalActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(myGameStateBase->LevelClear==true){
        static UMaterialInterface* EnterMaterial=LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Materials/PortalEnterMaterial.PortalEnterMaterial'"));
        StaticMesh->SetMaterial(0,EnterMaterial);
    }
}

void APortalActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    AElementCollectorCharacter* myCharacter=Cast<AElementCollectorCharacter>(OtherActor);
    UE_LOG(LogTemp, Warning, TEXT("APortalActor::overlap"));
    if(myGameStateBase->LevelClear==true){
        UE_LOG(LogTemp, Warning, TEXT("upgrade!"));
        UGameplayStatics::SetGlobalTimeDilation(GetWorld(),0.1f);
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APortalActor::upgrade, 0.1f, true);
//        UGameplayStatics::OpenLevel(GetWorld(), NextLevel);
        myGameInstance->AnemoValue=0;
        myGameInstance->GeoValue=0;
        myGameInstance->ElectroValue=0;
    }
}

void APortalActor::upgrade()
{
    UGameplayStatics::OpenLevel(GetWorld(), NextLevel);
    GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}
