// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CPP_Gauntlet_Crate.h"

#include "Components/WidgetComponent.h"

// Sets default values
ACPP_Gauntlet_Crate::ACPP_Gauntlet_Crate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void ACPP_Gauntlet_Crate::BeginPlay()
{
	Super::BeginPlay();
	
	HealthComponent = GetComponentByClass<UCPP_Gauntlet_HealthComponent>();
	
	HealthComponent->OnHealthChanged.AddDynamic(this, &ACPP_Gauntlet_Crate::OnHealthChanged);
	HealthComponent->OnDeath.AddDynamic(this, &ACPP_Gauntlet_Crate::OnDeath);
	
	Shader = ShaderMat;
	
	StaticMeshComponent = GetComponentByClass<UStaticMeshComponent>();
	
	
	Widget = GetComponentByClass<UWidgetComponent>()->GetUserWidgetObject();
	
	LifeBar = Cast<UProgressBar>(Widget->GetWidgetFromName("LifeBar"));
	
	if (LifeBar && HealthComponent)
	{
		LifeBar->SetPercent(HealthComponent->GetLifePercent());
	}
}

// Called every frame
void ACPP_Gauntlet_Crate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_Gauntlet_Crate::Interact_Implementation()
{
	IInteractable::Interact_Implementation();
	
	HealthComponent->DoDamage(5);
}

void ACPP_Gauntlet_Crate::Selected_Implementation()
{
	IInteractable::Selected_Implementation();
	
	if (IsValid(StaticMeshComponent))
	{
		StaticMeshComponent->SetOverlayMaterial(Shader.MaterialInterface);
	}
}

void ACPP_Gauntlet_Crate::UnSelected_Implementation()
{
	IInteractable::UnSelected_Implementation();
	
	if (IsValid(StaticMeshComponent))
	{
		StaticMeshComponent->SetOverlayMaterial(nullptr);
	}
}

void ACPP_Gauntlet_Crate::OnHealthChanged(float NewHealth, float MaxHealth)
{
	if (LifeBar)
	{
		LifeBar->SetPercent(HealthComponent->GetLifePercent());
	}
}

void ACPP_Gauntlet_Crate::OnDeath()
{
	UStaticMeshComponent* Mesh = GetComponentByClass<UStaticMeshComponent>();
	
	if (LifeBar)
	{
		LifeBar->SetPercent(HealthComponent->GetLifePercent());
		Widget->SetVisibility(ESlateVisibility::Hidden);
	}
	
	if (IsValid(Mesh))
	{
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Mesh->SetVisibility(false);
	}
}

