#include "stack.h"
#include <iostream>

using namespace std;

struct Stack
{
	int value;
	Stack *next;
};

void deleteStack(Stack *&head)
{
	while (head != nullptr)
	{
		Stack *oldHead = head;
		head = head->next;
		delete oldHead;
	}
}

void push(Stack *&head, int value)
{
	head = new Stack{ value, head };
}

bool isEmpty(Stack *head)
{
	return head == nullptr;
}

int pop(Stack *&head)
{
	if (!isEmpty(head))
	{
		Stack *oldHead = head;
		head = head->next;

		int value = oldHead->value;
		delete oldHead;
		return value;
	}
	else
	{
		return 10;
	}
}