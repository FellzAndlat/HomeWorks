// LeaveMeAlone Game by Netologiya. All RightsReserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LMAWeaponComponent.generated.h"

class ALMABaseWeapon;
class UAnimeMontage;
struct FAmmoWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEAVEMEALONE_API ULMAWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULMAWeaponComponent();
	void Fire();
	UFUNCTION(BlueprintCallable)
	void StopFire() { 
		UE_LOG(LogTemp, Warning, TEXT("StopFire"));
		StopTimerFireRate(); }
	void StopTimerFireRate();
	void Reload();
	void StartTimerFireRate();
	UFUNCTION(BlueprintCallable)
	bool GetCurrentWeaponAmmo(FAmmoWeapon& AmmoWeapon) const;
	void SetStaminaStatus(bool StaminaStat) { StaminaStatus = StaminaStat; }
protected:
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ALMABaseWeapon> WeaponClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	UAnimMontage* ReloadMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	UAnimMontage* FireMontage;

	virtual void BeginPlay() override;
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	UPROPERTY()
	ALMABaseWeapon* Weapon = nullptr;

	bool AnimReloading = false;
	FTimerHandle TimerHandle_Fire;
	bool StaminaStatus = false;

	void SpawnWeapon();
	void InitAnimNotify();
	void OnAmmoDepleted();

	void OnNotifyReloadFinished(USkeletalMeshComponent* SkeletalMesh);
	bool CanReload() const;
};
