// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameUtils.generated.h"

/**
 * 
 */
UCLASS()
class NETSHOOT_API UGameUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable, Category = "Utils")
	static FVector RestrictTarget(FVector Position);
};

