#include "tree.h"
#include <iostream>

using namespace std;

struct Tree
{
	int value;
	Tree *left;
	Tree *right;
};

bool searchValue(int value, Tree *tree)
{
	if (tree == nullptr)
	{
		return false;
	}

	if (value > tree->value)
	{
		return searchValue(value, tree->right);
	}

	if (value < tree->value)
	{
		return searchValue(value, tree->left);
	}
	
	return true;
}

void printFromMaxToMin(Tree *tree)
{
	if (tree == nullptr)
	{
		return;
	}
	else
	{
		if (tree->left != nullptr)
		{
			printFromMaxToMin(tree->left);
		}
		cout << tree->value << " ";
		if (tree->right != nullptr)
		{
			printFromMaxToMin(tree->right);
		}
	}
}

void printFromMinToMax(Tree *tree)
{
	if (tree == nullptr)
	{
		return;
	}
	else
	{
		if (tree->right != nullptr)
		{
			printFromMinToMax(tree->right);
		}
		cout << tree->value << " ";
		if (tree->left != nullptr)
		{
			printFromMinToMax(tree->left);
		}
	}
}

void add(int value, Tree *&tree)
{
	if (tree == nullptr)
	{
		tree = new Tree{ value, nullptr, nullptr };
	}
	else
	{
		if (tree->value < value)
		{
			add(value, tree->left);
		}

		if (tree->value > value)
		{
			add(value, tree->right);
		}
	}
}

Tree *findLeftEnd(Tree *&tree)
{
	while (tree->left != nullptr)
	{
		tree = tree->left;
	}

	return tree;
}

void deleteValue(int value, Tree *&tree)
{
	if ((!searchValue(value, tree)) || (tree == nullptr))
	{
		cout << "This value isn't available" << endl;
		return;
	}

	if (value == tree->value)
	{
		if (tree->left == nullptr)
		{
			if (tree->right == nullptr)
			{
				delete tree;
				tree = nullptr;
			}
			else
			{
				auto zero = tree;
				tree = tree->right;
				delete zero;
			}
		}
		else
		{
			if (tree->right == nullptr)
			{
				auto zero = tree;
				tree = tree->left;
				delete zero;
			}
			else
			{
				auto first = findLeftEnd(tree->right);
				tree->value = first->value;

				deleteValue(first->value, tree->right);
			}
		}
	}
	else
	{
		if (value > tree->value)
		{
			deleteValue(value, tree->right);
		}
		if (value < tree->value)
		{
			deleteValue(value, tree->left);
		}
	}
}

void deleteTree(Tree *&tree)
{
	while (tree != nullptr)
	{
		deleteValue(tree->value, tree);
	}
}