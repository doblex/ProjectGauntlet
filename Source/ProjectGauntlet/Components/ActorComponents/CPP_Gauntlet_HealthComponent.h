// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_Gauntlet_HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, NewHealth, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTGAUNTLET_API UCPP_Gauntlet_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_Gauntlet_HealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Health Component")
	float CurrentHealth;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health Component")
	float MaxHealth;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health Component")
	FOnHealthChanged OnHealthChanged;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health Component")
	FOnDeath OnDeath;
	
	void DoDamage(float damage);
	float GetLifePercent();
};
