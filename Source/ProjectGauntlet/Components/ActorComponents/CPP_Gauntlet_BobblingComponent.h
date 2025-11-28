// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_Gauntlet_BobblingComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTGAUNTLET_API UCPP_Gauntlet_BobblingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCPP_Gauntlet_BobblingComponent();
	
	UMeshComponent* MeshComponent;
	FVector StartingPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bobling Options")
	FName TagName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bobling Options|Animation")
	float SpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bobling Options|Animation")
	float PeriodMultiplier;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
