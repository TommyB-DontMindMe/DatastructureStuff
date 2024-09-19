// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ListDisplay.h"
#include "Core/LinkedList.h"
#include "Core/Node.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Types/SlateEnums.h"
#include "Components/TextBlock.h"

void UListDisplay::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	TextInput->OnTextCommitted.AddDynamic(this, &UListDisplay::NewTextCommited);

	if (!Content)
	{
		Content = NewObject<ULinkedList>();
	}
}


void UListDisplay::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (Content->Current)
	{
		Offset -= InDeltaTime * WidgetWidth / DisplayTime;

		if (Offset <= -DisplayWidgetWidth)
		{
			DataDisplay->SetText(FText::FromString(Content->Current->Data));
			Content->Step();
			DataDisplay->ForceLayoutPrepass();
			DisplayWidgetWidth = DataDisplay->GetDesiredSize().X;

			Offset = WidgetWidth;
		}
		DataDisplay->SetRenderTransform(FWidgetTransform(FVector2D(Offset, 0), FVector2D::UnitVector, FVector2D::ZeroVector, 0));

	}
}


void UListDisplay::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();
	DisplayPanel->ForceLayoutPrepass();
	WidgetWidth = DisplayPanel->GetDesiredSize().X;

	Offset = WidgetWidth;
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("The text display is: %f pixels wide"), WidgetWidth));
}


void UListDisplay::NewTextCommited(const FText& InText, ETextCommit::Type CommitMethod)
{
	if (!Content)
		return;

	Content->Append(InText.ToString());
	if (DataDisplay->GetText().IsEmptyOrWhitespace())
	{
		DataDisplay->SetText(FText::FromString(Content->Current->Data));
		DataDisplay->ForceLayoutPrepass();
		DisplayWidgetWidth = DataDisplay->GetDesiredSize().X;
		Offset = WidgetWidth;
	}

	WidgetWidth = DisplayPanel->GetCachedGeometry().GetAbsoluteSize().X;
}