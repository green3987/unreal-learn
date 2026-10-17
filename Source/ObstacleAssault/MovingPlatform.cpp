// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)//每帧都会调用
{
	Super::Tick(DeltaTime);

	RotatePlatform(DeltaTime);
	
	DistanceMoved = GetDistanceMoved();

	if (DistanceMoved >= MoveDistance)
	{
		float Overshoot = DistanceMoved - MoveDistance;
		FString PlatformName = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s overshot by %f"),*PlatformName,Overshoot);

		FVector MoveDirection=PlatformVelocity.GetSafeNormal();
		FVector NewStartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(NewStartLocation);
		StartLocation = NewStartLocation;

		PlatformVelocity *= -1;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();

		CurrentLocation += PlatformVelocity * DeltaTime;

		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DettaTime)
{
	FRotator RotationToAdd = RotationVelocity * DettaTime;
	AddActorLocalRotation(RotationToAdd);
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

