// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MyGameStateBase.h"
#include "MyGameInstance.h"
#include "MyPlayerController.h"
#include "ElementCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "PortalActor.generated.h"

UCLASS()
class ELEMENTCOLLECTOR_API APortalActor : public AActor
{
    GENERATED_BODY()
    
public:
    // Sets default values for this actor's properties
    APortalActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    UPROPERTY(EditAnywhere)
    USceneComponent* Root;
    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* StaticMesh;
    UPROPERTY(EditAnywhere)
    UBoxComponent* Box;

    UPROPERTY(EditAnywhere)
    FName CurrentLevel;
    UPROPERTY(EditAnywhere)
    FName NextLevel;
    
    UMyGameInstance* myGameInstance;
    AMyGameStateBase* myGameStateBase;
    
    FTimerHandle TimerHandle;
    
    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
    UFUNCTION()
    void upgrade();
};
