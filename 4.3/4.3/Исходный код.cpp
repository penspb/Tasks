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

	cout << "Управление:" << endl;
	cout << "0 - выйти" << endl;
	cout << "1 - добавить запись(имя и телефон)" << endl;
	cout << "2 - распечатать все имеющиеся записи" << endl;
	cout << "3 - найти телефон по имени" << endl;
	cout << "4 - найти имя по телефону" << endl;
	cout << "5 - сохранить текущие данные в файл" << endl;

	int quantity = 0;

	FILE *ptrFile = fopen("text.txt", "r");

	if (!access("text.txt", 0))
	{
		while (!feof(ptrFile))
		{
			add(workingArray, quantity);
			quantity++;
		}
	}

	fclose(ptrFile);

	bool check = true;

	while (check)
	{
		int option = 0;
		cin >> option;
		switch (option)
		{
			case 0:
				check = false;
				break;

			case 1:
				add(workingArray, quantity);
				quantity++;
				break;

			case 2:
				print(workingArray, quantity);
				break;

			case 3:
				findingNumber(workingArray, quantity);
				break;

			case 4:
				findingName(workingArray, quantity);
				break;

			case 5:
				save(workingArray, quantity);
				break;

			default:
				cout << "Ошибка исполнения";
		}
	}
	return 0;
}