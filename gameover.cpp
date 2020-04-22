#include "define.h"
bool checkHorizontal(int, int, int);
bool checkVertical(int, int, int);
bool checkDiagonal(int, int, int);

bool gameover(int x, int y, int player)//ÅĞ¶ÏÊÇ·ñÓÎÏ·½áÊø
{
	return checkHorizontal(x, y, player) || checkVertical(x, y, player) || checkDiagonal(x, y, player);
}

bool checkHorizontal(int x_, int y_, int player)
{
	int count = 1;
	int x = x_;
	int y = y_;
	for (int i = 1;i < 5;i++) 
	{
		if (inboard(x - 1, y) && chessBoard[x - 1][y] == player) 
		{
			count += 1;
			x--;
		}
		else 
		{
			break;
		}
	}
	x = x_;
	y = y_;
	for (int i = 1;i < 5;i++) 
	{
		if (inboard(x + 1, y) && chessBoard[x + 1][y] == player) 
		{
			count += 1;
			x++;
		}
		else 
		{
			break;
		}
	}
	if (count >= 5) 
	{
		return true;
	}
	return false;
}

bool checkVertical(int x_, int y_, int player)
{
	int count = 1;
	int x = x_;
	int y = y_;
	for (int i = 1;i < 5;i++) 
	{
		if (inboard(x, y - 1) && chessBoard[x][y - 1] == player) 
		{
			count += 1;
			y--;
		}
		else 
		{
			break;
		}
	}
	x = x_;
	y = y_;
	for (int i = 1;i < 5;i++) {
		if (inboard(x, y + 1) && chessBoard[x][y + 1] == player) 
		{
			count += 1;
			y++;
		}
		else 
		{
			break;
		}
	}
	if (count >= 5) 
	{
		return true;
	}
	return false;
}

bool checkDiagonal(int x_, int y_, int player)
{
	int count = 1;
	int x = x_;
	int y = y_;
	for (int i = 1;i < 5;i++) 
	{
		if (inboard(x-1, y-1) && chessBoard[x-1][y-1] == player) 
		{
			count += 1;
			x--;
			y--;
		}
		else 
		{
			break;
		}
	}
	x = x_;
	y = y_;
	for (int i = 1;i < 5;i++) 
	{
		if (inboard(x+1, y+1) && chessBoard[x+1][y+1] == player) 
		{
			count += 1;
			x++;
			y++;
		}
		else 
		{
			break;
		}
	}
	if (count >= 5) {
		return true;
	}

	x = x_;
	y = y_;
	count = 1;
	for (int i = 1;i < 5;i++) 
	{
		if (inboard(x-1, y+1) && chessBoard[x-1][y+1] == player) 
		{
			count += 1;
			x--;
			y++;
		}
		else 
		{
			break;
		}
	}
	x = x_;
	y = y_;
	for (int i = 1;i < 5;i++) 
	{
		if (inboard(x+1, y-1) && chessBoard[x+1][y-1] == player) 
		{
			count += 1;
			x++;
			y--;
		}
		else 
		{
			break;
		}
	}
	if (count >= 5) 
	{
		return true;
	}
	return false;
}
