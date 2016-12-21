#include <iostream>

using namespace std;

void bubbleSort(int workingArray[], int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		for (int j = sizeOfArray - 1; j > i; j--)
		{
			if (workingArray[j - 1] > workingArray[j])
			{
				swap(workingArray[j], workingArray[j - 1]);
			}
		}
	}

}

void output(int workingArray[], int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << workingArray[i] << ' ';
	}
}

void countingSort(int workingArray[], int sizeOfArray)
{
	int maximumValue = workingArray[0];
	for (int i = 1; i < sizeOfArray; i++)
	{
		if (workingArray[i] > maximumValue)
		{
			maximumValue = workingArray[i];
		}
	}
	int *arrayOfValues = new int[maximumValue + 1];
	for (int i = 0; i < maximumValue + 1; i++)
	{
		arrayOfValues[i] = 0;
	}

	for (int i = 0; i < sizeOfArray; i++)
	{
		arrayOfValues[workingArray[i]]++;
	}

	int j = 0;
	for (int i = 0; i <= maximumValue; i++)
	{

		while (arrayOfValues[i] != 0)
		{
			workingArray[j] = i;
			j++;
			arrayOfValues[i]--;
		}
	}

	cout << endl;
	delete[] arrayOfValues;
}

int main()
{
	int sizeOfArray = 0;
	cout << "Enter the size of array" << endl;
	cin >> sizeOfArray;

	int *workingArray = new int[sizeOfArray];
	int *workingArray1 = new int[sizeOfArray];
	int *workingArray2 = new int[sizeOfArray];

	cout << "Enter the array" << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		cin >> workingArray[i];
		workingArray1[i] = workingArray[i];
		workingArray2[i] = workingArray[i];
	}

	bubbleSort(workingArray1, sizeOfArray);

	countingSort(workingArray2, sizeOfArray);

	cout << "The result of bubble sort:" << endl;
	output(workingArray1, sizeOfArray);

	cout << endl;
	cout << endl;

	cout << "The result of counting sort:" << endl;
	output(workingArray2, sizeOfArray);

	cout << endl;

	delete[] workingArray;
	delete[] workingArray1;
	delete[] workingArray2;

	return 0;
}