// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

UCLASS()
class HW_1_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SinMovement();

	UFUNCTION(BlueprintCallable)
	void showInformation();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditInstanceOnly)
	FString Instancename = "A_Cpp_Base_C";
	UPROPERTY(EditInstanceOnly)
	int EnamyNum = 20;
	UPROPERTY(EditInstanceOnly)
	float CurrentHealth = 57.54687;
	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;
	FVector InitialLocation = FVector::ZeroVector;
	UPROPERTY(EditInstanceOnly)
	double Amplitude = 0;
	UPROPERTY(EditInstanceOnly)
	double Frequency = 0;

};
