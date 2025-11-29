// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/Interactable.h"
#include "CPP_Gauntlet_ItemKey.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTGAUNTLET_API UCPP_Gauntlet_ItemKey : public UActorComponent, public IInteractable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_Gauntlet_ItemKey();

protected:
	
	UStaticMeshComponent* StaticMeshComponent;
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Item")
	FName Meshtag;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact")
	FStaticMaterial ShaderMat;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Interact_Implementation() override;
	
	virtual void Selected_Implementation() override;
	virtual void UnSelected_Implementation() override;
		
};
