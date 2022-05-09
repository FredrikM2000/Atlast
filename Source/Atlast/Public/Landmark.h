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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FText InternalName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FText Description;
//	UPROPERTY(EditAnywhere, Category = "Information")
//	class UImage* Photo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	ACountry* AssociatedCountry{ nullptr };

	UFUNCTION(BlueprintCallable)
	void ActivateQuiz();

private:
	bool CountryHighlighted = false;

};
