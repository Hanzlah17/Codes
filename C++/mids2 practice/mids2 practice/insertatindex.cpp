//#include<iostream>
//using namespace std;
//void insertatindex(int a[], int s, int index, int n)
//{
//	int k=a[index];
//	a[index] = n;
//	for (int i = index + 1;i <s;i++)
//	{
//		int j = a[i];
//		a[i] = k;
//		k = j;
//	}
//}
//int main()
//{
//	int data[11];
//	for (int i = 0;i < 10;i++)
//	{
//		cout << "Enter the " << i + 1 << " number of array= ";
//		cin >> data[i];
//		cout << endl;
//	}
//	insertatindex(data, 11, 5, 9);
//	for (int i = 0;i < 10;i++)
//	{
//		cout << data[i] << "   " << i;
//		cout << endl;
//	}
//}