#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
int minmax(int a, int b, bool f)
{
	if (f == 1)
	{
		return max(a, b);
	}
	else
	{
		if (a < b)
		{
			return a;
		}
		return b;
	}
}
char cap(char a)
{
	if (a >= 'a' && a <= 'z')
	{
		return (a - 32);
	}
	return a;
}
void tocap(char& a)
{
	if (a >= 'a' && a <= 'z')
	{
		a= a - 32;
	}
	return ;
}
int count(int a[], int s, int k)
{
	int c = 0;
	for (int i = 0;i < s;i++)
	{
		if (a[i] == k)
		{
			c = c + 1;
		}
	}
	return c;
}
bool search(int a[], int s, int k)
{
	bool b = 0;
	for (int i = 0;i < s;i++)
	{
		if (a[i] == k)
		{
			b =  1;
		}
	}
	return b;
}
int countfrom(int a[], int s, int b, int k)
{
	int c = 0;
	for (int i = b;i < s;i++)
	{
		if (a[i] == k)
		{
			c = c + 1;
		}
	}
	return c;
}
bool searchtill(int a[], int s, int c,int k)
{
	bool b = 0;
	for (int i = 0;i < c;i++)
	{
		if (a[i] == k)
		{
			b = 1;
		}
	}
	return b;
}
void printfrequency(int a[], int s)
{
	for (int i = 0;i < s;i++)
	{
		int k = a[i];
		int c = countfrom(a,s,0,k);
		bool b = searchtill(a, s, 1, k);
		if (b == 1)
		{
			c++;
		}
		cout << "The frequency of " << k << " in array is= " << c << endl;
	}
}
int main()
{
	int a = 1, b = 45;
	int data[10], key;
	char r='d',r1='k';
	//function 1
	int m = max(a, b);
	cout << m;
	cout << endl;
	//function 2
	int n = minmax(a, b,0);
	cout << n;
	cout << endl;
	//function 3
	char s = cap(r);
	cout << s;
	cout << endl;
	//function 4
	 tocap(r1);
	 cout << r1;
	 cout << endl;
	 //function 5
	 for (int j = 0;j < 10;j++)
	 {
		 cout << "Enter the " << j + 1 << " number of array= ";
		 cin >> data[j];
		 cout << endl;
	 }
	 cout << "Enter the number to be searched= ";
	 cin >> key;
	 int c1 = count(data, 10, key);
	 cout << c1;
	 cout << endl;
	 //function 6
	 bool f = search(data, 10, key);
		 cout << f;
		 cout << endl;
     //function 7
		 int st;
		 cout << "Enter the index from where onwards the key is to be searched= ";
		 cin >> st;
		 int c2 = countfrom(data, 10, st, key);
		 cout << c2;
		 cout << endl;
	//function 8
		 int end;
		 cout << "Enter the index until where the key is to be searched= ";
		 cin >> end;
		 bool y = searchtill(data, 10, end, key);
		 cout << y;
		 cout << endl;
    //function 9
		 int a[10] = { 1,1,1,2,3,4,4,5,6,0 };
		 printfrequency(a, 10);
	return 0;
}