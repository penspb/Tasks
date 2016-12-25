#include <iostream>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

void push(int value, ListElement *&head)
{
	auto newElement = new ListElement{ value, head };
	head = newElement;
}

void add(int value, ListElement *&head)
{
	if ((head == nullptr) || (head->value >= value))
	{
		push(value, head);
	}
	else
	{
		ListElement *zero = head;

		while ((zero->next != nullptr) && (zero->next->value < value))
		{
			zero = zero->next;
		}

		auto newElement = new ListElement{ value, zero->next };
		zero->next = newElement;
	}
}

void print(ListElement *head)
{
	auto element = head;

	while (element != nullptr)
	{
		cout << element->value << " ";
		element = element->next;
	}
}

void deleteOfHead(ListElement *&head)
{
	ListElement *oldHead = head;
	head = head->next;

	delete oldHead;
}

void deleteList(ListElement *&head)
{
	while (head != nullptr)
	{
		deleteOfHead(head);
	}
}

void deleteElement(int value, ListElement *&head)
{
	ListElement *zero = new ListElement;
	zero = head;

	while ((zero->next != nullptr) && (zero->next->value != value))
	{
		zero = zero->next;
	}

	if (zero->next == nullptr)
	{
		cout << "there is no element which is equal to the value";
	}
	else
	{
		if (zero->next == zero)
		{
			deleteOfHead(head);
		}
		else
		{
			if (zero->next->value == value)
			{
				ListElement *first = zero->next;
				zero->next = zero->next->next;
				delete first;
			}
		}
	}
}

bool test()
{
	ListElement *list = nullptr;
	add(1, list);
	add(3, list);
	add(2, list);
	add(-1, list);
	deleteElement(2, list);

	return list->value == -1 && list->next->value == 1 && list->next->next->value == 3;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	ListElement *workingList = nullptr;

	if (!test())
	{
		cout << "ѕроблемы";
		return 0;
	}
	cout << "”правление:" << endl;
	cout << "0 - выйти" << endl;
	cout << "1 Ц добавить значение в сортированный список" << endl;
	cout << "2 Ц удалить значение из списка" << endl;
	cout << "3 Ц распечатать список" << endl;

	int reading = 0;
	bool checking = false;

	while (!checking)
	{
		cin >> reading;
		switch (reading)
		{
		case 0:
			checking = true;
			break;

		case 1:
		{
			int value1 = 0;
			cin >> value1;
			add(value1, workingList);
			break;
		}

		case 2:
		{
			int value2 = 0;
			cin >> value2;
			deleteElement(value2, workingList);
			break;
		}

		case 3:
		{
			print(workingList);
			break;
		}

		default:
			cout << "ќшибка исполнени€";
		}
	}

	deleteList(workingList);
	return 0;
}