#include<iostream>
#include<windows.h>
using namespace std;
static int x1 = 0;
static int y2 = 50;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
class node
{
public:
	node* up;
	node* down;
	node* left;
	node* right;
	bool printed;
	node()
	{
		up = down = left = right = 0;
		printed = 0;
	}
	~node()
	{
		up = down = left = right = 0;
		printed = 0;
	}
};
class Digit
{
	node* pos1;
	node* pos2;
public:
	Digit()
	{
		pos1 = pos2 = 0;
	}
	void SetPattern(int digit)
	{
		if (digit == 0)
		{
			pos1 = new node;
			pos1->down = new node;
			pos1->down->down = new node;
			pos1->down->up = pos1;
			pos1->down->down->up = pos1->down;
			//-------------//
			pos2 = new node;
			pos2->down = new node;
			pos2->down->down = new node;
			pos2->down->up = pos2;
			pos2->down->down->up = pos2->down;
			//-------//
			pos1->right = pos2;
			pos2->left = pos1;
			pos1->down->down->right = pos2->down->down;
			pos2->down->down->left = pos1->down->down;
		}
		else if (digit == 1)
		{
			pos2 = new node;
			pos2->down = new node;
			pos2->down->down = new node;
			pos2->down->up = pos2;
			pos2->down->down->up = pos2->down;

		}
		else if (digit == 2)
		{
			pos1 = new node;
			pos2 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos2->down = new node;
			pos2->down->up = pos2;
			pos2->down->left = new node;
			pos2->down->left->right = pos2->down;
			pos2->down->left->down = new node;
			pos2->down->left->down->up = pos2->down->left;
			pos2->down->left->down->right = new node;
			pos2->down->left->down->right->left = pos2->down->left->down;
		}
		else if (digit == 3)
		{
			pos1 = new node;
			pos2 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos2->down = new node;
			pos2->down->left = new node;
			pos2->down->left->right = pos2->down;
			pos2->down->down = new node;
			pos2->down->down->left = new node;
			pos2->down->down->left->right = pos2->down->down;
			pos2->down->up = pos2;
			pos2->down->down->up = pos2->down;
		}
		else if (digit == 4)
		{
			pos2 = new node;
			pos2->down = new node;
			pos2->down->down = new node;
			pos2->down->up = pos2;
			pos2->down->down->up = pos2->down;
			pos1 = new node;
			pos1->down = new node;
			pos1->down->up = pos1;
			pos1->down->right = pos2->down;
			pos2->down->left = pos1->down;
		}
		else if (digit == 5)
		{
			pos1 = new node;
			pos2 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos1->down = new node;
			pos1->down->up = pos1;
			pos1->down->right = new node;
			pos1->down->right->left = pos1->down;
			pos1->down->right->down = new node;
			pos1->down->right->down->up = pos1->down->right;
			pos1->down->right->down->left = new node;
			pos1->down->right->down->left->right = pos1->down->right->down;
		}
		else if (digit == 6)
		{
			pos1 = new node;
			pos2 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos1->down = new node;
			pos1->down->up = pos1;
			pos1->down->right = new node;
			pos1->down->right->left = pos1->down;
			pos1->down->right->down = new node;
			pos1->down->right->down->up = pos1->down->right;
			pos1->down->right->down->left = new node;
			pos1->down->right->down->left->right = pos1->down->right->down;
			pos1->down->down = pos1->down->right->down->left;
			pos1->down->down->up = pos1->down;
		}
		else if (digit == 7)
		{
			pos2 = new node;
			pos2->down = new node;
			pos2->down->down = new node;
			pos2->down->up = pos2;
			pos2->down->down->up = pos2->down;
			pos1 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
		}
		else if (digit == 8)
		{
			pos1 = new node;
			pos1->down = new node;
			pos1->down->down = new node;
			pos1->down->up = pos1;
			pos1->down->down->up = pos1->down;
			//-------------//
			pos2 = new node;
			pos2->down = new node;
			pos2->down->down = new node;
			pos2->down->up = pos2;
			pos2->down->down->up = pos2->down;
			//-------//
			pos1->right = pos2;
			pos2->left = pos1;
			pos1->down->right = pos2->down;
			pos2->down->left = pos1->down;
			pos1->down->down->right = pos2->down->down;
			pos2->down->down->left = pos1->down->down;
		}
		else if (digit == 9)
		{
			pos1 = new node;
			pos2 = new node;
			pos1->right = pos2;
			pos2->left = pos1;
			pos1->down = new node;
			pos1->down->up = pos1;
			pos1->down->right = new node;
			pos1->down->right->left = pos1->down;
			pos1->down->right->down = new node;
			pos1->down->right->down->up = pos1->down->right;
			pos1->down->right->down->left = new node;
			pos1->down->right->down->left->right = pos1->down->right->down;
			pos2->down = pos1->down->right;
			pos2->down->up = pos2;
		}
	}
	void Delink()
	{
		node* head = 0;
		if (pos1)
		{
			head = pos1;
		}
		else
		{
			head = pos2;
		}
		node* temp = 0;
		node* temp2 = 0;
		while (head)
		{
			if (head->down && head->right)
			{
				temp = head;
				temp2 = head->right;
				delete temp2;
				head = head->down;
				head->up = 0;
				delete temp;

			}
			else if (head->down && !head->right)
			{
				temp = head;
				head = head->down;
				head->up = 0;
				delete temp;
			}
			else if (!head->down && head->right)
			{
				temp = head;
				head = head->right;
				head->left = 0;
				delete temp;

			}
			else if (head->down && head->left)
			{
				temp = head;
				temp2 = head->left;
				delete temp2;
				head = head->down;
				head->up = 0;
				delete temp;

			}
			else if (!head->down && head->left)
			{
				temp = head;
				head = head->left;
				head->right = 0;
				delete temp;
			}
			else
			{
				if (head->up)
				{
					delete head->up;
				}
				temp = head;
				delete temp;
			}
		}
		if (pos2)
		{
			delete pos2;
		}
	}
	void PrintDigit()
	{
		node* head = 0;
		if (pos1)
		{
			head = pos1;
		}
		else
		{
			head = pos2;
		}
		node* temp = 0;
		node* temp2 = 0;
		while (head)
		{
			if (head->down && head->right)
			{
				cout << "*********";
				x1 = x1 - 6;
				y2 = y2 + 5;
				gotoxy(x1, y2);
				for (int i = 0;i < 6;i++)
				{
					cout << "*";
					y2 = y2 + 5;
					gotoxy(x1, y2);
				}
				head->right->printed = 1;
				head->printed = 1;
				head = head->down;
			}
			else if (head->down && !head->right)
			{
				for (int i = 0;i < 6;i++)
				{
					cout << "|";
					y2++;
					gotoxy(x1, y2);
				}
				head->printed = 1;
				head = head->down;
			}
			else if (!head->down && head->right)
			{
				cout << "-------";
				x1 = x1 + 6;
				head->printed = 1;
				head = head->right;

			}
			else if (head->down && head->left)
			{
				gotoxy(x1 - 6, y2);
				cout << "-------";
				gotoxy(x1, y2);
				head->left->printed = 1;
				for (int i = 0;i < 6;i++)
				{
					cout << "|";
					y2++;
					gotoxy(x1, y2);
				}
				head->printed = 1;
				head = head->down;

			}
			else if (!head->down && !head->left->printed)
			{
				head = head->left;
				x1 = x1 - 6;
				y2++;
				gotoxy(x1, y2);
			}
			else
			{
				if (head->up)
				{
					if (!head->up->printed)
					{
						y2 = y2 - 6;
						gotoxy(x1, y2);
						for (int i = 0;i < 6;i++)
						{
							cout << "|";
							y2++;
							gotoxy(x1, y2);
						}
					}
				}
				head->printed = 1;
				head = 0;
			}
		}
		if (pos2)
		{
			if (pos2->printed)
			{
				y2 = 0;
				pos2->printed = 1;
				gotoxy(x1, y2);
				for (int i = 0;i < 6;i++)
				{
					cout << "|";
					y2++;
					gotoxy(x1, y2);
				}
			}
		}
		x1 = x1 + 6;
		y2 = 0;
	}
	~Digit()
	{
		Delink();
	}
};
void main()
{
	Digit array[10];
	for (int i = 0;i < 10; i++)
	{
		array[i].SetPattern(i);
	}
	for (int i = 0;i < 10;i++)
	{
		array[i].PrintDigit();
	}
}