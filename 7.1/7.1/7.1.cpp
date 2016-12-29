#include "tree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Управление:" << endl;
	cout << "0 - выйти" << endl;
	cout << "1 - добавить зачение" << endl;
	cout << "2 - удалить значение" << endl;
	cout << "3 - проверить, принадлежит ли значение дереву" << endl;
	cout << "4 - распечатать по возрастанию" << endl;
	cout << "5 - распечатать по убыванию" << endl;

	Tree *working = nullptr;
	int reading = 0;
	bool checking = false;

	while (!checking)
	{
		cin >> reading;
		switch (reading)
		{
		case 0:
			checking = true;
			break;

		case 1:
		{
			int value1 = 0;
			cin >> value1;
			add(value1, working);
			break;
		}

		case 2:
		{
			int value2 = 0;
			cin >> value2;
			deleteValue(value2, working);
			break;
		}

		case 3:
		{
			int value = 0;
			cin >> value;
			if (searchValue(value, working))
			{
				cout << "Вершина с данным значением присутствует в дереве" << endl;
			}
			else
			{
				cout << "Вершина с данным значением не присутствует в дереве" << endl;
			}
			break;
		}

		case 4:
		{
			printFromMinToMax(working);
			break;
		}

		case 5:
		{
			printFromMaxToMin(working);
			break;
		}

		default:
			cout << "Ошибка исполнения";
		}
	}

	deleteTree(tree);
	return 0;
}