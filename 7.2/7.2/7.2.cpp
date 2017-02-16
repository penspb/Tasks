#include "tree.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool test()
{
	string line = "(* (+ 1 1) 2)";
	int count = 0;

	Tree *tree = create();
	createTree(tree, count, line);

	int lineResult = result(tree);
	deleteTree(tree);

	return lineResult == 4;
}

int main()
{
	if (!test)
	{
		cout << "Проблемы." << endl << "Завершение работы";
		return 0;
	}

	ifstream file("text.txt");
	string line = "";
	getline(file, line);

	int count = 0;

	Tree *tree = create();
	createTree(tree, count, line);

	print(tree);

	cout << "Результат вычислений: " << result(tree) << endl;

	deleteTree(tree);

	return 0;
}