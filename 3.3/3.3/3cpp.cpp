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
		if (array[i] == array[i - 1])
		{
			quantity++;
			if ((i == length - 1) && (quantity >= more))
			{
				element = array[i];
			}
		}
		else
		{
			if (quantity >= more)
			{
				more = quantity;
				element = array[i - 1];
				quantity = 1;
			}
		}
	}

	return element;
}

bool test1()
{
	const int length = 9;
	int array[length] = { 1, 2, 3, 2, 9, 9, 2, 1, 2 };
	
	return searching(array, length) == 2;
}

bool test2()
{
	const int length = 8;
	int array[length] = { 1, 2, 3, 4, 4, 5, 5, 5 };

	return searching(array, length) == 5;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Выполняется проверка тестов:" << endl;
	if (test1() && test2())
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

	cout << "Искомый элемент: " << element << endl;

	delete[] array;
	return 0;
}