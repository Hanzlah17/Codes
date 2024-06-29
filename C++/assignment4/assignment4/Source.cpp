#include<iostream>
using namespace std;
int FindMinMax(int& max)
{
	max = -1000000000;
	int input = 0,min=1000000;
	while (input != -1)
	{
		cout << "Enter the number= ";
		cin >> input;
		if (input != -1 && min > input)
		{
			min = input;
		}
		if (input != -1 && max < input)
		{
			max = input;
		}
	}
	return min;
}
int main()
{
	int max=0;
	int min = FindMinMax(max);
	cout << "Maximum input is= " << max << endl;
	cout << "Minimum input is= " << min << endl;
	system("pause");
	return 0;
}