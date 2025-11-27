// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Gauntlet/CPP_GauntletPlayerController.h"

#include "CPP_GauntletCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ACPP_GauntletPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!InputMapping) return;
	

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem)
	{
		Subsystem->AddMappingContext(InputMapping, 0);
	}
}
