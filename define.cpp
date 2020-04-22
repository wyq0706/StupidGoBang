#include "define.h"

int chessBoard[GRID_NUM][GRID_NUM];//∂®“Â∆Â≈Ã

stack<pair<int, int>> steps;

bool inBound(int x, int y)
{
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			if (i == 0 && j == 0) continue;
			if (chessBoard[x + i][y + j] != 0) 
				return true;
		}
	}
	return false;
}