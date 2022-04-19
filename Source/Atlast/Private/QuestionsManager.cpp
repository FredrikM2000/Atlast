// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestionsManager.h"
#include <Math/UnrealMathUtility.h>

// Sets default values
AQuestionsManager::AQuestionsManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuestionsManager::BeginPlay()
{
	Super::BeginPlay();
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("What is the main capital of Norway?")),
		TArray<FText>{FText::FromString(TEXT("Bergen")), FText::FromString(TEXT("Oslo")), FText::FromString(TEXT("Trondheim")), FText::FromString(TEXT("Helsinki"))},
		1, // Answers are 0, 1, 2, 3
		FText::FromString(TEXT("Norway")),
		FText::FromString(TEXT("That's right!")),
		FText::FromString(TEXT("Sorry, that's not correct.")),
		0,
		false));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("How much did the diving tower in Hamar end up costing?")),
		TArray<FText>{FText::FromString(TEXT("1,5 million NOK / 170k USD")), FText::FromString(TEXT("3,0 million NOK / 340k USD")), FText::FromString(TEXT("4,5 million NOK / 500k USD")), FText::FromString(TEXT("25 million NOK / 2,5 million USD"))},
		3,
		FText::FromString(TEXT("Norway")),
		FText::FromString(TEXT("That's right!")),
		FText::FromString(TEXT("Sorry, that's not correct.")),
		0,
		false));
	//for (int i = 0; i < AllQuestions.Num(); i++) {
	//	if (AllQuestions[i]->AssociatedCountry.CompareTo(FText::FromString(TEXT("Norway")))) {
	//		NorwayQuestions.Add(AllQuestions[i]);
	//	}
	//	if (AllQuestions[i]->AssociatedCountry.CompareTo(FText::FromString(TEXT("Sweden")))) {
	//		SwedenQuestions.Add(AllQuestions[i]);
	//	}
	//	if (AllQuestions[i]->AssociatedCountry.CompareTo(FText::FromString(TEXT("Denmark")))) {
	//		DenmarkQuestions.Add(AllQuestions[i]);
	//	}
	//	if (AllQuestions[i]->AssociatedCountry.CompareTo(FText::FromString(TEXT("Finland")))) {
	//		FinlandQuestions.Add(AllQuestions[i]);
	//	}
	//	if (AllQuestions[i]->AssociatedCountry.CompareTo(FText::FromString(TEXT("Iceland")))) {
	//		IcelandQuestions.Add(AllQuestions[i]);
	//	}
	//}
}

// Called every frame
void AQuestionsManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuestionsManager::FillQuestionPool(int32 NumberOfQuestions, FText Country, int32 MinDifficulty, int32 MaxDifficulty)
{
	QuestionPool.Empty();
	TempPool.Empty();
	for (int32 i = 0; i < AllQuestions.Num(); i++) {
		if (!Country.CompareTo(FText::FromString(TEXT("None")))) {
			if (Country.CompareTo(AllQuestions[i]->AssociatedCountry)) {
				if (AllQuestions[i]->Difficulty >= MinDifficulty && AllQuestions[i]->Difficulty <= MaxDifficulty) {
					TempPool.Add(AllQuestions[i]);
				}
			}
		}
		else {
			if (AllQuestions[i]->Difficulty >= MinDifficulty && AllQuestions[i]->Difficulty <= MaxDifficulty) {
				TempPool.Add(AllQuestions[i]);
			}
		}
	}
	if (TempPool.Num() < NumberOfQuestions) {

		return;
	}
	for (int32 j = 0; j < NumberOfQuestions; j++) {
		// Insert code for randomizing the order here
	}
}

FText AQuestionsManager::GetQuestionBody(int32 Index)
{
	return AllQuestions[Index]->QuestionBody;
}

FText AQuestionsManager::GetAnswerOption(int32 QuestionIndex, int32 AnswerIndex)
{
	return AllQuestions[QuestionIndex]->PossibleAnswers[AnswerIndex];
}

FText AQuestionsManager::GetQuestionCorrect(int32 Index)
{
	return AllQuestions[Index]->IfCorrect;
}

FText AQuestionsManager::GetQuestionWrong(int32 Index)
{
	return AllQuestions[Index]->IfWrong;
}

bool AQuestionsManager::AnswerQuestion(int32 Index, int32 Answer)
{
	AllQuestions[Index]->HasSeenBefore = true;
	if (AllQuestions[Index]->CorrectAnswer == Answer) {
		AllQuestions[Index]->HasAnsweredCorrectBefore = true;
	}
	return (AllQuestions[Index]->CorrectAnswer == Answer);
}

bool AQuestionsManager::CheckIfEndOfQuestions(int32 Index)
{
	return Index >= AllQuestions.Num()-1;
}

int32 AQuestionsManager::TotalQuestions()
{
	return AllQuestions.Num();
}

