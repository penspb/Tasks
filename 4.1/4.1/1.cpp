#include <iostream>
#include <bitset> 

using namespace std;

void binary(int number, bool array[])
{
	int numberCopy = number;
	const int sizeOfArray = sizeof(int) * 8;
	for (int i = sizeOfArray - 1; i >= 0; i--)
	{
		array[sizeOfArray - i - 1] = (numberCopy >> i) & 1;
	}
}

void print(bool array[])
{
	int i = 0;
	while (array[i] == 0)
	{
		i++;
	}

	const int sizeOfArray = sizeof(int) * 8;
	for (int j = i; j < sizeOfArray; j++)
	{
		cout << array[j];
	}
	if (i == sizeOfArray)
	{
		cout << 0;
	}
}

void summ(bool array1[], bool array2[], bool sum[])
{
	const int sizeOfArray = sizeof(int) * 8;
	int balance = 0;
	int pseudoSum = 0;
	for (int i = sizeOfArray - 1; i >= 0; i--)
	{
		pseudoSum = array1[i] + array2[i] + balance;
		sum[i] = pseudoSum % 2;
		balance = pseudoSum / 2;
	}
}

int denary(bool array[])
{
	const int sizeOfArray = sizeof(int) * 8;
	int power = 1;
	int requiredNumber = 0;
	for (int i = sizeOfArray - 1; i >= 0; i--)
	{
		requiredNumber += array[i] * power;
		power = power * 2;
	}
	return requiredNumber;
}

bool test()
{
	int first = 1;
	int second = 31;

	const int sizeOfArray = sizeof(int) * 8;
	bool firstArray[sizeOfArray] = {};
	bool secondArray[sizeOfArray] = {};

	binary(first, firstArray);
	binary(second, secondArray);

	bool sumArray[sizeOfArray] = {};
	summ(firstArray, secondArray, sumArray);

	if (denary(sumArray) == first + second)
	{
		return true;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	if (test())
	{

		int first = 0;
		int second = 0;
		cout << "Введите два числа" << endl;
		cin >> first >> second;
		cout << endl;

		const int sizeOfArray = sizeof(int) * 8;
		bool firstArray[sizeOfArray] = {};
		bool secondArray[sizeOfArray] = {};

		binary(first, firstArray);
		binary(second, secondArray);

		print(firstArray);
		cout << " ";
		print(secondArray);

		bool sumArray[sizeOfArray] = {};
		summ(firstArray, secondArray, sumArray);
		cout << endl;
		print(sumArray);
		cout << endl;

		cout << endl << "Сумма равна: " << denary(sumArray) << endl;
	}
	else
	{
		cout << "Проблемы";
	}

	return 0;
}