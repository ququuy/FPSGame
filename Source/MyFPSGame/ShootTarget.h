// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShootTarget.generated.h"

UCLASS()
class MYFPSGAME_API AShootTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShootTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Collision Component
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile Collision")
	USphereComponent* CollisionComponent;
	
	// Movement Component
	//UPROPERTY(VisibleAnywhere, Category = "Projectile Movement")
	//UProjectileMovementComponent* ProjectileMovementComponent;

	// Projectile mesh
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile Mesh")
	UStaticMeshComponent* MeshComponent;
	// Projectile material 
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile Material")
	UMaterialInstanceDynamic* MaterialInstance;

	//UFUNCTION(BlueprintNativeEvent, Category = "Event Hit")
	//void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION(BlueprintCallable)
	int OnHit(FVector HitWorldLocation);
	//int OnHit(UPrimitiveComponent* HitComponent, FVector HitWorldLocation);
};
