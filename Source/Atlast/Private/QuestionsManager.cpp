// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestionsManager.h"

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
		1,
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

FText AQuestionsManager::GetQuestionBody(int32 Index)
{
	return AllQuestions[Index]->QuestionBody;
}

FText AQuestionsManager::GetAnswerOption(int32 QuestionIndex, int32 AnswerIndex)
{
	return AllQuestions[QuestionIndex]->PossibleAnswers[AnswerIndex];
}

