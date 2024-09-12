// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ListDisplay.generated.h"

class UHorizontalBox;
class UButton;
class UEditableTextBox;

/**
 * 
 */
UCLASS()
class DATASTRUCTURESTUFF_API UListDisplay : public UUserWidget
{
	GENERATED_BODY()
protected:
	FTimerHandle DisplayLoop;

	int32 DisplayTime;


	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UHorizontalBox* DataDisplay;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UButton* ToggleInput;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UEditableTextBox* TextInput;

public:
	UFUNCTION()
	void ToggleInputBox();
};
