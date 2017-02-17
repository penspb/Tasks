#pragma once
#include <string>

using namespace std;

//initial hashTable
struct HashTable;

//initialisation
HashTable *initialisation();

//computer hash
int computerHash(const string &keyword);

//add to table
void addToTable(HashTable *&hashTable, const string &keyword);

//finding max length
int maxLength(HashTable *hashTable);

//finding load factor
double loadFactor(HashTable *hashTable);

//finding mid length