// LeaveMeAlone Game by Netologiya. All RightsReserved


#include "Components/LMAWeaponComponent.h"
#include "GameFramework/Character.h"
#include "Weapon/LMABaseWeapon.h"
#include "Animations/LMAReloadFinishedAnimNotify.h"

ULMAWeaponComponent::ULMAWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void ULMAWeaponComponent::Fire() 
{
	if (Weapon && !AnimReloading && !StaminaStatus)
	{
		Weapon->Fire();
	}
}

void ULMAWeaponComponent::StopTimerFireRate()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_Fire);
}

void ULMAWeaponComponent::StartTimerFireRate() 
{
	Fire();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_Fire, this, &ULMAWeaponComponent::Fire, 0.1f, true);
}

void ULMAWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
	InitAnimNotify();
}

void ULMAWeaponComponent::OnAmmoDepleted() {
	Reload();
}

void ULMAWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void ULMAWeaponComponent::SpawnWeapon()
{
	Weapon = GetWorld()->SpawnActor<ALMABaseWeapon>(WeaponClass);
	if (Weapon)
	{
		const auto Character = Cast<ACharacter>(GetOwner());
		if (Character)
		{
			FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
			Weapon->AttachToComponent(Character->GetMesh(), AttachmentRules, "r_Weapon_Socket");
		}
	}
	Weapon->OnAmmoEmpty.AddUObject(this, &ULMAWeaponComponent::OnAmmoDepleted);
}

void ULMAWeaponComponent::InitAnimNotify()
{
	if (!ReloadMontage) 
	{
		return;
	}
	const auto NotifiesEvents = ReloadMontage->Notifies;
	for (auto NotifyEvent : NotifiesEvents)
	{
		auto ReloadFinish = Cast<ULMAReloadFinishedAnimNotify>(NotifyEvent.Notify);
		if (ReloadFinish)
		{
			ReloadFinish->OnNotifyReloadFinished.AddUObject(this, &ULMAWeaponComponent::OnNotifyReloadFinished);
			break;
		}
	}
}

void ULMAWeaponComponent::OnNotifyReloadFinished(USkeletalMeshComponent* SkeletalMesh)
{
	const auto Character = Cast<ACharacter>(GetOwner());
	if (Character->GetMesh() == SkeletalMesh)
	{
		AnimReloading = false;
	}
}

bool ULMAWeaponComponent::CanReload() const
{
	if (!AnimReloading && !Weapon->ClipFull)
	{
		return true;
	}
	return false;
}

void ULMAWeaponComponent::Reload()
{
	if (!CanReload()) return;
	Weapon->ChangeClip();
	AnimReloading = true;
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	Character->PlayAnimMontage(ReloadMontage);
}

bool ULMAWeaponComponent::GetCurrentWeaponAmmo(FAmmoWeapon& AmmoWeapon)
const
{
	if (Weapon)
	{
		AmmoWeapon = Weapon->GetCurrentAmmoWeapon();
		return true;
	}
	return false;
}

