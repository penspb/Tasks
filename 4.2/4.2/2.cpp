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

	cout << "����������� �������� ������:" << endl;
	if (test())
	{
		cout << "������ ���������" << endl << endl;
	}
	else
	{
		cout << "��������. ��������� ���������" << endl;
		return 0;
	}

	FILE *ptrFile = fopen("f.txt", "r");

	int length = 0;
	cout << "������� ���������� ��������� � �������:" << endl;
	cin >> length;

	int *array = new int[length];

	cout << "������� ������:" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}
	fclose(ptrFile);

	int element = searching(array, length);

	cout << "������� �������: " << element;

	delete[] array;

	return 0;
}