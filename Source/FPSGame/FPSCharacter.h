// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShootProjectile.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class FPSGAME_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	/**** Shooting ****/
	// Projectile class to spawn.
    UPROPERTY(EditAnywhere, Category = "Shoot Projectile")
    TSubclassOf<class AShootProjectile> ProjectileClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	/**** Shooting ****/
	
	UFUNCTION()
	void Fire();

	// Gun muzzle offset from the camera location.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
    FVector MuzzleOffset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool CurrentWeaponType;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int CurrentWeaponNum;
};
