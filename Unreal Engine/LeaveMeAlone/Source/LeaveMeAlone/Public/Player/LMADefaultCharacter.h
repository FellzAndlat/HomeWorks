// LeaveMeAlone Game by Netologiya. All RightsReserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;
class UAnimMontage;
class ULMAWeaponComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStaminaChanged, float, NewStamina);

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALMADefaultCharacter();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	ULMAHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	ULMAWeaponComponent* WeaponComponent;
	
	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathMontage;

	UPROPERTY(BlueprintAssignable, Category = "Stamina")
	FOnStaminaChanged OnStaminaChanged;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stamina")
	float MaxStamina = 100.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stamina")
	float Stamina = 100.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stamina")
	float StaminaDrainRate = 10.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stamina")
	float StaminaRegenRate = 5.0f;
public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	float GetStamina() const { return Stamina; }

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	ULMAHealthComponent* GetHealthComponent() const { return HealthComponent; }


private:
	float YRotation = -75.0f;
	float ArmLength = 1400.0f;
	float ZoomSpeed = 20;
	float ArmLengtMax = 1800.0f;
	float ArmLengtMin = 1000.0f;
	float FOV = 55.0f;
	float PreviousStamina;
	bool SprintStatus = false;
	bool CanSprint = true;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Zoom(float Value);
	void StartSprint();
	void StopSprint();
	void OnDeath();
	void RotationPlayerOnCursor();
	void OnHealthChanged(float NewHealth);
	void UpdateStamina(float DeltaTime);
};
