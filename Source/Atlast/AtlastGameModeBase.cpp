// Copyright Epic Games, Inc. All Rights Reserved.


#include "AtlastGameModeBase.h"
#include "Achievements.h"
#include "QuestionsManager.h"
#include "Country.h"
#include "Landmark.h"
#include "Kismet/GameplayStatics.h"

AAtlastGameModeBase::AAtlastGameModeBase() {
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAtlastGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(this, AAchievements::StaticClass(), AchievementSystem);
	UGameplayStatics::GetAllActorsOfClass(this, AQuestionsManager::StaticClass(), QuestionsManager);
	UGameplayStatics::GetAllActorsOfClass(this, ACountry::StaticClass(), AllCountries);
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

FText AAtlastGameModeBase::GetAchievementName(int32 Index)
{
	return static_cast<AAchievements*>(AchievementSystem[0])->GetAchievementName(Index);
}

FText AAtlastGameModeBase::GetDescriptionName(int32 Index)
{
	return static_cast<AAchievements*>(AchievementSystem[0])->GetAchievementDescription(Index);
}

float AAtlastGameModeBase::GetAchievementProgress(int32 Index)
{
	return static_cast<AAchievements*>(AchievementSystem[0])->GetAchievementProgress(Index);
}

FText AAtlastGameModeBase::GetQuestionBody(int32 Index)
{
	return static_cast<AQuestionsManager*>(QuestionsManager[0])->GetQuestionBody(Index);
}

FText AAtlastGameModeBase::GetAnswerOption(int32 QuestionIndex, int32 AnswerIndex)
{
	return static_cast<AQuestionsManager*>(QuestionsManager[0])->GetAnswerOption(QuestionIndex, AnswerIndex);
}

FText AAtlastGameModeBase::GetQuestionCorrect(int32 Index)
{
	return static_cast<AQuestionsManager*>(QuestionsManager[0])->GetQuestionCorrect(Index);
}

FText AAtlastGameModeBase::GetQuestionWrong(int32 Index)
{
	return static_cast<AQuestionsManager*>(QuestionsManager[0])->GetQuestionWrong(Index);
}

bool AAtlastGameModeBase::AnswerQuestion(int32 Index, int32 Answer)
{
	return static_cast<AQuestionsManager*>(QuestionsManager[0])->AnswerQuestion(Index, Answer);
}

bool AAtlastGameModeBase::CheckIfEndOfQuestions(int32 Index)
{
	return static_cast<AQuestionsManager*>(QuestionsManager[0])->CheckIfEndOfQuestions(Index);
}

int32 AAtlastGameModeBase::TotalQuestions()
{
	return static_cast<AQuestionsManager*>(QuestionsManager[0])->TotalQuestions();
}

void AAtlastGameModeBase::CountryClicked(ACountry* SelectedCountry, ALandmark* SelectedLandmark)
{
	//for (int i = 0; i < AllCountries.Num(); i++) {
	//	if (static_cast<ACountry*>(AllCountries[i]) != SelectedCountry) {
	//		static_cast<ACountry*>(AllCountries[i])->Highlighted = false;
	//	}
	//}
	//for (int i = 0; i < AllLandmarks.Num(); i++) {
	//	if (SelectedLandmark) {
	//		if (static_cast<ALandmark*>(AllLandmarks[i]) != SelectedLandmark) {
	//			static_cast<ALandmark*>(AllLandmarks[i])->Highlighted = false;
	//		}
	//	}
	//	else {
	//		static_cast<ALandmark*>(AllLandmarks[i])->Highlighted = false;
	//	}
	//}
}