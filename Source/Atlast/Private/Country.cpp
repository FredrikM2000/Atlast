// Fill out your copyright notice in the Description page of Project Settings.


#include "Country.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACountry::ACountry()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Land = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Land->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACountry::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACountry::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

