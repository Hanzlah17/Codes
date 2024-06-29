#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int i, j, f = 0, p1 = -1, p2 = -1, r1, r2, c1 = 0, c2 = 0;
	char ch1, ch2;
	for (i = 1;c1 == 0 || c2 == 0;i = i++)
	{
		if (c1 == 0 && p1 == -1)
		{
			cout << "player 1 press any key to roll the dice" << endl;
			cin >> ch1;
			r1 = rand() % 6 + 1;
			cout << r1 << endl;
			if (r1 == 6)
			{
				c1 = 1;
				p1 = 0;
			}
		}
		if (c2 == 0 && p2 == -1)
		{
			cout << "player 2 press any to roll the dice" << endl;
			cin >> ch2;
			r2 = rand() % 6 + 1;
			cout << r2 << endl;
			if (r2 == 6)
			{
				c2 = 1;
				p2 = 0;
			}
		}
	}
	for (j = 1;(p1 >= 0 && p1 < 56) || (p2 >= 0 && p2 < 56);j = j++)
	{
		if (c1 > 0)
		{
			cout << "player 1 press any key to roll the dice" << endl;
			cin >> ch1;
			r1 = rand() % 6 + 1;
			cout << r1 << endl;
			if (p1 > 49)
			{
				p1 = p1 + r1;
				cout << "player 1 is currently at= " << p1 << endl;
				if (p1 == 56)
				{
					cout << "Player 1 won :)" << endl;
					p1 = 57;
					p2 = 57;
				}
				else if (p1 > 56)
				{
					cout << "turn cancelled" << endl;
					p1 = p1 - r1;
				}
			}
			else
			{
				p1 = p1 + r1;
				cout << "player 1 is currently at= " << p1 << endl;
				if (r1 == 6)
				{
					cout << "player 1 press any key to roll the dice" << endl;
					cin >> ch1;
					r1 = rand() % 6 + 1;
					cout << r1 << endl;
					p1 = p1 + r1;
					cout << "player 1 is currently at= " << p1 << endl;
				}
			}
		}
		if (c2 > 0)
		{
			cout << "player 2 press any key to roll the dice" << endl;
			cin >> ch2;
			r2 = rand() % 6 + 1;
			cout << r2 << endl;
			if (p2 > 49)
			{
				p2 = p2 + r2;
				cout << "player 2 is currently at= " << p2 << endl;
				if (p2 == 56)
				{
					cout << "Player 2 won :)" << endl;
					p1 = 57;
					p2 = 57;
				}

				else if (p2 > 56)
				{
					cout << "turn cancelled" << endl;
					p2 = p2 - r2;
				}
			}
			else
			{
				p2 = p2 + r2;
				cout << "player 2 is currently at= " << p2 << endl;
				if (r2 == 6)
				{
					cout << "player 2 press space to roll the dice" << endl;
					cin >> ch2;
					r2 = rand() % 6 + 1;
					cout << r2 << endl;
					p2 = p2 + r2;
					cout << "player 2 is currently at= " << p2 << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}
