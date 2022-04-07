// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Components/Image.h"
#include "Country.h"
#include "GameFramework/Actor.h"
#include "Landmark.generated.h"

UCLASS()
class ATLAST_API ALandmark : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALandmark();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Information")
	FString Name;
	UPROPERTY(EditAnywhere, Category = "Information")
	FString Description;
//	UPROPERTY(EditAnywhere, Category = "Information")
//	class UImage* Photo;
	UPROPERTY(EditAnywhere, Category = "Information")
	ACountry* AssociatedCountry{ nullptr };

	void Clicked();
	bool Highlighted = false;

private:
	//UPROPERTY(VisibleAnywhere)
	//UStaticMeshComponent* BaseMesh;

	bool CountryHighlighted = false;

};
