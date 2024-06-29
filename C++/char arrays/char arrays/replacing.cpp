#include<iostream>
#include<stdio.h>
using namespace std;
void helper(char a[], char tr, char r)
{
	for (int i = 0;a[i] != '\0';i++)
	{
		if (a[i] == tr)
		{
			a[i] = r;
		}
	}
}
void replacer(char a[][50], char tr, char r)
{
	for (int i = 0;i < 3;i++)
	{
		helper(a[i], tr, r);
	}
}
int main()
{
	char a[3][50],b,c;
	for (int i = 0;i < 3;i++)
	{
		gets_s(a[i], 50);
	}
	cout << "Enter the letter to replace: ";
	cin >> b;
	cout << "Enter the letter to replace with: ";
	cin >> c;
	replacer(a, b, c);
	for (int i = 0;i < 3;i++)
	{
		cout << a[i] << endl;
	}
}