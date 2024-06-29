#include<iostream>
using namespace std;
bool helper(int a[][6], int b[][3], int r, int s)
{
	bool b1 = 1;
	for (int i = 0, k = r;i < 3;i++, k++)
	{
		for (int j = 0, l = s;j < 3;j++, l++)
		{
			if (a[k][l] != b[i][j])
			{
				b1 = 0;
			}
		}
	}
	return b1;
}
bool Exist(int a[][6], int b[][3])
{
	bool c = 0;
	for (int i = 0;i < 4 && c == 0;i++)
	{
		for (int j = 0;j < 4 && c == 0;j++)
		{
			if (helper(a, b, i, j))
			{
				c = 1;
			}
		}
	}
	return c;
}
int main()
{
	int a[6][6];
	int b[3][3];
	cout << "-------Array---------\n";
	for (int i = 0;i < 6;i++)
	{
		cout << "Row" << i + 1 << endl;
		for (int j = 0;j < 6;j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "-------Pattern---------\n";
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cin >> b[i][j];
		}
	}
	cout << Exist(a, b);
}