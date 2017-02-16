#pragma once

#include <iostream>
#include <string>

//phonebook
struct Phonebook;

//add new element
void push(Phonebook *&head, const std::string &name, const std::string &number);

//delete phonebook
void deletePhonebook(Phonebook *&head);

//check: empty/not
bool isEmpty(Phonebook *head);

//read list
void read(Phonebook *&head);

//print list
void print(Phonebook *head);

//quantity
int quantityOfSubscriber(Phonebook *head);

//return number of element
std::string returnNumber(Phonebook *head);

//return name of element
std::string returnName(Phonebook *head);

//return next element
Phonebook *returnNext(Phonebook *head);

//set next element
void setNext(Phonebook *&head, Phonebook* nextElement);