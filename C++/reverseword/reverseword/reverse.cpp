//#include<iostream>
//#include<stdio.h>
//using namespace std;
//void reverse(char a[])
//{
//	int j = strlen(a);
//	j--;
//	for (int i = 0;i < j;i++)
//	{
//		swap(a[i], a[j]);
//		j--;
//	}
//}
//void print(char a[])
//{
//	for (int i = 0;a[i] != '\0';i++)
//	{
//		cout << a[i];
//	}
//}
//void wordreverse(char a[])
//{
//	int s = strlen(a);
//	char b[50];
//	int j = 0;
//	for (int i = 0;a[i] != '\0';i++)
//	{
//		if (a[i] != ' ')
//		{
//			b[j] = a[i];
//			j++;
//		}
//		else
//		{
//			b[j] = '\0';
//			reverse(b);
//			print(b);
//			cout << " ";
//			j = 0;
//		}
//	}
//	b[j] = '\0';
//	reverse(b);
//	print(b);
//	cout << " ";
//}
//int main()
//{
//	char a[50];
//	gets_s(a, 50);
//	cout << "------laiba answer--------\n";
//	wordreverse(a);
//	cout << "\n------ruban answer--------\n";
//	reverse(a);
//	print(a);
//}