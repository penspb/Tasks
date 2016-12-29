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
		delete oldhead;
	}
}

void push(Stack *&head, char value)
{
	head = new Stack{ value, head };
}

char valueFromHead(Stack *&head)
{
	if (!isEmpty(head))
	{
		return head->value;
	}
}

bool isEmpty(Stack *head)
{
	return head == nullptr;
}

void pop(Stack *&head)
{
	if (!isEmpty(head))
	{
		Stack *oldHead = head;
		head = head->next;

		delete oldHead;
	}
}