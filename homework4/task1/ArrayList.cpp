#include"ArrayList.h"

using namespace std;

	ArrayList::ArrayList()
	{
		capacity = 10;
		count = 0;
		data = new int[10];
	}

	ArrayList::ArrayList(int cap)
	{
		capacity = cap;
		count = 0;
		data = new int[capacity];
	}

	//деструктор
	ArrayList::~ArrayList()
	{
		delete[] data;;
	}

	int ArrayList::errors(int index)
	{
		if ((index > count) or (index < 0)) return false;
		else return true;
	}
	void ArrayList::expand(int*& data1)
	{
		int* temp = new int(2 * capacity);
		for (int i = 0; i < count; ++i)
		{
			temp[i] = data1[i];
		}
		capacity *= 2;
		delete[] data1;
		data1 = temp;
	}

	int ArrayList::addInList(int num)
	{
		ArrayList b;
		int i = 0;
		while (true)
		{
			int x = 0;
			cin >> x;
			if (x == 0) break;
			b.data[i] = x;
			++i;

		}
		return addAll(num, b);
	}
	
	bool ArrayList::add(int element)
	{
		data[count] = element;
		count++;
		if (count == capacity)
		{
			expand(data);
		}
		return true;
	}

	
	bool ArrayList::add(int index, int element)
	{

		for (int i = count; i > index; --i)
		{
			data[i] = data[i - 1];
		}
		data[index] = element;
		count++;
		if (count == capacity)
		{
			expand(data);
		}
		return errors(index);
	}

	
	
	bool ArrayList::addAll(int index, ArrayList& list)
	{
		for (int i = index; i < index + list.count; ++i)
		{
			add(i, list.data[i - index]);
		}
		count += list.count;
		return errors(index);
	}

	
	void ArrayList::clear()
	{
		for (int i = 0; i < count; ++i)
		{
			data[i] = 0;
		}
		count = 0;
	}

	
	bool ArrayList::contains(int element)
	{
		int result = 0;
		for (int i = 0; i < count; ++i)
		{
			if (data[i] = element)
			{
				++result;
				break;
			}
		}
		return(result == 0 ? false : true);
	}

	
	int ArrayList::get(int index)
	{
		return(errors(index) == false ? -1 : data[index]);
	}

	
	int ArrayList::indexOf(int element)
	{
		int result = -1;
		for (int i = 0; i < count; ++i)
		{
			if (data[i] = element)
			{
				result = i;
				break;
			}	
		}
		return result;
	}

	bool ArrayList::isEmpty()
	{
		return(count == 0 ? true : false);
	}

	
	void ArrayList::print()
	{
		printf("[%d/%d]{", count, capacity);
		if (count == 0)
		{
			printf("EMPTY");
		}
		else
		{
			for (int i = 0; i < count; ++i)
			{
				printf("%d%s", data[i], (i == count - 1 ? "" : ", "));
			}
		}
		printf("}\n");
	}

	bool ArrayList::remove(int index)
	{
		for (int i = index; i < count - 1; ++i)
		{
			data[i] = data[i + 1];
		}
		data[count - 1] = 0;
		return errors(index);
	}

	
	int ArrayList::swap(int index1, int index2)
	{
		int c = 0;
		c = data[index1];
		data[index1] = data[index2];
		data[index2] = c;
		return((errors(index1) == errors(index2) == true) ? true : false);
	}
