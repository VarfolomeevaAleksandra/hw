#include<iostream>

using namespace std;

void print(int& count, int*& arr)
{
	for (int i = 0; i < count; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void expand(int& count, int& cap, int*& arr)
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
void add(int& count, int& cap, int*& arr)
{
	int a,b,n;
	int i;
	cout << "Введите промежуток [a,b] и количество n" << endl;
	cin >> a >> b >> n;
	for (i = count; i < (count + n); ++i)
	{
		arr[i] = rand() % (b - a + 1) + a;
		++count;
	}
	print(count, arr);
}
void reverse(int& count, int*& arr)
{
	int c;
	for (int i = 0; i <= (count / 2); ++i)
	{
		c = arr[i];
		arr[i] = arr[count - i];
		arr[count - i] = arr[i];
	}
	print(count, arr);
}
void pair_reverse(int& count, int*& arr)
{
	int i;
	int c;
	for (i = 0; i < count; i = i + 2)
	{
		if ((i + 1) > count)
			break;
		c = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = c;
	}
	print(count, arr);
}
void cyclic_shift(int& count, int*& arr)
{
	int t;
	t = arr[count - 1];
	for (int j = count - 2; j >= 0; j--)
	{
		arr[j + 1] = arr[j];
	}
	arr[0] = t;
	print(count, arr);
}
void half_reverse(int& count, int*& arr)
{
	int n;
	int c;
	cout << "Введите число, делящее массив" << endl;
	cin >> n;
	for (int i = 0; i < (n / 2); ++i)
	{
		c = arr[i];
		arr[i] = arr[n - i];
		arr[n - i] = arr[i];
	}
	for (int i = n; i <= (((count - n)  / 2) + n); ++i)
	{
		c = arr[i];
		arr[i] = arr[count - i];
		arr[count - i] = arr[i];
	}
	print(count, arr);
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
		add(count, cap, *&arr);
		break;
	}
	case 2:
	{
		reverse(count, *&arr);
		break;
	}
	case 3:
	{
		pair_reverse(count, *&arr);
		break;
	}
	case 4:
	{
		cyclic_shift(count, *&arr);
		break;
	}
	case 5:
	{
		half_reverse(count, *&arr);
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
		cout << "0 - Выход из программы" <<
			endl << "1 - Добавить в массив n случайных чисел в промежутке от a до b(n, a, b вводится с клавиатуры)" <<
			endl << "2 - Развернуть массив" <<
			endl << "3 - Поменять элементы массива местами в парах.Если число элементов нечетно, последний элемент остается на своем месте" <<
			endl << "4 - Циклический сдвиг вправо на 1" <<
			endl << "5 - Развернуть две половинки массива.n - индекс элемента, разделяющего половинки" <<
			endl;
		cin >> in;
		choise(arr, count, in, cap);
	}
	delete[] arr;
	return 0;	
}

