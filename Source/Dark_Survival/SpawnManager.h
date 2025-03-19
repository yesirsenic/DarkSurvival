// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnManager.generated.h"

class ASpawn;

UCLASS()
class DARK_SURVIVAL_API ASpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category= "Spawn", meta = (AllowPrivateAccess = "true"))
	float SpawnDelay = 4.f;

	UPROPERTY(EditAnywhere, Category= "Spawn", meta = (AllowPrivateAccess = "true"))
	float MinSpawnDelay = 1.5f;

	UPROPERTY(EditAnywhere, Category= "Spawn", meta = (AllowPrivateAccess = "true"))
	float SpawnDecreaseDelay = 0.05f;

	UPROPERTY(EditAnywhere, Category= "Spawn", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ACharacter> Monster;

	UPROPERTY(EditAnywhere, Category= "Spawn", meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> Spawns;

	void SpawnRepeatMonster();

	FTimerHandle SpawnTimerHandle;

};
