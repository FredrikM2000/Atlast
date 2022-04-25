// Fill out your copyright notice in the Description page of Project Settings.


#include "Landmark.h"
#include "Kismet/GameplayStatics.h"
#include "Atlast/AtlastGameModeBase.h"

// Sets default values
ALandmark::ALandmark()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALandmark::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALandmark::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALandmark::ActivateQuiz()
{
	Cast<AAtlastGameModeBase>(UGameplayStatics::GetGameMode(this))->FillQuestionPool(InternalName);
}
