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
		searchValue(value, tree->left);
	}
	if (value < tree->value)
	{
		searchValue(value, tree->right);
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

void deleteValue(int value, Tree *&tree)
{
	if (!searchValue(value, tree))
	{
		cout << "This value isn't available" << endl;
		return;
	}

	if (tree == nullptr)
	{
		return;
	}

	if (value == tree->value)
	{
		if (tree->left == nullptr)
		{
			if (tree->right == nullptr)
			{
				delete tree;
			}
			else
			{
				auto oldTree = tree;
				tree = tree->right;
				delete oldTree;
			}
		}
		else
		{
			if (tree->right == nullptr)
			{
				auto oldTree = tree;
				tree = tree->left;
			}
			else
			{
				Tree *zero = tree->left;
				while (zero->right != nullptr)
				{
					zero = zero->right;
				}
				tree->value = zero->value;
				delete zero;
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