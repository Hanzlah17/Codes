//#include <iostream>
//using namespace std;
//int main()
//{
//	int a[10];
//	for (int i = 0;i < 10;i++)
//	{
//		cout << "Enter the " << i + 1 << " number of array= ";
//		cin >> a[i];
//		cout << endl;
//	}
//	int max = a[0], index = 0;
//	for (int i = 0;i < 10;i++)
//	{
//		if (max < a[i])
//		{
//			max = a[i];
//			index = i;
//		}
//	}
//	int max2 = 0,index2=0;
//	for (int i = 0;i < 10;i++)
//	{
//		if (max2 < a[i]&& a[i]<max)
//		{
//			max2 = a[i];
//			index2 = i;
//		}
//	}
//	cout << "the second largest element of array is " << max2 << " and is at " << index2;
//
//}