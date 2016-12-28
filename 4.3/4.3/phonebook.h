#pragma once
#include <string>

//phonebook
struct phoneBook
{
	std::string name;
	std::string number;
};

//add new information about the subscriber
void add(phoneBook array[], int quantity, std::string name, std::string phone);

//prtint all information from phonebook
void print(phoneBook array[], int quantity);

//search the phonenumber by suscriber's name
void findingNumber(phoneBook array[], int quantity, std::string name);

//search the subscriber by number
void findingName(phoneBook array[], int quantity, std::string number);

//save phonebook in file
void save(phoneBook array[], int quantity);

//read from file
void read(phoneBook array[], int &quantity);