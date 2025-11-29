// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ActorComponents/CPP_Gauntlet_ItemKey.h"

#include "Core/CPP_GauntletCharacter.h"
#include "Core/CPP_Gauntlet_FunctionLibrary.h"

// Sets default values for this component's properties
UCPP_Gauntlet_ItemKey::UCPP_Gauntlet_ItemKey()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPP_Gauntlet_ItemKey::BeginPlay()
{
	Super::BeginPlay();

	UStaticMeshComponent* objectMesh = nullptr;
	
	if (UCPP_Gauntlet_FunctionLibrary::GetStaticMeshByTag(GetOwner(), Meshtag, objectMesh))
	{
		StaticMeshComponent = objectMesh;
	}
	
	Shader = ShaderMat;
}


// Called every frame
void UCPP_Gauntlet_ItemKey::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCPP_Gauntlet_ItemKey::Interact_Implementation()
{
	IInteractable::Interact_Implementation();
	
	ACPP_GauntletCharacter* PC = Cast<ACPP_GauntletCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	
	if (IsValid(PC))
	{
		PC->bHasKey = true;
		
		if (IsValid(StaticMeshComponent))
		{
			StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			StaticMeshComponent->SetVisibility(false);
		}
	}
}

void UCPP_Gauntlet_ItemKey::Selected_Implementation()
{
	IInteractable::Selected_Implementation();
	
	if (IsValid(StaticMeshComponent))
	{
		StaticMeshComponent->SetOverlayMaterial(Shader.MaterialInterface);
	}
}

void UCPP_Gauntlet_ItemKey::UnSelected_Implementation()
{
	IInteractable::UnSelected_Implementation();
	if (IsValid(StaticMeshComponent))
	{
		StaticMeshComponent->SetOverlayMaterial(nullptr);
	}
}


