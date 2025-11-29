// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_Gauntlet_LockedDoor.generated.h"

class ACPP_Gauntlet_Button;

UCLASS()
class PROJECTGAUNTLET_API ACPP_Gauntlet_LockedDoor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ACPP_Gauntlet_LockedDoor();

protected:
	
	UStaticMeshComponent* StaticMeshComponent;
	bool DoorOpen;
	
	// Called when the game starts
	virtual void BeginPlay() override;
public:	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Locked Door")
	FName DoorMeshTag;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Locked Door")
	int DoorID;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Locked Door")
	TMap<ACPP_Gauntlet_Button*, bool> RegisteredButtons;
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
		
	UFUNCTION( BlueprintCallable, Category = "Locked Door" )
	virtual void SubscribeToDoor(ACPP_Gauntlet_Button* button);
	
	UFUNCTION( BlueprintCallable, Category = "Locked Door" )
	virtual void UnSubscribeToDoor(ACPP_Gauntlet_Button* button);
	
	UFUNCTION( BlueprintCallable, Category = "Locked Door" )
	virtual void TryOpenDoor(ACPP_Gauntlet_Button* button);
	void Open();
	void Close();
	void CheckForDoorOpening();
};
