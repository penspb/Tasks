#include "phonebook.h"
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>

using namespace std;

void add(phoneBook array[], int quantity, string name, string phone)
{
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

void findingNumber(phoneBook array[], int quantity, string name)
{
	bool check = false;
	for (int i = 0; i < quantity; i++)
	{
		if (array[i].name == name)
		{
			cout << "������� �����: " << array[i].number << endl;
			check = true;
			return;
		}
	}

	if (check == 0)
	{
		cout << "������ ��� � ���������� �����" << endl;
	}
}

void findingName(phoneBook array[], int quantity, string number)
{
	bool check = false;
	for (int i = 0; i < quantity; i++)
	{
		if (array[i].number == number)
		{
			cout << "�������: " << array[i].name << endl;
			check = true;
			return;
		}
	}

	if (!check)
	{
		cout << "���������� ����� �� �������� ������ �� ��������" << endl;
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

void read(phoneBook array[], int &quantity)
{
	FILE *ptrFile = fopen("text.txt", "r");

	if (access("text.txt", 0))
	{
		ofstream ptrFile("text.txt");
	}

	while (!feof(ptrFile))
	{
		string name = "";
		string phone = "";
		cin >> name;
		cin >> phone;
		add(array, quantity, name, phone);
		quantity++;
	}

	fclose(ptrFile);
}