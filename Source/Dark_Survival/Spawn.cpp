// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawn.h"
#include "GameFramework/Character.h"

// Sets default values
ASpawn::ASpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawn::SpawnMonster(TSubclassOf<ACharacter> Monster)
{
	if (Monster)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		FVector SpawnLocation = GetActorLocation();
		FRotator SpawnRotation = GetActorRotation();
		
		ACharacter* SpawnedMonster = GetWorld()->SpawnActor<ACharacter>(Monster, SpawnLocation, SpawnRotation, SpawnParams);
		SpawnedMonster->SpawnDefaultController();
		if (SpawnedMonster)
		{
			UE_LOG(LogTemp, Warning, TEXT("Monster spawned successfully!"));
		}
	}
}


