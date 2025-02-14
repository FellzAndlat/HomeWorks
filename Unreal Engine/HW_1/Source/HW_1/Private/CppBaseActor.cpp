// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Engine/World.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
	
}

void ACppBaseActor::SinMovement() 
{
	SetActorLocation(FVector(InitialLocation.X, InitialLocation.Y, InitialLocation.Z = InitialLocation.Z + (FPlatformMath::Sin(Frequency * GetWorld()->GetTimeSeconds()) * Amplitude)));
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::showInformation() {

	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *Instancename);
	UE_LOG(LogTemp, Display, TEXT("EnamyNum: %d"), EnamyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

