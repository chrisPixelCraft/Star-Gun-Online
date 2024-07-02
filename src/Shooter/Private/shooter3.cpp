// Fill out your copyright notice in the Description page of Project Settings.


#include "shooter3.h"
#include "Gun.h"
#include <algorithm>
#include "Components/CapsuleComponent.h"
#include "Blueprint/UserWidget.h"
#include "MyGameModeBase.h"
#include "KillEmAllGameMode.h"


// Sets default values
Ashooter3::Ashooter3()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Ashooter3::BeginPlay()
{

	Super::BeginPlay();

	Health = MaxHealth;
	
	Gun=GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);

	//UpdateTimerDisplay();

	
	//AdvanceTimer();
	//GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &Ashooter3::AdvanceTimer, 1.0f, true);
	//if (CountdownTime < 1 && Health<100&&Health>0) Health=std::max(MaxHealth,Health+20);
	

	/*create the hud widget 
	TSubclassOf<class UUserWidget> HUDClass;
	UUserWidget* HUD = CreateWidget(this, HUDClass);
	if (HUD != NULL) HUD->AddToViewport();*/

}

// Called every frame
void Ashooter3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Ashooter3::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &Ashooter3::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &Ashooter3::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &Ashooter3::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &Ashooter3::LookRightRate);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &Ashooter3::Shoot);



}

float Ashooter3::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	float DamageToApply = std::min(DamageApplied, Health);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);

	if (IsDead()) {
		AKillEmAllGameMode* GameMode = GetWorld()->GetAuthGameMode<AKillEmAllGameMode>();
		if (GameMode != NULL) {
			GameMode->PawnKilled(this);
		}

		//after it GetController when the pawn be killed.
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
	}
	return DamageToApply;
}

bool Ashooter3::IsDead() const
{
	return Health <= 0;
}

void Ashooter3::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void Ashooter3::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);

}

void Ashooter3::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void Ashooter3::LookRightRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}


void Ashooter3::Shoot()
{
	Gun->PullTrigger();
}



