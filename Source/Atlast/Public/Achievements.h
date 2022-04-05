// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/UnrealString.h"
#include <vector>
#include "Internationalization/Text.h"
#include "GameFramework/Actor.h"
#include "UObject/Class.h"
#include "Achievements.generated.h"

USTRUCT(BlueprintType)
 struct FCoreAchievement {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FText AchievementName = FText::FromString(TEXT("ACHIEVEMENT_NAME_HERE"));
	UPROPERTY(BlueprintReadOnly)
	FText AchievementDescription = FText::FromString(TEXT("ACHIEVEMENT_DESCRIPTION_HERE"));
	UPROPERTY(BlueprintReadOnly)
	bool AchievementUnlocked = false;
	UPROPERTY(BlueprintReadOnly)
	int AchievementNumber = 0;
	FString AchievementType = FString(TEXT("ACHIEVEMENT_TYPE_HERE"));
	void UnlockAchievement() {
		AchievementUnlocked = true;
		UE_LOG(LogTemp, Warning, TEXT("Achievement unlocked!"));
	}
};

USTRUCT(BlueprintType)
struct FIncrementAchievement : public FCoreAchievement {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	int AchievementCurrentNumber = 0;
	UPROPERTY(BlueprintReadOnly)
	int AchievementTargetNumber = 1;
	FIncrementAchievement(){}
	FIncrementAchievement(FText name, FText desc, int number, int target, FString type) {
		AchievementName = name;
		AchievementDescription = desc;
		AchievementNumber = number;
		AchievementTargetNumber = target;
		AchievementType = type;
	}
	void IncrementNumber(int count) {
		AchievementCurrentNumber += count;
		if (!AchievementUnlocked) {
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

public:
	TArray<FCoreAchievement*> AllAchievements;

	FText GetAchievementName(int32 Index);
	FText GetAchievementDescription(int32 Index);
	float GetAchievementProgress(int32 Index);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ClickAnywhere(int Clicks);
};
