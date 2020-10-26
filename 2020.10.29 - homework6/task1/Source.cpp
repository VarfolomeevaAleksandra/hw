#include<iostream>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "ÌÅÍÞ" << endl;
	cout << "0 - Âûõîä èç ïðîãðàììû" << endl;
	cout << "1 - Äîáàâèòü â ñïèñîê 10 ñëó÷àéíûõ ïîëîæèòåëüíûõ äâóçíà÷íûõ ÷èñåë è âûâåñòè ñïèñîê" << endl;
	cout << "2 - Äîáàâèòü â ñïèñîê 10 ñëó÷àéíûõ îòðèöàòåëüíûõ äâóçíà÷íûõ ÷èñåë è âûâåñòè ñïèñîê" << endl;
	cout << "3 - Ïîìåíÿòü ìåñòàìè ïåðâûé ìèíèìàëüíûé è ïîñëåäíèé ìàêñèìàëüíûé ýëåìåíò è âûâåñòè ñïèñîê" << endl;
	cout << "4 - Ïåðåìåøàòü âñå ýëåìåíòû ìàññèâà è âûâåñòè ìàññèâ" << endl;
	cout << "5 - Çàìåíèòü êàæäûé îòðèöàòåëüíûé ýëåìåíò ìàññèâà íà 0" << endl;
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
		ArrayList b(a.length());
		for (int i = 0; i < b.length(); ++i)
		{
			for (int j = 0; j < b.length(); ++j)
			{
				if (b.get(i) > b.get(j)) b.swap(i, j);
			}
		}
		a.swap(a.indexOf(b.get(0)), a.indexOf(b.get(b.length() - 1)));
		cout << a.toString() << endl;
	}
	break;
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