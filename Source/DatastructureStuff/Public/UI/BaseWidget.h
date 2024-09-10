// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"

class UCppQueue;
class UCppStack;
class UDataCard;
class UCanvasPanel;
class UHorizontalBox;
class UButton;

/**
 * 
 */
UCLASS()
class DATASTRUCTURESTUFF_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	void NativeOnInitialized() override;

	UPROPERTY()
	UCppQueue* Content;

	UPROPERTY()
	UCppStack* AltContent;

	UPROPERTY()
	bool StackSwitch;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UDataCard> DataDisplayClass;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UCanvasPanel* RootCanvas;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UHorizontalBox* DataDisplay;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UButton* AddDataButton;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UButton* RemoveDataButton;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UButton* SwitchModeButton;

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	void DisplayContent();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void AddRandom();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void RemoveData();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void SwitchMode();
};
