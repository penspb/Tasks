#include "qSort.h"
#include <iostream>
#include <fstream>

using namespace std;

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

bool test()
{
	const int length = 9;
	int array[length] = { 1, 2, 3, 2, 9, 9, 2, 1, 2 };

	return searching(array, length) == 2;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Выполняется проверка тестов:" << endl;
	if (test())
	{
		cout << "Запуск программы" << endl << endl;
	}
	else
	{
		cout << "Проблемы. Остановка программы" << endl;
		return 0;
	}

	FILE *ptrFile = fopen("f.txt", "r");

	int length = 0;
	cout << "Введите количество элементов в массиве:" << endl;
	cin >> length;

	int *array = new int[length];

	cout << "Введите массив:" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}
	fclose(ptrFile);

	int element = searching(array, length);

	cout << "Искомый элемент: " << element;

	delete[] array;

	return 0;
}