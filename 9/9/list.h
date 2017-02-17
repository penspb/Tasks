#pragma once
#include <string>

//struct list
struct List;

//add new element to head
void add(List *&head, const string &word);

//delete element from head
void deleteFromHead(List *&head);

//seach by keyword
List *searchByKeyword(List *&head, const string &keyword);

//print 
void print(List *&head);

//check availability of keyword
bool check(List *head, const string &keyword);

//finding identical
void findingIdentical(List *&head, const string &keyword);

//length of list
int lengthOfList(List *head);

//quantity of elements
int quantityOfElements(List *head);