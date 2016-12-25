#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

char pair0(char symbol)
{
	if (symbol == ')')
	{
		return '(';
	}

	if (symbol == ']')
	{
		return '[';
	}

	if (symbol == '}')
	{
		return '{';
	}
}

bool balance(string line)
{
	Stack *workingStack = nullptr;

	int sizeOfLine = line.length();
	for (int i = 0; i < sizeOfLine; i++)
	{
		if ((line[i] == '(') || (line[i] == '{') || (line[i] == '['))
		{
			push(workingStack, line[i]);
		}
		else
		{
			char result = pop(workingStack);
			if (result != pair0(line[i]))
			{
				return false;
			}
		}
	}
	return isEmpty(workingStack);
}

bool test1()
{
	string line = "){}";
	return balance(line);
}

bool test2()
{
	string line = "(({[]{}}){})";
	return balance(line);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test1() && test2())
	{
		cout << "Проблемы";
		return 0;
	}

	string line = "";
	cout << "Введите строку" << endl;
	getline(cin, line);

	if (balance(line))
	{
		cout << "Последовательность сбалансирована" << endl;
	}
	else
	{
		cout << "Последовательность не сбалансирована" << endl;
	}

	return 0;
}