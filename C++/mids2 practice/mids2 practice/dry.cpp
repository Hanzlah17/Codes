#include<iostream>
using namespace std;
int main()
{
	int s;
	for (int i = 1;i < 8;i++)
	{
		s = 0;
		for (int j = 1;j < i;j++)
		{
			s = s - j;
		}
		cout << s * s;
		cout << endl;
	}
}