#include <istream>
#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

void readStateTable(int stateTable[4][3])
{
	ifstream table("table.txt");

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			table >> stateTable[i][j];
		}
	}

	table.close();
}

bool isInsideCommentState(int state)
{
	return state == 2 || state == 3;
}

void searchAndPrint(int stateTable[4][3])
{
	ifstream file("input.txt");

	char element = '_';
	int state = 0;
	int oldState = 0;

	file >> element;

	while (file.eof())
	{
		oldState = state;
		switch (element)
		{
			case '/':
			{
				state = stateTable[state][0];
				break;
			}
				
			case '*':
			{
				state = stateTable[state][1];
				break;
			}

			default:
			{
				state = stateTable[state][2];
				break;
			}
		}

		if (isInsideCommentState(state) || isInsideCommentState(oldState))
		{
			if (!isInsideCommentState(oldState))
			{
				cout << '/';
			}
			cout << element;
		}

		if (isInsideCommentState(oldState) && !isInsideCommentState(state))
		{
			cout << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int stateTable[4][3] = { 0 };
	readStateTable(stateTable);

	searchAndPrint(stateTable);
	
	return 0;
}