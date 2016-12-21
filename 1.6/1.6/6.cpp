#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
string s1, s2;
bool truefalse(string s, int n)
{
	bool t = true;
	if (n + s.length() <= s2.length())
	{
		for (int i = n; i < n + s.length(); i++)
		{
			if (s[i - n] != s2[i])
			{
				t = false;
			}
		}
	}
	else
	{
		t = false;
	}
	return(t);
}
int main()
{
	int quantity = 0;
	bool t;
	getline(cin, s2);
	getline(cin, s1);
	for (int i = 0; i <= s2.length(); i++)
	{
		t = truefalse(s1, i);
		if (t == true)
		{
			quantity++;
		}
	}
	printf("%d", quantity);
	return 0;
}