// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementActor.h"

// Sets default values
AElementActor::AElementActor()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
    SetRootComponent(Root);
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(Root);
    
    Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
    Sphere->SetupAttachment(Root);
    UE_LOG(LogTemp, Warning, TEXT("AElementActor::AElementActor(),Died:%d"),Died);
}

// Called when the game starts or when spawned
void AElementActor::BeginPlay()
{
    Super::BeginPlay();
    Sphere->OnComponentBeginOverlap.AddDynamic(this, &AElementActor::OnOverlapBegin);
    if (GetGameInstance()){
        myGameInstance = Cast<UMyGameInstance>(GetGameInstance());
    }
    if (GetWorld()->GetGameState()){
        myGameStateBase = Cast<AMyGameStateBase>(GetWorld()->GetGameState());
    }
    rand = FMath::FRandRange(0.0f,2.0f);
    UE_LOG(LogTemp, Warning, TEXT("AElementActor::rand:%f"),rand);
}

// Called every frame
void AElementActor::Tick(float DeltaTime)
{
    if(Died){
        Destroy();
    }
    Super::Tick(DeltaTime);
    FVector NewLocation = GetActorLocation();
    FRotator NewRotation = GetActorRotation();
    float RunningTime = GetGameTimeSinceCreation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    NewLocation.Z += DeltaHeight * 20.0f * rand;       //Scale our height by a factor of 20
    float DeltaRotation = DeltaTime * 20.0f * rand;    //Rotate by 20 degrees per second
    NewRotation.Yaw += DeltaRotation;
    SetActorLocationAndRotation(NewLocation, NewRotation);
    if(Died){
        Destroy();
    }
}

void AElementActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("AElementActor::overlap"));
    AElementCollectorCharacter* myCharacter=Cast<AElementCollectorCharacter>(OtherActor);
    myGameInstance->AnemoValueOverall+=AnemoValue;
    myGameInstance->GeoValueOverall+=GeoValue;
    myGameInstance->ElectroValueOverall+=ElectroValue;
    myGameInstance->ElementOverall+=(AnemoValue+GeoValue+ElectroValue);
    myGameInstance->AnemoValue+=AnemoValue;
    myGameInstance->GeoValue+=GeoValue;
    myGameInstance->ElectroValue+=ElectroValue;
    myCharacter->AnemoValue=myGameInstance->AnemoValue;
    myCharacter->GeoValue=myGameInstance->GeoValue;
    myCharacter->ElectroValue=myGameInstance->ElectroValue;
    myGameStateBase->UpgradeTest();
    UE_LOG(LogTemp, Warning, TEXT("myGameStateBase->LevelClear after: %d"),myGameStateBase->LevelClear);
    Died=true;
    Destroy();
}
