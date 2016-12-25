#include "stack.h"
#include <iostream>

using namespace std;

struct Stack
{
	char value;
	Stack *next;
};

void deleteStack(Stack *&head)
{
	while (head != nullptr)
	{
		Stack *oldHead = head;
		head = head->next;
	}
}

void push(Stack *&head, char value)
{
	head = new Stack{ value, head };
}

bool isEmpty(Stack *head)
{
	return head == nullptr;
}

char pop(Stack *&head)
{
	if (!isEmpty(head))
	{
		Stack *oldHead = head;
		head = head->next;

		char value = oldHead->value;
		delete oldHead;
		return value;
	}
	else
	{
		return '/';
	}
}