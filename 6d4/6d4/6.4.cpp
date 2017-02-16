#include "sort.h"
#include "phonebook.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool test()
{
	Phonebook *working = nullptr;

	push(working, "Ben", "90912");
	push(working, "Cate", "91405");
	push(working, "Ann", "91124");
	push(working, "Sam", "98135");
	mergeSort(working, true);

	const int quantity = 4;

	Phonebook *newList = working;
	for (int i = 0; i < quantity - 1; i++)
	{
		if (returnName(returnNext(newList)) < returnName(newList))
		{
			deletePhonebook(working);
			return false;
		}
		newList = returnNext(newList);
	}

	deletePhonebook(working);
	return true;
}

int main()
{
	if (!test())
	{
		cout << "��������" << endl;
		return 0;
	}

	setlocale(LC_ALL, "Russian");
	Phonebook *working = nullptr;
	read(working);

	cout << "���� �� ������� ������������� ���������� ����� �� ������, �� ������� 1. ����� ������� 0." << endl;
	cout << "�������. �������� �����������." << endl;

	int intSign = 0;
	cin >> intSign;

	bool sign = false;
	if (intSign == 1)
	{
		sign = true;
	}

	mergeSort(working, sign);
	print(working);

	deletePhonebook(working);

	return 0;
}