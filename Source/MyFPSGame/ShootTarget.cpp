// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootTarget.h"


// Sets default values
AShootTarget::AShootTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ShootTargetSceneComponent"));
	}
	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Target")); // projectile respond connected to Engine-Collision
		//CollisionComponent->OnComponentHit.AddDynamic(this, &AShootProjectile::OnHit); // Interact with world, Event called when hits
		//CollisionComponent->OnComponentHit.AddDynamic(this, &AShootProjectile::OnHit_Implementation); // Interact with world, Event called when hits
		
		CollisionComponent->InitSphereRadius((15.0f));
		RootComponent = CollisionComponent;
	}

	if (!MeshComponent)
	{
		MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMeshComponent"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/FirstPerson/FPActor/Target/TargetCylinder.TargetCylinder'"));
        if(Mesh.Succeeded())
        {
            MeshComponent->SetStaticMesh(Mesh.Object);
        }
		//static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/FPProjectile/ProjectileMaterial.ProjectileMaterial'"));
		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/FirstPerson/FPActor/Target/TargetMaterial.TargetMaterial'"));
    	if (Material.Succeeded())
    	{
			MaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, MeshComponent);
    	}
    	MeshComponent->SetMaterial(0, MaterialInstance);
    	MeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
    	MeshComponent->SetupAttachment(RootComponent);
	}
}

// Called when the game starts or when spawned
void AShootTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShootTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


int AShootTarget::OnHit(FVector HitWorldLocation)
{
	FTransform ActorToWorld = GetActorTransform();
	
	//FVector HitLocalLocation = ActorToWorld.Inverse().TransformVector(HitWorldLocation);
	FVector HitLocalLocation = ActorToWorld.InverseTransformPosition(HitWorldLocation);//.TransformVector(HitWorldLocation);
	//FVector HitLocalLocation = ActorToWorld.InverseTransformVectorNoScale(HitWorldLocation);;//InverseTransformVector(HitWorldLocation);

	float Radius = HitLocalLocation.X * HitLocalLocation.X + HitLocalLocation.Y * HitLocalLocation.Y;
	//if(GEngine)
    //      GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("radius %f %f %f"),
    //      	HitLocalLocation.X, HitLocalLocation.Y, HitLocalLocation.Z));    
    //      	//HitWorldLocation.X, HitWorldLocation.Y, HitWorldLocation.Z));    
	if (Radius < 3.0) return 5;
	else return 1;
}
