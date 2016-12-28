#include "phonebook.h"
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int sizeOfArray = 100;
	phoneBook workingArray[sizeOfArray] = {};

	cout << "����������:" << endl;
	cout << "0 - �����" << endl;
	cout << "1 - �������� ������(��� � �������)" << endl;
	cout << "2 - ����������� ��� ��������� ������" << endl;
	cout << "3 - ����� ������� �� �����" << endl;
	cout << "4 - ����� ��� �� ��������" << endl;
	cout << "5 - ��������� ������� ������ � ����" << endl;

	int quantity = 0;
	read(workingArray, quantity);

	bool check = true;

	while (check)
	{
		string name = "";
		string phone = "";

		int option = 0;
		cin >> option;
		switch (option)
		{
		case 0:
			check = false;
			break;

		case 1:

			cout << "������� ������:" << endl;
			cin >> name;
			cin >> phone;

			add(workingArray, quantity, name, phone);
			quantity++;
			break;

		case 2:
			print(workingArray, quantity);
			break;

		case 3:

			cout << "������� ��� �������� ��������:" << endl;
			cin >> name;
			findingNumber(workingArray, quantity, name);
			break;

		case 4:
			cout << "������� ����� �������� ��������:" << endl;
			cin >> phone;
			findingName(workingArray, quantity, phone);
			break;

		case 5:
			save(workingArray, quantity);
			break;

		default:
			cout << "������ ����������";
		}
	}
	return 0;
}