// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CppStack.h"

void UCppStack::Push_Implementation(int32 Data)
{
	Container.EmplaceAt(0, Data);
}

int32 UCppStack::Pop_Implementation()
{
	if (Container.IsEmpty())
		return 0;

	int32 Output = Container[0];
	Container.RemoveAt(0);
	return Output;
}

int32 UCppStack::Top_Implementation()
{
	if (Container.IsEmpty())
		return 0;

	return Container[0];
}
