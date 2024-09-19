// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ListDisplay.generated.h"

class ULinkedList;
class UButton;
class UEditableTextBox;
class UTextBlock;

/**
 * 
 */
UCLASS()
class DATASTRUCTURESTUFF_API UListDisplay : public UUserWidget
{
	GENERATED_BODY()
private:
	UPROPERTY()
	float Offset = 0;

	UPROPERTY()
	float WidgetWidth = 10;

	UPROPERTY()
	float DisplayWidgetWidth;

protected:
	void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void OnWidgetRebuilt() override;

	UPROPERTY(EditAnywhere, Category = "List")
	ULinkedList* Content;

	UPROPERTY(EditAnywhere, Category = "UI")
	float DisplayTime = 15;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UWidget* DisplayPanel;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UTextBlock* DataDisplay;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UEditableTextBox* TextInput;

public:
	UFUNCTION()
	void NewTextCommited(const FText& InText, ETextCommit::Type CommitMethod);
};
