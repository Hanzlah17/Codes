#include <iostream>
using namespace std;
bool issorted(int a[])
{
	bool b = 0;
	int c = 0;
	for (int i = 0;i+1 < 6;i++)
	{
		if (a[i] < a[i + 1])
		{
			c++;
		}
	}
	if (c == 5)
	{
		b = 1;
	}
	if (b == 0)
	{
		c = 0;
		for (int i = 0;i + 1 < 6;i++)
		{
			if (a[i] > a[i + 1])
			{
				c++;
			}
		}
		if (c == 5)
		{
			b = 1;
		}
	}
	return b;
}
int main()
{
	int a[6];
	for (int i = 0;i < 6;i++)
	{
		cout << "enter " << i + 1 << " element of array= ";
		cin >> a[i];
		cout << endl;
	}
	if (issorted(a))
	{
		cout << "array is sorted";
	}
	else
	{
		cout << "array is not sorted";
	}
}