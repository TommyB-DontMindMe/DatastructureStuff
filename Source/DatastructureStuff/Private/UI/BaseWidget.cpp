// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseWidget.h"
#include "Core/CppQueue.h"
#include "Core/CppStack.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/HorizontalBox.h"
#include "Components/Button.h"
#include "UI/DataCard.h"
#include "Animation/WidgetAnimation.h"

void UBaseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	AddDataButton->OnClicked.AddDynamic(this, &UBaseWidget::AddRandom);
	RemoveDataButton->OnClicked.AddDynamic(this, &UBaseWidget::RemoveData);
	SwitchModeButton->OnClicked.AddDynamic(this, &UBaseWidget::SwitchMode);
	Content = NewObject<UCppQueue>();
	AltContent = NewObject<UCppStack>();

	StackSwitch = false;
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
	TArray<int32> DataReadout = StackSwitch? AltContent->ReadContainer() : Content->ReadContainer();
	for (int32 val : DataReadout)
	{
		UDataCard* NewWidget = CreateWidget<UDataCard>(this, DataDisplayClass);
		DataDisplay->AddChild(NewWidget);
		NewWidget->SetDisplay(val);
		NewWidget->PlayAnimation(NewWidget->OpenAnimation);
	}
}

void UBaseWidget::AddRandom()
{
	if (StackSwitch)
	{
		if (ICppStackInterface* ContentReference = Cast<ICppStackInterface>(AltContent))
		{
			ContentReference->Execute_Push(AltContent, FMath::RandRange(1, 99));
		}
	}
	else if (ICppQueueInterface* ContentReference = Cast<ICppQueueInterface>(Content))
	{
		ContentReference->Execute_Enqueue(Content, FMath::RandRange(1, 99));
	}
	DisplayContent();
}

void UBaseWidget::RemoveData()
{
	if (StackSwitch)
	{
		if (ICppStackInterface* ContentReference = Cast<ICppStackInterface>(AltContent))
		{
			ContentReference->Execute_Pop(AltContent);
		}
	}
	else if (ICppQueueInterface* ContentReference = Cast<ICppQueueInterface>(Content))
	{
		ContentReference->Execute_Dequeue(Content);
	}
	DisplayContent();
}

void UBaseWidget::SwitchMode()
{
	StackSwitch = !StackSwitch;
	DisplayContent();
}
