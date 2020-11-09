// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class NETSHOOT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float ClientPitch;

	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	bool bTouchMoving = false;
	ETouchIndex::Type TouchingIndex{};
	FVector LastTouchEventPosition{};

	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Position);
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Position);
	void TouchMoved(ETouchIndex::Type FingerIndex, FVector Position);

	void Turn(float Value);
	void LookUp(float Value);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
};

