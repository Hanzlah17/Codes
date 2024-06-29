//#include<iostream>
//#include<stdio.h>
//using namespace std;
//bool Exist(char a[], char key[])
//{
//	char b[50];
//	bool c = 0;
//	int i = 0,j=0;
//	while (a[i] != '\0' && c == 0)
//	{
//		if (a[i] != ' ')
//		{
//			b[j] = a[i];
//			j++;
//		}
//		else
//		{
//			b[j] = '\0';
//			if (!strcmp(b, key))
//			{
//				c = 1;
//			}
//			j = 0;
//		}
//		i++;
//	}
//	if (c == 0)
//	{
//		b[j] = '\0';
//		if (!strcmp(b, key))
//		{
//			c = 1;
//		}
//	}
//	return c;
//}
//int main()
//{
//	char data[3][100], key[50];
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
//			cout << endl;
//		}
//	}
//}