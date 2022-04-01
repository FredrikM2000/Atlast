// Copyright Epic Games, Inc. All Rights Reserved.


#include "AtlastGameModeBase.h"
#include "Achievements.h"
#include "Kismet/GameplayStatics.h"

AAtlastGameModeBase::AAtlastGameModeBase() {
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAtlastGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(this, AAchievements::StaticClass(), AchievementSystem);
}

// Called every frame
void AAtlastGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
//	ClickAnywhere(1);
//	UE_LOG(LogTemp, Warning, TEXT("Tick"));
}

void AAtlastGameModeBase::ClickAnywhere(int Clicks)
{
	static_cast<AAchievements*>(AchievementSystem[0])->ClickAnywhere(Clicks);
}