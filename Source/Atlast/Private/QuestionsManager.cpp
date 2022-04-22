// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestionsManager.h"
#include <Math/UnrealMathUtility.h>
#include "Kismet/KismetArrayLibrary.h"

// Sets default values
AQuestionsManager::AQuestionsManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("What psychological term was first used to refer to\nwhat happened during a bank robbery in Sweden in 1971?")),
		TArray<FText>{FText::FromString(TEXT("Stockholm Syndrome:\nWhen captives develop sympathy for their captor.")), FText::FromString(TEXT("Malmo Madness:\nA murderous rage criminals enter when\nfaced with the threat of arrest.")), FText::FromString(TEXT("Helsingborg Honor:\nDangerous people acting extremely politely\ndespite doing horrible acts.")), FText::FromString(TEXT("Gothenburg Gall:\nWhen a criminal genuinely believes 'getting away'\nmeans they'll never be prosecuted."))},
		0,
		FText::FromString(TEXT("Sweden")),
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
	//FillQuestionPool(3, FText::FromString(TEXT("Norway")));
}

void AQuestionsManager::FillQuestionPool(int32 NumberOfQuestions, FText Country, int32 MinDifficulty, int32 MaxDifficulty)
{
	QuestionPool.Empty();
	TempPool.Empty();
	for (int32 i = 0; i < AllQuestions.Num(); i++) {
		if (Country.EqualTo(FText::FromString(TEXT("None")))) {
				if (AllQuestions[i]->Difficulty >= MinDifficulty && AllQuestions[i]->Difficulty <= MaxDifficulty) {
					TempPool.Add(AllQuestions[i]);
				}
		}
		else {
		if (Country.EqualTo(AllQuestions[i]->AssociatedCountry)) {
			if (AllQuestions[i]->Difficulty >= MinDifficulty && AllQuestions[i]->Difficulty <= MaxDifficulty) {
				TempPool.Add(AllQuestions[i]);
			}
		}
		}
	}

	if (TempPool.Num() > 0)
	{
		int32 LastIndex = TempPool.Num() - 1;
		for (int32 i = 0; i <= LastIndex; ++i)
		{
			int32 Index = FMath::RandRange(i, LastIndex);
			if (i != Index)
			{
				TempPool.Swap(i, Index);
			}
		}
	}
	else {
		QuestionPool.Add(new FQuestion(FText::FromString(TEXT("ERROR")),
			TArray<FText>{FText::FromString(TEXT("ERROR")), FText::FromString(TEXT("ERROR")), FText::FromString(TEXT("ERROR")), FText::FromString(TEXT("ERROR"))},
			0,
			FText::FromString(TEXT("None")),
			FText::FromString(TEXT("ERROR")),
			FText::FromString(TEXT("ERROR")),
			0,
			false));
		return;
	}
	if (TempPool.Num() < NumberOfQuestions) {
		for (int32 i = 0; i < TempPool.Num(); i++) {
			QuestionPool.Add(TempPool[i]);
		}
	}
	else {
		for (int32 i = 0; i < NumberOfQuestions; i++) {
			QuestionPool.Add(TempPool[i]);
		}
	}
}

FText AQuestionsManager::GetQuestionBody(int32 Index)
{
	return QuestionPool[Index]->QuestionBody;
}

FText AQuestionsManager::GetAnswerOption(int32 QuestionIndex, int32 AnswerIndex)
{
	return QuestionPool[QuestionIndex]->PossibleAnswers[AnswerIndex];
}

FText AQuestionsManager::GetQuestionCorrect(int32 Index)
{
	return QuestionPool[Index]->IfCorrect;
}

FText AQuestionsManager::GetQuestionWrong(int32 Index)
{
	return QuestionPool[Index]->IfWrong;
}

bool AQuestionsManager::AnswerQuestion(int32 Index, int32 Answer)
{
	QuestionPool[Index]->HasSeenBefore = true;
	if (QuestionPool[Index]->CorrectAnswer == Answer) {
		QuestionPool[Index]->HasAnsweredCorrectBefore = true;
	}
	return (QuestionPool[Index]->CorrectAnswer == Answer);
}

bool AQuestionsManager::CheckIfEndOfQuestions(int32 Index)
{
	return Index >= QuestionPool.Num()-1;
}

int32 AQuestionsManager::TotalQuestions()
{
	return QuestionPool.Num();
}

