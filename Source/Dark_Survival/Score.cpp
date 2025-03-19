// Fill out your copyright notice in the Description page of Project Settings.


#include "Score.h"
#include "SaveTime.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AScore::AScore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScore::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(ScoreTimerHandle, this, &AScore::IncreaseSecond,1, true);
	
}

// Called every frame
void AScore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScore::IncreaseSecond()
{
	TimeSecond++;
}

bool AScore::ScoreComparison()
{
	if (GetWorldTimerManager().IsTimerActive(ScoreTimerHandle))
	{
		GetWorldTimerManager().ClearTimer(ScoreTimerHandle);
	}

	
	auto USaveGame = Cast<USaveTime>(UGameplayStatics::LoadGameFromSlot("BestTime",0));

	if (nullptr == USaveGame)
	{
		USaveGame = Cast<USaveTime>(UGameplayStatics::CreateSaveGameObject(USaveTime::StaticClass()));

		if (USaveGame)
		{
			USaveGame->BestTime = TimeSecond;
			UGameplayStatics::SaveGameToSlot(USaveGame,"BestTime",0);

			return true;
			
		}
	}

	if (TimeSecond > USaveGame->BestTime)
	{
		USaveGame->BestTime = TimeSecond;
		UGameplayStatics::SaveGameToSlot(USaveGame,"BestTime",0);

		return true;
	}

	return false;
}

FString AScore::ScoreCalculate()
{
	int32 Minutes = TimeSecond / 60;
	int32 Seconds = TimeSecond % 60;

	return FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
}




