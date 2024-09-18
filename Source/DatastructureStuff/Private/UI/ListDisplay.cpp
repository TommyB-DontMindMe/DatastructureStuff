// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ListDisplay.h"
#include "Core/LinkedList.h"
#include "Core/Node.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/HorizontalBox.h"

void UListDisplay::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	TextInput->OnTextCommitted.AddDynamic(this, &UListDisplay::TextCommit);

	if (!Content)
	{
		Content = NewObject<ULinkedList>();
	}
}

void UListDisplay::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (DataDisplay->GetChildrenCount() > 1)
	{
		Offset -= InDeltaTime * WidgetWidth / DisplayTime;
		

		float FirstChildWidth = DataDisplay->GetChildAt(0)->GetDesiredSize().X;
		if (Offset <= -FirstChildWidth)
		{
			Offset += FirstChildWidth;
			DataDisplay->RemoveChildAt(0);
		}
		DataDisplay->SetRenderTransform(FWidgetTransform(FVector2D(Offset, 0), FVector2D::UnitVector, FVector2D::ZeroVector, 0));
	}
}

void UListDisplay::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();
	ForceLayoutPrepass();
	WidgetWidth = DataDisplay->GetDesiredSize().X;

	BeginScroll();
}



void UListDisplay::TextCommit(const FText& Text, ETextCommit::Type CommitMethod)
{
	if (!Content)
		return;
	
	Content->Append(Text.ToString());
}

void UListDisplay::BeginScroll()
{
	Offset = WidgetWidth;
}
