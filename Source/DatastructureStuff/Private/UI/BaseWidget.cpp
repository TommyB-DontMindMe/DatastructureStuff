// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseWidget.h"
#include "Algo/Reverse.h"
#include "Core/CppQueue.h"
#include "Core/CppStack.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/HorizontalBox.h"
#include "Components/Button.h"
#include "UI/DataCard.h"
#include "Components/TextBlock.h"
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
	
	
	DataDisplay->ClearChildren();
	TArray<int32> DataReadout = StackSwitch? AltContent->ReadContainer() : Content->ReadContainer();
	if (StackSwitch)
		Algo::Reverse(DataReadout);
	for (int32 val : DataReadout)
	{
		DisplayDataWidget(val);
	}
}

UDataCard* UBaseWidget::DisplayDataWidget(int32 Input)
{
	if (!DataDisplayClass)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("No valid data display widget assigned"));
		return nullptr;
	}

	UDataCard* NewWidget = CreateWidget<UDataCard>(this, DataDisplayClass);
	DataDisplay->InsertChildAt(StackSwitch ? 0 : DataDisplay->GetChildrenCount(), NewWidget);
	
	NewWidget->SetDisplay(Input);
	NewWidget->PlayAnimation(NewWidget->OpenAnimation);

	return NewWidget;
}

void UBaseWidget::RemoveDataWidget()
{
	if (!DataDisplay->HasAnyChildren())
		return;

	DataDisplay->RemoveChildAt(0);
}

void UBaseWidget::AddRandom()
{
	int32 Random = FMath::RandRange(1, 99);
	if (StackSwitch)
	{
		if (ICppStackInterface* ContentReference = Cast<ICppStackInterface>(AltContent))
		{
			ContentReference->Execute_Push(AltContent, Random);
		}
	}
	else if (ICppQueueInterface* ContentReference = Cast<ICppQueueInterface>(Content))
	{
		ContentReference->Execute_Enqueue(Content, Random);
	}
	DisplayDataWidget(Random);
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
	RemoveDataWidget();
}

void UBaseWidget::SwitchMode()
{
	StackSwitch = !StackSwitch;
	if (StackSwitch)
	{
		AddButtonText->SetText(FText::FromString("Push"));
		RemoveButtonText->SetText(FText::FromString("Pop"));
	}
	else
	{
		AddButtonText->SetText(FText::FromString("Enqueue"));
		RemoveButtonText->SetText(FText::FromString("Dequeue"));
	}
	DisplayContent();
}
