// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Gauntlet_BobblingComponent.h"

#include "CPP_Gauntlet_FunctionLibrary.h"

// Sets default values for this component's properties
UCPP_Gauntlet_BobblingComponent::UCPP_Gauntlet_BobblingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPP_Gauntlet_BobblingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	UStaticMeshComponent* StaticMesh = nullptr;
	bool prova = UCPP_Gauntlet_FunctionLibrary::GetStaticMeshByTag(GetOwner(),TagName,StaticMesh);
	if (prova)
	{
		MeshComponent = StaticMesh;
		StartingPos = MeshComponent->GetRelativeLocation();
	}
}


// Called every frame
void UCPP_Gauntlet_BobblingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (MeshComponent == nullptr) return;

	float Z = FMath::Sin( GetWorld()->TimeSeconds * SpeedMultiplier) * PeriodMultiplier;


	FVector NewLocation = StartingPos + FVector(0, 0, Z);

	MeshComponent->SetRelativeLocation(NewLocation);
}

