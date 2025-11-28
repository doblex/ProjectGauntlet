// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ActorComponents/CPP_GauntletItemKey.h"

#include "Core/CPP_GauntletCharacter.h"
#include "Core/CPP_Gauntlet_FunctionLibrary.h"

// Sets default values for this component's properties
UCPP_GauntletItemKey::UCPP_GauntletItemKey()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPP_GauntletItemKey::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCPP_GauntletItemKey::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCPP_GauntletItemKey::Interact_Implementation()
{
	IInteractable::Interact_Implementation();
	
	ACPP_GauntletCharacter* PC = Cast<ACPP_GauntletCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	
	if (IsValid(PC))
	{
		PC->bHasKey = true;
		
		UStaticMeshComponent* objectMesh = nullptr;
		
		if ( UCPP_Gauntlet_FunctionLibrary::GetStaticMeshByTag(GetOwner(), Meshtag, objectMesh))
		{
			objectMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			objectMesh->SetVisibility(false);
		}
	}
}


