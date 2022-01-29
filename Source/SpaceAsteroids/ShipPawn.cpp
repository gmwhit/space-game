// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipPawn.h"

// Sets default values
AShipPawn::AShipPawn()
{
	//Set up visual component with root component
  VisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualComponent"));
  SetRootComponent(VisualComponent);


  //Pawn Possession

  AutoPossessPlayer = EAutoReceiveInput::Player0;
  
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AShipPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AShipPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
  {
      if (!CurrentVelocity.IsZero())
      {
          FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
          SetActorLocation(NewLocation);
      }
  }

}

// Called to bind functionality to input
void AShipPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

  InputComponent->BindAxis("MoveY", this, &AShipPawn::Move_YAxis);
}

void AShipPawn::Move_YAxis(float AxisValue)
{
    CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * maxVelocity;
}

void AShipPawn::SpawnBullet()
{
    FActorSpawnParameters ShipSpawnParams;
    FVector Loc = GetActorLocation() + SpawnDisplacement;
    FRotator Rot = GetActorRotation();
    AActor* ActorRef = GetWorld()->SpawnActor<AActor>(ActorToSpawn, Loc, Rot, ShipSpawnParams);
}

