// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CPP_GauntletCharacter.h"

#include "EnhancedInputComponent.h"
#include "Interfaces/Interactable.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPP_GauntletCharacter::ACPP_GauntletCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_GauntletCharacter::BeginPlay()
{
	Super::BeginPlay();
	bHasKey = false;
	
	HealthComponent = GetComponentByClass<UCPP_Gauntlet_HealthComponent>();
	
	HealthComponent->OnHealthChanged.AddDynamic(this, &ACPP_GauntletCharacter::OnHealthChanged);
	HealthComponent->OnDeath.AddDynamic(this, &ACPP_GauntletCharacter::OnDeath);
}

void ACPP_GauntletCharacter::FellOutOfWorld(const class UDamageType& dmgType)
{
	Respawn();
}

void ACPP_GauntletCharacter::OnHealthChanged(float CurrentHealth, float MaxHealth)
{
	//TODO UI
}

void ACPP_GauntletCharacter::Respawn()
{
	AGameModeBase* GM = GetWorld()->GetAuthGameMode();
	if (!IsValid(GM)) return;
	
	AActor* Start = GM->ChoosePlayerStart(GetController());
		
	if (!IsValid(Start)) return;
	
	SetActorLocation(Start->GetActorLocation());
}

void ACPP_GauntletCharacter::OnDeath()
{
	Respawn();
}

void ACPP_GauntletCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	if (!EnhancedInput) return;
	
	if (MoveAction)
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPP_GauntletCharacter::Move);
	}
	
	if (LookAction)
	{
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPP_GauntletCharacter::Look);
	}
	
	if (JumpAction)
	{
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ACPP_GauntletCharacter::StartJump);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACPP_GauntletCharacter::StopJump);
	}
	
	if (InteractAction)
	{
		EnhancedInput->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ACPP_GauntletCharacter::Interact);
	}
}

// Called every frame
void ACPP_GauntletCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_GauntletCharacter::Move(const struct FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();
	
	AddMovementInput(GetActorForwardVector(), Input.Y);
	AddMovementInput(GetActorRightVector(), Input.X);
}

void ACPP_GauntletCharacter::Look(const struct FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();	
	
	AddControllerYawInput(Input.Y);
	AddControllerPitchInput(Input.X);
}

void ACPP_GauntletCharacter::StartJump(const struct FInputActionValue& Value)
{
	Jump();
}

void ACPP_GauntletCharacter::StopJump(const struct FInputActionValue& Value)
{
	StopJumping();
}

void ACPP_GauntletCharacter::Interact(const struct FInputActionValue& Value)
{
	ETraceTypeQuery TraceType{};
	TArray<AActor*> ActorsToIgnore;
	
	FHitResult Hit;
	
	bool bIsOverlaping = 
		UKismetSystemLibrary::SphereTraceSingle
		(
			GetWorld(),
			GetActorLocation(),
			GetActorLocation(),
			InteractionRange,
			TraceType,
			false,
			ActorsToIgnore,
			EDrawDebugTrace::ForDuration,
			Hit,
			true
			);
	
	AActor* OverlappedActor = Hit.GetActor();
	
	if (bIsOverlaping && IsValid(OverlappedActor))
	{
		UE_LOG(LogTemp, Log, TEXT("Overlapping"));
		
		if (IsValid(OverlappedActor))
		{
			TArray<UActorComponent*> InteractableComponent = OverlappedActor->GetComponentsByInterface(UInteractable::StaticClass());
			if (InteractableComponent.IsEmpty()) return;
			
			UActorComponent* Comp = InteractableComponent[0];

			if (Comp && Comp->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
			{
				IInteractable::Execute_Interact(Comp);
			}
		}
	}
}

