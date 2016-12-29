#include <iostream>
#include <string>

using namespace std;

enum State { start, mantissaIntegerPart, mantissaFractionStart, mantissaFractionPart, exponentaStart, exponentaStartNumber, exponentaNumber };

bool isRealNumber(const string &word)
{
	int length = word.length();
	int i = 0;

	State state = start;
	while (i < length)
	{
		const char c = word[i];

		switch (state)
		{
			case start:
			{
				if (isdigit(c))
				{
					state = mantissaIntegerPart;
				}
				else
				{
					return false;
				}
				break;
			}	
			case mantissaIntegerPart:
			{
				if (!isdigit(c))
				{
					switch (c)
					{
						case '.':
						{
							state = mantissaFractionStart;
							break;
						}
						case 'E':
						{
							state = exponentaStart;
							break;
						}
						default:
						{
							return false;
							break;
						}
					}
				}
				break;
			}
			case mantissaFractionStart:
			{
				if (!isdigit(c))
				{
					return false;
				}
				state = mantissaFractionPart;
				break;
			}

			case mantissaFractionPart:
			{
				if (!isdigit(c))
				{
					if (c == 'E')
					{
						state = exponentaStart;
					}
					else
					{
						return false;
					}
				}
				break;
			}
		
			case exponentaStart:
			{
				if ((c == '+') || (c == '-'))
				{
					state = exponentaStartNumber;
				}
				else
				{
					if (isdigit(c))
					{
						state = exponentaNumber;
					}
					else
					{
						return false;
					}
				}
				break;
			}

			case exponentaStartNumber:
			{
				if (!isdigit(c))
				{
					return false;
				}
				state = exponentaNumber;
				break;
			}

			case exponentaNumber:
			{
				if (!isdigit(c))
				{
					return false;
				}
				break;
			}
		}	
		i++;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите что-нибудь" << endl;

	string word;
	cin >> word;

	if (isRealNumber(word))
	{
		cout << "Действительно, это вещественное число" << endl;
	}
	else
	{
		cout << "Увы, но это не является вещественным числом" << endl;
	}

	return 0;
}