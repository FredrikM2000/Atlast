// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include <string>
#include "GameFramework/Actor.h"
#include "QuestionsManager.generated.h"

struct QuestionBase {
	std::string AssociatedCountry = "INSERT_COUNTRY_HERE";
	int32 Difficulty = 0;
	std::string QuestionBody = "INSERT_QUESTION_BODY_HERE";
	std::string IfCorrect = "INSERT_ADDITIONAL_INFORMATION_HERE";
	std::string IfWrong = "INSERT_WRONG_MESSAGE_HERE";
	bool IsLandmarkQuestion = false;
	bool HasSeenBefore = false;
	bool HasAnsweredCorrectBefore = false;
};

struct MultipleChoiceQuestion : QuestionBase {
	std::vector<std::string> PossibleAnswers;
	int32 CorrectAnswer;
	MultipleChoiceQuestion(std::string Question, std::vector<std::string> Answers, int32 Correct, std::string Country, std::string Congrats, std::string Sorry, int32 Challenge, bool LandmarkQuestion) {
		QuestionBody = Question;
		PossibleAnswers = Answers;
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
	std::vector<QuestionBase*> AllQuestions;
	std::vector<QuestionBase*> NorwayQuestions;
	std::vector<QuestionBase*> SwedenQuestions;
	std::vector<QuestionBase*> DenmarkQuestions;
	std::vector<QuestionBase*> FinlandQuestions;
	std::vector<QuestionBase*> IcelandQuestions;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
