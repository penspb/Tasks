#include "phonebook.h" 
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>

using namespace std;

struct Phonebook
{
	string name;
	string number;
	Phonebook *next;
};

void push(Phonebook *&head, const string &name,const string &number)
{
	auto newElement = new Phonebook{ name, number, head };
	head = newElement;
}

void deletePhonebok(Phonebook *&head)
{
	while (head != nullptr)
	{
		Phonebook *oldHead = head;
		head = head->next;
		delete oldHead;
	}
}

bool isEmpty(Phonebook *head)
{
	return head == nullptr;
}

void read(Phonebook *&head)
{
	FILE *ptrFile = fopen("text.txt", "r");

	if (!access("text.txt", 0))
	{
		while (!feof(ptrFile))
		{
			string name = "";
			string phone = "";
			cin >> name;
			cin >> phone;
			push(head, name, phone);
		}
	}

	fclose(ptrFile);
}

void print(Phonebook *&head)
{
	Phonebook *newElement = head;

	while (newElement != nullptr)
	{
		cout << newElement->name << " " << newElement->number << endl;
	}
}

int quantityOfSubscriber(Phonebook *&head)
{
	Phonebook *newElement = head;
	int quantity = 0;
	while (newElement != nullptr)
	{
		quantity++;
		newElement = newElement->next;
	}
	
	return quantity;
}

string returnNumber(Phonebook *head)
{
	return head->number;
}

string returnName(Phonebook *head)
{
	return head->name;
}

Phonebook *returnNext(Phonebook *head)
{
	return head->next;
}

void addAfter(Phonebook *&head, const string &name, const string &number)
{
	Phonebook *zero = head;

	if (zero == nullptr)
	{
		head = new Phonebook{ name, number, nullptr };
	}
	else
	{
		while (zero->next != nullptr)
		{
			zero = zero->next;
		}
		zero->next = new Phonebook{ name, number, nullptr };
	}
}