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
	AllAchievements.push_back(new IncrementAchievement("Clicker 1", "Clicked 10 times.", 1, 10, "Click Anywhere"));
	
}

// Called every frame
void AAchievements::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAchievements::ClickAnywhere(int Clicks)
{
	for (int i = 0; i < AllAchievements.size(); i++) {
		if (AllAchievements[i]->AchievementType == "Click Anywhere") {
			static_cast<IncrementAchievement*>(AllAchievements[i])->IncrementNumber(Clicks);
		}
	}
}