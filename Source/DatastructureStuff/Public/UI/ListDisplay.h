// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ListDisplay.generated.h"

class ULinkedList;
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
private:
	UPROPERTY()
	float Offset = 0;

	UPROPERTY()
	float WidgetWidth;

protected:
	void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void OnWidgetRebuilt() override;


	UPROPERTY(EditAnywhere, Category = "List")
	ULinkedList* Content;

	UPROPERTY(EditAnywhere, Category = "UI")
	float DisplayTime = 15;


	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UHorizontalBox* DataDisplay;

	/*UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UDataCard> DataDisplayClass;*/

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UButton* InputTextButton;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UEditableTextBox* TextInput;

public:
	UFUNCTION()
	void TextCommit(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION()
	void BeginScroll();

};
