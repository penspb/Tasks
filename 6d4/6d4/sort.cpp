#include "phonebook.h"
#include <iostream>
#include <string>
#include <fstream>

void assunder(Phonebook *head, Phonebook *&left, Phonebook *&right)
{
	int quantity = quantityOfSubscriber(head);
	int leftSize = quantity / 2;

	left = head;
	right = head;

	Phonebook *preRight = nullptr;

	for (int i = 0; i < leftSize; i++)
	{
		preRight = right;
		right = returnNext(right);
	}

	setNext(preRight, nullptr);
}

Phonebook* merge(Phonebook *left, Phonebook *right, bool sign)
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
			setNext(all, merge(returnNext(left), right, sign));
		}
		else
		{
			all = right;
			setNext(all, merge(left, returnNext(right), sign));
		}
	}
	else
	{
		if (returnNumber(left) <= returnNumber(right))
		{
			all = left;
			setNext(all, merge(returnNext(left), right, sign));
		}
		else
		{
			all = right;
			setNext(all, merge(left, returnNext(right), sign));
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
	head = merge(zero, first, sign);
}