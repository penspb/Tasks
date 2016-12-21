#include<iostream>

using namespace std;

int main()
{
	int lastnumber;
	cin >> lastnumber;
	bool number[100001] = {};
	for (int i = 2; i <= lastnumber; i++)
	{
		if (number[i] == false)
		{
			int j = i * i;
			while (j <= lastnumber)
			{
				number[j] = true;
				j = j + i;
			}
		}
	}
	for (int i = 2; i <= lastnumber; i++)
	{
		if (number[i] == false)
		{
			cout << i << " ";
		}
	}
	return 0;
}