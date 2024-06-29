#include <iostream>
using namespace std;
int main()
{
	int i, j, s1=0,s2=0;
	int a[10], b[10];
	cout << "Array 1" << endl;
	for (i = 0;i < 10;i++)
	{
		cout << "Enter the number= ";
		cin >> a[i];
		s1 = s1 + a[i];
		cout << endl;
	}
	cout << "Array 2" << endl;
	for (j = 0; j < 10; j++)
	{
		cout << "enter the number= ";
		cin >> b[j];
		s2 = s2 + b[j];
		cout << endl;
	}
	if (s1 == s2)
	{
		cout << "Same" << endl;
	}
	else if (s1 > s2)
	{
		for (i = 0;i < 10;i++)
		{
			cout << a[i] << " ";
		}
	}
	else if (s2 > s1)
	{
		for (j = 0;j < 10;j++)
		{
			cout << b[j] << " ";
		}
	}
	system("pause");
	return 0;
}