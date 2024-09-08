// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataCard.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class DATASTRUCTURESTUFF_API UDataCard : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UTextBlock* Data;

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetDisplay(int32 Input);
};
