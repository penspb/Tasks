#pragma once
struct Stack;

// delete stack
void deleteStack(Stack *&head);

// add element in stack
void push(Stack *&head, char value);

// delete element from stack
char pop(Stack *&head);

// check: empty/not
bool isEmpty(Stack *head);