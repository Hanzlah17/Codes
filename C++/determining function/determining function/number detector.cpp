#include<iostream>
using namespace std;
bool prime(int a)
{
	bool b = 1;
	if (a == 2)
	{
		b = 1;
	}
	else if (a < 2)
	{
		b = 0;
	}
	else
	{
		for (int i = 2;i < a;i++)
		{
			if (a % i == 0)
			{
				b = 0;
			}
		}
	}
	return b;
}
bool armstrong(int a,int n)
{
	int r, c = a,s=0;
	bool b = 0;
	for (int i = 0;a > 0;i++)
	{
		r = a % 10;
		a = a / 10;
		int p = 1;
		for (int j = 1;j <= n;j++)
		{
			p = p * r;
		}
		s = s + p ;
	}
	if (s == c)
	{
		b = 1;
	}
	return b;
}
bool perfect(int a)
{
	int s = 0;
	bool b = 0;
	for (int i = 1;i < a;i++)
	{
		if (a % i == 0)
		{
			s=s+i;
		}
	}
	if (s == a)
	{
		b = 1;
	}
	return b;
}
int main()
{
	int n,m;
	cout << "Enter the number= ";
	cin >> n;
	/*cout << "Enter the number of digits= ";
	cin >> m;*/
	bool c = prime(n);
	if (c == 1)
	{
		cout << "given number is perfect";
	}
	else
	{
		cout << "given number is not perfect";
	}
}