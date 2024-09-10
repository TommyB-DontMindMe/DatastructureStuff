// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Core/CppStackInterface.h"
#include "CppStack.generated.h"

/**
 * 
 */
UCLASS()
class DATASTRUCTURESTUFF_API UCppStack : public UObject, public ICppStackInterface
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	TArray<int32> Container;

public:
	// CppStackinterface Implementation
	void Push_Implementation(int32 Data) override;
	int32 Pop_Implementation() override;
	int32 Top_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Queue")
	TArray<int32> ReadContainer();
};
