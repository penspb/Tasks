#pragma once

#include <iostream>
#include <string>

/*struct Phonebook
{
	std::string name;
	std::string number;
	Phonebook *next;
};*/

//phonebook
struct Phonebook;

//add new element
void push(Phonebook *&head, const std::string &name, const std::string &number);

//delete phonebook
void deletePhonebok(Phonebook *&head);

//check: empty/not
bool isEmpty(Phonebook *head);

//read list
void read(Phonebook *&head);

//print list
void print(Phonebook *&head);

//quantity
int quantityOfSubscriber(Phonebook *&head);

//return number of element
std::string returnNumber(Phonebook *head);

//return name of element
std::string returnName(Phonebook *head);

//return next element
Phonebook *&returnNext(Phonebook *head);

Phonebook *returnNextNext(Phonebook *head);

//add after last element
void addAfter(Phonebook *&head, std::string name, std::string number);