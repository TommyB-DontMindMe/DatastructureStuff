// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/InsertionSort.h"

TArray<int32> UInsertionSort::InsertionSort(TArray<int32> Subject)
{
	int32 SubjectSize = Subject.Num();
	int32 bSorted = false;

	while (!bSorted)
	{
		for (size_t i = 1; i < SubjectSize; i++)
		{
			bSorted = true;
			if (Subject[i] < Subject[i - 1])
			{
				int32 Held = Subject[i - 1];
				Subject[i - 1] = Subject[i];
				Subject[i] = Held;
				bSorted = false;
			}
		}
	}
	
	return Subject;
}
