// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform() {

	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
	Speed = 5.f;
}



void AMovingPlatform::BeginPlay(){

	Super::BeginPlay();

	if (HasAuthority()) {
	
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	if (HasAuthority()) {

		FVector ActorLocation = GetActorLocation();
		ActorLocation += FVector(Speed * DeltaTime, 0, 0);
		SetActorLocation(ActorLocation);
	}



}
