#include<iostream>
using namespace std;
void spaces(int a)
{
	for (int i = 1;i <= a;i++)
	{
		cout << " ";
	}
}
void pluses(int a)
{
	for (int i = 1;i <= a;i++)
	{
		cout << "+";
	}
}
int main()
{
	int sp=1;
	spaces(3);
	pluses(1);
	cout << endl;
	for (int i = 2;i <=4;i++)
	{
		spaces(4 - i);
		pluses(1);
		spaces(sp);
		pluses(1);
		sp = sp + 2;
		cout << endl;
	}
	int s=5;
	for (int i = 1;i < 3;i++)
	{
		s = s - 2;
		spaces(i);
		pluses(1);
		spaces(s);
		pluses(1);
		cout << endl;
	}
	spaces(3);
	pluses(1);
	return 0;
}
