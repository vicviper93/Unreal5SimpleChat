// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestCPPLib.h"

TArray<int32> UMyTestCPPLib::GetRandom()
{
    TArray<int32> Numbers;

    for (int32 i = 1; i <= 9; i++)
    {
        Numbers.Add(i);
    }

    TArray<int32> Result;

    for (int32 i = 0; i < 3; i++)
    {
        int32 RandomIndex = FMath::RandRange(0, Numbers.Num() - 1);
        Result.Add(Numbers[RandomIndex]);
        Numbers.RemoveAt(RandomIndex);
    }

    return Result;
}
bool UMyTestCPPLib::JudgeNumber(const TArray<int32>& SecretNumber, const TArray<int32>& PlayerNumber, int32& OutStrikeCount, int32& OutBallCount)
{
    OutStrikeCount = 0;
    OutBallCount = 0;

    if (SecretNumber.Num() != 3 || PlayerNumber.Num() != 3)
    {
        return false;
    }

    TSet<int32> SecretSet;
    TSet<int32> PlayerSet;

    for (int32 Num : SecretNumber)
    {
        if (Num < 1 || Num > 9)
        {
            return false;
        }
        if (SecretSet.Contains(Num))
        {
            return false;
        }
        SecretSet.Add(Num);
    }

    for (int32 Num : PlayerNumber)
    {
        if (Num < 1 || Num > 9)
        {
            return false;
        }
        if (PlayerSet.Contains(Num))
        {
            return false;
        }
        PlayerSet.Add(Num);
    }

    for (int32 i = 0; i < 3; i++)
    {
        if (SecretNumber[i] == PlayerNumber[i])
        {
            OutStrikeCount++; 
        }
        else if (SecretNumber.Contains(PlayerNumber[i]))
        {
            OutBallCount++;
        }
    }

    return true;
}