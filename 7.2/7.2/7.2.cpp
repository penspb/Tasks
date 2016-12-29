#include "tree.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream file("text.txt");
	string line = "";
	getline(file, line);

	int count = 0;

	Tree *tree = create();
	createTree(tree, count, line);

	print(tree);

	cout << "��������� ����������: " << result(tree) << endl;

	deleteTree(tree);

	return 0;
}