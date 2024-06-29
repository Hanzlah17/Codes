#include<iostream>
#include<conio.h>
#include<Windows.h>
#include <cstdio>
using namespace std;
void printboard(int a[][3])
{
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (a[i][j] == 0)
			{
				cout << "_" << " ";
			}
			else if (a[i][j] == 1)
			{
				cout << "X" << " ";
			}
			else
			{
				if (a[i][j] == 2)
				{
					cout << "O" << " ";
				}
			}
		}
		cout << endl;
	}
}
void updateboard(int a[][3], int row, int col, int s)
{
	a[row][col] = s;
}
bool checkwinner(int a[][3], int& who)
{
	bool b = 0;
	for (int i = 0;i < 3;i++)
	{
		if (a[i][0] == a[i][1] && a[i][0] == a[i][2] && a[i][0] != 0)
		{
			who = a[i][0];
			b = 1;
		}
	}
	for (int i = 0;i < 3;i++)
	{
		if (a[0][i] == a[1][i] && a[0][i] == a[2][i] && a[0][i] != 0)
		{
			who = a[0][i];
			b = 1;
		}
	}
	if (a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0] != 0)
	{
		who = a[0][0];
		b = 1;
	}
	else
	{
		if (a[0][2] == a[1][1] && a[0][2] == a[2][0] && a[0][2] != 0)
		{
			who = a[0][2];
			b = 1;
		}
		return b;
	}
	return b;
}
void PlayTurn(int& r, int& c)
{
	int box = 0;
	cout << "Enter the box number: ";
	cin >> box;
	while (box < 1 || box>9)
	{
		cout << "Enter a valid box number!!!!\n";
		cout << "Enter the box number: ";
		cin >> box;
	}
	if (box == 1)
	{
		r = 0;
		c = 0;
	}
	else if (box == 2)
	{
		r = 0;
		c = 1;
	}
	else if (box == 3)
	{
		r = 0;
		c = 2;
	}
	else if (box == 4)
	{
		r = 1;
		c = 0;
	}
	else if (box == 5)
	{
		r = 1;
		c = 1;
	}
	else if (box == 6)
	{
		r = 1;
		c = 2;
	}
	else if (box == 7)
	{
		r = 2;
		c = 0;
	}
	else if (box == 8)
	{
		r = 2;
		c = 1;
	}
	else if (box == 9)
	{
		r = 2;
		c = 2;
	}
}
void calculate(int b[][3], int& r, int& c, int s)
{
	int who;
	bool w = 0;
	//checking for wimning box
	for (int i = 0;i < 3 && w == 0;i++)
	{
		for (int j = 0;j < 3 && w == 0;j++)
		{
			if (b[i][j] == 0)
			{
				r = i;
				c = j;
				b[i][j] = s;
				w = checkwinner(b, who);
				b[i][j] = 0;

			}
		}
	}
	//block the opponent
	for (int i = 0;i < 3 && w == 0;i++)
	{
		for (int j = 0;j < 3 && w == 0;j++)
		{
			if (b[i][j] == 0)
			{
				r = i;
				c = j;
				b[i][j] = 1;
				w = checkwinner(b, who);
				b[i][j] = 0;

			}
		}
	}
	if (w == 0)
	{
		if (b[1][1] == 0)
		{
			r = 1;
			c = 1;
		}
		else if (b[0][0] == 0)
		{
			r = 0;
			c = 0;
		}
		else if (b[2][0] == 0)
		{
			r = 2;
			c = 0;
		}
		else if (b[0][2] == 0)
		{
			r = 0;
			c = 2;
		}
		else if (b[2][2] == 0)
		{
			r = 2;
			c = 2;
		}
		else if (b[0][1] == 0)
		{
			r = 0;
			c = 1;
		}
		else if (b[1][0] == 0)
		{
			r = 1;
			c = 0;
		}
		else if (b[1][2] == 0)
		{
			r = 1;
			c = 2;
		}
		else if (b[2][1] == 0)
		{
			r = 2;
			c = 1;
		}
	}

}


//front end functions
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void myLine2(int x1, int y1, int x2, int y2, float R, float G, float B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 10, RGB(R, B, G));  //width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
bool isCursorKeyPressed(int& whichKey, int& Key)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		Key = 0;
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		Key = 0;
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		Key = 0;
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		Key = 0;
		return true;
	}
	key = GetAsyncKeyState(VK_SPACE);
	if (key == 1)
	{
		whichKey = 0;
		Key = 1;   // 1 if enter key is pressed
		return true;
	}
	return false;
}
void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int r, int g, int b)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(r, g, b)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void emptyRectangle(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = (HBRUSH)::GetStockObject(NULL_BRUSH); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, float R, float G, float B, float r, float g, float b)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(r, g, b));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}
void CreateBox()
{
	int x = 400, y = 50;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			myRectangle(x, y, x + 300, y + 300, 208, 239, 247, 0, 0, 0);
			x = x + 300;
		}
		x = 400;
		y = y + 300;
	}
}
void ProvideCo(int i, int j, int& x, int& y)
{
	x = 400;
	y = 50;
	if (i == 0 && j > 0)
	{
		for (int l = 0;l < j;l++)
		{
			x = x + 300;
		}
		y = 50;
	}
	else
	{
		for (int k = 0;k < i;k++)
		{
			x = 400;
			for (int l = 0;l < j;l++)
			{
				x = x + 300;
			}
			y = y + 300;
		}
	}

}
void ProvideShapeCo(int i, int j, int& x, int& y)
{
	x = 450;
	y = 100;
	if (i == 0 && j > 0)
	{
		for (int l = 0;l < j;l++)
		{
			x = x + 300;
		}
		y = 100;
	}
	else
	{
		for (int k = 0;k < i;k++)
		{
			x = 450;
			for (int l = 0;l < j;l++)
			{
				x = x + 300;
			}
			y = y + 300;
		}
	}

}
void FillWithX(int x, int y)
{
	myLine2(x, y, x + 200, y + 200, 255, 0, 0);
	myLine2(x, y + 200, x + 200, y, 255, 0, 0);
}
void PlayAi(int board[][3])
{
	//function to be added here
	int i = 0, j = 0;
	calculate(board, i, j, 2);
	int Sx, Sy;
	ProvideShapeCo(i, j, Sx, Sy);
	myEllipse(Sx, Sy, Sx + 200, Sy + 200, 78, 231, 71, 0, 0, 0);
	updateboard(board, i, j, 2);
}
void MoveCursor(int board[][3])
{
	int i = 0, j = 0, key, direction, x = 400, y = 50, Sx = 450, Sy = 100, counter = 0, who = 0;
	bool win = 0;
	emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
	while (counter < 9 && win == 0)
	{
		_getch();
		if (isCursorKeyPressed(direction, key))
		{
			if (key == 0)
			{
				if (direction == 1)
				{
					if (i == 0 && j == 0)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						i = 2;
						j = 2;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
					else if (j > 0 && j <= 2)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						j--;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
					else if (j == 0 && i > 0)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						j = 2;
						i--;
						if (i == 0)
						{
							j = 2;
						}
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
					else if (j == 2 && i == 0)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						j--;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);

					}
				}
				else if (direction == 3)
				{
					if (i == 2 && j == 2)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						i = 0;
						j = 0;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
					else if (j > 0 && j < 2)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						j++;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
					else if (j == 2 && i < 2)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						j = 0;
						i++;
						if (i == 2)
						{
							j = 0;
						}
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);

					}
					else if (i == 0 && j == 0 || j == 0)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						j++;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
				}
				else if (direction == 2)
				{
					if (i == 0)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						i = 2;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
					else
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						i--;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
				}
				else if (direction == 4)
				{
					if (i == 2)
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						i = 0;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
					else
					{
						emptyRectangle(x, y, x + 300, y + 300, 208, 239, 247);
						i++;
						ProvideCo(i, j, x, y);
						emptyRectangle(x, y, x + 300, y + 300, 187, 34, 244);
					}
				}
			}
			else
			{
				if (board[i][j] == 0)
				{
					ProvideShapeCo(i, j, Sx, Sy);
					FillWithX(Sx, Sy);
					updateboard(board, i, j, 1);
					win = checkwinner(board, who);
					counter++;
					if (win == 0 && counter < 9)
					{
						PlayAi(board);
						win = checkwinner(board, who);
						counter++;
					}
				}
			}
		}


	}
	system("cls");
	if (win)
	{
		cout << "winner is player " << who;
	}
	else
	{
		cout << "\nDRAW!!!!";
	}

}

#pragma once
