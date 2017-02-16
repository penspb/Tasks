#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> prefixFunction(const string &line) 
{
	int length = line.size();

	vector<int> pi(length);
	int count = pi[0] = 0;

	for (int i = 2; i <= length; ++i)
	{
		while ((count > 0) && (line[count] != line[i - 1]))
		{
			count = pi[count - 1];
		}

		if (line[count] == line[i - 1])
		{
			count++;
		}

		pi[i - 1] = count;
	}

	return pi;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	ifstream file("text.txt");

	if (!file.is_open())
	{
		cout << "Файл не доступен" << endl;
	}
	else
	{
		string text = "";
		string pattern = "";
		
		file >> text;

		file.close();

		cout << "Введите искомую подстроку: ";
		cin >> pattern;
		cout << endl;

		vector<int> forPattern = prefixFunction(pattern);
		vector<int> table;
		{
			string line = pattern;
			reverse(line.begin(), line.end());
			table = prefixFunction(line);
		}

		int lengthOfPattern = pattern.size();

		map<char, int> stopSymbols;

		for (int i = 0; i < lengthOfPattern; i++)
		{
			stopSymbols[pattern[i]] = i;
		}

		map<int, int> suffix;

		for (int i = 0; i < lengthOfPattern; i++)
		{
			suffix[i] = lengthOfPattern - forPattern.back();
		}

		for (int i = 1; i < lengthOfPattern; i++)
		{
			int j = table[i];
			suffix[j] = min(suffix[i], i - j + 1);
		}

		vector<int> answer;

		for (int shift = 0; shift <= int(text.size()) - lengthOfPattern;)
		{
			int position = lengthOfPattern - 1;

			while (position >= 0 && pattern[position] == text[shift + position])
			{
				position--;
			}

			if (position < 0)
			{
				answer.push_back(shift);
				shift += suffix[lengthOfPattern - 1];
			}

			if (position == lengthOfPattern - 1)
			{
				auto working = stopSymbols.find(text[shift + position]);
				if (working == stopSymbols.end())
				{
					shift += position - (-1);
				}
				else
				{
					shift += position - working->second;
				}
			}
			else
			{
				shift += suffix[lengthOfPattern - position - 1];
			}
		}
		cout << "Количество совпадений: " << answer.size() << endl;

		for (int i : answer)
		{
			cout << (i + 1) << ' ';
		}

	}

	return 0;
}