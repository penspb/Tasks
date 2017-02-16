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
	for (int i = 0; i < quantity - 1; i++)
	{
		if (returnName(returnNext(working)) < returnName(working))
		{
			deletePhonebok(working);
			return false;
		}
		working = returnNext(working);
	}

	deletePhonebok(working);
	return true;
}

int main()
{
	if (!test())
	{
		cout << "Проблмы" << endl;
		return 0;
	}

	setlocale(LC_ALL, "Russian");
	Phonebook *working = nullptr;
	read(working);
	
	cout << "Если Вы желаете отсортировать телефонную книгу по именам, то введите 1. Иначе введите 0." << endl;
	cout << "Спасибо. Операция выполняется." << endl;

	int intsign = 0;
	cin >> intsign;

	bool sign = false;
	if (intsign == 1)
	{
		sign = true;
	}

	mergeSort(working, sign);
	print(working);

	deletePhonebok(working);

	return 0;
}