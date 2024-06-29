#include<iostream>
#include<time.h>
#include<conio.h>
#include "help.h"
using namespace std;
int main()
{
	srand(time(NULL));
	int a[8][8];
	bool s=startscreen();
	if (s == 1)
	{
		//creation of Game
		background();
		create(a);
		movingpointer(a);
		_getch();
	}
	return 0;
}