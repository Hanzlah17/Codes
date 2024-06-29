#include<iostream>
#include<stdio.h>
using namespace std;
bool isExist(char a[], char b[])
{
	int k = 0, i = 0;
	bool c = 0;
	char key[50];
	int s = strlen(b);
	while(a[k]!='\0'&& c==0)
	{
		i = 0;
		while(i<s)
		{
			key[i] = a[k];
			k++;
			i++;
		}
		key[i] = '\0';
		if (!strcmp(key, b))
		{
			c = 1;
		}
	}
	return c;
}
int main()
{
	char a[50],b[50];
	gets_s(a, 50);
	cin >> b;
	if (isExist(a, b))
	{
		cout << "Exist";
	}
	else
	{
		cout << "!exist";
	}
	
}