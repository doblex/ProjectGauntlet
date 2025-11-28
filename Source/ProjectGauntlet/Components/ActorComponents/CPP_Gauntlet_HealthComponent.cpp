// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ActorComponents/CPP_Gauntlet_HealthComponent.h"

#include "Kismet/GameplayStatics.h"


UCPP_Gauntlet_HealthComponent::UCPP_Gauntlet_HealthComponent()
{
}

// Called when the game starts
void UCPP_Gauntlet_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentHealth = MaxHealth;
}

void UCPP_Gauntlet_HealthComponent::DoDamage(float damage)
{
	if (CurrentHealth - damage < 0)
	{
		CurrentHealth = 0;
		OnDeath.Broadcast();
	}
	else
	{
		CurrentHealth -= damage;
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	}
}


