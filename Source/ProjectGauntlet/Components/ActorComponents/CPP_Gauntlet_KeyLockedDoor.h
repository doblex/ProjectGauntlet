// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/Interactable.h"
#include "CPP_Gauntlet_KeyLockedDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTGAUNTLET_API UCPP_Gauntlet_KeyLockedDoor : public UActorComponent , public IInteractable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_Gauntlet_KeyLockedDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact")
	FName DoorTag;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Interact")
	FStaticMaterial ShaderMat;
	
	TObjectPtr<UStaticMeshComponent> DoorMesh;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void Interact_Implementation() override;
	void Selected_Implementation();
	void UnSelected_Implementation();
};
