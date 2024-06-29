//#include<iostream>
//#include<stdio.h>
//using namespace std;
////secondary function
//bool check(char a)
//{
//	bool b = 0;
//	if (a < 'A' || (a>'Z' && a < 'a') || a>'z')
//	{
//		b = 1;
//	}
//	return b;
//}
//bool isPalindrome(char a[])
//{
//	bool c = 1;
//	int j = strlen(a);
//	j--;
//	int i = 0;
//	while(i<j && c == 1)
//	{
//		if (check(a[i]))
//		{
//			i++;
//		}
//		if (check(a[j]))
//		{
//			j--;
//		}
//		if (a[i] != a[j])
//		{
//			c = 0;
//		}
//		i++;
//		j--;
//	}
//	return c;
//}
//int main()
//{
//	char a[50];
//	gets_s(a, 50);
//	if (isPalindrome(a))
//	{
//		cout << "Palindrome";
//	}
//	else
//	{
//		cout << "Not a Palindrome";
//	}
//}