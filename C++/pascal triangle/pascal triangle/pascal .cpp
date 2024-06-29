#include<iostream>
using namespace std;
int main()
{
	int a,k;
	cout << "enter the size of triangle= ";
	cin >> a;
	k = a;
	for (int i = 1;i <= a;i++)
	{
		for (int j = 1;j < k;j++)
		{
			cout << " ";
		}
		k--;
		int x = 1;
		for (int a = 1;a <= i;a++)
		{
			cout << x << " ";
			x = x * (i - a) / a;
		}
		cout << endl;
	}
	return 0;
}