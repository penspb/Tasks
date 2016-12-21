#include<iostream>

using namespace std;

int main()
{
	int dividend, divisor;
	cin >> dividend >> divisor;
	int quotient = 0;
	while (divisor * quotient <= dividend)
	{
		quotient++;
	}
	printf("%d", quotient - 1);
	return 0;
}