#include<iostream>
using namespace std;
int main()
{
	int num1, num2;
	cout << "Enter two number: " << endl;
	cin >> num1 >> num2;
	int output = num1 + num2;
	cout << "The two numbers are " << num1 << " and " << num2 << endl;
	cout << "The sum is: " << output << endl;
	return 0;
}