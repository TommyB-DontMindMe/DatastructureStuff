// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Node.generated.h"

/**
 * 
 */
UCLASS()
class DATASTRUCTURESTUFF_API UNode : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FString Data;

	UPROPERTY()
	UNode* Next;
	
};
