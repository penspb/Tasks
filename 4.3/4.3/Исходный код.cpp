#include <iostream>
#include <string>
#include <fstream>
#include <io.h>

using namespace std;

struct phoneBook
{
	string name;
	string number;
};

void add(phoneBook array[], int quantity)
{
	string name;
	string phone;
	cin >> name;
	cin >> phone;

	int i = 0;

	while ((array[i].name < name) && (i < quantity))
	{
		i++;
	}

	for (int j = quantity - 1; j >= i; j--)
	{
		array[j + 1].name = array[j + 1].name;
		array[j + 1].number = array[j + 1].number;
	}

	array[i].name = name;
	array[i].number = phone;
}

void print(phoneBook array[], int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		cout << array[i].name << " " << array[i].number << endl;
	}
}

void findingNumber(phoneBook array[], int quantity)
{
	string name;
	cin >> name;

	bool check = false;
	for (int i = 0; i < quantity; i++)
	{
		if (array[i].name == name)
		{
			cout << "Искомый номер: " << array[i].number << endl;
			check = true;
			return;
		}
	}

	if (check == 0)
	{
		cout << "Номера нет в телефонной книге" << endl;
	}
}

void findingName(phoneBook array[], int quantity)
{
	string number;
	cin >> number;

	bool check = false;
	for (int i = 0; i < quantity; i++)
	{
		if (array[i].number == number)
		{
			cout << "Абонент: " << array[i].name << endl;
			check = true;
			return;
		}
	}

	if (!check)
	{
		cout << "Телефонная книга не содержит данных об абоненте" << endl;
	}
}

void save(phoneBook array[], int quantity)
{
	FILE *ptrFile = fopen("retext.txt", "w");
	if (!access("text.txt", 0))
	{
		for (int i = 0; i < quantity; i++)
		{
			cout << array[i].name << " " << array[i].number << endl;
		}
	}

	fclose(ptrFile);
}

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