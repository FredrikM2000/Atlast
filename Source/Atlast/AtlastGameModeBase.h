// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AtlastGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ATLAST_API AAtlastGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AAtlastGameModeBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<AActor*> AchievementSystem;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ClickAnywhere(int Clicks);

};
