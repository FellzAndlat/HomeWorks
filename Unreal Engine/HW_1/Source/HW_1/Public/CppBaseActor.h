// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

USTRUCT(BlueprintType)
struct FTransformStruct 
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);

};

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
	void showInformation();
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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	

};
