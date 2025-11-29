// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CPP_Gauntlet_FunctionLibrary.h"

#include "Actors/CPP_Gauntlet_LockedDoor.h"
#include "Kismet/GameplayStatics.h"

bool UCPP_Gauntlet_FunctionLibrary::GetStaticMeshByTag(const AActor* Owner ,const FName Tag, UStaticMeshComponent*& OutComponent)
{
	TArray<UStaticMeshComponent*> MeshComponents;
	OutComponent = nullptr;
	
	Owner->GetComponents<UStaticMeshComponent>(MeshComponents);

	if (MeshComponents.Num() > 0)
	{
		if (MeshComponents.Num() == 1 || Tag == "")
		{
			OutComponent = MeshComponents[0];
			return true;
		}
		else
		{
			for (auto CurrentMeshComponent : MeshComponents)
			{
				if (CurrentMeshComponent != nullptr)
				{
					if (CurrentMeshComponent->ComponentHasTag(Tag))
					{
						OutComponent = CurrentMeshComponent;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool UCPP_Gauntlet_FunctionLibrary::GetDoorById(const UObject* WorldInstance ,const int Id, ACPP_Gauntlet_LockedDoor*& OutDoor)
{
	OutDoor = nullptr;
	
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(WorldInstance, ACPP_Gauntlet_LockedDoor::StaticClass(), Actors);
	
	if (!Actors.IsEmpty())
	{
		ACPP_Gauntlet_LockedDoor* CurrentDoor = nullptr;
		
		for (auto* Actor : Actors)
		{
			CurrentDoor = Cast<ACPP_Gauntlet_LockedDoor>(Actor);
			
			if (CurrentDoor != nullptr)
			{
				if (CurrentDoor->DoorID == Id)
				{
					OutDoor = CurrentDoor;
					return true;
				}
			}
		}
	}
	
	return false;
}