// Fill out your copyright notice in the Description page of Project Settings.


#include "Landmark.h"

// Sets default values
ALandmark::ALandmark()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//BaseMesh->SetupAttachment(RootComponent);
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
	//if (AssociatedCountry) {
	//	if (AssociatedCountry->Highlighted == true && CountryHighlighted == false) {
	//		CountryHighlighted = true;
	//	}
	//	else if (AssociatedCountry->Highlighted == false && CountryHighlighted == true) {
	//		CountryHighlighted = false;
	//	}
	//}
}

//void ALandmark::Clicked()
//{
//	if (Highlighted) {
//		//Bring up an information menu perhaps?
//	}
//	else {
//		Highlighted = true;
//		if (AssociatedCountry) {
//			if (AssociatedCountry->CurrentGameMode && AssociatedCountry->Highlighted == false) {
//				AssociatedCountry->Clicked(this);
//			}
//		}
//	}
//}

