// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveTime.generated.h"

/**
 * 
 */
UCLASS()
class DARK_SURVIVAL_API USaveTime : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BestTime = 0;
	
};
