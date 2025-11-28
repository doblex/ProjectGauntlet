// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ActorComponents/CPP_GauntletLockedDoor.h"

#include "Core/CPP_GauntletCharacter.h"
#include "Core/CPP_Gauntlet_FunctionLibrary.h"

// Sets default values for this component's properties
UCPP_GauntletLockedDoor::UCPP_GauntletLockedDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPP_GauntletLockedDoor::BeginPlay()
{
	Super::BeginPlay();
	
	UStaticMeshComponent* staticMesh = nullptr;
	if (UCPP_Gauntlet_FunctionLibrary::GetStaticMeshByTag(GetOwner(),DoorTag, staticMesh))
	{
		DoorMesh = staticMesh;
	}
}


// Called every frame
void UCPP_GauntletLockedDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCPP_GauntletLockedDoor::Interact_Implementation()
{
	ACPP_GauntletCharacter* Pc = Cast<ACPP_GauntletCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	
	if (!IsValid(Pc)) return;
	
	if (Pc->bHasKey && IsValid(DoorMesh))
	{
		DoorMesh->SetVisibility(false);
		DoorMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}



