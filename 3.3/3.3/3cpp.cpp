#include <iostream>

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
		if (array[i] == element)
		{
			quantity++;
		}
		else
		{
			if (quantity >= more)
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
	if (searching(array, length) == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
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

	int length = 0;
	cout << "Введите количество элементов в массиве:" << endl;
	cin >> length;

	int *array = new int[length];

	cout << "Введите массив:" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}

	int element = searching(array, length);

	cout << "Искомый элемент: " << element;

	delete[] array;
	return 0;
}