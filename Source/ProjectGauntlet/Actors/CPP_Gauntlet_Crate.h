// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ProgressBar.h"
#include "Components/ActorComponents/CPP_Gauntlet_HealthComponent.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "CPP_Gauntlet_Crate.generated.h"

UCLASS()
class PROJECTGAUNTLET_API ACPP_Gauntlet_Crate : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACPP_Gauntlet_Crate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UCPP_Gauntlet_HealthComponent* HealthComponent;
	UStaticMeshComponent* StaticMeshComponent;
	UUserWidget* Widget;
	UProgressBar* LifeBar;
	
public:	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact")
	FStaticMaterial ShaderMat;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;
	virtual void Selected_Implementation() override;
	virtual void UnSelected_Implementation() override;
	
	UFUNCTION(BlueprintCallable)
	void OnHealthChanged(float NewHealth, float MaxHealth);
	
	UFUNCTION(BlueprintCallable)
	void OnDeath();
};
