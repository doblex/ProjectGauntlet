// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CPP_Gauntlet_FunctionLibrary.h"

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