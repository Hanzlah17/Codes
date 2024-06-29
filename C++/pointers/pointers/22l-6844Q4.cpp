//#include<iostream>
using namespace std;
int input(int* array, int size)
{
	int c = 0;
	bool b = 0;
	int* end = array + size;
	for (int* i = array;i < end && b == 0;i++)
	{
		cout << "Enter the number= ";
		cin >> *i;
		c++;
		if (*i == -1)
		{
			b = 1;
		}
	}
	return c;
}
void print(int* array, int size)
{
	int* end = array + size;
	for (int* i = array;i < end;i++)
	{
		cout << *i << "\t";
	}
}
void copy(int* array, int size, int* array2)
{
	int* j = array + size;
	int* k = array2;
	for (int* i = array;i < j;i++)
	{
		*k = *i;
		k++;
	}
}
void main()
{
	int size = 5;
	int* array = new int[size];
	int c = input(array, size);
	int* temp = array;
	while (*(temp + c) != -1)
	{
		int* tem = array;
		delete[] array;
		int* array = new int[size * 2];
		copy(tem, c, array);
		temp = array + c;
		size = size * 2;
		int c1 = input(temp, size);
		c = c1 + c;

	}
	print(temp, c);
}