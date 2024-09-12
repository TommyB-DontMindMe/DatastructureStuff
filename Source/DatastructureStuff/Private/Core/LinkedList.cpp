// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/LinkedList.h"
#include "Core/Node.h"

void ULinkedList::Append(FString Input)
{
	if (!Head)
	{
		Head = NewObject<UNode>();
		Head->Data = Input;
	}
	else
	{
		Current = Head;
		while (Current->Next)
		{
			Current = Current->Next;
		}
		Current->Next = NewObject<UNode>();
		Current = Current->Next;
		Current->Data = Input;

	}
}

void ULinkedList::Prepend(FString Input)
{
	if (!Head)
	{
		Head = NewObject<UNode>();
		Head->Data = Input;
	}
	else
	{
		Current = NewObject<UNode>();
		Current->Data = Input;

		Current->Next = Head;
		Head = Current;
	}
}

void ULinkedList::DeleteWithValue(FString Subject)
{
	if (!Head)
		return;

	if (Head->Data == Subject)
	{
		if (Head->Next)
		{
			Head = Head->Next;
		}
		else
		{
			Head = nullptr;
		}
	}
	else
	{
		Current = Head;
		while (Current->Next)
		{
			if (Current->Next->Data == Subject)
			{
				if (Current->Next->Next)
				{
					Current = Current->Next->Next;
				}
				else
				{
					Current->Next = nullptr;
				}
			}
			else
			{
				Current = Current->Next;
			}
		}
	}
}

TArray<FString> ULinkedList::OutputContent()
{
	return TArray<FString>();
}
