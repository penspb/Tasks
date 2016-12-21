#include <iostream>

using namespace std;

int partition(int workingArray[], int left, int right)
{
	int relative = 0;
	if (left == right - 1)
	{
		if (workingArray[left] > workingArray[right])
		{
			swap(workingArray[left], workingArray[right]);
		}
		return left;
	}

	if (((workingArray[left] >= workingArray[left + 1]) && (workingArray[left + 2] <= workingArray[left + 1]))
		|| ((workingArray[left] <= workingArray[left + 1]) && (workingArray[left + 2] <= workingArray[left + 1])))
	{
		relative = left + 1;
	}
	else
	{
		if (((workingArray[left] >= workingArray[left + 2]) && (workingArray[left + 1] <= workingArray[left + 2]))
			|| ((workingArray[left] <= workingArray[left + 2]) && (workingArray[left + 1] <= workingArray[left + 2])))
		{
			relative = left + 2;
		}
		else
		{
			relative = left;
		}
	}

	int pivot = workingArray[relative];
	int newLeft = left;
	for (int i = left; i < right; i++)
	{
		if (workingArray[i] <= pivot)
		{
			swap(workingArray[relative], workingArray[i]);
			newLeft++;
		}
	}
	swap(workingArray[relative], workingArray[right]);

	return newLeft;
}

void insertionSort(int workingArray[], int left, int right)
{
	for (int i = left; i <= right; i++)
	{
		int newI = i;
		while (workingArray[newI] <= workingArray[newI - 1])
		{
			if (newI != 0)
			{
				swap(workingArray[newI], workingArray[newI - 1]);
				newI--;
			}
		}
	}
}

void qsort(int workingArray[], int left, int right)
{
	if (right - left < 10)
	{
		insertionSort(workingArray, left, right);
	}
	else
	{
		if (left < right)
		{
			int border = partition(workingArray, left, right);
			qsort(workingArray, left, border - 1);
			qsort(workingArray, border, right);
		}
	}
}

bool test1()
{
	const int size = 12;
	int array[size] = { 1, 12, 2, 11, 3, 10, 4, 9, 5, 8, 6, 7 };
	qsort(array, 0, size - 1);
	for (int i = 1; i < size; i++)
	{
		if (array[i - 1] > array[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cout << "Checking tests:";
	if (test1)
	{
		cout << "The program works" << endl;
	}
	else
	{
		cout << "Errors" << endl;
		return 0;
	}
	cout << endl;

	int sizeOfArray = 0;
	cout << "Enter the size of array: ";
	cin >> sizeOfArray;
	int *basicArray = new int[sizeOfArray];
	cout << endl;

	cout << "Enter the array: ";
	for (int i = 0; i < sizeOfArray; i++)
	{
		cin >> basicArray[i];
	}

	cout << endl;

	int left = 0;
	int right = sizeOfArray - 1;

	qsort(basicArray, left, right);
	cout << "The result of quicksort: ";
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << basicArray[i] << ' ';
	}

	delete[] basicArray;
	cout << endl;
	return 0;
}