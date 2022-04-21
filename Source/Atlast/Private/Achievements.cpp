// Fill out your copyright notice in the Description page of Project Settings.


#include "Achievements.h"

// Sets default values
AAchievements::AAchievements()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAchievements::BeginPlay()
{
	Super::BeginPlay();
	AllAchievements.Emplace(new FAchievement(FText::FromString(TEXT("Clicker 1")), FText::FromString(TEXT("Clicked 10 times.")), 1, 1000, FString(TEXT("Click Anywhere"))));
}

FText AAchievements::GetAchievementName(int32 Index)
{
	return AllAchievements[Index]->AchievementName;
}

FText AAchievements::GetAchievementDescription(int32 Index)
{
	return AllAchievements[Index]->AchievementDescription;
}

float AAchievements::GetAchievementProgress(int32 Index)
{
	if (AllAchievements[Index] != nullptr) {
		return ((float)(AllAchievements[Index]->AchievementCurrentNumber) / (float)(AllAchievements[Index]->AchievementTargetNumber));
	}
	return 0.0f;
}

// Called every frame
void AAchievements::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ClickAnywhere(1);
}

void AAchievements::ClickAnywhere(int Clicks)
{
	for (int i = 0; i < AllAchievements.Num(); i++) {
		if (AllAchievements[i]->AchievementType == "Click Anywhere") {
			AllAchievements[i]->IncrementNumber(Clicks);
		}
	}
}