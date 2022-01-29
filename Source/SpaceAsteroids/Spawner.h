// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Spawner.generated.h"

UCLASS()
class SPACEASTEROIDS_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

  UPROPERTY(EditDefaultsOnly, Category = "Spawning")
      TSubclassOf<AActor> ActorToSpawn;

  int randSpawnTime;

  UPROPERTY(VisibleAnywhere, Category = "Timer")
      float spawnTime = 2;

  FTimerDelegate TimerDel;
  FTimerHandle TimerHandle;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  UFUNCTION()
      void SpawningFunc(FVector Loc, FRotator Rot);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
