// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyTestCPPLib.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLECHAT_API UMyTestCPPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Custom")
	static TArray<int32> GetRandom();
	UFUNCTION(BlueprintCallable, Category = "JudgeWinner")
	static bool JudgeNumber(const TArray<int32>& SecretNumber, const TArray<int32>& PlayerNumber, int32& OutStrikeCount, int32& OutBallCount);
};
