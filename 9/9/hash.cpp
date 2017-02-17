#include "hash.h"
#include "list.h"
#include <iostream>
#include <string>

using namespace std;

const int sizeOf = 255;

struct HashTable
{
	List *head[sizeOf];
};

HashTable *initialisation()
{
	auto hashTable = new HashTable;
	for (int i = 0; i < sizeOf; i++)
	{
		hashTable->head[i] = nullptr;
	}

	return hashTable;
}

int computerHash(const string &keyword)
{
	int hash = 0;
	hash = (((int(keyword[0]) * 3 + int(keyword[1]) * 2 + int(keyword[1]) * 1)) * 37) % sizeOf;
	return hash;
}

void addToTable(HashTable *&hashTable, const string &keyword)
{
	int hash = computerHash(keyword);
	
	if (check(hashTable->head[hash], keyword))
	{
		findingIdentical(hashTable->head[hash], keyword);
	}
	else
	{
		add(hashTable->head[hash], keyword);
	}
}

int maxLength(HashTable *hashTable)
{
	int max = 0;

	for (int i = 0; i < sizeOf; i++)
	{
		if (max < lengthOfList(hashTable->head[i]))
		{
			max = lengthOfList(hashTable->head[i]);
		}
	}

	return max;
}

double loadFactor(HashTable *hashTable)
{
	double loadFactor = 0;
	for (int i = 0; i < sizeOf; i++)
	{
		loadFactor += lengthOfList(hashTable->head[i]);
	}
	
	loadFactor = loadFactor / sizeOf;

	return loadFactor;
}

double midLength(HashTable *hashTable)
{
	double result = 0;
	for (int i = 0; i < sizeOf; ++i)
	{
		result += quantityOfElements(hashTable->head[i]);
	}
	return result / sizeOf;
}