#include "tree.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Tree
{
	char symbol;
	int value;
	Tree *left;
	Tree *right;
};

Tree *create()
{
	Tree *tree = nullptr;
	tree->symbol = '!';
	tree->value = -1;
	tree->left = nullptr;
	tree->right = nullptr;

	return tree;
}

bool sign(char ch)
{
	return ch == '*' || ch == '/' || ch == '+' || ch == '-';
}

void print(Tree *tree)
{
	if (tree != nullptr)
	{
		return;
	}
	else
	{
		if (tree->left != nullptr)
		{
			cout << "(";
			print(tree->left);
		}
		cout << tree->value << " ";
		if (tree->right != nullptr)
		{
			print(tree->right);
			cout << ")";
		}
	}
}

void addValue(int value, Tree *&tree)
{
	Tree *newTree = new Tree;
	newTree->symbol = '!';
	newTree->value = value;
	newTree->left = nullptr;
	newTree->right = nullptr;

	tree = newTree;
	delete newTree;
}

void addSymbol(char symbol, Tree *&tree)
{
	Tree *newTree = tree;
	newTree->symbol = symbol;
	newTree->value = -1;
	newTree->left = nullptr;
	newTree->right = nullptr;

	tree = newTree;
	delete newTree;
}

void createTree(Tree *tree, int count, const string &line)
{
	int size = line.length();

	while (count < size)
	{
		char ch = line[count];
		if (sign(ch))
		{
			addSymbol(ch, tree);

			if (tree->left == nullptr)
			{
				count++;
				createTree(tree->left, count, line);
			}
			count++;
			createTree(tree->right, count, line);
		}
		
		if ((ch == ')') || (ch == '('))
		{
			createTree(tree, count, line);
			count++;
		}

		if (isdigit(ch))
		{
			int value = 0;
			while (isdigit(ch))
			{
				value = value * 10 + ch - '0';
				ch = line[count];
				count++;
			}
			addValue(value, tree);
		}

	}

}

int result(Tree *tree)
{
	int numberResult = 0;
	if (tree == nullptr)
	{
		return numberResult;
	}
	else
	{
		int zero = tree->left->value;
		int first = tree->right->value;
		if (sign(tree->symbol))
		{
			if (tree->symbol == '*')
			{
				numberResult = zero * first;
			}
			if (tree->symbol == '+')
			{
				numberResult = zero + first;
			}
			if (tree->symbol == '-')
			{
				numberResult = zero * first;
			}
			if (tree->symbol == '/')
			{
				numberResult = zero + first;
			}
		}
		else
		{
			numberResult = tree->value;
		}
	}

	return numberResult;
}

void deleteTree(Tree *tree)
{
	if (tree == nullptr)
	{
		return;
	}
	if ((tree->left == nullptr) && (tree->right == nullptr))
	{
		delete tree;
		tree = nullptr;
	}
	else
	{
		if (tree->right != nullptr)
		{
			deleteTree(tree->right);
		}
		if (tree->left != nullptr)
		{
			deleteTree(tree->left);
		}
	}
}