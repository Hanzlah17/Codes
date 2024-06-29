#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;
static int positionx = 100;
static int positiony = 150;


void myLine(int x1, int y1, int x2, int y2, float R, float G, float B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 10, RGB(R, B, G)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}

void Print(bool b)
{
	if (b)
	{
		myLine(700, 150, 700, 250, 255,255,255);
		myLine(700, 150, 750, 150, 255,255,255);
		myLine(700, 200, 750, 200, 255, 255, 255);
		myLine(750, 150, 750, 200, 255, 255, 255);

		myLine(800, 150, 800, 250, 255, 255, 255);
		myLine(800, 150, 850, 200, 255, 255, 255);
		myLine(850, 200, 900, 150, 255, 255, 255);
		myLine(900, 150, 900, 250, 255, 255, 255);

	}
	else
	{
		myLine(700, 150, 700, 250, 255, 255, 255);
		myLine(700, 150, 750, 150, 255, 255, 255);
		myLine(750, 150, 750, 250, 255, 255, 255);
		myLine(700, 200, 750, 200, 255, 255, 255);

		myLine(800, 150, 800, 250, 255, 255, 255);
		myLine(800, 150, 850, 200, 255, 255, 255);
		myLine(850, 200, 900, 150, 255, 255, 255);
		myLine(900, 150, 900, 250, 255, 255, 255);

	}
}


class node
{
public:
	node* up;
	node* down;
	node* right;
	node* left;
	bool printed;
	node()
	{
		up = down = right = left = 0;
		printed = 0;
	}
	void Print()
	{
		if (!printed)
		{
			if (up)
			{
				myLine(positionx, positiony - 30, positionx, positiony, 255, 255, 255);
			}
			if (down)
			{
				myLine(positionx, positiony + 30, positionx, positiony, 255, 255, 255);
			}
			if (left)
			{
				myLine(positionx - 30, positiony, positionx, positiony, 255, 255, 255);
			}
			if (right)
			{
				myLine(positionx + 30, positiony, positionx, positiony, 255, 255, 255);
			}
		}
		printed = 1;
	}
	~node()
	{
		up = down = right = left = 0;
		printed = 0;
	}
};
class Digit
{
private:
	node* pos1;
	node* pos2;
	node* pos3;
	node* pos4;
	node* pos5;
	node* pos6;
public:
	Digit()
	{
		pos1 = pos2 = pos3 = pos4 = pos5 = pos6 = 0;
	}
	void SetPattern(int digit)
	{
		if (digit == 0)
		{
			pos1 = new node;
			pos2 = new node;
			pos3 = new node;
			pos4 = new node;
			pos5 = new node;
			pos6 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos2->down = pos4;
			pos4->up = pos2;
			pos1->down = pos3;
			pos3->up = pos1;
			pos3->down = pos5;
			pos5->up = pos3;
			pos4->down = pos6;
			pos6->up = pos4;
			pos5->right = pos6;
			pos6->left = pos5;

		}
		else if (digit == 1)
		{
			pos2 = new node;
			pos4 = new node;
			pos6 = new node;
			pos2->down = pos4;
			pos4->up = pos2;
			pos4->down = pos6;
			pos6->up = pos4;
		}
		else if (digit == 2)
		{
			pos1 = new node;
			pos2 = new node;
			pos3 = new node;
			pos4 = new node;
			pos5 = new node;
			pos6 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos2->down = pos4;
			pos4->up = pos2;
			pos3->right = pos4;
			pos4->left = pos3;
			pos3->down = pos5;
			pos5->up = pos3;
			pos5->right = pos6;
			pos6->left = pos5;
		}
		else if (digit == 3)
		{
			pos1 = new node;
			pos2 = new node;
			pos3 = new node;
			pos4 = new node;
			pos5 = new node;
			pos6 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos2->down = pos4;
			pos4->up = pos2;
			pos3->right = pos4;
			pos4->left = pos3;
			pos4->down = pos6;
			pos6->up = pos4;
			pos5->right = pos6;
			pos6->left = pos5;
		}
		else if (digit == 4)
		{
			pos1 = new node;
			pos2 = new node;
			pos3 = new node;
			pos4 = new node;
			pos6 = new node;
			pos2->down = pos4;
			pos4->up = pos2;
			pos1->down = pos3;
			pos3->up = pos1;
			pos3->right = pos4;
			pos4->left = pos3;
			pos4->down = pos6;
			pos6->up = pos4;
		}
		else if (digit == 5)
		{
			pos1 = new node;
			pos2 = new node;
			pos3 = new node;
			pos4 = new node;
			pos5 = new node;
			pos6 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos1->down = pos3;
			pos3->up = pos1;
			pos3->right = pos4;
			pos4->left = pos3;
			pos4->down = pos6;
			pos6->up = pos4;
			pos5->right = pos6;
			pos6->left = pos5;
		}
		else if (digit == 6)
		{
			pos1 = new node;
			pos2 = new node;
			pos3 = new node;
			pos4 = new node;
			pos5 = new node;
			pos6 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos1->down = pos3;
			pos3->up = pos1;
			pos3->right = pos4;
			pos4->left = pos3;
			pos3->down = pos5;
			pos5->up = pos3;
			pos4->down = pos6;
			pos6->up = pos4;
			pos5->right = pos6;
			pos6->left = pos5;
		}
		else if (digit == 7)
		{
			pos1 = new node;
			pos2 = new node;
			pos4 = new node;
			pos6 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos2->down = pos4;
			pos4->up = pos2;
			pos4->down = pos6;
			pos6->up = pos4;
		}
		else if (digit == 8)
		{
			pos1 = new node;
			pos2 = new node;
			pos3 = new node;
			pos4 = new node;
			pos5 = new node;
			pos6 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos2->down = pos4;
			pos4->up = pos2;
			pos1->down = pos3;
			pos3->up = pos1;
			pos3->right = pos4;
			pos4->left = pos3;
			pos3->down = pos5;
			pos5->up = pos3;
			pos4->down = pos6;
			pos6->up = pos4;
			pos5->right = pos6;
			pos6->left = pos5;
		}
		else if (digit == 9)
		{
			pos1 = new node;
			pos2 = new node;
			pos3 = new node;
			pos4 = new node;
			pos5 = new node;
			pos6 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos2->down = pos4;
			pos4->up = pos2;
			pos1->down = pos3;
			pos3->up = pos1;
			pos3->right = pos4;
			pos4->left = pos3;
			pos4->down = pos6;
			pos6->up = pos4;
			pos5->right = pos6;
			pos6->left = pos5;
		}
	}
	void Delink()
	{
		if (pos1)
		{
			delete pos1;
		}
		if (pos2)
		{
			delete pos2;
		}
		if (pos3)
		{
			delete pos3;
		}
		if (pos4)
		{
			delete pos4;
		}
		if (pos5)
		{
			delete pos5;
		}
		if (pos6)
		{
			delete pos6;
		}
	}
	void Print()
	{
		if (pos1)
		{
			pos1->Print();
		}
		positionx = positionx + 30;
		if (pos2)
		{
			pos2->Print();
		}
		positionx = positionx - 30;
		positiony = positiony + 30;
		if (pos3)
		{
			pos3->Print();
		}
		positionx = positionx + 30;
		if (pos4)
		{
			pos4->Print();
		}
		positionx = positionx - 30;
		positiony = positiony + 30;
		if (pos5)
		{
			pos5->Print();
		}
		positionx = positionx + 30;
		if (pos6)
		{
			pos6->Print();
		}
		positionx = positionx + 100;
		positiony = 150;
	}
	~Digit()
	{
		Delink();
	}
};
class Clock 
{
private:
	int hour1;
	int hour2;
	int minute1;
	int minute2;
public:
	Clock(int a, int b, int c, int d)
	{
		hour1 = a;
		hour2 = b;
		minute1 = c;
		minute2 = d;
	}
	void addMinutes(int minutes)
	{
		int totalMinutes = (hour1 * 10 + hour2) * 60 + minute1 * 10 + minute2 + minutes;
		hour1 = (totalMinutes / 60) / 10;
		hour2 = (totalMinutes / 60) % 10;
		if ((hour1 * 10 + hour2) == 24)
		{
			hour1 = hour2 = 0;
		}
		minute1 = ((totalMinutes % 60) / 10) % 6;
		minute2 = (totalMinutes % 60) % 10;
	}
	void subtractMinutes(int minutes)
	{
		int totalMinutes = (hour1 * 10 + hour2) * 60 + minute1 * 10 + minute2;
		if (totalMinutes >= minutes)
		{
			totalMinutes -= minutes;
		}
		else 
		{
			totalMinutes = 24 * 60 - (minutes - totalMinutes);
		}
		hour1 = (totalMinutes / 60) / 10;
		hour2 = (totalMinutes / 60) % 10;
		minute1 = ((totalMinutes % 60) / 10) % 6;
		minute2 = (totalMinutes % 60) % 10;
	}
	void addHours(int hours) 
	{
		int totalHours = hour1 * 10 + hour2 + hours;
		if (totalHours >= 24)
		{
			totalHours %= 24;
		}
		hour1 = totalHours / 10;
		hour2 = totalHours % 10;
	}
	void subtractHours(int hours)
	{
		int totalHours = hour1 * 10 + hour2;
		if (totalHours >= hours) 
		{
			totalHours -= hours;
		}
		else
		{
			totalHours = 24 - (hours - totalHours);
		}
		hour1 = totalHours / 10;
		hour2 = totalHours % 10;
	}
	bool Convertto12HourFormat()
	{
		bool b = 1;
		int hours = hour1 * 10 + hour2;
		if (hours < 12)
		{
			if (hours == 0)
			{
				hour1 = 1;
				hour2 = 2;
			}
			return !b;
		}
		else
		{
			if (hours == 12)
			{
				return b;
			}
			if (hour1 == 1)
			{
				hour1 = 0;
				hour2 = hour2 - 2;
				return b;
			}
			if (hour2 < 2)
			{
				hour1 = 0;
				if (hour2)
				{
					hour2 = 9;
				}
				else
				{
					hour2 = 8;
				}
				return b;
			}
			hour1 = 1;
		}
		return b;
	}
	void Print()
	{
		Digit h1;
		h1.SetPattern(hour1);
		Digit h2;
		h2.SetPattern(hour2);
		Digit m1;
		m1.SetPattern(minute1);
		Digit m2;
		m2.SetPattern(minute2);
		system("cls");
		h1.Print();
		h2.Print();
		m1.Print();
		m2.Print();
		positionx = 100;
		positiony = 150;

	}
};
void main()
{
	int array[4];
	for (int i = 0;i < 4;i++)
	{
		cout << "Enter " << i + 1 << " digit of time: ";
		cin >> array[i];
	}
	Clock c(array[0], array[1], array[2], array[3]);
	c.Print();
	cin >> array[0];
	c.addMinutes(60);
	c.Print();
	cin >> array[0];
	c.subtractMinutes(60);
	c.Print();
	cin >> array[0];
	c.addHours(27);
	c.Print();
	cin >> array[0];
	c.subtractHours(23);
	c.Print();
	cin >> array[0];
	if (c.Convertto12HourFormat())
	{
		c.Print();
		Print(1);
	}
	else
	{
		c.Print();
		Print(0);
	}
	
	cin >> array[0];

}