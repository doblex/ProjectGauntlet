// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/CPP_Gauntlet_LockedDoor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPP_Gauntlet_FunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGAUNTLET_API UCPP_Gauntlet_FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public:
	static bool GetStaticMeshByTag(const AActor* Owner, const FName Tag, UStaticMeshComponent*& OutComponent);
	static bool GetDoorById(const UObject* WorldInstance, int Id, ACPP_Gauntlet_LockedDoor*& OutDoor);
};
