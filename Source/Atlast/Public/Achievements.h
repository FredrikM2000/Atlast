// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include <vector>
#include "GameFramework/Actor.h"
#include "Achievements.generated.h"

struct CoreAchievement {
	std::string AchievementName = "ACHIEVEMENT_NAME_HERE";
	std::string AchievementDescription = "ACHIEVEMENT_DESCRIPTION_HERE";
	bool AchievementUnlocked = false;
	int AchievementNumber = 0;
	std::string AchievementType = "ACHIEVEMENT_TYPE_HERE";
	void UnlockAchievement() {
		AchievementUnlocked = true;
		UE_LOG(LogTemp, Warning, TEXT("Achievement unlocked!"));
	}
};

struct IncrementAchievement : CoreAchievement {
	int AchievementCurrentNumber = 0;
	int AchievementTargetNumber = 1;
	IncrementAchievement(std::string name, std::string desc, int number, int target, std::string type) {
		AchievementName = name;
		AchievementDescription = desc;
		AchievementNumber = number;
		AchievementTargetNumber = 10;
		AchievementType = type;
	}
	void IncrementNumber(int count) {
		AchievementCurrentNumber += count;
		if (!AchievementUnlocked) {
			UE_LOG(LogTemp, Warning, TEXT("Progress"));
			if (AchievementCurrentNumber >= AchievementTargetNumber) {
				UnlockAchievement();
			}
		}
	}
};

UCLASS()
class ATLAST_API AAchievements : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAchievements();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	std::vector<CoreAchievement*> AllAchievements;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ClickAnywhere(int Clicks);

};
