#include<iostream>
#include<fstream>
using namespace std;
void fill(ifstream& file, ofstream& even, ofstream& odd)
{
	int a;
	file.open("myFile.txt", ios::in);
	while (!file.eof())
	{
		file >> a;
		if (a % 2 == 0)
		{
			even.open("even.txt", ios::app);
			even << a << endl;
			even.close();
		}
		else
		{
			odd.open("odd.txt", ios::app);
			odd << a << endl;
			odd.close();
		}
	}
	file.close();
}
int main()
{
	ifstream file;
	ofstream odd, even;
	fill(file, even, odd);
}