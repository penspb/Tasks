#pragma once

//struct
struct Tree;

//search value
bool searchValue(int value, Tree *tree);

//print in decreading order
void printFromMaxToMin(Tree *tree);

//print in ascending order
void printFromMinToMax(Tree *tree);

//add new value
void add(int value, Tree *&tree);

//delete value
void deleteValue(int value, Tree *tree);

//delete tree
void deleteTree(Tree *tree);