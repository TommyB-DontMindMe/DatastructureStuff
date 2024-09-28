// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InsertionSort.generated.h"

/**
 * 
 */
UCLASS()
class DATASTRUCTURESTUFF_API UInsertionSort : public UObject
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "Sorting")
	static TArray<int32> InsertionSort(TArray<int32> Subject);
};
