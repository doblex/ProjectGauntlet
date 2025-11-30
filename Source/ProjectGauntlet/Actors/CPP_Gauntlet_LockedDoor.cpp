// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CPP_Gauntlet_LockedDoor.h" 
#include "Core/CPP_Gauntlet_FunctionLibrary.h"

// Sets default values for this component's properties
ACPP_Gauntlet_LockedDoor::ACPP_Gauntlet_LockedDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ACPP_Gauntlet_LockedDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	UStaticMeshComponent* comp = nullptr;
	if(UCPP_Gauntlet_FunctionLibrary::GetStaticMeshByTag(this, DoorMeshTag,comp))
	{
		StaticMeshComponent = comp;
	}
}

void ACPP_Gauntlet_LockedDoor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ACPP_Gauntlet_LockedDoor::SubscribeToDoor(ACPP_Gauntlet_Button* button)
{
	RegisteredButtons.Add(button, false);
}

void ACPP_Gauntlet_LockedDoor::UnSubscribeToDoor(ACPP_Gauntlet_Button* button)
{
	for (auto Element : RegisteredButtons)
	{
		if (Element.Key == button)
		{
			RegisteredButtons.Remove(Element.Key);
			return;
		}
	}
}

void ACPP_Gauntlet_LockedDoor::TryOpenDoor(ACPP_Gauntlet_Button* button)
{
	for (auto& Element : RegisteredButtons)
	{
		if (Element.Key == button)
		{
			bool bIsOpen = !Element.Value;
			Element.Value = bIsOpen;
			UE_LOG(LogTemp, Log, TEXT("Door %hhd"), Element.Value);
			break;
		}
	}
	
	CheckForDoorOpening();
}

void ACPP_Gauntlet_LockedDoor::Open()
{
	UE_LOG(LogTemp, Log, TEXT("Door Opened"));
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMeshComponent->SetVisibility(false);
}

void ACPP_Gauntlet_LockedDoor::Close()
{
	UE_LOG(LogTemp, Log, TEXT("Door Closed"));
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndProbe);
	StaticMeshComponent->SetVisibility(true);
}

void ACPP_Gauntlet_LockedDoor::CheckForDoorOpening()
{
	bool bDoorOpening = true;
	
	for (auto Element : RegisteredButtons)
	{
		if (!Element.Value)
		{
			bDoorOpening = false;
		}
	}
	
	bDoorOpening ? Open() : Close();
}





