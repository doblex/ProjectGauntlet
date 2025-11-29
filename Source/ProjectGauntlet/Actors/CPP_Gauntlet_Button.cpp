// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Gauntlet_Button.h"

#include "Core/CPP_Gauntlet_FunctionLibrary.h"
#include "Actors/CPP_Gauntlet_LockedDoor.h"


// Sets default values
ACPP_Gauntlet_Button::ACPP_Gauntlet_Button()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_Gauntlet_Button::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UStaticMeshComponent* comp = nullptr;
	if(UCPP_Gauntlet_FunctionLibrary::GetStaticMeshByTag(this, Meshtag,comp))
	{
		StaticMeshComponent = comp;
	}
	
	Shader = Material;
	
	ACPP_Gauntlet_LockedDoor* DoorToGet = nullptr;
	
	if (UCPP_Gauntlet_FunctionLibrary::GetDoorById(GetWorld(), DoorId, DoorToGet))
	{
		this->Door = DoorToGet;
		Door->SubscribeToDoor(this);
	}
}

void ACPP_Gauntlet_Button::CloseDoor()
{
	UE_LOG(LogTemp, Log, TEXT("Timer Fired"));
	Door->TryOpenDoor(this);
	
	bActivated = false;
	bActivated ? StaticMeshComponent->SetVisibility(false) : StaticMeshComponent->SetVisibility(true);
}


void ACPP_Gauntlet_Button::Interact_Implementation()
{
	IInteractable::Interact_Implementation();
	
	if (bLever)
	{
		bActivated = !bActivated;
		
		Door->TryOpenDoor(this);
	}
	else
	{
		if (!GetWorld()->GetTimerManager().IsTimerActive(TimerHandle))
		{
			bActivated = true;
			Door->TryOpenDoor(this);
		}
	
		GetWorld()->GetTimerManager().SetTimer(
			TimerHandle,
			this,
			&ACPP_Gauntlet_Button::CloseDoor,
			Duration,
			false);
	}
	
	bActivated ? StaticMeshComponent->SetVisibility(false) : StaticMeshComponent->SetVisibility(true);
}

void ACPP_Gauntlet_Button::Selected_Implementation()
{
	IInteractable::Selected_Implementation();
	
	if (IsValid(StaticMeshComponent))
	{
		StaticMeshComponent->SetOverlayMaterial(Shader.MaterialInterface);
	}
}

void ACPP_Gauntlet_Button::UnSelected_Implementation()
{
	IInteractable::UnSelected_Implementation();
	
	if (IsValid(StaticMeshComponent))
	{
		StaticMeshComponent->SetOverlayMaterial(nullptr);
	}
}

void ACPP_Gauntlet_Button::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

