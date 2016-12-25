#include <iostream>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

void add(ListElement *&head, int n)
{
	auto newElement = new ListElement{ 1, nullptr };
	head = newElement;

	ListElement *zero = head;

	int i = 2;
	while (i <= n)
	{
		if (i != n)
		{
			newElement = new ListElement{ i, nullptr };
			zero->next = newElement;
			zero = newElement;
		}
		else
		{
			auto newElement = new ListElement{ i, head };
			zero->next = newElement;
		}
		i++;
	}
}

int game(ListElement *&head, int n, int m)
{
	int quantity = n;
	int last = 0;
	ListElement *zero = head;
	ListElement *deleted = head;

	while (quantity > 1)
	{
		if (m - 2 >= 0)
		{
			for (int i = 0; i < m - 2; i++)
			{
				zero = zero->next;
			}

			deleted = zero->next;
			zero->next = zero->next->next;
			zero = zero->next;
		}
		else
		{
			deleted = zero;
			zero = zero->next;
		}

		delete deleted;

		quantity--;
	}
	last = zero->value;
	delete zero;

	return last;
}

bool test()
{
	int n = 9;
	int m = 4;
	ListElement *workingList = nullptr;
	add(workingList, n);

	return game(workingList, n, m) == 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	if (!test())
	{
		cout << "Проблемы";
		return 0;
	}

	cout << "Введите количество воинов и номер убиваемого" << endl;
	int n = 0;
	int m = 0;
	cin >> n >> m;

	ListElement *workingList = nullptr;

	add(workingList, n);

	cout << "№ позиции для того, кто хочет выжить: ";
	cout << game(workingList, n, m) << endl;
}