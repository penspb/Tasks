#include <string>
#include <iostream>
#include "list.h"

using namespace std;

struct List
{
	string word;
	int value;
	List *next;
};

void add(List *&head, const string &word)
{
	head = new List{ word, 1, head };
}

void deleteFromHead(List *&head)
{
	List *zero = head;
	head = head->next;
	delete zero;
	zero = nullptr;
}

List *searchByKeyword(List *&head, const string &keyword)
{
	while ((head != nullptr) && (keyword != head->word))
	{
		head = head->next;
	}
	return head;
}

void print(List *&head)
{
	while (head != nullptr)
	{
		cout << head->word << " " << head->value << endl;
		head = head->next;
	}
}
bool check(List *head, const string &keyword)
{
	auto zero = head;
	while (zero != nullptr)
	{
		if (zero->word == keyword)
		{
			return true;
		}
		zero = zero->next;
	}

	return false;
}
void findingIdentical(List *&head, const string &keyword)
{
	auto zero = head;
	while (zero->word != keyword)
	{
		zero = zero->next;
	}

	zero->value++;
}

int lengthOfList(List *head)
{
	int length = 0;

	while (head != nullptr)
	{
		length++;
		head = head->next;
	}

	return length;
}

int quantityOfElements(List *head)
{
	int quantity = 0;
	auto zero = head;
	while (zero != nullptr)
	{
		zero = zero->next;
		quantity++;
	}

	return quantity;
}