#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
char** AllocateMemory(int r, int c)
{
	char** list = new char* [r];
	for (int i = 0;i < r;i++)
	{
		list[i] = new char[c];
	}
	return list;
}
bool StringCom(char* str1, char* str2)
{
	bool b = 1;
	for (int i = 0;str1[i] != '\0' && str2[i] != '\0' && b == 1;i++)
	{
		if (str1[i] != str2[i])
		{
			b = 0;
		}
	}
	if (b == 1 && (strlen(str1) != strlen(str2)))
	{
		b = 0;
	}
	return b;
}
void DeleteFromList(char** list, int size)
{
	for (int i = 0;i < size;i++)
	{
		for (int j = i+1;j < size;j++)
		{
			if (list[i] != 0 && list[j]!=0)
			{
				if (StringCom(list[i], list[j]))
				{
					delete[] list[j];
					list[j] = 0;
				}
			}
		}
	}
}
void DeAllocate(char** array, int r)
{
	for (int i = 0;i < r;i++)
	{
		if (array[i] != 0)
		{
			delete[] array[i];
		}
		
	}
	delete[] array;
}
void Print(char** array, int size)
{
	for (int i = 0;i < size;i++)
	{
		if (array[i] != 0)
		{
			cout << array[i] << "\n";
		}
	}
}
void main()
{
	int r = 50, c = 50;
	ifstream file;
	file.open("list.txt");
	char** list = AllocateMemory(r, c);
	for (int i = 0;i < r;i++)
	{
		file.getline(list[i], 50);
	}
	DeleteFromList(list, r);
	Print(list, r);
	DeAllocate(list, r);
	file.close();
}