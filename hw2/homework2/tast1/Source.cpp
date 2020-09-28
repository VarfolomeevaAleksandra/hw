#include<iostream>

using namespace std;

void expand(int* arr, int& count, int& cap)
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
void add1(int* arr, int& count, int& cap)
{
	int x;
	cout << "������� �����" << endl;
	cin >> x;
	if (count == cap)
		expand(arr, count, cap);
	arr[count] = x;
	++count;
}
void print(int* arr, int& count)
{
	int i;
	for (i = 0; i < count; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void max(int* arr, int& count)
{
	int i;
	int max;
	int num;
	max = arr[0];
	num = 0;
	for (i = 1; i <= count; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			num = i;
		}
	}
	cout << "�����(�) �������������(��) ��������(��) " << endl;
	for (i = 0; i <= count; ++i)
	{
		if (max == arr[i])
			cout << i << " ";
	}
	cout << endl;
}
void min(int* arr, int& count)
{
	int i;
	int min = arr[0];
	for (i = 1; i < count; ++i)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	cout << "����������� ������� ������� " << min << endl;
}
void summa(int* arr, int& count)
{
	int i;
	int sum = 0;
	for (i = 0; i < count; ++i)
		sum = sum + arr[i];
	cout << "�����" << sum << endl;
}
void reverse(int* arr, int& count)
{
	int i;
	for (i = count; i >= 0; --i)
		cout << arr[i] << " ";
	cout << endl;
}
void choi�e(int* arr, int& count, int& in, int& cap)
{
	switch (in)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		add1(arr, count, cap);
		break;
	}
	case 2:
	{
		print(arr, count);
		break;
	}
	case 3:
	{
		max(arr, count);
		break;
	}
	case 4:
	{
		min(arr, count);
		break;
	}
	case 5:
	{
		summa(arr, count);
		break;
	}
	case 6:
	{
		reverse(arr, count);
		break;
	}
	}
}
void menu(int*& arr, int& count, int& cap)
{

	int in = -1;
	while (in != 0)
	{
		cout << "0 - ����� �� ���������" << endl
			<< "1 - �������� ����� � ������" << endl
			<< "2 - ������� ������ �� �����" << endl
			<< "3 - ����� ����� ������������� �������� �������"
			<< endl << "4 - ����� ����������� ������� �������"
			<< endl << "5 - ��������� ����� ��������� �������"
			<< endl << "6 - ������� ������ � �������� �������"
			<< endl;
		cin >> in;
		choi�e(arr, count, in, cap);
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int cap;
	cap = 10;
	int* arr = new int[cap];
	cout << "������� �������� �������, ��������� ����� 0" << endl;
	int count = 0;
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		arr[count] = x;
		count++;
		if (count == cap)
		{
			expand(arr, count, cap);
		}
	}
	cout << endl;
	menu(arr, count, cap);
	delete[] arr;
	return 0;
}

