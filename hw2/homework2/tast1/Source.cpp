#include<iostream>

using namespace std;

void expand(int& count, int& cap, int*& arr)
{
	if (count == cap)
	{
		cap *= 2;
		int* temp = new int[cap];
		for (int i = 0; i < count; ++i)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
}
 void add1 (int& count, int& cap, int*& arr)
{
	 int x;
	 cout << "Введите число" << endl;
	 cin >> x;
	 expand(count, cap, arr);
	 arr[count] = x;
	 ++count;
}
 void print(int& count, int*& arr)
 {
	 int i;
	 for (i = 0; i < count; ++i)
		 cout << arr[i] << " ";
	 cout << endl;
 }
 void max(int& count, int*& arr)
 {
	 int i;
	 int max;
	 int num;
	 max = arr[0];
	 num = 0;
	 for (i = 0; i <= count; ++i)
	 {
		 if (arr[i] > max)
		 {
			 max = arr[i];
			 num = i;
		 }
	 }
	 cout << "Номер(а) максимального(ых) элемента(ов) " << endl;
	 for (i = 0; i < count; ++i)
	 {
		 if (max == arr[i])
			 cout << i << " ";
	 }
	 cout << endl;
 }
 void min(int& count, int*& arr)
 {
	int i;
	int min = arr[0];
	for (i = 1; i < count; ++i)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	cout << "Минимальный элемент массива " << min << endl;
 }
 void summa(int& count, int*& arr)
 {
	int i; 
	int sum = arr[0];
	for (i = 1; i < count; ++i)
		sum = sum + arr[i];
	cout << "Сумма" << sum << endl;
 }
 void reverse(int& count, int*& arr)
 {
	 int i;
	 for (i = count; i >= 0; --i)
		 cout << arr[i] << " ";
	 cout << endl;
 }
 void choise(int*& arr, int& count, int& in, int& cap)
 {
	 switch (in)
	 {
	 case 0:
	 {
		 break;
	 }
	 case 1:
	 {
		 add1(count, cap, *&arr);
		 break;
	 }
	 case 2:
	 {
		 print(count, *&arr);
		 break;
	 }
	 case 3:
	 {
		 max(count, *&arr);
		 break;
	 }
	 case 4:
	 {
		 min(count, *&arr);
		 break;
	 }
	 case 5:
	 {
		 summa(count, *&arr);
		 break;
	 }
	 case 6:
	 {
		 reverse(count, *&arr);
		 break;
	 }
	 }
 }
int main()
{
	setlocale(LC_ALL, "Russian");
	int cap;
	cap = 10;
	int* arr = new int[cap];
	cout << "Введите элементы массива, последняя цифра 0" << endl;
	int count = 0;
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		expand(count, cap, arr);
		arr[count] = x;
		count++;
	}
	cout << endl;
	int in = -1;
	while (in != 0)
	{
			cout << "0 - Выход из программы" << endl 
			<< "1 - Добавить число в массив" << endl 
			<< "2 - Вывести массив на экран" << endl 
			<< "3 - Найти номер максимального элемента массива" 
			<< endl << "4 - Найти минимальный элемент массива" 
			<< endl << "5 - Посчитать сумму элементов массива" 
			<< endl << "6 - Вывести массив в обратном порядке" 
			<< endl;
		cin >> in;
		choise(arr, count, in, cap);
	}
	delete[] arr;
	return 0;
}

