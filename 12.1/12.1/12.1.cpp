#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void symbolTable(int array[], const string &line)
{
	const int sizeOfArray = 256;
	string newLine = "";

	for (int i = 0; i < line.length() - 1; i++)
	{
		array[int(line[i])] = i + 1;
	}
}

void suffixTable(int array[], const string &line)
{
	array[0] = 1;
	for (int i = 1; i < line.length(); i++)
	{
		for (int j = 0; j < line.length() + 1 - i; j++)
		{
			int count = 0;
			while (line[j + count] == line[line.length() + 1 - i + count])
			{
				count++;
			}
			if (count == i)
			{
				array[i] = line.length() + 1 - i - j;
			}
		}
	}
}

void searching(const string &line)
{
	int sizeOfLine = line.length();

	int symbol[256];
	symbolTable(symbol, line);

	int *suffix = new int[sizeOfLine + 1];
	suffixTable(suffix, line);

	ifstream file("text.txt");

	if (!file.is_open())
	{
		cout << "File is not avaible" << endl;
	}
	else
	{
		string st = "";
		char ch = 'q';

		for (int i = 0; i < line.length() - 1; i++)
		{
			cin >> ch;
			st += ch;
		}

		int count = line.length() - 1;
		int index = 0;

		while (file.eof())
		{
			cin >> ch;
			count++;
			index++;

			if (count == line.length())
			{
				bool check = false;
				int j = line.length() - 1;
				while ((j >= 0) && (st[line.length() - 1 - j] == line[line.length() - 1 - j]))
				{
					j++;
				}
				if (j == line.length())
				{
					cout << "Подстрока содержится в строке, начиная с элемента: " << index << endl;
				}
				else
				{
					if (j == 0)
					{
						for (int k = 0; k < line.length(); k++)
						{
							cin >> ch;
							st[k] = ch;
							index++;
						}
					}
					else
					{
						if (j == 1)
						{
							char newchar = st[line.length() - 1];
							for (int k = 0; k < line.length(); k++)
							{
								if (k < line.length() - symbol[newchar])
								{
									st[k] = st[k + symbol[newchar]];
								}
								else
								{
									cin >> ch;
									st[k] = ch;
									index++;
								}
							}
						}
						else
						{
							for (int k = 0; k < line.length(); k++)
							{
								if (k < line.length() - suffix[j])
								{
									st[k] = st[k + suffix[j]];
								}
								else
								{
									cin >> ch;
									st[k] = ch;
									index++;
								}
							}
						}
					}
				}
			}
		}
	}
	file.close();
						
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string line = "";
	cout << "Пожалуйста, введите искомую подстроку" << endl;
	getline(cin, line);

	cout << line;

	searching(line);
	return 0;
}