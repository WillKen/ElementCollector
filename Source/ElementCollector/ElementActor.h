// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "MyGameStateBase.h"
#include "MyGameInstance.h"
#include "ElementCollectorCharacter.h"
#include "GameplayTagContainer.h"
#include "ElementActor.generated.h"

UCLASS()
class ELEMENTCOLLECTOR_API AElementActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElementActor();

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
    USphereComponent* Sphere;
        
    UMyGameInstance* myGameInstance;
    AMyGameStateBase* myGameStateBase;
    UPROPERTY(EditAnywhere)
    int32 AnemoValue;
    UPROPERTY(EditAnywhere)
    int32 GeoValue;
    UPROPERTY(EditAnywhere)
    int32 ElectroValue;
    UPROPERTY(EditAnywhere,BlueprintReadWrite)
    bool Died=false;
    float rand;
    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
