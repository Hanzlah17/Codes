//#include<iostream>
//using namespace std;
////secondary function
//int helper(int a[][3], int b[][3], int i, int j)
//{
//	int s = 0;
//	for (int k = 0;k < 3;k++)
//	{
//		s = s + a[i][k] * b[k][j];
//	}
//	return s;
//}
//void matrixmultiplier(int a[][3], int b[][3], int c[][3])
//{
//	for (int i = 0;i < 3;i++)
//	{
//		for (int j = 0;j < 3;j++)
//		{
//			c[i][j] = helper(a, b, i, j);
//		}
//	}
//}
//int main()
//{
//	int a[3][3];
//	int b[3][3];
//	int c[3][3];
//	cout << "---------Matrix1----------\n";
//	for (int i = 0;i < 3;i++)
//	{
//		cout << "---------row" << i + 1 << "----------\n";
//		for (int j = 0;j < 3;j++)
//		{
//			cout << "Enter " << j + 1 << " element= ";
//			cin >> a[i][j];
//		}
//	}
//	cout << "---------Matrix2----------\n";
//	for (int i = 0;i < 3;i++)
//	{
//		cout << "---------row" << i + 1 << "----------\n";
//		for (int j = 0;j < 3;j++)
//		{
//			cout << "Enter " << j + 1 << " element= ";
//			cin >> b[i][j];
//		}
//	}
//	matrixmultiplier(a, b, c);
//	cout << "---------resultant----------\n";
//	for (int i = 0;i < 3;i++)
//	{
//		for (int j = 0;j < 3;j++)
//		{
//			cout<< c[i][j]<<" ";
//		}
//		cout << endl;
//	}
//}