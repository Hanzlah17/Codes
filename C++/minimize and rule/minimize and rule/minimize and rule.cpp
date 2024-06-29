#include<iostream>
using namespace std;
int main()
{
	int cards[52] = { 1,2,3,4,5,6,0,8,9,10,0,10,10,1,2,3,4,5,6,0,8,9,10,0,10,10,1,2,3,4,5,6,0,8,9,10,0,10,10,1,2,3,4,5,6,0,8,9,10,0,10,10 };
	int p1[5], p2[5], p3[5], p4[5], index = 0, open, player = 1, max, indexm, s1 = 0, s2 = 0, s3 = 0, s4 = 0, indexmi = 0, min=0, temp;
	int sum[4] = { s1,s2,s3,s4 };
	min = sum[0];
	for (int i = 0;i < 5;i++)
	{
		p1[i] = cards[index];
		index++;
		p2[i] = cards[index];
		index++;
		p3[i] = cards[index];
		index++;
		p4[i] = cards[index];
		index++;
	}
	open = cards[index];
	index++;
	while (index < 52)
	{
		if (player == 1)
		{
			max = 0;
			for (int j = 0;j < 5;j++)
			{
				if (max < p1[j])
				{
					max = p1[j];
					indexm = j;
				}
			}
			if (max > open)
			{
				swap(open, p1[indexm]);
			}
			else
			{
				open = cards[index];
				index++;
				if (max > open)
				{
					swap(open, p1[indexm]);
				}
			}
			player = 2;
		}
		else if (player == 2)
		{
			max = 0;
			for (int j = 0;j < 5;j++)
			{
				if (max < p2[j])
				{
					max = p2[j];
					indexm = j;
				}
			}
			if (max > open)
			{
				swap(open, p2[indexm]);
			}
			else
			{
				open = cards[index];
				index++;
				if (max > open)
				{
					swap(open, p2[indexm]);
				}
			}
			player = 3;
		}
		else if (player == 3)
		{
			max = 0;
			for (int j = 0;j < 5;j++)
			{
				if (max < p3[j])
				{
					max = p3[j];
					indexm = j;
				}
			}
			if (max > open)
			{
				swap(open, p3[indexm]);
			}
			else
			{
				open = cards[index];
				index++;
				if (max > open)
				{
					swap(open, p3[indexm]);
				}
			}
			player = 4;
		}
		else
		{
			max = 0;
			for (int j = 0;j < 5;j++)
			{
				if (max < p4[j])
				{
					max = p4[j];
					indexm = j;
				}
			}
			if (max > open)
			{
				swap(open, p4[indexm]);
			}
			else
			{
				open = cards[index];
				index++;
				if (max > open)
				{
					swap(open, p4[indexm]);
				}
			}
			player = 1;
		}
	}
	cout << "-----player1----" << endl;
	for (int i = 0;i < 5;i++)
	{
		cout << p1[i] << " ";
	}
	cout << endl;
	cout << "-----player2----" << endl;
	for (int i = 0;i < 5;i++)
	{
		cout << p2[i] << " ";
	}
	cout << endl;
	cout << "-----player3----" << endl;
	for (int i = 0;i < 5;i++)
	{
		cout << p3[i] << " ";
	}
	cout << endl;
	cout << "-----player4----" << endl;
	for (int i = 0;i < 5;i++)
	{
		cout << p4[i] << " ";
	}
	cout << endl;
	for (int i = 0;i < 5;i++)
	{
		s1 = s1 + p1[i];
		s2 = s2 + p2[i];
		s3 = s3 + p3[i];
		s4 = s4 + p4[i];
	}
	cout << "total of player 1=" << s1 << endl;
	cout << "total of player 2=" << s2 << endl;
	cout << "total of player 3=" << s3 << endl;
	cout << "total of player 4=" << s4 << endl;
	for (int j = 0;j < 5;j++)
	{
		if (min > sum[j])
		{
			min = sum[j];
			indexmi = j;
		}
	}
	system("pause");
	return 0;
}