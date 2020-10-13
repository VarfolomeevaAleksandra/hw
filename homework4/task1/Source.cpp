#include<iostream>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������� ������ �� �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - �������� ������� � �������" << endl;
	cout << "4 - ������� ������� �� �������" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - �������� ��������� ���������" << endl;
	cout << "7 - �������� ��������� ���������, ������� � ��������� �������" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		a.print();
	}
	break;
	case 2:
	{
		int element;
		cout << "������� �������" << endl;
		cin >> element;
		cout << a.add(element) << endl;
	}
	break;
	case 3:
	{
		int element;
		int index;
		cout << "������� ������� � ������" << endl;
		cin >> element >> index;
		cout << a.add(index, element) << endl;
	}
	break;
	case 4:
	{
		int index;
		cout << "������� ������" << endl;
		cin >> index;
		cout << a.remove(index) << endl;;
	}
	break;
	case 5:
	{
		int element;
		cout << "������� �������" << endl;
		cin >> element;
		cout << a.indexOf(element) << endl;
	}
	break;
	case 6:
	{
		cout << "������� ��������, ��������� �����" << endl;

		cout << a.addInList(a.count) << endl;;
	}
	break;
	case 7:
	{
		int index;
		cout << "������� ������" << endl;
		cin >> index;
		cout << "������ ��������, ��������� �����" << endl;
		cout << a.addInList(index) << endl;
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;
	ArrayList b;
	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}