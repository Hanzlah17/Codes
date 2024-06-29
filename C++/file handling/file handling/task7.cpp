#include<iostream>
#include<fstream>
using namespace std;
void takearray(ifstream& array, int array1[],int size)
{
	int i = 0;
	array.open("myarray.txt", ios::in);
	while (!array.eof() && i < size)
	{
		array >> array1[i];
		i++;
	}
	array.close();
}
int main()
{
	ifstream array;
	int array1[5];
	takearray(array, array1, 5);
	for (int i = 0;i < 5;i++)
	{
		cout << array1[i] << " ";
	}
}