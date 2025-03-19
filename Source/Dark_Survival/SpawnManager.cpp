// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"
#include "Spawn.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle,this,&ASpawnManager::SpawnRepeatMonster,SpawnDelay,false);
	
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnManager::SpawnRepeatMonster()
{
	int32 randNum = FMath::RandRange(0,Spawns.Num()-1);

	ASpawn* Spawn = Cast<ASpawn>(Spawns[randNum]);

	if (Spawn)
	{
		Spawn->SpawnMonster(Monster);

		SpawnDelay = FMath::Max(SpawnDelay-SpawnDecreaseDelay, MinSpawnDelay);

		GetWorldTimerManager().SetTimer(SpawnTimerHandle,this,&ASpawnManager::SpawnRepeatMonster,SpawnDelay,false);
	}
}


