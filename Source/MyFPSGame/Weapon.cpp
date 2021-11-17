// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponSceneComponent"));
	}
	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		
		//CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Weapon")); // projectile respond connected to Engine-Collision
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Weapon")); // projectile respond connected to Engine-Collision
		//CollisionComponent->OnComponentHit.AddDynamic(this, &AShootProjectile::OnHit); // Interact with world, Event called when hits
		//CollisionComponent->OnComponentHit.AddDynamic(this, &AShootProjectile::OnHit_Implementation); // Interact with world, Event called when hits
		
		CollisionComponent->InitSphereRadius((5.0f));
		RootComponent = CollisionComponent;
	}

	if (!MeshComponent)
	{
		//MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMeshComponent"));
		MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMeshComponent"));
		//static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
		static ConstructorHelpers::FObjectFinder<USkeletalMesh>Mesh(TEXT("'/Game/FirstPerson/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
        if(Mesh.Succeeded())
        {
            //MeshComponent->SetStaticMesh(Mesh.Object);
            MeshComponent->SetSkeletalMesh(Mesh.Object);
        }
		//static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/FPProjectile/ProjectileMaterial.ProjectileMaterial'"));
		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/FirstPerson/FPWeapon/Materials/M_FPGun.M_FPGun'"));
    	if (Material.Succeeded())
    	{
			MaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, MeshComponent);
    		MaterialInstance->SetVectorParameterValue(FName("BodyColor"), FLinearColor(1.0, 1.0, 1.0, 1.0));
    	}
    	MeshComponent->SetMaterial(0, MaterialInstance);
    	MeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
    	MeshComponent->SetupAttachment(RootComponent);
	}
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


int AWeapon::OnHit(FVector HitWorldLocation)
{
	return 0;
}

