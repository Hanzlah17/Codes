#include<iostream>
using namespace std;
int sum(int a, int b)
{
	int s = 0;
	static int count = 0;
	if (count < 5)
	{
		s = a + b;
		count++;
		return s;
		
	}
	else
	{
		cout << "paisa dyy\n";
		return 0;
	}
}
int main()
{
	for (int i = 0;i < 10;i++)
	{
		cout << sum(5, 6);
		cout << " ";
	}
}