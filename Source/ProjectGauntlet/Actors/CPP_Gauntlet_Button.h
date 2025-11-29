// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "CPP_Gauntlet_Button.generated.h"

class ACPP_Gauntlet_LockedDoor;

UCLASS()
class PROJECTGAUNTLET_API ACPP_Gauntlet_Button : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_Gauntlet_Button();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void CloseDoor();
	
	virtual void Interact_Implementation() override;
	virtual void Selected_Implementation() override;
	virtual void UnSelected_Implementation() override;
	
	UStaticMeshComponent* StaticMeshComponent;
	FTimerHandle TimerHandle;
	ACPP_Gauntlet_LockedDoor* Door;
	
	bool bActivated;
	

public:
	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Button" )
	int DoorId;
	
	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Button" )
	FName Meshtag;
	
	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Button" )
	FStaticMaterial Material;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Locked Door")
	bool bLever;
	
	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "Button" ,meta=(EditCondition="!bLever", EditConditionshow))
	float Duration;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
