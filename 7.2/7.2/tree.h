#pragma once

//struct
struct Tree;

// create Tree
Tree *create();

//sign
bool sign(char ch);

//print tree
void print(Tree *tree);


//add new value
void addValue(int value, Tree *&tree);

//add new symbol
void addSymbol(char symbol, Tree *&tree);

//create new tree
void createTree(Tree *tree, int count, const string &line);

//count the result
int result(Tree *tree);

//delete tree
void deleteTree(Tree *tree);