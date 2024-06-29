#include"mstream.h"
using namespace std;
void main()
{
	int board[3][3] = { 0 };
	char a;
	cin >> a;
	CreateBox();
	MoveCursor(board);
	_getch();
}