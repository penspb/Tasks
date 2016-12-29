#include <iostream>
#include <fstream>

using namespace std;

void showTown(int *town, int quantityOfTown, int quantityOfCapital)
{
	for (int i = 1; i <= quantityOfCapital; i++)
	{
		cout << "Государство " << " " << i << ": ";
		for (int j = 1; j <= quantityOfTown; j++)
		{
			if (town[j] == i)
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
}

bool freeTown(int *town, int quantityOfTown)
{
	for (int i = 1; i <= quantityOfTown; i++)
	{
		if (town[i] == 0)
		{
			return true;
		}
	}
	return false;
}


void addTown(int *town, int **road, int quantityOfTown, int k)
{
	int num = 0;
	int minRoad = 0;

	for (int i = 1; i <= quantityOfTown; i++)
	{
		if (town[i] == 0)
		{
			for (int j = 1; j <= quantityOfTown; j++)
			{
				if ((i != j) && (town[j] == k) && (road[i][j] != 0))
				{
					if (minRoad == 0 || minRoad > road[i][j])
					{
						num = i;
						minRoad = road[i][j];
					}
				}
			}
		}
	}

	if (num != 0) 
	{
		town[num] = k;
	}
}

void result(int *town, int **road, int quantityOfTown, int quantityOfCapital)
{
	while (freeTown(town, quantityOfTown))
	{
		for (int i = 1; i <= quantityOfCapital; i++)
		{
			addTown(town, road, quantityOfTown, i);
		}
	}
}

void clean(int *town, int **road, int quantityOfTown)
{
	for (int i = 0; i <= quantityOfTown; i++)
	{
		delete road[i];
	}

	delete road;
	delete town;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int quantityOfTown = 0;
	int quantityOfRoad = 0;
	int quantityOfCapital = 0;

	ifstream file("text.txt");

	if (!file.is_open())
	{
		cout << "Проблемы с открытием файла" << endl;
	}
	else 
	{
		file >> quantityOfTown >> quantityOfRoad;

		int **road = 0;
		road = new int*[quantityOfTown + 1];

		for (int i = 0; i <= quantityOfTown; i++)
		{
			road[i] = new int[quantityOfTown + 1];
		}
		
		for (int i = 0; i <= quantityOfTown; i++)
		{
			for (int j = 0; j <= quantityOfTown; j++)
			{
				road[i][j] = 0;
			}
		}

		int *town = 0;
		town = new int[quantityOfTown + 1];

		for (int i = 0; i <= quantityOfTown; i++)
		{
			town[i] = 0;
		}

		int i = 0;
		int j = 0;
		int len = 0;

		for (int k = 0; k < quantityOfRoad; k++)
		{
			file >> i >> j >> len;
			road[i][j] = len; 
			road[j][i] = len;
		}
		
		file >> quantityOfCapital;

		int cap = 0;
		
		for (int z = 1; z <= quantityOfCapital; z++)
		{
			file >> cap; 
			town[cap] = z; 
		}

		file.close();

		result(town, road, quantityOfTown, quantityOfCapital);

		cout << endl << "Итоговое распределение:" << endl;
		showTown(town, quantityOfTown, quantityOfCapital);
		
	
		clean(town, road, quantityOfTown);
	}
	return 0;
}