// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/ActorComponent.h"
#include "CPP_GauntletLockedDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTGAUNTLET_API UCPP_GauntletLockedDoor : public UActorComponent , public IInteractable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_GauntletLockedDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact")
	FName DoorName;
	
	TObjectPtr<UStaticMeshComponent> DoorMesh;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void Interact_Implementation() override;
};
