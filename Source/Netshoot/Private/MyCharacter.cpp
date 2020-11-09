// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::Turn);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMyCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMyCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AMyCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AMyCharacter::TouchStopped);
	PlayerInputComponent->BindTouch(IE_Repeat, this, &AMyCharacter::TouchMoved);
}

void AMyCharacter::TouchMoved(ETouchIndex::Type FingerIndex, FVector Position)
{
	if (!bTouchMoving || FingerIndex != TouchingIndex)
	{
		return;
	}

	FVector Movement = Position - LastTouchEventPosition;

	LookUp(Movement.Y * 0.1);
	Turn(Movement.X * 0.1);

	LastTouchEventPosition = Position;
}

void AMyCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Position)
{
	if (bTouchMoving)
	{
		return;
	}

	TouchingIndex = FingerIndex;
	LastTouchEventPosition = Position;
	bTouchMoving = true;
}

void AMyCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Position)
{
	if (bTouchMoving && FingerIndex == TouchingIndex)
	{
		bTouchMoving = false;
	}
}

void AMyCharacter::TurnAtRate(float Rate)
{
	Turn(45 * Rate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::LookUpAtRate(float Rate)
{
	LookUp(45 * Rate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AMyCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
	ClientPitch += Value * Cast<APlayerController>(Controller)->InputPitchScale;
	if (ClientPitch > 90)
	{
		ClientPitch = 90;
	}
	if (ClientPitch < -90)
	{
		ClientPitch = -90;
	}
}

