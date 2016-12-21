#include <iostream>
#include "binary.h"
#include <fstream>

using namespace std;

void partition(int array[], int &left, int &right)
{
	int i = left;
	int j = right;
	int relative0 = 0;

	int pivot = array[(left + right) / 2];

	while (i <= j)
	{
		while (array[i] < pivot)
		{
			i++;
		}
		while (array[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			relative0 = array[i];
			array[i] = array[j];
			array[j] = relative0;
			i++;
			j--;
		}
	}
	left = i;
	right = j;
}

void qSort(int array[], int left, int right)
{
	int i = left;
	int j = right;

	partition(array, left, right);

	if (left < j)
	{
		qSort(array, left, j);
	}
	if (i < right)
	{
		qSort(array, i, right);
	}
}

int searching(int array[], int length)
{
	qSort(array, 0, length - 1);

	int quantity = 1;
	int more = 1;
	int element = array[0];

	for (int i = 1; i < length; i++)
	{
		if (array[i] == array[i - 1])
		{
			quantity++;
		}
		else
		{
			if (quantity > more)
			{
				more = quantity;
				element = array[i - 1];
			}
			quantity = 1;
		}
	}

	return element;
}