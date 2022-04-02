// Copyright Epic Games, Inc. All Rights Reserved.


#include "AtlastGameModeBase.h"
#include "Achievements.h"
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

void AAtlastGameModeBase::CountryClicked(ACountry* SelectedCountry, ALandmark* SelectedLandmark)
{
	for (int i = 0; i < AllCountries.Num(); i++) {
		if (static_cast<ACountry*>(AllCountries[i]) != SelectedCountry) {
			static_cast<ACountry*>(AllCountries[i])->Highlighted = false;
		}
	}
	for (int i = 0; i < AllLandmarks.Num(); i++) {
		if (SelectedLandmark) {
			if (static_cast<ALandmark*>(AllLandmarks[i]) != SelectedLandmark) {
				static_cast<ALandmark*>(AllLandmarks[i])->Highlighted = false;
			}
		}
		else {
			static_cast<ALandmark*>(AllLandmarks[i])->Highlighted = false;
		}
	}
}