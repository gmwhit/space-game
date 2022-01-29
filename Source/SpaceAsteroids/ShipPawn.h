// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Controller.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"

#include "Blueprint/UserWidget.h"

#include "ShipPawn.generated.h"

UCLASS()
class SPACEASTEROIDS_API AShipPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShipPawn();

  UPROPERTY(EditAnywhere)
      UStaticMeshComponent* VisualComponent;

  UPROPERTY(EditDefaultsOnly, Category = "Personal Changes")
      TSubclassOf<AActor> ActorToSpawn;

  UPROPERTY(EditAnywhere, Category = "Personal Changes")
      FVector SpawnDisplacement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

  void Move_YAxis(float AxisValue);

  FVector CurrentVelocity;

  UPROPERTY(EditAnywhere, Category = "Personal Changes")
      float maxVelocity;

  FActorSpawnParameters SpawnParams;

  UFUNCTION(BlueprintCallable)
      void SpawnBullet();

};
