#include <iostream>
#include <time.h>

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

bool scan(int array[], int length, int desiredNumber)
{
	int left = 0;
	int right = length - 1;
	int mean = (left + right) / 2;

	bool result = false;

	while ((!result) && (left <= right))
	{
		if (array[mean] == desiredNumber)
		{
			result = true;
		}
		else
		{
			if (desiredNumber < array[mean])
			{
				right = mean - 1;
				mean = (right + left) / 2;
			}
			else
			{
				left = mean + 1;
				mean = (right + left) / 2;
			}
		}
	}

	return result;
}

bool test()
{
	const int length = 9;
	int array[length] = { 1, 29, 102, 53, 38, 6, 272, 1037, 9 };
	qSort(array, 0, length - 1);

	if (scan(array, length, 29) && !scan(array, length, 100))
	{
		return true;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

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

	int n = 0;
	cout << "Введите n: " << endl;
	cin >> n;

	int *array = new int[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 1000;
	}

	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	qSort(array, 0, n - 1);

	int k = 0;
	cout << "Введите k: " << endl;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int number = rand() % 1000;
		cout << "Число " << number << " ";
		if (scan(array, n, number))
		{
			cout << "содержится в массиве" << endl;
		}
		else
		{
			cout << "не содержится в массиве" << endl;
		}
	}

	delete[] array;
	return 0;
}