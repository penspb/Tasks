#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

bool sign(char ch)
{
	return ch == '-' || ch == '+' || ch == '*' || ch == '/';
}

bool bracket(char ch)
{
	return ch == ')' || ch == '(';
}

string result(string &line)
{
	Stack *workingStack = nullptr;
	string stringResult = "";

	int sizeOfLine = line.length();
	for (int i = 0; i < sizeOfLine; i++)
	{
		if (line[i] != ' ')
		{
			if (bracket(line[i]))
			{
				if (line[i] == '(')
				{
					push(workingStack, line[i]);
				}
				else
				{
					while (valueFromHead(workingStack) != '(')
					{
						char ch = valueFromHead(workingStack);
						stringResult += ch;
						stringResult += ' ';

						pop(workingStack);
					}

					pop(workingStack);
				}
			}
			else
			{
				if (sign(line[i]))
				{
					if ((line[i] == '-') || (line[i] == '+'))
					{
						while (sign(valueFromHead(workingStack)))
						{
							char ch = valueFromHead(workingStack);
							stringResult += ch;
							stringResult += ' ';
							pop(workingStack);
						}
					}
					else
					{
						while ((valueFromHead(workingStack) == '*') || (valueFromHead(workingStack) == '/'))
						{
							char ch = valueFromHead(workingStack);
							stringResult += ch;
							stringResult += ' ';
							pop(workingStack);
						}
					}

					push(workingStack, line[i]);
				}
				else
				{
					stringResult += line[i];
					stringResult += ' ';
				}
			}
		}
	}

	while (!isEmpty(workingStack))
	{
		char ch = valueFromHead(workingStack);
		stringResult += ch;
		stringResult += ' ';
		pop(workingStack);
	}

	deleteStack(workingStack);

	return stringResult;
}

bool test()
{
	string line0 = "(1 + 1) * 2";
	string line1 = "1 + 2 + 3 * 4";

	return result(line0) == "1 1 + 2 * " && result(line1) == "1 2 + 3 4 * + ";
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
}