#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string brackets;
	int inspection = 0;
	getline(cin, brackets);
	for (int i = 0; i < brackets.length(); i++)
	{
		if (brackets[i] == '(')
		{
			inspection++;
		}
		else
		{
			inspection--;
		}
		if (inspection < 0)
		{
			i = brackets.length();
		}
	}
	if ((inspection > 0) || (inspection < 0))
	{
		cout << "Problem";
	}
	else
	{
		cout << "Welldone";
	}
	return 0;
}