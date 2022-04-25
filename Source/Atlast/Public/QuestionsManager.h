// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include <string>
#include "GameFramework/Actor.h"
#include "QuestionsManager.generated.h"

USTRUCT(BlueprintType)
struct FQuestion {
	GENERATED_BODY()
public:
	FQuestion() {}
	~FQuestion() {}
	UPROPERTY(BlueprintReadOnly)
	FText AssociatedCountry = FText::FromString(TEXT("INSERT_COUNTRY_HERE"));

	UPROPERTY(BlueprintReadOnly)
	FText AssociatedLandmark = FText::FromString(TEXT("INSERT_COUNTRY_HERE"));

	UPROPERTY(BlueprintReadOnly)
	FText QuestionBody = FText::FromString(TEXT("INSERT_QUESTION_BODY_HERE"));

	UPROPERTY(BlueprintReadOnly)
	FText IfCorrect = FText::FromString(TEXT("INSERT_ADDITIONAL_INFORMATION_HERE"));

	UPROPERTY(BlueprintReadOnly)
	FText IfWrong = FText::FromString(TEXT("INSERT_WRONG_MESSAGE_HERE"));

	UPROPERTY(BlueprintReadOnly)
	TArray<FText> PossibleAnswers{ FText::FromString(TEXT("INSERT_QUESTION_ANSWERS_HERE")) };

	bool HasSeenBefore = false;
	bool HasAnsweredCorrectBefore = false;
	int32 CorrectAnswer = 0;
	FQuestion(FText Question, TArray<FText> Answers, int32 Correct, FText Country, FText Landmark, FText Congrats, FText Sorry) {
		QuestionBody = Question;
		PossibleAnswers = Answers;
		CorrectAnswer = Correct;
		AssociatedCountry = Country;
		AssociatedLandmark = Landmark;
		IfCorrect = Congrats;
		IfWrong = Sorry;
	}
};

UCLASS()
class ATLAST_API AQuestionsManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AQuestionsManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:
	TArray<FQuestion*> AllQuestions;
	TArray<FQuestion*> QuestionPool{ nullptr };
	TArray<FQuestion*> TempPool{ nullptr };

	void FillQuestionPool(FText Landmark = FText::FromString(TEXT("None")));
	FText GetQuestionBody(int32 Index);
	FText GetAnswerOption(int32 Index, int32 AnswerIndex);
	FText GetQuestionCorrect(int32 Index);
	FText GetQuestionWrong(int32 Index);
	bool AnswerQuestion(int32 Index, int32 Answer);
	bool CheckIfEndOfQuestions(int32 Index);
	int32 TotalQuestions();
};
