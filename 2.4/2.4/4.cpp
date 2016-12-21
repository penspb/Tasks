#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
	srand(time(nullptr));

	const int sizeOfArray = 16;
	int workingArray[sizeOfArray] = {};
	for (int i = 0; i < sizeOfArray; i++)
	{
		workingArray[i] = rand();
		cout << workingArray[i] << ' ';
	}

	int first = 0;

	for (int i = 1; i < sizeOfArray; i++)
	{
		if ((workingArray[i] < workingArray[first]) && (first == i - 1))
		{
			swap(workingArray[i], workingArray[first]);
			first++;
		}
		else
		{
			{
				if ((workingArray[i] < workingArray[first]) && (i - first > 1))
				{
					int q = workingArray[first];
					workingArray[first] = workingArray[i];
					workingArray[i] = workingArray[first + 1];
					workingArray[first + 1] = q;
					first++;
				}
			}
		}
	}

	cout << endl;

	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << workingArray[i] << ' ';
	}
	cout << endl;
	return 0;
}