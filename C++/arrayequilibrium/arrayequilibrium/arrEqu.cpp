//#include<iostream>
//using namespace std;
//int sumBefore(int a[], int in)
//{
//	int s = 0;
//	for (int i = 0;i < in;i++)
//	{
//		s = s + a[i];
//	}
//	return s;
//}
//int sumAfter(int a[],int si, int in)
//{
//	int s = 0;
//	in++;
//	for (int i = in;i < si;i++)
//	{
//		s = s + a[i];
//	}
//	return s;
//}
//int equIndex(int a[], int s)
//{
//	int index = -1;
//	int s1 = a[0],s2;
//	s2 = sumAfter(a, s, 0);
//	if (s1 == s2)
//	{
//		return 0;
//	}
//	else 
//	{
//		for (int i = 1;i < s - 1 && index == -1;i++)
//		{
//			s1 = sumBefore(a, i);
//			s2 = sumAfter(a, s, i);
//			if (s1 == s2)
//			{
//				index = i;
//			}
//		}
//		if (index == -1)
//		{
//			s1 = sumBefore(a, s - 1);
//			s2 = a[s - 1];
//			if (s1 == s2)
//			{
//				index = s - 1;
//			}
//		}
//	}
//	return index;
//}
//int main()
//{
//	int a[8];
//	for (int i = 0;i < 8; i++)
//	{
//		cin >> a[i];
//	}
//	cout << equIndex(a, 8);
//}