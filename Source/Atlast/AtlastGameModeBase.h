// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Internationalization/Text.h"
#include "AtlastGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ATLAST_API AAtlastGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AAtlastGameModeBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<AActor*> AchievementSystem;
	TArray<AActor*> QuestionsManager;
	TArray<AActor*> AllCountries;
	TArray<AActor*> AllLandmarks;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ClickAnywhere(int Clicks);

	UFUNCTION(BlueprintCallable)
	FText GetAchievementName(int32 Index);

	UFUNCTION(BlueprintCallable)
	FText GetDescriptionName(int32 Index);

	UFUNCTION(BlueprintCallable)
	float GetAchievementProgress(int32 Index);

	UFUNCTION(BlueprintCallable)
	FText GetQuestionBody(int32 Index);

	UFUNCTION(BlueprintCallable)
	FText GetAnswerOption(int32 QuestionIndex, int32 AnswerIndex);

	UFUNCTION(BlueprintCallable)
	FText GetQuestionCorrect(int32 Index);

	UFUNCTION(BlueprintCallable)
	FText GetQuestionWrong(int32 Index);

	UFUNCTION(BlueprintCallable)
	bool AnswerQuestion(int32 Index, int32 Answer);

	void CountryClicked(class ACountry* SelectedCountry, class ALandmark* SelectedLandmark = nullptr);
};
