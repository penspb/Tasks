#pragma once
struct Stack;

// delete stack
void deleteStack(Stack *&head);

// add element in stack
void push(Stack *&head, char value);

// return value from head
char valueFromHead(Stack *&head);

// delete element from stack
void pop(Stack *&head);

// check: empty/not
bool isEmpty(Stack *head);