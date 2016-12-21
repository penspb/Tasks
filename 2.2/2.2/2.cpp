#include <iostream>

using namespace std;

float raisingToAPower(int degree, float number)
{
	if (degree == 0)
	{
		return 1;
	}

	if ((degree % 2) == 1)
	{
		return raisingToAPower(degree - 1, number) * number;
	}
	else
	{
		float intermediateValue = raisingToAPower(degree / 2, number);
		return intermediateValue * intermediateValue;
	}
}

float raisingToAPower2(int degree, float number)
{
	float number0 = number;

	if (degree == 0)
	{
		number = 1;
	}
	else
	{
		for (int i = 1; i < degree; i++)
		{
			number = number * number0;
		}
	}

	return number;
}

int main()
{
	int degree = 0;
	cout << "Enter the degree";
	cout << endl;
	cin >> degree;

	float number = 0;
	cout << "Enter the number";
	cout << endl;
	cin >> number;

	float answer;

	cout << "First variant. O(n):" << endl;
	cout << "Answer: ";
	answer = raisingToAPower2(degree, number);
	cout << answer;
	cout << endl;
	cout << endl;

	cout << "Second variant. O(log n):" << endl;
	cout << "Answer: ";
	answer = raisingToAPower(degree, number);
	cout << answer;

	cout << endl;

	return 0;
}