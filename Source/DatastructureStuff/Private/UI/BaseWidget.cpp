// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseWidget.h"
#include "Core/CppQueue.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/HorizontalBox.h"
#include "Components/Button.h"
#include "UI/DataCard.h"

void UBaseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	AddDataButton->OnClicked.AddDynamic(this, &UBaseWidget::AddRandom);
	RemoveDataButton->OnClicked.AddDynamic(this, &UBaseWidget::RemoveData);
	Content = NewObject<UCppQueue>();
}

void UBaseWidget::DisplayContent()
{
	if (!DataDisplayClass)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("No valid data display widget assigned"));
		return;
	}
	
	DataDisplay->ClearChildren();
	TArray<int32> DataReadout = Content->ReadContainer();
	for (int32 val : DataReadout)
	{
		UDataCard* NewWidget = CreateWidget<UDataCard>(this, DataDisplayClass);
		DataDisplay->AddChild(NewWidget);
		NewWidget->SetDisplay(val);
	}
}

void UBaseWidget::AddRandom()
{
	if (ICppQueueInterface* ContentReference = Cast<ICppQueueInterface>(Content))
	{
		ContentReference->Execute_Enqueue(Content, FMath::RandRange(1, 128));
	}
	DisplayContent();
}

void UBaseWidget::RemoveData()
{
	if (ICppQueueInterface* ContentReference = Cast<ICppQueueInterface>(Content))
	{
		ContentReference->Execute_Dequeue(Content);
	}
	DisplayContent();
}
