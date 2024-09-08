// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CppQueue.h"

void UCppQueue::Enqueue_Implementation(int32 Data)
{
	Container.Emplace(Data);
}

int32 UCppQueue::Dequeue_Implementation()
{
	if (Container.IsEmpty())
		return 0;

	int32 Output = Container[0];
	Container.RemoveAt(0);
	return Output;
}

int32 UCppQueue::Front_Implementation()
{
	if (Container.IsEmpty())
		return 0;

	return Container[0];
}

TArray<int32> UCppQueue::ReadContainer()
{
	return Container;
}
