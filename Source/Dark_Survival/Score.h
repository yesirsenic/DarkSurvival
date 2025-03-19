// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Score.generated.h"

UCLASS()
class DARK_SURVIVAL_API AScore : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScore();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	bool ScoreComparison();

	UFUNCTION(BlueprintCallable)
	FString ScoreCalculate();

private:
	int32 TimeSecond = 0;

	void IncreaseSecond();

	FTimerHandle ScoreTimerHandle;

};
