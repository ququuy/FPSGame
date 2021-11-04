// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ShootProjectile.generated.h"

UCLASS()
class FPSGAME_API AShootProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShootProjectile();

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
	UPROPERTY(VisibleAnywhere, Category = "Projectile Movement")
	UProjectileMovementComponent* ProjectileMovementComponent;

	// Projectile mesh
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile Mesh")
	UStaticMeshComponent* ProjectileMeshComponent;
	// Projectile material 
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile Material")
	UMaterialInstanceDynamic* ProjectileMaterialInstance;

	//UFUNCTION(BlueprintNativeEvent, Category = "Event Hit")
	//void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION(BlueprintCallable)
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	//DECLARE_EVENT(FlayerViewModel, FChangedEvent)
	//FChangedEvent& OnHitTarget() { return ChangedEvent; }

	
	UFUNCTION(BlueprintCallable)
	void FireInDirection(const FVector& ShootDirection);

};
