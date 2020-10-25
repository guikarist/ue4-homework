// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUtils.h"

FVector UGameUtils::RestrictTarget(FVector Position)
{
	if (Position.X < -1500)
	{
		Position.X = -1500;
	}
	if (Position.X > 1500)
	{
		Position.X = 1500;
	}
	if (Position.Z < 300)
	{
		Position.Z = 300;
	}
	if (Position.Z > 1500)
	{
		Position.Z = 1500;
	}
	return Position;
}

