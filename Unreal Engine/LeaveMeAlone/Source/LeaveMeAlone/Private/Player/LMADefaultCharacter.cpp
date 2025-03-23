// LeaveMeAlone Game by Netologiya. All RightsReserved


#include "Player/LMADefaultCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/LMAHealthComponent.h"
#include "Components/InputComponent.h"
#include "Components/LMAWeaponComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/Engine.h"


ALMADefaultCharacter::ALMADefaultCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	HealthComponent = CreateDefaultSubobject<ULMAHealthComponent>("HealthComponent");;

	WeaponComponent = CreateDefaultSubobject<ULMAWeaponComponent>("Weapon");

	SpringArmComponent->SetUsingAbsoluteRotation(true);
	SpringArmComponent->TargetArmLength = ArmLength;
	SpringArmComponent->SetRelativeRotation(FRotator(YRotation, 0.0f, 0.0f));
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->bEnableCameraLag = true;
	CameraComponent->SetFieldOfView(FOV);
	CameraComponent->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

}

void ALMADefaultCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (CursorMaterial) {
		CurrentCursor = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), CursorMaterial, CursorSize, FVector(0));
	}
	HealthComponent->OnDeath.AddDynamic(this, &ALMADefaultCharacter::OnDeath);
}

void ALMADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!(HealthComponent->IsDead())) {
		RotationPlayerOnCursor();
	}
	UpdateStamina(DeltaTime);
	
}

void ALMADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ALMADefaultCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALMADefaultCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Zoom", this, &ALMADefaultCharacter::Zoom);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ALMADefaultCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ALMADefaultCharacter::StopSprint);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &ULMAWeaponComponent::StartTimerFireRate);
	PlayerInputComponent->BindAction("Fire", IE_Released, WeaponComponent, &ULMAWeaponComponent::StopTimerFireRate);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, WeaponComponent, &ULMAWeaponComponent::Reload);
}

void ALMADefaultCharacter::MoveForward(float Value) {
	AddMovementInput(GetActorForwardVector(), Value);
}

void ALMADefaultCharacter::MoveRight(float Value) {
	AddMovementInput(GetActorRightVector(), Value);
}

void ALMADefaultCharacter::Zoom(float Value) {
	float NewDistance = SpringArmComponent->TargetArmLength - Value * ZoomSpeed;
	SpringArmComponent->TargetArmLength = FMath::Clamp(NewDistance, ArmLengtMin, ArmLengtMax);
}
void ALMADefaultCharacter::OnDeath()
{
	CurrentCursor->DestroyRenderState_Concurrent();
	PlayAnimMontage(DeathMontage);
	GetCharacterMovement()->DisableMovement();
	SetLifeSpan(5.0f);
	if (Controller) 
	{
		Controller->ChangeState(NAME_Spectating);
	}
}

void ALMADefaultCharacter::RotationPlayerOnCursor() 
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC) 
	{
		FHitResult ResultHit;
		PC->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, ResultHit);
		float FindRotatorResultYaw = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), ResultHit.Location).Yaw;
		SetActorRotation(FQuat(FRotator(0.0f, FindRotatorResultYaw, 0.0f)));
		if (CurrentCursor) 
		{
			CurrentCursor->SetWorldLocation(ResultHit.Location);
		}
	}
}

void ALMADefaultCharacter::StartSprint() 
{
	if (CanSprint)
	{
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
		SprintStatus = true;
	}
}

void ALMADefaultCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	SprintStatus = false;
}

void ALMADefaultCharacter::UpdateStamina(float DeltaTime)
{
	float OldStamina = Stamina;

	if (GetCharacterMovement()->MaxWalkSpeed > 300 && CanSprint == true)
	{
		Stamina = FMath::Clamp(Stamina - StaminaDrainRate * DeltaTime, 0.0f, MaxStamina);
	} 
	else
	{
		Stamina = FMath::Clamp(Stamina + StaminaRegenRate * DeltaTime, 0.0f, MaxStamina);
	}
	if (Stamina <= 0) 
	{
		CanSprint = false;
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	}
	if (Stamina >= 100) 
	{
		CanSprint = true;
	}
	if (OldStamina != Stamina)
	{
		OnStaminaChanged.Broadcast(Stamina);
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("Stamina: %f"), Stamina));
	}	
}