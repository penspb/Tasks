#pragma once
#include "phonebook.h" 
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>

//divide tthe list into two parts
void assunder(Phonebook *&head, Phonebook *&zero, Phonebook *&first);

//merge
Phonebook *merge(Phonebook *&left, Phonebook *&right, bool sign);

//merge sort
void mergeSort(Phonebook *&head, bool sign);