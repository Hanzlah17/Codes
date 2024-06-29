#include<iostream>
using namespace std;
bool fibo(int a[], int s)
{
	bool b = 0;
	if (a[0] == 0 || a[0] == 1 && a[1] == 1)
	{
		for (int j = 0;j < s - 2;j++)
		{
			if (a[j] + a[j + 1] == a[j + 2])
			{
				b = 1;
			}
			else
			{
				b = 0;
			}
		}
	}
	return b;
}
int main()
{
	int data[10];
	for (int i = 0;i < 10 ; i++)
	{
		cout << "Enter the " << i + 1 << " number of array= ";
		cin >> data[i];
		cout << endl;
	}
	int c = fibo(data, 10);
	if (c == 1)
	{
		cout << "Array has Fibonacci Sequence" << endl;
	}
	else
	{
		cout << "Array does not have Fibonacci Sequence" << endl;
	}
	system("pause");
	return 0;
}