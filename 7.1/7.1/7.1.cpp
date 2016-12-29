#include "tree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "����������:" << endl;
	cout << "0 - �����" << endl;
	cout << "1 - �������� �������" << endl;
	cout << "2 - ������� ��������" << endl;
	cout << "3 - ���������, ����������� �� �������� ������" << endl;
	cout << "4 - ����������� �� �����������" << endl;
	cout << "5 - ����������� �� ��������" << endl;

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
				cout << "������� � ������ ��������� ������������ � ������" << endl;
			}
			else
			{
				cout << "������� � ������ ��������� �� ������������ � ������" << endl;
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
			cout << "������ ����������";
		}
	}

	deleteTree(tree);
	return 0;
}