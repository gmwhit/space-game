// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"

// Sets default values
AAsteroid::AAsteroid()
{
  //Set up root component

  //Set up Static Mesh Component and set as root
  VisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
  SetRootComponent(VisualComponent);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();

  randSpeed = rand() % 8 + 5;

  CurrentVelocity.X = randSpeed * -100;
	
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
  {
      FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
      SetActorLocation(NewLocation);
  }

}

