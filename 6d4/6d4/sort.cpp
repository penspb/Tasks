#include "phonebook.h"
#include <iostream>
#include <string>
#include <fstream>

void assunder(Phonebook *&head, Phonebook *&left, Phonebook *&right)
{
	int quantity = quantityOfSubscriber(left);

	Phonebook *zero = head;
	Phonebook *first = head;

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

			returnNext(all) = merge(returnNext(left), right, sign);
		}
		else
		{
			all = right;
			returnNext(all) = merge(left, returnNext(right), sign);
		}
	}
	else
	{
		if (returnNumber(left) <= returnNumber(right))
		{
			all = left;
			returnNext(all) = merge(returnNext(left), right, sign);
		}
		else
		{
			all = right;
			returnNext(all) = merge(left, returnNext(right), sign);
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
	mergeSort(zero, sign);
	mergeSort(first, sign);
	merge(zero, first, sign);
}