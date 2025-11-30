// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CPP_Gauntlet_GameInstance.generated.h"

class ACPP_Gauntlet_EndPoint;

/**
 * 
 */
UCLASS()
class PROJECTGAUNTLET_API UCPP_Gauntlet_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	
	ACPP_Gauntlet_EndPoint* CurrentEndpoint;
	
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> LevelReference;
	
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> MenuReference;

	virtual void LoadComplete(const float LoadTime, const FString& MapName) override;
	void FindObjectAndBindDelegate(UWorld* World);

	UFUNCTION(BlueprintCallable)
	void GoToMenu();
	
	UFUNCTION(BlueprintCallable)
	void GoToGame();
};
