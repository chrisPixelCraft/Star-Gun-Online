// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"
//
//USTRUCT()
//struct FPointDamageEvent{};

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateAbstractDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);


}

void AGun::PullTrigger()
{
	//UE_LOG(LogTemp, Warning, TEXT("You've been shot!"));
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound,Mesh, TEXT("MuzzleFlashSocket"));

	APawn* OwnerPawn = Cast<APawn>(GetOwner());
		if (OwnerPawn == nullptr) return;
	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr) return;

	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location,Rotation);

	FVector End = Location + Rotation.Vector() * MaxRange;

	//test for aiming camera
	//DrawDebugCamera(GetWorld(), Location, Rotation, 90,2,FColor::Red,true);

	//DrawDebugPoint(GetWorld(), Location, 20, FColor::Red, true);

	FHitResult Hit;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());


	bool bSuccess=	GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1,Params);
	if (bSuccess) {
		FVector ShotDirection = -Rotation.Vector();
		//DrawDebugPoint(GetWorld(), Hit.Location, 20, FColor::Red, true);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, Hit.Location);

		//generate damage mechanism
		AActor* HitActor = Hit.GetActor();
		//const FDamageEvent &Event();
		float Damage = 10;
		TSubclassOf <UDamageType> DamageType;
		if (HitActor != nullptr) {
			FPointDamageEvent DamageEvent( Damage, Hit, ShotDirection, DamageType);
			HitActor->TakeDamage(Damage,DamageEvent,OwnerController,this);
			}
		}

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

