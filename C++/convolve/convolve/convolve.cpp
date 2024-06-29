#include<iostream>
using namespace std;
void multiply(int a[][3], int b[][3])
{
	int s = 0;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			s =s+ a[i][j] * b[i][j];
		}
	}
	cout << s;
}
void convolve(int a[][5], int f[][3])
{
	int b[3][3];
	int x = 0, y = 0;
	//row1
	for (int l = 0;l < 3;l++)
	{
		for (int k = 0;k < 3;k++)
		{
			for (int j = l;j < l+3;j++)
			{
				for (int i = k;i < k + 3;i++)
				{
					b[x][y] = a[i][j];
					y++;
				}
				x++;
				y = 0;
			}
			multiply(b, f);
			cout << " ";
			x = 0;
		}
		cout << endl;
	}
}
int main()
{
	int a[5][5],b[3][3];
	cout << "-------Matrix------" << endl;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			cout << "Enter " << j + 1 << " element of row" << i + 1 << " = ";
			cin >> a[i][j];
			cout << endl;
		}
	}
	cout << "---filter---" << endl;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << "Enter " << j + 1 << " element of row" << i + 1 << " = ";
			cin >> b[i][j];
			cout << endl;
		}
	}
	cout << "-----convolved Matrix-----" << endl;
	convolve(a, b);
}