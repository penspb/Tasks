#include "phonebook.h"
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>

void assunder(Phonebook *&head, Phonebook *&left, Phonebook *&right)
{
	int quantity = quantityOfSubscriber(left);

	Phonebook *zero = head;
	Phonebook *first = head;;

	if ((head == nullptr) || (returnNext(head) == nullptr))
	{
		left = head;
		right = nullptr;
	}
	else
	{
		first = returnNext(head);

		while (first != nullptr)
		{
			first = returnNext(first);
			if (first != nullptr)
			{
				zero = returnNext(zero);
				first = returnNext(first);
			}
		}

		left = head;
		right = returnNext(zero);
	}
	delete first;
	delete zero;
}

Phonebook *merge(Phonebook *&left, Phonebook *&right, bool sign)
{
	Phonebook *all = nullptr;
	if (left == nullptr)
	{
		return right;
	}
	else
	{
		if (right == nullptr)
		{
			return left;
		}
	}
	
	if (sign)
	{
		if (returnName(left) <= returnName(right))
		{
			all = left;
			all->next = merge(returnNext(left), right);
		}
		else
		{
			all = right;
			all->next = merge(left, returnNext(right));
		}
	}
	else
	{
		if (returnNumber(left) <= returnNumber(right))
		{
			all = left;
			all->next = merge(returnNext(left), right);
		}
		else
		{
			all = right;
			all->next = merge(left, returnNext(right));
		}
	}
	return all;
}

void mergeSort(Phonebook *&head, bool sign)
{
	if ((head == nullptr) || (returnNext(head) == nullptr))
	{
		return;
	}

	Phonebook *zero = nullptr;
	Phonebook *first = nullptr;
	
	assunder(head, zero, first);
	mergeSort(zero);
	mergeSort(first);
	merge(zero, first, sign);
}