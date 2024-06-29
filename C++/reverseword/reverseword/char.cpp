//#include<iostream>
//#include<stdio.h>
//using namespace std;
//bool helper(char a[], char b[], int j)
//{
//	bool c = 1;
//	int k = 0;
//	for (int i = j; a[i] != '\0' && a[i] != ' ' && b[k] != '\0' && c==1;i++, k++)
//	{
//		if (a[i] != b[k])
//		{
//			c = 0;
//		}
//	}
//	return c;
//}
//bool Exist(char a[], char b[])
//{
//	bool b1 = 0;
//	int i = 0;
//	while (a[i] != '\0' && b1==0)
//	{
//		if (helper(a, b, i) && a[i] != ' ')
//		{
//			b1 = 1;
//		}
//		i++;
//	}
//	return b1;
//}
//int main()
//{
//	char a[100],b[50];
//	gets_s(a, 100);
//	cout << "Enter the word to search: ";
//	cin >> b;
//	cout << Exist(a, b);
//}