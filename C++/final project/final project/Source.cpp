#include<iostream>
#include<time.h>
#include"help.h"
using namespace std;
int main()
{
	srand(time(NULL));
	int a[8][8];
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			a[i][j] = rand() % 4;
		}
	}
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}