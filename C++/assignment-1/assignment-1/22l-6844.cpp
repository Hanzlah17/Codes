#include<iostream>
#include<fstream>
using namespace std;
void GetSize(ifstream& file, int& size)
{
	file >> size;
}
int* GetArray(ifstream& file, int size)
{
	if (size > 0)
	{
		int* temp = new int[size];
		int* end = temp + size;
		for (int* i = temp;i < end;i++)
		{
			file >> *i;
		}
		return temp;
	}
	return 0;
}
void BubbleSort(int* array, int size)
{
	int* end = array + size;
	for (int* i = array;i < end;i++)
	{
		for (int* j = i;j < end;j++)
		{
			if (*i > *j)
			{
				swap(*i, *j);
			}
		}
	}
}
void DisplayArray(int* array, int size)
{
	int* end = array + size;
	for (int* i = array;i < end;i++)
	{
		cout << *i << "\t";
	}
}
int* MergeAndSort(int* array1, int A, int* array2, int B)
{
	int size = A + B;
	int* array = new int[size];
	int* i = array1;
	int* j = array2;
	int* k = array;
	int* end1 = array1 + A;
	int* end2 = array2 + B;
	while (i < end1 && j < end2)
	{
		if (*i < *j)
		{
			*k = *i;
			i++;
			k++;
		}
		else
		{
			*k = *j;
			j++;
			k++;
		}
	}
	while (i < end1)
	{
		*k = *i;
		i++;
		k++;
	}
	while (j < end2)
	{
		*k = *j;
		j++;
		k++;
	}
	return array;
}
void main()
{
	int size;
	int* array;
	ifstream file;
	file.open("Data1.txt");
	for (int i = 1;i < 4;i++)
	{
		cout << "\n         Test Case" << i << ":\n";
		GetSize(file, size);
		array = GetArray(file, size);
		if (array != 0)
		{
			cout << "Array before sorting:\n";
			DisplayArray(array, size);
			BubbleSort(array, size);
			cout << "\nArray after sorting:\n";
			DisplayArray(array, size);
		}
		else
		{
			cout << "size is invalid";
		}
		delete[] array;
	}
	file.close();
	cout << "\n---------------------------ANSWER2-------------------------------\n";
	ifstream file2;
	file2.open("Data2.txt");
	int size1, size2, size3;
	int* array1;
	int* array2;
	int* array3;
	for (int i = 1;i < 4;i++)
	{
		cout << "\n Test Case" << i << " :\n";
		GetSize(file2, size1);
		array1 = GetArray(file2, size1);
		cout << "\nARRAY 1: \n";
		DisplayArray(array1, size1);
		GetSize(file2, size2);
		array2 = GetArray(file2, size2);
		cout << "\nARRAY 2: \n";
		DisplayArray(array2, size2);
		cout << "\nMerged and Sorted Array: \n";
		array3 = MergeAndSort(array1, size1, array2, size2);
		size3 = size1 + size2;
		DisplayArray(array3, size3);
		delete[] array1;
		delete[] array2;
		delete[] array3;
	}
	file2.close();
}