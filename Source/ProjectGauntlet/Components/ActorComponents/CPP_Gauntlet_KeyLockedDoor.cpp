// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ActorComponents/CPP_Gauntlet_KeyLockedDoor.h"

#include "Core/CPP_GauntletCharacter.h"
#include "Core/CPP_Gauntlet_FunctionLibrary.h"

// Sets default values for this component's properties
UCPP_Gauntlet_KeyLockedDoor::UCPP_Gauntlet_KeyLockedDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPP_Gauntlet_KeyLockedDoor::BeginPlay()
{
	Super::BeginPlay();
	
	UStaticMeshComponent* staticMesh = nullptr;
	if (UCPP_Gauntlet_FunctionLibrary::GetStaticMeshByTag(GetOwner(),DoorTag, staticMesh))
	{
		DoorMesh = staticMesh;
	}
	
	Shader = ShaderMat;
}


// Called every frame
void UCPP_Gauntlet_KeyLockedDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCPP_Gauntlet_KeyLockedDoor::Interact_Implementation()
{
	ACPP_GauntletCharacter* Pc = Cast<ACPP_GauntletCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	
	if (!IsValid(Pc)) return;
	
	if (Pc->bHasKey && IsValid(DoorMesh))
	{
		DoorMesh->SetVisibility(false);
		DoorMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void UCPP_Gauntlet_KeyLockedDoor::Selected_Implementation()
{
	IInteractable::Selected_Implementation();
	
	if (IsValid(DoorMesh))
	{
		DoorMesh->SetOverlayMaterial(Shader.MaterialInterface);
	}
}

void UCPP_Gauntlet_KeyLockedDoor::UnSelected_Implementation()
{
	IInteractable::UnSelected_Implementation();
	if (IsValid(DoorMesh))
	{
		DoorMesh->SetOverlayMaterial(nullptr);
	}
}



