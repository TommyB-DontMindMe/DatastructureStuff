// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Core/CppQueueInterface.h"
#include "CppQueue.generated.h"

/**
 * 
 */
UCLASS()
class DATASTRUCTURESTUFF_API UCppQueue : public UObject, public ICppQueueInterface
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	TArray<int32> Container = {};

public:
	// CppInterfaceImplementation
	virtual void Enqueue_Implementation(int32 Data) override;
	virtual int32 Dequeue_Implementation() override;
	virtual int32 Front_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Queue")
	TArray<int32> ReadContainer();
	
};
