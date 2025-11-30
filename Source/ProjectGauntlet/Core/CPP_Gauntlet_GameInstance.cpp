// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CPP_Gauntlet_GameInstance.h"

#include "Actors/CPP_Gauntlet_EndPoint.h"
#include "Kismet/GameplayStatics.h"

void UCPP_Gauntlet_GameInstance::FindObjectAndBindDelegate(UWorld* World)
{
	if (!IsValid(World)) return;
	
	ACPP_Gauntlet_EndPoint* endpoint = 
		Cast<ACPP_Gauntlet_EndPoint>(UGameplayStatics::GetActorOfClass( World, ACPP_Gauntlet_EndPoint::StaticClass()));
	
	if (!IsValid(endpoint)) return;
	
	endpoint->OnEndPointTouched.AddDynamic(this, &UCPP_Gauntlet_GameInstance::GoToMenu);
	
	CurrentEndpoint = endpoint;
}

void UCPP_Gauntlet_GameInstance::LoadComplete(const float LoadTime, const FString& MapName)
{
	Super::LoadComplete(LoadTime, MapName);

	UWorld* World = GetWorld();
	
	if (!World)
		return;

	// Name of the level you want to react to

	// Check if the level is this one
	if (World->GetMapName().Contains("Level"))
	{
		FindObjectAndBindDelegate(World);
	}
}

void UCPP_Gauntlet_GameInstance::GoToMenu()
{
	CurrentEndpoint->OnEndPointTouched.RemoveDynamic(this, &UCPP_Gauntlet_GameInstance::GoToMenu);
	UGameplayStatics::OpenLevelBySoftObjectPtr( GetWorld(),MenuReference);
}

void UCPP_Gauntlet_GameInstance::GoToGame()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr( GetWorld(),LevelReference);
}


