#include<iostream>
using namespace std;
int main()
{
	int n,ma,mi;
	cout << "enter the number= ";
	cin >> n;
	 ma = n;
	 mi = n;
	while (n >= 0)
	{
		cout << "enter the number= ";
			cin >> n;
			if (n > ma)
			{
				ma = n;
			}
			else if (n < mi && n>=0)
			{
				mi = n;
			}
	}
	cout << "The largest value is= " << ma << endl;
	cout << "The smallest value is= " << mi << endl;
	system("pause");
	return 0;
}