#include<iostream>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить в список 10 случайных положительных двузначных чисел и вывести список" << endl;
	cout << "2 - Добавить в список 10 случайных отрицательных двузначных чисел и вывести список" << endl;
	cout << "3 - Поменять местами первый минимальный и последний максимальный элемент и вывести список" << endl;
	cout << "4 - Перемешать все элементы массива и вывести массив" << endl;
	cout << "5 - Заменить каждый отрицательный элемент массива на 0" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		for (int i = 0; i < 11; ++i)
		{
			a.add(rand() % 90 + 10);
		}
		cout << a.toString() << endl;
	}
	break;
	case 2:
	{
		for (int i = 0; i < 11; ++i)
		{
			a.add(-(rand() % 90 + 10));
		}
		cout << a.toString() << endl;
	}
	break;
	case 3:
	{
		int index1;
		int index2;
		int max = a.get(0);
		int min = a.get(0);
		for (int i = 0; i < a.length(); ++i)
		{
			if (max <= a.get(i))
			{
				index1 = i;
				max = a.get(i);
			}
			for (int j = 0; j < a.length(); ++j)
			{
				if (min > a.get(j))
				{
					index2 = j;
					min = a.get(j);
				}
			}
			a.swap(index1, index2);
			cout << a.toString() << endl;
		}
		break;
	}
	case 4:
	{
		for (int i = 0; i < a.length(); ++i)
		{
			a.swap(i, rand() % a.length());
		}
		cout << a.toString() << endl;
	}
	break;
	case 5:
	{
		for (int i = 0; i < a.length(); ++i)
		{
			if (a.get(i) < 0) a.set(i, 0);
		}
		cout << a.toString() << endl;
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;
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