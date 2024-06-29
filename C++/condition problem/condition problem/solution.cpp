#include<iostream>
using namespace std;
int main()
{
	int i=1,a=1,s=0;
	while (i <= 10 || s < 70 || a < 10)
	{
		cout << "Enter a number= ";
		cin >> a;
		cout << endl;
		s = s + a;
		i++;
	}
	system("pause");
	return 0;
}