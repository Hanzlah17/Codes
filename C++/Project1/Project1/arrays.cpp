#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a[6][6];
	char data[3][100];
	//input
	for (int i = 0;i < 6;i++)
	{
		for (int j = 0;j < 6;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0;i < 3;i++)
	{
		gets_s(data[i]);
	}
	//output
	for (int i = 0;i < 6;i++)
	{
		cout<< a[i];
	}
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;a[i][j] != '\0';j++)
		{

		}
	}
}