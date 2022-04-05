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
	AllQuestions.push_back(new MultipleChoiceQuestion("What is the main capital of Norway?", std::vector<std::string>{"Bergen", "Oslo", "Trondheim", "Helsinki"}, 1, "Norway", "That's right!", "Sorry, that's not correct.", 0, false));
	for (int i = 0; i < AllQuestions.size(); i++) {
		if (AllQuestions[i]->AssociatedCountry == "Norway") {
			NorwayQuestions.push_back(AllQuestions[i]);
		}
		if (AllQuestions[i]->AssociatedCountry == "Sweden") {
			SwedenQuestions.push_back(AllQuestions[i]);
		}
		if (AllQuestions[i]->AssociatedCountry == "Denmark") {
			DenmarkQuestions.push_back(AllQuestions[i]);
		}
		if (AllQuestions[i]->AssociatedCountry == "Finland") {
			FinlandQuestions.push_back(AllQuestions[i]);
		}
		if (AllQuestions[i]->AssociatedCountry == "Iceland") {
			IcelandQuestions.push_back(AllQuestions[i]);
		}
	}
}

// Called every frame
void AQuestionsManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

