// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProgressManager.generated.h"

UCLASS()
class ATLAST_API AProgressManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProgressManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	int64 Progress = 0;
	int64 Total = 100000;
	void Increase(int64 increase);
	float GetProgress();
	void Reset();
};
