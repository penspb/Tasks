#include <iostream>

using namespace std;

int fibonacci(int number)
{
	if (number == 1 || number == 0)
	{
		return 1;
	}

	return fibonacci(number - 1) + fibonacci(number - 2);
}

int fibonacci2(int number)
{
	int f0 = 1;
	int f1 = 1;

	for (int i = 1; i < number; i++)
	{
		f0 = f1 + f0;
		swap(f0, f1);
	}

	return f1;
}

int main()
{
	int number = 0;
	cout << "Enter the number";
	cout << endl;
	cin >> number;

	cout << "First variant: recursive";
	cout << endl;
	cout << "N-th Fibonacci number is equal to ";
	cout << fibonacci2(number);
	cout << endl;

	cout << endl;

	cout << "Second variant: iterative";
	cout << endl;
	cout << "N-th Fibonacci number is equal to ";
	cout << fibonacci(number);
	cout << endl;

	return 0;
}