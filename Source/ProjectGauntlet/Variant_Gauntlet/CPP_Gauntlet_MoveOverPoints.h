// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_Gauntlet_MoveOverPoints.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTGAUNTLET_API UCPP_Gauntlet_MoveOverPoints : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_Gauntlet_MoveOverPoints();
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category = "MovingOverPointsComponent", meta = (MakeEditWidget = true))
	TArray<FTransform>	PointsToReach;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category = "MovingOverPointsComponent")
	float TimeToMove = 1.f;

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category = "MovingOverPointsComponent")
	int StartingIndex = 0;
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category = "MovingOverPointsComponent")
	FName ObjectTag;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UStaticMeshComponent* ObjectToMove;
	int CurrentIndex = 0;
	int NextIndex = 0;

	float MovementAlpha = 0.f;
	int GetNextIndex(int CurrentIndex);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
