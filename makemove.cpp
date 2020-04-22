#include "define.h"
#include "printchessboard.h"
bool makeMove(int x,int y, int player)
{
	if (inboard(x, y)) 
	{
		if (chessBoard[x][y]) 
		{
			return false;
		}
		chessBoard[x][y] = player;
		steps.push(make_pair(x, y));
		return true;
	}
	//执行落子操作（chessboard[i][j]=1 & chessboard[i][j]=2）
	return false;
}

bool unMakeMove(int x,int y)
{
	if (!chessBoard[x][y]) {
		return false;
	}
	chessBoard[x][y] = 0;
	//撤销落子操作（chessboard[i][j]=0）
	steps.pop();
	return true;
}

bool regretMove() 
{
	if (steps.size()<2)
		return false;
	auto tmp = steps.top();
	unMakeMove(tmp.first, tmp.second);
	tmp = steps.top();
	unMakeMove(tmp.first, tmp.second);
	return true;
}