// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgressManager.h"

// Sets default values
AProgressManager::AProgressManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AProgressManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProgressManager::Increase(int64 increase)
{
	Progress += increase;
	UE_LOG(LogTemp, Warning, TEXT("Progress: %i"), Progress);
}

float AProgressManager::GetProgress()
{
	return (float)Progress/(float)Total;
}

void AProgressManager::Reset()
{
	Progress = 0;
}

