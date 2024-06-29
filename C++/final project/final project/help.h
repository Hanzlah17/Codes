#include <windows.h>
#include<time.h>
using namespace std;
void shcoprovider(int a[][8], int i, int j, int& x, int& y, int& r, int& g, int& b)
{
	//providing co-ordinates for shapes
	x = 465;
	y = 115;
	if (i == 0 && j > 0)
	{
		x = 465;
		for (int l = 0;l < j;l++)
		{
			x = x + 100;
		}
		y = 115;
	}
	else
	{
		for (int k = 0;k < i;k++)
		{
			x = 465;
			for (int l = 0;l < j;l++)
			{
				x = x + 100;
			}
			y = y + 100;
		}
	}
	if (a[i][j] == 1)
	{
		r = 250;
		g = 244;
		b = 29;
	}
	else if (a[i][j] == 2)
	{
		r = 255;
		g = 0;
		b = 0;
	}
	else if (a[i][j] == 3)
	{
		r = 0;
		g = 255;
		b = 0;
	}
	else if (a[i][j] == 4)
	{
		r = 0;
		g = 0;
		b = 255;
	}
	else if (a[i][j] == 5)
	{
		r = 251;
		g = 64;
		b = 181;
	}
	else if (a[i][j] == 0)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else if (a[i][j] == 6)
	{
		r = 255;
		g = 255;
		b = 255;
	}
}
//function provided by professor
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void myLine(int x1, int y1, int x2, int y2,float R,float G,float B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,2,RGB(R,B,G)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
	
}
void myLine2(int x1, int y1, int x2, int y2, float R, float G, float B) //use three 3 integers if you want colored lines.
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
// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey,int& Key)   //whichKey passed as reference.... 
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
void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B,int r,int g,int b )
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(r,g,b)); //Fill color can also be passed as parameter to the function!!!
	
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
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
void myEllipse(int x1, int y1, int x2, int y2, float R, float G, float B,float r,float g,float b)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(r, g, b));  //Fill color is black
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
		

}
//function to display score
void score(int score)
{
	emptyRectangle(1400, 200, 1801, 250, 255, 0, 0);
	int x = 1401;
	for (int i = 0; i < score; i++) 
	{
		myRectangle(x, 201, x + score, 249, 255, 255, 255, 255, 255, 255);
	}
}
//function to display moves
void movess(int moves)
{
	int x = 1400;
	for (int i = 0; i < moves; i++)
	{
		if (i < 5)
		{
			myLine(x, 350, x, 400, 255, 255, 255);
			x = x + 5;
		}
		else if (i > 5 && i<=9)
		{
			myLine(x, 350, x, 400, 0, 255, 0);
			x = x + 5;
		}
		else if (i > 9 && i < 15)
		{
			myLine(x, 350, x, 400, 255, 242, 0);
			x = x + 5;
		}
		else if (i >= 15)
		{
			myLine(x, 350, x, 400, 255, 0, 0);
			x = x + 5;
		}
	}
}
// this function will create the game box and give each number a shape
void create(int a[][8])
{
	int x = 450, y = 100;
	for (int i = 0;i < 8;i++)  //gamebox
	{
		for (int j = 0;j < 8;j++)
		{
			emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
				x = x + 100;
		}
		y = y + 100;
		x = 450;
	}
	x = 465;
	y = 115;
	for (int i = 0;i < 8;i++)//shapes
	{
		for (int j = 0;j < 8;j++)
		{
			a[i][j] = rand() % 5 + 1;
			if (a[i][j] == 1)
			{
				myRectangle(x, y, x + 70, y + 70,255,255,255, 250, 244, 29);
			}
			else if (a[i][j] == 2)
			{
				myRectangle(x, y, x + 70, y + 70, 255, 255, 255, 255, 0, 0);
			}
			else if (a[i][j] == 3)
			{
				myRectangle(x, y, x + 70, y + 70, 255, 255, 255, 0, 255, 0);
			}
			else if (a[i][j] == 4)
			{
				myRectangle(x, y, x + 70, y + 70, 255, 255, 255, 0, 0, 255);
			}
			else if (a[i][j] == 5)
			{
				myRectangle(x, y, x + 70, y + 70, 255, 255, 255, 251, 64, 181);
			}
			x = x + 100;
		}
		x = 465;
		y = y + 100;
	}
}
//secondary function
void rotateup(int arr[][8], int row, int column)
{
	int x, y, r, g, b;
	while (row != 0)
	{
		swap(arr[row][column], arr[row - 1][column]);
		shcoprovider(arr, row, column, x, y, r, g, b);
		myRectangle(x, y, x + 70, y + 70, 255, 255, 255, r, g, b);
		shcoprovider(arr, row - 1, column, x, y, r, g, b);
		myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
		row--;
	}
}
void win()
{
	int x, y;
	myRectangle(300, 300, 1500, 600, 0, 0, 255, 255, 255, 32);
	//Y
	x = 320;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x + 100, y + 120, 0, 0, 255);
		x = x + 1;
	}
	x = 420;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y + 120, x + 100, y, 0, 0, 255);
		x = x + 1;
	}
	x = 420;
	y = 440;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 100, 0, 0, 255);
		x = x + 1;
	}
	//O
	x = 560;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y = y + 1;
	}
	x = 560;
	y = 540;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y = y + 1;
	}
	x = 560;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 222, 0, 0, 255);
		x = x + 1;
	}
	x = 680;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x = x + 1;
	}
	//U
	x = 720;
	y = 540;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y = y + 1;
	}
	x = 720;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 222, 0, 0, 255);
		x = x + 1;
	}
	x = 840;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x = x + 1;
	}
	//W
	x = 1000;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x = x + 1;
	}
	x = 1000;
	y = 546;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x + 100, y - 150, 0, 0, 255);
		x = x + 1;
	}
	x = 1100;
	y = 396;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x + 100, y + 150, 0, 0, 255);
		x = x + 1;
	}
	x = 1200;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x = x + 1;
	}
	//I
	x = 1260;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x = x + 1;
	}
	//N
	x = 1320;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x = x + 1;
	}
	x = 1460;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x = x + 1;
	}
	x = 1320;
	y = 320;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x + 140, y + 226, 0, 0, 255);
		x = x + 1;
	}
}
void lose()
{
	int x, y;
	myRectangle(300, 300, 1500, 600, 0, 0, 255, 255, 255, 32);
	//Y
	x = 320;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 100, y + 120, 0, 0, 255);
		x = x + 1;
	}
	x = 420;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y + 120, x + 100, y, 0, 0, 255);
		x = x + 1;
	}
	x = 420;
	y = 440;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 100, 0, 0, 255);
		x = x + 1;
	}
	//O
	x = 560;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y = y + 1;
	}
	x = 560;
	y = 540;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y = y + 1;
	}
	x = 560;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 222, 0, 0, 255);
		x = x + 1;
	}
	x = 680;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x = x + 1;
	}
	//U
	x = 720;
	y = 540;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y = y + 1;
	}
	x = 720;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 222, 0, 0, 255);
		x = x + 1;
	}
	x = 840;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);

		x = x + 1;
	}

	/*LOSE*/

	//L
	x = 880;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x++;
	}

	x = 880;
	y = 546;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y++;
	}


	/*O*/
	x = 1030;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x++;
	}
	x = 1030;
	y = 546;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y++;
	}
	x = 1150;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x++;
	}
	x = 1030;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y++;
	}

	/*S*/

	x = 1180;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y++;

	}
	x = 1180;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 113, 0, 0, 255);
		x++;

	}
	x = 1180;
	y = 433;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y++;
	}
	x = 1300;
	y = 433;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 113, 0, 0, 255);
		x++;
	}
	x = 1180;
	y = 546;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y++;

	}

	/*E*/
	x = 1330;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y++;

	}

	x = 1330;
	y = 320;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x, y + 226, 0, 0, 255);
		x++;
	}

	x = 1330;
	y = 433;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y++;
	}

	x = 1330;
	y = 546;
	for (int i = 0; i < 8; i++)
	{
		myLine(x, y, x + 120, y, 0, 0, 255);
		y++;
	}
}
bool matching(int arr[8][8])
{
	bool t = 0;
	int x, y, r, g, b;
	for (int i = 0; i < 8; i++)//checking matches in a row
	{
		for (int j = 0; j < 8; j++)
		{
			/*check match in row*/
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4]) /*5 similar in row*/
			{
				arr[i][j] = 0;
				shcoprovider(arr, i, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i][j + 1] = 0;
				shcoprovider(arr, i, j+1, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i][j + 2] = 6;
				shcoprovider(arr, i, j+2, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, 0, 0, 0);
				myEllipse(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i][j + 3] = 0;
				shcoprovider(arr, i, j+3, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i][j + 4] = 0;
				shcoprovider(arr, i, j+4, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				t = 1;
			}
			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3]) /*4 similar in row*/
			{
				arr[i][j] = 0;
				shcoprovider(arr, i, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i][j + 1] = 6;
				shcoprovider(arr, i, j+1, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, 0, 0, 0);
				myEllipse(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i][j + 2] = 0;
				shcoprovider(arr, i, j+2, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i][j + 3] = 0;
				shcoprovider(arr, i, j+3, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				t = 1;
			}
			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) /*3 similar in row*/
			{
				arr[i][j] = 0;
				shcoprovider(arr, i, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i][j + 1] = 0;
				shcoprovider(arr, i, j+1, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i][j + 2] = 0;
				shcoprovider(arr, i, j+2, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				t = 1;
			}
		}
	}
	//checking matches in a column
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			/*check match in column*/
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j] && arr[i][j] == arr[i + 4][j]) /*5 similar in column*/
			{
				arr[i][j] = 0;
				shcoprovider(arr, i, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i + 1][j] = 0;
				shcoprovider(arr, i+1, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i + 2][j] = 6;
				shcoprovider(arr, i+2, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, 0, 0, 0);
				myEllipse(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i + 3][j] = 0;
				shcoprovider(arr, i+3, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i + 4][j] = 0;
				shcoprovider(arr, i+4, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				t = 1;
			}
			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j]) /*4 similar in column*/
			{
				arr[i][j] = 0;
				shcoprovider(arr, i, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i + 1][j] = 6;
				shcoprovider(arr, i+1, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, 0, 0, 0);
				myEllipse(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i + 2][j] = 0;
				shcoprovider(arr, i+2, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i + 3][j] = 0;
				shcoprovider(arr, i+3, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				t = 1;
			}
			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]) /*3 similar in column*/
			{
				arr[i][j] = 0;
				shcoprovider(arr, i, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i + 1][j] = 0;
				shcoprovider(arr, i+1, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				arr[i + 2][j] = 0;
				shcoprovider(arr, i+2, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				t = 1;
			}
		}
	}
	return t;
}
void bringzerostotop(int arr[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 0)
			{
				rotateup(arr, i, j);
			}
		}
	}
}
void filling(int a[][8])
{
	int x, y, r, g, b;
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = rand() % 5 + 1;
				shcoprovider(a, i, j, x, y, r, g, b);
				myRectangle(x, y, x + 70, y + 70, 255, 255, 255, r, g, b);
			}
		}
	}
}
//this function will deal with special candy
void special(int arr[][8])
{
	int x, y,r,g,b;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 6)
			{
				for (int k = 0; k < 8; k++)
				{
					arr[i][k] = 0;
					shcoprovider(arr, i, k, x, y, r, g, b);
					myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
					arr[k][j] = 0;
					shcoprovider(arr, k, j, x, y, r, g, b);
					myRectangle(x, y, x + 70, y + 70, 0, 0, 0, r, g, b);
				}
			}
		}
	}
}
// this function will provide co-ordinates of console on console based on its indexes
void coprovider(int i, int j, int& x, int& y)//for cursor
{
	x = 450;
	y = 100;
	if (i == 0 && j > 0)
	{
		x = 450;
		for (int l = 0;l < j;l++)
		{
			x = x + 100;
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
				x = x + 100;
			}
			y = y + 100;
		}
	}
}
void movingpointer(int a[][8])
{
	int i = 0, j = 0,x=450,y=100,x2=1680;
	int k,c=0,b,x1,y1,r,g,bl,moves=0,lives=0;
	emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
	while(c<400 && moves<20 && lives<3)
	{
		while (matching(a))
		{
			bringzerostotop(a);
			filling(a);
		}
		_getch();
		if (isCursorKeyPressed(k, b))
		{
			if (b == 0)
			{
				if (k == 1)
				{
					if (i == 0 && j == 0)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						i = 7;
						j = 7;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
					}
					else if (j > 0 && j <= 7)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						j--;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
					}
					else if (j == 0 && i > 0)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						j = 7;
						i--;
						if (i == 0)
						{
							j = 7;
						}
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);

					}
					else if (j == 7 && i == 0)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						j--;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);

					}
				}
				else if (k == 3)
				{
					if (i == 7 && j == 7)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						i = 0;
						j = 0;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
					}
					else if (j > 0 && j < 7)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						j++;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
					}
					else if (j == 7 && i < 7)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						j = 0;
						i++;
						if (i == 7)
						{
							j = 0;
						}
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);

					}
					else if (i == 0 && j == 0 || j == 0)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						j++;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
					}
				}
				else if (k == 2)
				{
					if (i == 0)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						i = 7;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
					}
					else
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						i--;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
					}
				}
				else if (k == 4)
				{
					if (i == 7)
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						i = 0;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
					}
					else
					{
						emptyRectangle(x, y, x + 100, y + 100, 208, 239, 247);
						i++;
						coprovider(i, j, x, y);
						emptyRectangle(x, y, x + 100, y + 100, 187, 34, 244);
					}
				}
			}
			else
			{
				_getch();
				if (isCursorKeyPressed(k, b))
				{
					if (k == 1)
					{
						if (j != 0)
						{
							swap(a[i][j], a[i][j - 1]);
							shcoprovider(a, i, j, x1, y1, r, g, bl);
							myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							shcoprovider(a, i, j - 1, x1, y1, r, g, bl);
							myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							if (a[i][j] == 6 || a[i][j - 1] == 6)
							{
								Sleep(500);
								special(a);
								Sleep(500);
								filling(a);
								c = c + 50;
								score(c);
								moves++;
								movess(moves);
							}
							else if (!matching(a))
							{
								myRectangle(125, 620, 175, 625, 255, 255, 255, 255, 255, 255);
								myLine2(135, 610, 155, 630, 255, 0, 0);
								myLine2(155, 610, 135, 630, 255, 0, 0);
								Sleep(500);
								myLine2(135, 610, 155, 630, 255, 255, 255);
								myLine2(155, 610, 135, 630, 255, 255, 255);
								//lives 
								myLine2(x2, 680, x2 + 20, 700, 255, 255, 255);
								myLine2(x2 + 20, 680, x2, 700, 255, 255, 255);
								x2 = x2 + 80;
								lives++;
								myRectangle(125, 620, 175, 625, 0, 0, 0, 0, 0, 0);
								swap(a[i][j], a[i][j - 1]);
								shcoprovider(a, i, j, x1, y1, r, g, bl);
								myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
								shcoprovider(a, i, j - 1, x1, y1, r, g, bl);
								myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							}
							else
							{
								moves++;
								movess(moves);
								c = c + 10;
								score(c);
								matching(a);
								myRectangle(125, 620, 175, 625, 255, 255, 255, 255, 255, 255);//for snowman expression
								myEllipse(135, 610, 155, 630, 0, 0, 0, 0, 0, 0);//smile
								Sleep(500);
								myEllipse(135, 610, 155, 630, 255, 255, 255, 255, 255, 255);//smile
								myRectangle(125, 620, 175, 625, 0, 0, 0, 0, 0, 0);
								bringzerostotop(a);
								Sleep(500);
								filling(a);
							}
						}
					}
					else if (k == 3)
					{
						if (j != 7)
						{
							swap(a[i][j], a[i][j + 1]);
							shcoprovider(a, i, j, x1, y1, r, g, bl);
							myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							shcoprovider(a, i, j + 1, x1, y1, r, g, bl);
							myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							if (a[i][j] == 6 || a[i][j + 1] == 6)
							{
								Sleep(500);
								special(a);
								Sleep(500);
								filling(a);
								c = c + 50;
								score(c);
								moves++;
								movess(moves);
							}
							else if (!matching(a))
							{
								myRectangle(125, 620, 175, 625, 255, 255, 255, 255, 255, 255);
								myLine2(135, 610, 155, 630, 255, 0, 0);
								myLine2(155, 610, 135, 630, 255, 0, 0);
								Sleep(500);
								myLine2(135, 610, 155, 630, 255, 255, 255);
								myLine2(155, 610, 135, 630, 255, 255, 255);
								//lives 
								myLine2(x2, 680, x2 + 20, 700, 255, 255, 255);
								myLine2(x2 + 20, 680, x2, 700, 255, 255, 255);
								x2 = x2 + 80;
								lives++;
								myRectangle(125, 620, 175, 625, 0, 0, 0, 0, 0, 0);
								swap(a[i][j], a[i][j + 1]);
								shcoprovider(a, i, j, x1, y1, r, g, bl);
								myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
								shcoprovider(a, i, j + 1, x1, y1, r, g, bl);
								myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							}
							else
							{
								moves++;
								movess(moves);
								c = c + 10;
								score(c);
								matching(a);
								myRectangle(125, 620, 175, 625, 255, 255, 255, 255, 255, 255);//for snowman expression
								myEllipse(135, 610, 155, 630, 0, 0, 0, 0, 0, 0);//smile
								Sleep(500);
								myEllipse(135, 610, 155, 630, 255, 255, 255, 255, 255, 255);//smile
								myRectangle(125, 620, 175, 625, 0, 0, 0, 0, 0, 0);
								bringzerostotop(a);
								Sleep(500);
								filling(a);
							}
						}
					}
					else if (k == 2)
					{
						if (i != 0)
						{
							swap(a[i][j], a[i - 1][j]);
							shcoprovider(a, i, j, x1, y1, r, g, bl);
							myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							shcoprovider(a, i - 1, j, x1, y1, r, g, bl);
							myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							if (a[i][j] == 6 || a[i - 1][j] == 6)
							{
								Sleep(500);
								special(a);
								Sleep(500);
								filling(a);
								c = c + 50;
								score(c);
								moves++;
								movess(moves);
							}
							else if (!matching(a))
							{
								myRectangle(125, 620, 175, 625, 255, 255, 255, 255, 255, 255);
								myLine2(135, 610, 155, 630, 255, 0, 0);
								myLine2(155, 610, 135, 630, 255, 0, 0);
								Sleep(500);
								myLine2(135, 610, 155, 630, 255, 255, 255);
								myLine2(155, 610, 135, 630, 255, 255, 255);
								//lives 
								myLine2(x2, 680, x2 + 20, 700, 255, 255, 255);
								myLine2(x2 + 20, 680, x2, 700, 255, 255, 255);
								x2 = x2 + 80;
								lives++;
								myRectangle(125, 620, 175, 625, 0, 0, 0, 0, 0, 0);
								swap(a[i][j], a[i - 1][j]);
								shcoprovider(a, i, j, x1, y1, r, g, bl);
								myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
								shcoprovider(a, i - 1, j, x1, y1, r, g, bl);
								myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							}
							else
							{
								moves++;
								movess(moves);
								c = c + 10;
								score(c);
								matching(a);
								myRectangle(125, 620, 175, 625, 255, 255, 255, 255, 255, 255);//for snowman expression
								myEllipse(135, 610, 155, 630, 0, 0, 0, 0, 0, 0);//smile
								Sleep(500);
								myEllipse(135, 610, 155, 630, 255, 255, 255, 255, 255, 255);//smile
								myRectangle(125, 620, 175, 625, 0, 0, 0, 0, 0, 0);
								bringzerostotop(a);
								Sleep(500);
								filling(a);
							}
							
						}
					}
					else
					{
						if (i != 7)
						{
							swap(a[i][j], a[i + 1][j]);
							shcoprovider(a, i, j, x1, y1, r, g, bl);
							myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							shcoprovider(a, i + 1, j, x1, y1, r, g, bl);
							myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							if (a[i][j] == 6 || a[i + 1][j] == 6)
							{
								Sleep(500);
								special(a);
								Sleep(500);
								filling(a);
								c = c + 50;
								score(c);
								moves++;
								movess(moves);
							}
							else if (!matching(a))
							{
								myRectangle(125, 620, 175, 625, 255, 255, 255, 255, 255, 255);
								myLine2(135, 610, 155, 630, 255, 0, 0);
								myLine2(155, 610, 135, 630, 255, 0, 0);
								Sleep(500);
								myLine2(135, 610, 155, 630, 255, 255, 255);
								myLine2(155, 610, 135, 630, 255, 255, 255);
								//lives 
								myLine2(x2, 680, x2 + 20, 700, 255, 255, 255);
								myLine2(x2 + 20, 680, x2, 700, 255, 255, 255);
								x2 = x2 + 80;
								lives++;
								myRectangle(125, 620, 175, 625, 0, 0, 0, 0, 0, 0);
								swap(a[i][j], a[i + 1][j]);
								shcoprovider(a, i, j, x1, y1, r, g, bl);
								myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
								shcoprovider(a, i + 1, j, x1, y1, r, g, bl);
								myRectangle(x1, y1, x1 + 70, y1 + 70, 255, 255, 255, r, g, bl);
							}
							else
							{
								moves++;
								movess(moves);
								c = c + 10;
								score(c);
								matching(a);
								myRectangle(125, 620, 175, 625, 255, 255, 255, 255, 255, 255);//for snowman expression
								myEllipse(135, 610, 155, 630, 0, 0, 0, 0, 0, 0);//smile
								Sleep(500);
								myEllipse(135, 610, 155, 630, 255, 255, 255, 255, 255, 255);//smile
								myRectangle(125, 620, 175, 625, 0, 0, 0, 0, 0, 0);
								bringzerostotop(a);
								Sleep(500);
								filling(a);
							}
						}
					}
				}
			}

		}
		
	}
	if (c >= 400)
	{
		system("cls");
		win();
	}
	else
	{
		system("cls");
		lose();
	}
}
void background()
{
	myRectangle(0, 0, 2000, 1000, 255, 255, 255, 0, 0, 0);
	int x = -50;
	//clouds
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			myEllipse(x, -100, x + 200, 100, 195, 195, 195, 195, 195, 195);
			x = x + 50;
		}
		x = x + 100;
	}
	//snow
	x = -100;
	for (int i = 0;i < 13;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			myEllipse(x, 820, x + 200, 1020, 255, 255, 255, 255, 255, 255);
			x = x + 50;
		}

	}
	//snowman
	myEllipse(100, 560, 200, 660, 255, 255, 255, 255, 255, 255);//upperbody
	myRectangle(125, 510, 175, 560, 255, 255, 255, 0, 0, 0);//hat
	myRectangle(125, 525, 175, 535, 255, 255, 255, 255, 255, 255);//hat
	myRectangle(100, 560, 200, 570, 255, 255, 255, 0, 0, 0);//hat
	myEllipse(130, 590, 140, 600, 0, 0, 0, 0, 0, 0);// left eye
	myEllipse(160, 590, 170, 600, 0, 0, 0, 0, 0, 0);//right eye
	myRectangle(125, 620, 175, 625, 0, 0, 0, 0, 0, 0);//smile
	myEllipse(50, 640, 250, 840, 255, 255, 255, 255, 255, 255);//lowerbody
	int y = 660;
	for (int i = 0;i < 4;i++)//buttons
	{
		myEllipse(142, y, 152, y + 10, 0, 0, 0, 0, 0, 0);
		y = y + 50;
	}
	//sign board
	myRectangle(1800, 700, 1830, 820, 255, 255, 255, 128, 64, 0);//support
	myRectangle(1700, 700, 1730, 820, 255, 255, 255, 128, 64, 0);//support
	myRectangle(1650, 650, 1880, 730, 255, 255, 255, 128, 64, 0);//board
}
bool startscreen()
{
	bool c=1;
	char end;
	cin >> end;
	int y = 102;
	myRectangle(0, 0, 2000, 1550, 0, 0, 0, 255, 255, 255);
	emptyRectangle(400, 50, 1800, 250, 0, 0, 0);
	for (int i = 0;i < 10;i++)//T
	{
		myLine(450, y, 550, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	int x = 500;
	for (int i = 0;i < 8;i++)//T
	{
		myLine(x, 110, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	y = 100;
	for (int i = 0;i < 10;i++)//O
	{
		myLine(570, y, 654, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	y = 192;
	for (int i = 0;i < 10;i++)//O
	{
		myLine(570, y, 650, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 570;
	for (int i = 0;i < 8;i++)//O
	{
		myLine(x, 100, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	x = 650;
	for (int i = 0;i < 8;i++)//O
	{
		myLine(x, 100, x, 201, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	x = 670;
	for (int i = 0;i < 8;i++)//F
	{
		myLine(x, 100, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	y = 100;
	for (int i = 0;i < 10;i++)//F
	{
		myLine(670, y, 750, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	y = 150;
	for (int i = 0;i < 10;i++)//F
	{
		myLine(670, y, 730, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 770;
	for (int i = 0;i < 8;i++)//F2
	{
		myLine(x, 100, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	y = 100;
	for (int i = 0;i < 10;i++)//F2
	{
		myLine(770, y, 850, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	y = 150;
	for (int i = 0;i < 10;i++)//F2
	{
		myLine(770, y, 830, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 870;
	for (int i = 0;i < 8;i++)//E
	{
		myLine(x, 100, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	y = 100;
	for (int i = 0;i < 10;i++)//E
	{
		myLine(870, y, 950, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	y = 150;
	for (int i = 0;i < 10;i++)//E
	{
		myLine(870, y, 930, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	y = 191;
	for (int i = 0;i < 10;i++)//E
	{
		myLine(869, y, 950, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 970;
	for (int i = 0;i < 8;i++)//E2
	{
		myLine(x, 100, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	y = 100;
	for (int i = 0;i < 10;i++)//E2
	{
		myLine(970, y, 1050, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	y = 150;
	for (int i = 0;i < 10;i++)//E2
	{
		myLine(970, y, 1030, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	y = 191;
	for (int i = 0;i < 10;i++)//E2
	{
		myLine(969, y, 1050, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	//crush
	//C
	y = 100;
	for (int i = 0;i < 10;i++)
	{
		myLine(1170, y, 1254, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	y = 192;
	for (int i = 0;i < 10;i++)
	{
		myLine(1170, y, 1250, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 1170;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, 100, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	//R
	x = 1270;
	for (int i = 0;i < 8;i++)//F
	{
		myLine(x, 100, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	y = 100;
	for (int i = 0;i < 10;i++)//F
	{
		myLine(1270, y, 1350, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	y = 150;
	for (int i = 0;i < 10;i++)//F
	{
		myLine(1270, y, 1350, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 1350;
	for (int i = 0;i < 8;i++)//F
	{
		myLine(x, 99, x, 159, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	x = 1270;
	y = 150;
	for (int i = 0;i < 15;i++)
	{
		myLine(x, y, x + 80, y + 50, 255, 0, 0);
		Sleep(20);
		y = y + 1;
		x = x + 1;
	}
	//U
	y = 192;
	for (int i = 0;i < 10;i++)//O
	{
		myLine(1370, y, 1450, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 1370;
	for (int i = 0;i < 8;i++)//O
	{
		myLine(x, 100, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	x = 1450;
	for (int i = 0;i < 8;i++)//O
	{
		myLine(x, 100, x, 201, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	//S
	y = 100;
	for (int i = 0;i < 10;i++)
	{
		myLine(1470, y, 1550, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 1470;
	for (int i = 0;i < 10;i++)
	{
		myLine(x, 100, x, 150, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	y = 145;
	for (int i = 0;i < 10;i++)
	{
		myLine(1470, y, 1550, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 1545;
	for (int i = 0;i < 10;i++)
	{
		myLine(x, 145, x, 204, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	y = 195;
	for (int i = 0;i < 10;i++)
	{
		myLine(1470, y, 1550, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	//H
	y = 145;
	for (int i = 0;i < 10;i++)//O
	{
		myLine(1570, y, 1650, y, 255, 0, 0);
		Sleep(20);
		y = y + 1;
	}
	x = 1570;
	for (int i = 0;i < 8;i++)//O
	{
		myLine(x, 100, x, 200, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	x = 1650;
	for (int i = 0;i < 8;i++)//O
	{
		myLine(x, 100, x, 201, 255, 0, 0);
		Sleep(20);
		x = x + 1;
	}
	//start box
	myRectangle(700, 500, 1200, 650, 0, 0, 0, 0, 0, 0);
	//S
	y = 520;
	for (int i = 0;i < 10;i++)
	{
		myLine(750, y, 800, y, 255, 0, 0);
		y = y + 1;
	}
	x = 750;
	for (int i = 0;i < 10;i++)
	{
		myLine(x, 520, x, 570, 255, 0, 0);
		x = x + 1;
	}
	y = 565;
	for (int i = 0;i < 10;i++)
	{
		myLine(750, y, 800, y, 255, 0, 0);
		y = y + 1;
	}
	x = 795;
	for (int i = 0;i < 10;i++)
	{
		myLine(x, 565, x, 623, 255, 0, 0);
		x = x + 1;
	}
	y = 615;
	for (int i = 0;i < 10;i++)
	{
		myLine(750, y, 800, y, 255, 0, 0);
		y = y + 1;
	}
	y = 520;
	for (int i = 0;i < 10;i++)//T
	{
		myLine(820, y, 910, y, 255, 0, 0);
		y = y + 1;
	}
	x = 865;
	for (int i = 0;i < 8;i++)//T
	{
		myLine(x, 520, x, 625, 255, 0, 0);
		x = x + 1;
	}
	//H
	y = 520;
	for (int i = 0;i < 10;i++)//O
	{
		myLine(930, y, 980, y, 255, 0, 0);
		y = y + 1;
	}
	y = 570;
	for (int i = 0;i < 10;i++)//O
	{
		myLine(930, y, 980, y, 255, 0, 0);
		y = y + 1;
	}
	x = 930;
	for (int i = 0;i < 8;i++)//O
	{
		myLine(x, 520, x, 625, 255, 0, 0);
		x = x + 1;
	}
	x = 980;
	for (int i = 0;i < 8;i++)//O
	{
		myLine(x, 520, x, 625, 255, 0, 0);
		x = x + 1;
	}
	//R
	x = 1030;
	for (int i = 0;i < 8;i++)//F
	{
		myLine(x, 520, x, 625, 255, 0, 0);
		x = x + 1;
	}
	y = 520;
	for (int i = 0;i < 10;i++)//F
	{
		myLine(1030, y, 1080, y, 255, 0, 0);
		y = y + 1;
	}
	y = 570;
	for (int i = 0;i < 10;i++)//F
	{
		myLine(1030, y, 1080, y, 255, 0, 0);
		y = y + 1;
	}
	x = 1080;
	for (int i = 0;i < 8;i++)//F
	{
		myLine(x, 519, x, 579, 255, 0, 0);
		x = x + 1;
	}
	x = 1030;
	y = 570;
	for (int i = 0;i < 10;i++)
	{
		myLine(x, y, x + 50, y + 54, 255, 0, 0);
		x = x + 1;
	}
	y = 520;
	for (int i = 0;i < 10;i++)//T
	{
		myLine(1100, y, 1180, y, 255, 0, 0);
		y = y + 1;
	}
	x = 1140;
	for (int i = 0;i < 8;i++)//T
	{
		myLine(x, 520, x, 625, 255, 0, 0);
		x = x + 1;
	}
	//cursor
	emptyRectangle(700, 500, 1200, 650, 255, 0, 0);
	//end box
	myRectangle(800, 700, 1100, 800, 0, 0, 0, 0, 0, 0);
	//E
	x = 820;
	for (int i = 0;i < 8;i++)//E
	{
		myLine(x, 720, x, 780, 255, 0, 0);
		x = x + 1;
	}
	y = 720;
	for (int i = 0;i < 10;i++)//E
	{
		myLine(820, y, 880, y, 255, 0, 0);
		y = y + 1;
	}
	y = 750;
	for (int i = 0;i < 10;i++)//E
	{
		myLine(820, y, 860, y, 255, 0, 0);
		y = y + 1;
	}
	y = 771;
	for (int i = 0;i < 10;i++)//E
	{
		myLine(819, y, 880, y, 255, 0, 0);
		y = y + 1;
	}
	//X
	x = 900;
	y = 720;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x+60, y+60, 255, 0, 0);
		x = x + 1;
	}
	x = 900;
	y = 780;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, y, x+60 , y-60, 255, 0, 0);
		x = x + 1;
	}
	//I
	x = 1000;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, 720, x, 780, 255, 0, 0);
		x = x + 1;
	}
	//T
	x = 1050;
	for (int i = 0;i < 8;i++)
	{
		myLine(x, 720, x, 780, 255, 0, 0);
		x = x + 1;
	}
	y = 720;
	for (int i = 0;i < 8;i++)
	{
		myLine(1020, y, 1080, y, 255, 0, 0);
		y = y + 1;
	}
	//moving cursor
	int k, b=0, x1 = 700, y1 = 500;
	for (int i = 0;b==0;i++)
	{
		_getch();
		if (isCursorKeyPressed(k, b))
		{
			if (k == 2)
			{
				if (x1 == 700 && y1 == 500)
				{
					emptyRectangle(700, 500, 1200, 650, 255, 255, 255);
					x1 = 800;
					y1 = 700;
					emptyRectangle(x1, y1, x1 + 300, y1 + 100, 255, 0, 0);
				}
				else
				{
					emptyRectangle(800, 700, 1100, 800, 255, 255, 255);
					x1 = 700;
					y1 = 500;
					emptyRectangle(x1, y1, x1 + 500, y1 + 150, 255, 0, 0);
				}
			}
			if (k == 4)
			{
				if (x1 == 800 && y1 == 700)
				{
					emptyRectangle(800, 700, 1100, 800, 255, 255, 255);
					x1 = 700;
					y1 = 500;
					emptyRectangle(x1, y1, x1 + 500, y1 + 150, 255, 0, 0);

				}
				else
				{
					emptyRectangle(700, 500, 1200, 650, 255, 255, 255);
					x1 = 800;
					y1 = 700;
					emptyRectangle(x1, y1, x1 + 300, y1 + 100, 255, 0, 0);
				}
			}
			if (b == 1)
			{
				if (x1 == 700 && y1 == 500)
				{
					system("cls");
					c = 1;
				}
				else
				{
					system("cls");
					c = 0;
				}
				
			}
		}
	}
	return c;
}