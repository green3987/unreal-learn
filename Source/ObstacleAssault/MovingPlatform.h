// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)//可编辑状态
	FVector PlatformVelocity = FVector(0.0f, 0.0f, 0.0f);

	void RotatePlatform(float DetalTime);

	float GetDistanceMoved();

	UPROPERTY(EditAnywhere)
	float MoveDistance = 100.0f;


	UPROPERTY(VisibleAnywhere)
	float DistanceMoved = 0.0f;

	UPROPERTY(EditAnywhere)
	FRotator RotationVelocity;

	// FVector StartLocation = FVector();//初始化 有值
	FVector StartLocation; //创见变量 没赋值
};
