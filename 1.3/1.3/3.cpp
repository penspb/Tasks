#include <iostream>

using namespace std;

void upturning(int *workingArray, int firstNumber, int lastNumber)
{
	for (int i = firstNumber; i <= (firstNumber + lastNumber) / 2; i++)
	{
		swap(workingArray[i], workingArray[firstNumber + lastNumber - i]);
	}
}

int main()
{
	cout << "Enter two lengths of segments" << '\n';
	int n;
	int m;
	cin >> n >> m;
	cout << '\n';
	int *workingArray = new int[n + m + 1];

	for (int i = 0; i < n + m; i++)
	{
		workingArray[i] = i + 1;
		cout << workingArray[i] << " ";
	}
	cout << '\n';

	upturning(workingArray, 0, n - 1);
	upturning(workingArray, n, m + n - 1);
	upturning(workingArray, 0, m + n - 1);

	for (int i = 0; i < n + m; i++)
	{
		cout << workingArray[i] << " ";
	}
	cout << endl;

	delete[] workingArray;

	return 0;
}