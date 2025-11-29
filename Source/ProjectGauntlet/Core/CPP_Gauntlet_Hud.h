// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "CPP_Gauntlet_Hud.generated.h"

class UVerticalBox;
/**
 * 
 */
UCLASS()
class PROJECTGAUNTLET_API ACPP_Gauntlet_Hud : public AHUD
{
	GENERATED_BODY()
	
protected:
	UUserWidget* HudWidget;
	
	UVerticalBox* VerticalBox;
	
	virtual void BeginPlay() override; 
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HUD")
	TSubclassOf<UUserWidget> HUDWidgetClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HUD")
	FName VBoxName;
	
	UFUNCTION(BlueprintCallable, Category = "HUD")
	void PushHud(UWidget* widget);
	
	UFUNCTION(BlueprintCallable, Category = "HUD")
	void PopHud(UWidget* widget);
	
	
};
