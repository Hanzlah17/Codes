#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	char a[3][50];
	char key[50],c[50];
	int i = 0, j = 0,k=0;
	for (i = 0;i < 3;i++)
	{
		gets_s(a[i], 50);
	}
	i = 0;
	while (i < 3)
	{
		bool b = 0;
		int size = strlen(a[i]);
		for (j = 0;j < size && b==0;j++)
		{
			if (a[i][j] != ' ' && a[i][j] != '\0')
			{
				c[k] = a[i][j];
				k++;
			}
			else if (a[i][j] == ' ' || a[i][j] == '\0')
			{
				c[k] = '\0';
				cout << c;
				cout << endl;
				k = 0;
			}
			if (a[i][j] == '\0')
			{
				b = 1;
			}
		}
		i++;
	}
}