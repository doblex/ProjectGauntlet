// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/CPP_Gauntlet_Widget_Hud.h"

#include "Components/Button.h"
#include "Core/CPP_Gauntlet_GameInstance.h"
#include "Kismet/KismetSystemLibrary.h"

void UCPP_Gauntlet_Widget_Hud::OnStartButton()
{
	UCPP_Gauntlet_GameInstance* GI =	Cast<UCPP_Gauntlet_GameInstance>(GetGameInstance());
	
	if (IsValid(GI))
	{
		GI->GoToGame();
	}
	
	
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->SetInputMode(FInputModeGameOnly());
	}
}

void UCPP_Gauntlet_Widget_Hud::OnQuitButton()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),GetOwningPlayer(),EQuitPreference::Quit, true);
}

void UCPP_Gauntlet_Widget_Hud::NativeConstruct()
{
	Super::NativeConstruct();

	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UCPP_Gauntlet_Widget_Hud::OnStartButton);
	}

	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UCPP_Gauntlet_Widget_Hud::OnQuitButton);
	}
	
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->SetInputMode(FInputModeUIOnly());
	}
}
