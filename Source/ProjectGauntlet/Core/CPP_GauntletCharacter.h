// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponents/CPP_Gauntlet_HealthComponent.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "CPP_GauntletCharacter.generated.h"

UCLASS()
class PROJECTGAUNTLET_API ACPP_GauntletCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_GauntletCharacter();

protected:
	
	UObject* ObjInRange;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void FellOutOfWorld(const class UDamageType& dmgType) override;
	
	void Respawn();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Inventory")
	bool bHasKey;  
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction")
	float InteractionRange;
	
	UCPP_Gauntlet_HealthComponent* HealthComponent;

	UFUNCTION(BlueprintCallable)
	void OnHealthChanged(float CurrentHealth, float MaxHealth);
	
	UFUNCTION(BlueprintCallable)
	void OnDeath();

	void Move(const struct FInputActionValue& Value);
	void Look(const struct FInputActionValue& Value);
	void StartJump(const struct FInputActionValue& Value);
	void StopJump(const struct FInputActionValue& Value);
	bool GetInteractable(UObject*& InteractableObject);
	void Interact(const struct FInputActionValue& Value);
	
};
