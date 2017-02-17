#include "hash.h"
#include "list.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int sizeOf = 255;

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream file("text.txt");
	if (!file.is_open())
	{
		cout << "Проблемы открытия файла" << endl << "Завершение работы." << endl;
	}
	else
	{
		auto hashTable = initialisation();

		string line;
		while (!file.eof())
		{
			file >> line;
			add(hashTable, line);
		}
	}

	file.close();

	for (int i = 0; i < sizeOf; ++i)
	{
		if (hashTable->head[i] != nullptr)
		{
			print(hashTable->head[i]);
		}
	}

	cout << "Коэффициент заполнения равен: " << loadFactor(hashTable) << endl;
	cout << "Максимальная длина списка равна: " << maxLength(hashTable) << endl;
	cout << "Средняя длина списка равна: " << midLength(hashTable) << endl;

	for (int i = 0; i < sizeOf; i++)
	{
		deleteFromHead(hashTable->head[i]);
	}

	delete hashTable;

	return 0;
}