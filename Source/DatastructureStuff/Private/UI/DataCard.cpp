// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataCard.h"
#include "Components/TextBlock.h"

void UDataCard::SetDisplay(int32 Input)
{
	Data->SetText(FText::FromString(FString::FromInt(Input)));
}
