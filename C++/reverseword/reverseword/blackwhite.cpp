//#include<iostream>
//using namespace std;
//int helper(int a[][4], int r, int c)
//{
//	int c1 = 0;
//	for (int i = r;i < (r + 3);i++)
//	{
//		for (int j = c;j < (c + 3);j++)
//		{
//			if (a[i][j] == 1)
//			{
//				c1++;
//			}
//		}
//	}
//	return c1;
//}
//void countwhite(int a[][4])
//{
//	int b = 0;
//	for (int i = 0;i < 3;i++)
//	{
//		for (int j = 0;j < 2;j++)
//		{
//			int c = helper(a, i, j);
//			if (c >= 4)
//			{
//				cout << "(" << i << "," << j << ")\n";
//				b++;
//			}
//		}
//	}
//	cout << "The white blocks= " << b;
//}
//int main()
//{
//	int a[5][4];
//	cout << "-------data--------\n";
//	for (int i = 0;i < 5;i++)
//	{
//		cout << "Row " << i + 1 << endl;
//		for (int j = 0;j < 4;j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	countwhite(a);
//}