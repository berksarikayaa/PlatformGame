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
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Move Platform Forward
		//Get Current Location
	FVector CurrentLocation = GetActorLocation();
		//Add Vector To That Location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		//Set The Location
	SetActorLocation(CurrentLocation);
	//SendPlatform Back If Gone Too Far
		//Check How Far We've Moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		//Reverse Direction Of Motion If Gone Too Far
	if (DistanceMoved > MovedDistance)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MovedDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity =-PlatformVelocity;
	}
	
}

