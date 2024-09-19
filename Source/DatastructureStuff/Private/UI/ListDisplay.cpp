// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ListDisplay.h"
#include "Core/LinkedList.h"
#include "Core/Node.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"

void UListDisplay::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	//TextInput->OnTextCommitted.AddDynamic(this, &UListDisplay::NewTextCommited);

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
			Offset = WidgetWidth;
		}
		DataDisplay->SetRenderTransform(FWidgetTransform(FVector2D(Offset, 0), FVector2D::UnitVector, FVector2D::ZeroVector, 0));
	}
}


void UListDisplay::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();
	ForceLayoutPrepass();
	WidgetWidth = DataDisplay->GetDesiredSize().X;

	Offset = WidgetWidth;
}


//void UListDisplay::NewTextCommited(const FText& InText, ETextCommit::Type CommitMethod)
//{
//	if (!Content)
//		return;
//
//	Content->Append(InText.ToString());
//	if (DataDisplay->GetText().IsEmptyOrWhitespace())
//	{
//		DataDisplay->SetText(FText::FromString(Content->Current->Data));
//		DataDisplay->ForceLayoutPrepass();
//		Offset = WidgetWidth;
//	}
//}