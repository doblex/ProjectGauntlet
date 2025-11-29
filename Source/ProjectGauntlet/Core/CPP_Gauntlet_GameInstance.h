// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CPP_Gauntlet_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGAUNTLET_API UCPP_Gauntlet_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> LevelReference;
	
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> MenuReference;
	
	UFUNCTION(BlueprintCallable)
	void GoToMenu();
	
	UFUNCTION(BlueprintCallable)
	void GoToGame();
	
	
};
