#include<Windows.h>
#include<iostream>
#include<stdio.h>
using namespace std;
// helping functions
void textcolor(int a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, a);

}
char lower(char a)
{
	char l = a;
	if (a >= 65 && a <= 90)
	{
		l = a + 32;
	}
	return l;
}
bool prime(int a)
{
	bool b = 1;
	for(int i = 2;i < a && b==1 ;i++)
	{
		if (a % i == 0)
		{
			b = 0;
		}
	}
	return b;
}
void del(char a[1000], char i)
{
	for (int j = 0;a[j] != '\0';j++)
	{
		if (a[j] == i)
		{
			for (int i = j;a[i] != '\0';i++)
			{
				a[i] = a[i + 1];
			}
		}

	}
}
bool search(char a[1000], int s)
{
	bool b = 0;
	for (int i = 0;i < s;i++)
	{
		char l = lower(a[s]);
		if (a[i] == a[s] || l == a[i])
		{
			b = 1;
		}
	}
	return b;
}
// required functions
void takeinput(char a[1000])
{
	cout << "Enter the sentence: ";
	gets_s(a, 1000);
}
int uniquecounter(char a[1000], char a1[1000])
{
	int j = 0;
	for (int i = 0;a[i] != '\0';i++)
	{
		bool b = search(a, i);
		if (b == 0 && a[i] != ' ')
		{
			a1[j] = a[i];
			j++;
		}
		b = 0;
	}
	a1[j] = '\0';
	for (int i = 0;a1[i] != '\0';i++)
	{
		for (int j = 0;j < i;j++)
		{
			if (a1[i] == a1[j] + 32)
			{
				del(a1, a1[i]);
			}
		}
	}
	return (strlen(a1));
}
void chardictionary(char a[1000], char b[1000])
{
	int c = 0;
	for (int i = 0;b[i] != '\0';i++)
	{
		char l = lower(b[i]);
		for (int j = 0;a[j] != '\0';j++)
		{
			char d = lower(a[j]);
			if (b[i] == a[j] || l == d)
			{
				c++;
			}
		}
		cout << "the count of " << b[i] << " is" << c;
		cout << endl;
		c = 0;
	}
}
int rainbownumber(char a[1000],char b)
{
	int c = 0;
	char l = lower(b);
	for (int j = 0;a[j] != '\0';j++)
	{
		char d = lower(a[j]);
		if (b == a[j]|| l==d)
		{
			c++;
		}
	}
	if (c == 1)
	{
		return 0;
	}
	else if (c > 1 && c < 4)
	{
		return 1;
	}
	else if (c > 3 && c < 6)
	{
		return 2;
	}
	else if (c > 5 && c < 8)
	{
		return 3;
	}
	return 4;
}
void showmetherainbow(char a[1000], char c[4])
{
	for (int i = 0;a[i] != '\0';i++)
	{
		if (a[i] != ' ')
		{
			int c = rainbownumber(a, a[i]);
			if (c == 0)
			{
				textcolor(4);
			}
			else if (c == 1)
			{
				textcolor(2);
			}
			else if (c == 2)
			{
				textcolor(1);
			}
			else if (c == 3)
			{
				textcolor(5);
			}
			else
			{
				textcolor(6);
			}
		}
		cout << a[i];
	}
	cout << endl;
	int s = atoi(c);
	bool b;
	if (s % 2 == 0)
	{
		for (int i = 0;a[i] != '\0';i++)
		{
			 b = prime(i);
			if (b == 0)
			{
				textcolor(11);
				cout << a[i];
			}
			else
			{
				textcolor(7);
				cout << a[i];
			}
		}
	}
	else if (s % 2 == 1)
	{
		textcolor(7);
		cout << a[0];
		cout << a[1];
		for (int i = 2;a[i] != '\0';i++)
		{
			 b = prime(i);
			if (b == 1)
			{
				textcolor(13);
				cout << a[i];
			}
			else
			{
				textcolor(7);
				cout << a[i];
			}
		}
	}
	
}
int main()
{
	char a[1000], b[1000];
	char c[4] = { '6','8','4','5' };
	takeinput(a);
	int s = uniquecounter(a, b);
	chardictionary(a, b);
	showmetherainbow(a, c);
	textcolor(7);
	return 0;
}