#pragma once
struct Stack;

// delete stack
void deleteStack(Stack *&head);

// add element in stack
void push(Stack *&head, int value);

// delete element from stack
int pop(Stack *&head);

// check: empty/not
bool isEmpty(Stack *head);