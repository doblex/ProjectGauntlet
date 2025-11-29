// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CPP_Gauntlet_GameInstance.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UCPP_Gauntlet_GameInstance::GoToMenu()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr( GetWorld(),MenuReference);
}

void UCPP_Gauntlet_GameInstance::GoToGame()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr( GetWorld(),LevelReference);
}
