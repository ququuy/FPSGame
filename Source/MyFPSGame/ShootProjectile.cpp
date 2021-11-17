// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootProjectile.h"

// Sets default values
AShootProjectile::AShootProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ShootProjectileSceneComponent"));
	}
	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile")); // projectile respond connected to Engine-Collision
		//CollisionComponent->OnComponentHit.AddDynamic(this, &AShootProjectile::OnHit); // Interact with world, Event called when hits
		//CollisionComponent->OnComponentHit.AddDynamic(this, &AShootProjectile::OnHit_Implementation); // Interact with world, Event called when hits
		
		CollisionComponent->InitSphereRadius((15.0f));
		RootComponent = CollisionComponent;
	}
	
	if (!ProjectileMovementComponent)
	{
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 3000.0f;
		ProjectileMovementComponent->MaxSpeed = 3000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	if (!ProjectileMeshComponent)
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/FirstPerson/FPActor/Projectile/Sphere.Sphere'"));
        if(Mesh.Succeeded())
        {
            ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
        }
		//static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/FPProjectile/ProjectileMaterial.ProjectileMaterial'"));
		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/FirstPerson/FPActor/Projectile/ProjectileMaterial.ProjectileMaterial'"));
    	if (Material.Succeeded())
    	{
			ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
    		//ProjectileMaterialInstance->SetVectorParameterValue(FName("ColorProjectile"), FLinearColor(1.0, 1.0, 1.0, 1.0));
    	}
    	ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
    	ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
    	ProjectileMeshComponent->SetupAttachment(RootComponent);
	}

	InitialLifeSpan = 3.0f; // delete after 3s
}

// Called when the game starts or when spawned
void AShootProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShootProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Function that initializes the projectile's velocity in the shoot direction.
void AShootProjectile::FireInDirection(const FVector& ShootDirection)
{
    ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

void AShootProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
	    OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
		//APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
		//PlayerCharacter->AddScore(2);
	}

   //Destroy();
}	
