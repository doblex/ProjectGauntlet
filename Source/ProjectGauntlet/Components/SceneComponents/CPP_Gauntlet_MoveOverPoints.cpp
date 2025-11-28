// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Gauntlet_MoveOverPoints.h"

#include "Core/CPP_Gauntlet_FunctionLibrary.h"

// Sets default values for this component's properties
UCPP_Gauntlet_MoveOverPoints::UCPP_Gauntlet_MoveOverPoints()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPP_Gauntlet_MoveOverPoints::BeginPlay()
{
	Super::BeginPlay();

	UStaticMeshComponent* StaticMeshComponent = nullptr;
	if ( UCPP_Gauntlet_FunctionLibrary::GetStaticMeshByTag(GetOwner(),ObjectTag,StaticMeshComponent))
	{
		ObjectToMove = StaticMeshComponent;
		
		if (PointsToReach.Num() >0)
		{
			CurrentIndex = StartingIndex;
			NextIndex = GetNextIndex(CurrentIndex);
			ObjectToMove->SetRelativeLocation(PointsToReach[StartingIndex].GetLocation());
		}
	}
	
	
}


// Called every frame
void UCPP_Gauntlet_MoveOverPoints::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsValid(ObjectToMove)) return;

	FVector Debugpoint1 = GetOwner()->GetActorLocation() + PointsToReach[CurrentIndex].GetLocation();
	FVector Debugpoint2 = GetOwner()->GetActorLocation() + PointsToReach[NextIndex].GetLocation();
	
	DrawDebugSphere(GetWorld(),Debugpoint1 ,10,10,FColor::Yellow );
	DrawDebugSphere(GetWorld(),Debugpoint2 ,10,10,FColor::Green );
	
	FVector newpos =
		FMath::Lerp(
		 PointsToReach[CurrentIndex].GetLocation(),
		 PointsToReach[NextIndex].GetLocation(),
		MovementAlpha);

	
	
	ObjectToMove->SetRelativeLocation(newpos);
	MovementAlpha += DeltaTime / TimeToMove;

	if (MovementAlpha > 1.f)
	{
		MovementAlpha = 0.f;
		CurrentIndex = GetNextIndex(CurrentIndex);
		NextIndex = GetNextIndex(CurrentIndex);
	}
}

int UCPP_Gauntlet_MoveOverPoints::GetNextIndex(int CurrentIdx)
{
	return (CurrentIdx + 1) % PointsToReach.Num();
}

