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

void push(Phonebook *&head, const string &name, const string &number)
{
	auto newElement = new Phonebook{ name, number, head };
	head = newElement;
}

void deletePhonebook(Phonebook *&head)
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
	ifstream ptrFile("text.txt");

	if (!access("text.txt", 0))
	{
		while (!ptrFile.eof())
		{
			string name = "";
			string phone = "";
			ptrFile >> name;
			ptrFile >> phone;
			push(head, name, phone);
		}
	}

	ptrFile.close();
}

void print(Phonebook *head)
{
	Phonebook *newElement = head;

	while (newElement != nullptr)
	{
		cout << newElement->name << " " << newElement->number << endl;
		newElement = newElement->next;
	}
}

int quantityOfSubscriber(Phonebook *head)
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

Phonebook* returnNext(Phonebook *head)
{
	return head->next;
}

void setNext(Phonebook *&head, Phonebook *nextElement)
{
	head->next = nextElement;
}