// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CPP_Gauntlet_Hud.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/VerticalBox.h"

void ACPP_Gauntlet_Hud::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsValid(HUDWidgetClass)) return;
	
	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
	
	HudWidget->AddToViewport();
	
	VerticalBox = Cast<UVerticalBox>(HudWidget->GetWidgetFromName(VBoxName));
	
	// UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(GetOwningPlayerController(), VerticalBox);
}

void ACPP_Gauntlet_Hud::PushHud(UWidget* widget)
{
	VerticalBox->AddChildToVerticalBox(widget);
}

void ACPP_Gauntlet_Hud::PopHud(UWidget* widget)
{
	VerticalBox->RemoveChild(widget);
}
