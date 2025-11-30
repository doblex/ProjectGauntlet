// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CPP_Gauntlet_EndPoint.h"

#include "Components/SphereComponent.h"
#include "Core/CPP_GauntletCharacter.h"
#include "GameFramework/GameSession.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPP_Gauntlet_EndPoint::ACPP_Gauntlet_EndPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Gauntlet_EndPoint::BeginPlay()
{
	Super::BeginPlay();
	
	SphereCollider = GetComponentByClass<USphereComponent>();
	
	if (!IsValid(SphereCollider)) return;
	
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Gauntlet_EndPoint::OnEndPointOverlap);
}

// Called every frame
void ACPP_Gauntlet_EndPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Gauntlet_EndPoint::OnEndPointOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	ACPP_GauntletCharacter* Character = Cast<ACPP_GauntletCharacter>(OtherActor);
	
	if (IsValid(Character))
	{
		OnEndPointTouched.Broadcast();
	}
}



