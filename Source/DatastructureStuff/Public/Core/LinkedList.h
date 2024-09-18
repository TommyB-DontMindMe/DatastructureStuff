// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LinkedList.generated.h"

class UNode;

/**
 * 
 */
UCLASS()
class DATASTRUCTURESTUFF_API ULinkedList : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UNode* Head;

	UPROPERTY()
	FString Data;

	UPROPERTY()
	UNode* Current;


	UFUNCTION(BlueprintCallable, Category = "List")
	void Append(FString Input);

	UFUNCTION(BlueprintCallable, Category = "List")
	void Prepend(FString Input);

	UFUNCTION(BlueprintCallable, Category = "List")
	void DeleteWithValue(FString Subject);

	UFUNCTION(BlueprintCallable, Category = "List")
	void Step(int32 Steps = 1);

	UFUNCTION(BlueprintCallable, Category = "List")
	TArray<FString> OutputContent();
};
