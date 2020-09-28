#include<iostream>
#include<math.h>

using namespace std;


void print(int*& arr, int& count)
{
	for (int i = 0; i < count; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void expand(int*& arr, int& count, int& cap)
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
void add(int*& arr, int& count, int& cap)
{
	int a;
	int b; 
	int n;
	int i;
	cout << "Введите промежуток [a,b] и количество n" << endl;
	cin >> a >> b >> n;
	for (i = 0; i < n; ++i)
	{
		if (count == cap) expand(arr, count, cap);
		arr[count] = rand() % (b - a + 1) + a;
		++count;
	}
	print(arr, count);
}
void reverse(int*& arr, int& count)
{
	int c = 0;
	for (int i = 0; i <= (count / 2); ++i)
	{
		c = arr[i];
		arr[i] = arr[count - i];
		arr[count - i] = c;
	}
	print(arr, count);
}
void pair_reverse(int*& arr, int& count)
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
	print(arr, count);
}
void cyclic_shift(int*& arr, int& count)
{
	int t;
	t = arr[count - 1];
	for (int j = count - 2; j >= 0; j--)
	{
		arr[j + 1] = arr[j];
	}
	arr[0] = t;
	print(arr, count);
}
void half_reverse(int*& arr, int& count)
{
	int n;
	int c;
	cout << "Введите число, делящее массив" << endl;
	cin >> n;
	int n_l = n - 1;
	int n_r = n;
	int i = 0;
	while (i < n_l)
	{
		c = arr[i];
		arr[i] = arr[n_l];
		arr[n_l] = c;
		i++;
		n_l--;
	}
	int new_count = count;
	while (n_r < new_count)
	{
		c = arr[n_r];
		arr[n_r] = arr[new_count - 1];
		arr[new_count - 1] = c;
		n_r++;
		new_count--;
	}
	print(arr, count);
}
void choice(int*& arr, int& count, int& in, int& cap)
{
	switch (in)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		add(arr, count, cap);
		break;
	}
	case 2:
	{
		reverse(arr, count);
		break;
	}
	case 3:
	{
		pair_reverse(arr, count);
		break;
	}
	case 4:
	{
		cyclic_shift(arr, count);
		break;
	}
	case 5:
	{
		half_reverse(arr, count);
		break;
	}
	}
}
void menu(int*& arr, int& count, int& cap)
{
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
		choice(arr, count, in, cap);
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
		if (count == cap)
		{
			expand(arr, count, cap);
		}
		arr[count] = x;
		count++;
	}
	cout << endl;
	menu(arr, count, cap);
	delete[] arr;
	return 0;
}

