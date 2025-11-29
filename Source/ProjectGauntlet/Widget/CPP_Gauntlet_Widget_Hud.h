// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CPP_Gauntlet_Widget_Hud.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class PROJECTGAUNTLET_API UCPP_Gauntlet_Widget_Hud : public UCommonUserWidget
{
	GENERATED_BODY()

	
protected:
	
	virtual void NativeConstruct() override;
	
public:
	UPROPERTY(meta = (BindWidget))
	UButton* StartButton;
	
	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;
	
	UFUNCTION()
	void OnStartButton();
	
	UFUNCTION()
	void OnQuitButton();
};
