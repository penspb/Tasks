#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int sign(int a, int b, char ch)
{
	if (ch == '+')
	{
		return a + b;
	}
	
	if (ch == '-')
	{
		return a - b;
	}

	if (ch == '*')
	{
		return a * b;
	}

	if (ch == '/')
	{
		return a / b;
	}
}

int result(const string &line)
{
	int sizeOfLine = line.length();
	Stack *workingStack = nullptr;


	for (int i = 0; i < sizeOfLine; i++)
	{
		if (line[i] != ' ')
		{
			if (line[i] <= '9') && (line[i] >= '0')
			{
				push(workingStack, int(line[i]) - '0');
			}
			else
			{
				int a = pop(workingStack);
				int b = pop(workingStack);
				int value = sign(b, a, line[i]);
				push(workingStack, value);
			}
		}
	}
	int intresult = pop(workingStack);
	deleteStack(workingStack);
	return intresult;
}

bool test()
{
	string line0 = "9 6 - 1 2 + *";
	string line1 = "8 4 / 5 6 + *";

	return result(line0) == 9 && result(line1) == 22;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	if (!test())
	{
		cout << "Проблемы";
		return 0;
	}

	string line = "";
	cout << "Введите выражение" << endl;
	getline(cin, line);
	
	cout << "Значение выражения: " << result(line) << endl;

	return 0;
}