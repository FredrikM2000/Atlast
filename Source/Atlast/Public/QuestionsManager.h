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

	int32 Difficulty = 0;

	UPROPERTY(BlueprintReadOnly)
	FText QuestionBody = FText::FromString(TEXT("INSERT_QUESTION_BODY_HERE"));

	UPROPERTY(BlueprintReadOnly)
	FText IfCorrect = FText::FromString(TEXT("INSERT_ADDITIONAL_INFORMATION_HERE"));

	UPROPERTY(BlueprintReadOnly)
	FText IfWrong = FText::FromString(TEXT("INSERT_WRONG_MESSAGE_HERE"));

	UPROPERTY(BlueprintReadOnly)
	TArray<FText> PossibleAnswers{ FText::FromString(TEXT("INSERT_QUESTION_ANSWERS_HERE")) };

	UPROPERTY(BlueprintReadOnly)
	FText Answer1 = FText::FromString(TEXT("INSERT_ANSWER1_HERE"));

	UPROPERTY(BlueprintReadOnly)
	FText Answer2 = FText::FromString(TEXT("INSERT_ANSWER2_HERE"));

	UPROPERTY(BlueprintReadOnly)
	FText Answer3 = FText::FromString(TEXT("INSERT_ANSWER3_HERE"));

	UPROPERTY(BlueprintReadOnly)
	FText Answer4 = FText::FromString(TEXT("INSERT_ANSWER4_HERE"));

	bool IsLandmarkQuestion = false;
	bool HasSeenBefore = false;
	bool HasAnsweredCorrectBefore = false;
	int32 CorrectAnswer = 0;
	FQuestion(FText Question, TArray<FText> Answers, int32 Correct, FText Country, FText Congrats, FText Sorry, int32 Challenge, bool LandmarkQuestion) {
		QuestionBody = Question;
		PossibleAnswers = Answers;
		Answer1 = FText::FromString(TEXT("INSERT_ANSWER1_HERE"));
		Answer2 = FText::FromString(TEXT("INSERT_ANSWER2_HERE"));
		Answer3 = FText::FromString(TEXT("INSERT_ANSWER3_HERE"));
		Answer4 = FText::FromString(TEXT("INSERT_ANSWER4_HERE"));
		CorrectAnswer = Correct;
		AssociatedCountry = Country;
		IfCorrect = Congrats;
		IfWrong = Sorry;
		Difficulty = Challenge;
		IsLandmarkQuestion = LandmarkQuestion;
	}
	void AnswerQuestion(int32 AnswerRecieved) {
		if (AnswerRecieved == CorrectAnswer) {
			HasAnsweredCorrectBefore = true;
		}
		else {
		}
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
	TArray<FQuestion*> AllQuestions{ nullptr };

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FText GetQuestionBody(int32 Index);
	FText GetAnswerOption(int32 Index, int32 AnswerIndex);
};
