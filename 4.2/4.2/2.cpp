#include <iostream>
#include "binary.h"
#include <fstream>

using namespace std;

bool test()
{
	const int length = 9;
	int array[length] = {1, 2, 3, 2, 9, 9, 2, 1, 2};
	if (searching(array, length) == 2)
	{
		return true;
	}
	return false;
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