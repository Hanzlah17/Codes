//#include<iostream>
//#include<stdio.h>
//using namespace std;
//bool helper(char a[],char b[], int j)
//{
//	bool c = 1;
//	int k = 0;
//	for (int i = j;a[i] != '\0' && c == 1 && a[i] != ' ' && b[k] != '\0';i++)
//	{
//		if (a[i] != b[k])
//		{
//			c = 0;
//		}
//		k++;
//	}
//	return c;
//}
//bool Exist(char a[], char b[])
//{
//	bool d = 0;
//	int i = 0;
//	while (a[i] != '\0' && d == 0)
//	{
//		if (helper(a, b, i) && a[i]!=' ')
//		{
//			d = 1;
//		}
//		i++;
//	}
//	return d;
//}
//int main()
//{
//	char data[3][100],key[50];
//	for (int i = 0;i < 3;i++)
//	{
//		gets_s(data[i], 100);
//	}
//	cout << "Enter the string to search: ";
//	cin >> key;
//	for (int i = 0;i < 3;i++)
//	{
//		if (Exist(data[i], key))
//		{
//			cout << data[i];
//		}
//	}
//}