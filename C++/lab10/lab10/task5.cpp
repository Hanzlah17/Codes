#include<iostream>
using namespace std;
int main()
{
	int a[3][3], b[3][3],c[3][3];
	cout << "--------Matrix1-------" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << "Enter the " << j + 1 << " element of row " << i + 1<<" = ";
			cin >> a[j][i];
		}
	}
	cout << "--------Matrix2-------" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << "Enter the " << j + 1 << " element of row " << i + 1<<" = ";
			cin >> b[j][i];
		}
	}
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	cout << "--------Matrix1-------" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "--------Matrix2-------" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << b[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "--------Resultant-------" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << c[i][j];
		}
		cout << endl;
	}
}
	