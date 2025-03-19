// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterCharacter.generated.h"

UENUM(BlueprintType)
enum class ECharacterMonsterState : uint8
{
	Idle        UMETA(DisplayName = "Idle"),
	Running     UMETA(DisplayName = "Running"),
	Attacking   UMETA(DisplayName = "Attacking")
};

UCLASS()
class DARK_SURVIVAL_API AMonsterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonsterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetState(ECharacterMonsterState ChangeState);

private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Anim, meta = (AllowPrivateAccess = "true"))
	ECharacterMonsterState CharacterState = ECharacterMonsterState::Idle;

};
