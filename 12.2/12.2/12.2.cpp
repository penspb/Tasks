#include<conio.h>
#include<iostream>
#include<fstream>

using namespace std;

int scan(int **array)
{
	ifstream file("text.txt");
	int size = 0;
	file >> size;

	const int maxWeight = 1000;
	array = new int*[size + 1];

	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			file >> array[i][j];
			if (array[i][j] == 0)
			{
				array[i][j] = maxWeight;
			}
		}
	}
	file.close();

	return size;
}

void spanningTree(int **result, int **array, int size)
{
	int begin = 1;
	int end = 1;
	int counter = 1;
	const int maxWeight = 1000;
	
	int min = 0;
	int minCost = 0;
	int visited[10] = { 0 };
	visited[1] = 1;
	cout << endl;

	int path[100] = { 0 };
	int indexOfPath = 0;

	while (counter < size)
	{
		min = maxWeight;
		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)
			{
				if (array[i][j] < min)
				{
					if (visited[i] != 0)
					{
						min = array[i][j];
						begin = i;
						end = j;
					}
				}
			}
			if (visited[begin] == 0 || visited[end] == 0)
			{
				path[indexOfPath] = end;
				indexOfPath;

				result[counter][0] = begin;
				result[counter][1] = end;
				
				counter++;
				minCost += min;
				visited[end] = 1;

				array[begin][end] = maxWeight;
				array[end][begin] = maxWeight;
				cout << endl;
			}
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");

	int **array;
	int size = scan(array);

	int **result;
	result = new int*[size + 1];

	spanningTree(result, array, size);

	for (int i = 1; i <= size; i++)
	{
		cout << result[i][0] << " " << result[i][1] << endl;
	}

	for (int i = 0; i <= size; i++)
	{
		delete array[i];
		delete result[i];
	}
	delete array;
	delete result;

	return 0;
}