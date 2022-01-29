// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

  FVector Location = GetActorLocation();
  FRotator Rotation = GetActorRotation();

  SpawningFunc(Location, Rotation);

  TimerDel.BindUFunction(this, FName("SpawningFunc"), Location, Rotation);

  GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, spawnTime, true);
	
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner::SpawningFunc(FVector Loc, FRotator Rot)
{
    FActorSpawnParameters SpawnParams;
    AActor* ActorRef = GetWorld()->SpawnActor<AActor>(ActorToSpawn, Loc, Rot, SpawnParams);
    randSpawnTime = rand() % 6 + 2;
    spawnTime = static_cast<float>(randSpawnTime);
    return;
}

