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

	cout << "”правление:" << endl;
	cout << "0 - выйти" << endl;
	cout << "1 - добавить запись(им€ и телефон)" << endl;
	cout << "2 - распечатать все имеющиес€ записи" << endl;
	cout << "3 - найти телефон по имени" << endl;
	cout << "4 - найти им€ по телефону" << endl;
	cout << "5 - сохранить текущие данные в файл" << endl;

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

			cout << "¬ведите дааные:" << endl;
			cin >> name;
			cin >> phone;

			add(workingArray, quantity, name, phone);
			quantity++;
			break;

		case 2:
			print(workingArray, quantity);
			break;

		case 3:

			cout << "¬ведите им€ искомого абонента:" << endl;
			cin >> name;
			findingNumber(workingArray, quantity, name);
			break;

		case 4:
			cout << "¬ведите номер искомого абонента:" << endl;
			cin >> phone;
			findingName(workingArray, quantity, phone);
			break;

		case 5:
			save(workingArray, quantity);
			break;

		default:
			cout << "ќшибка исполнени€";
		}
	}
	return 0;
}