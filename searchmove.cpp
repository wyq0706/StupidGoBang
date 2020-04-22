#include "define.h"
#include "createmoves.h"
#include "makemove.h"
#include "evaluate.h"
#include "printchessboard.h"

int alphaBeta(int player, int alpha, int beta, int depth, int turn,int val);
bool inBound(int, int);

int to_move_x;
int to_move_y;

int search_depth = 4;

pair<int, int> searchMove(int player) //搜索函数主体
{
	int depth = steps.size() / 40;
	search_depth = 4 + depth;
	alphaBeta(player, INT_MIN, INT_MAX, search_depth, player,0);
	return make_pair(to_move_x, to_move_y);
}

int alphaBeta(int player, int alpha, int beta, int depth, int turn,int val) {
	// turn:0 MAX 1 MIN
	// player指需要下棋的选手；turn指在minimax过程中不断交替的选手
	int score = 0;
	int max_i = 0;
	int max_j = 0;
	if (turn == player) {
		int* moves_x = new int[MOVES_AVAILABLE];
		int* moves_y = new int[MOVES_AVAILABLE];
		int* values = new int[MOVES_AVAILABLE];
		int tmp_max = INT_MIN;
		int len = createMoves(moves_x, moves_y, values, turn);
		for (int k = 0;k < len;k++) {
			int i = moves_x[k];
			int j = moves_y[k];
			if (depth > 1) {
				makeMove(i, j, turn);
				score = alphaBeta(player, alpha, beta, depth - 1, 1 - turn,val+values[k]);
				unMakeMove(i, j);
			}
			else {
				score = val;
			}
			if (score > tmp_max) {
				tmp_max = score;
				if (depth == search_depth) {
					to_move_x = i;
					to_move_y = j;
				}
			}
			if (score > alpha) {
				alpha = score;
			}
			if (alpha >= beta) {
				delete[] moves_x;
				delete[] moves_y;
				delete[] values;
				//return make_pair(alpha, make_pair(max_i, max_j));
				return alpha;
			}
		}
		delete[] moves_x;
		delete[] moves_y;
		delete[] values;
		//return make_pair(alpha, make_pair(max_i, max_j));
		return alpha;
	}
	else {
		int* moves_x = new int[MOVES_AVAILABLE];
		int* moves_y = new int[MOVES_AVAILABLE];
		int* values = new int[MOVES_AVAILABLE];
		int len = createMoves(moves_x, moves_y, values, turn);
		for (int k = 0;k < len;k++) {
			int i = moves_x[k];
			int j = moves_y[k];
			if (depth > 1) {
				makeMove(i, j, turn);
				score= alphaBeta(player, alpha, beta, depth - 1, 1 - turn,val-values[k]);
				unMakeMove(i, j);
			}
			else {
				score = val;
			}
			if (score < beta) {
				beta = score;
			}
			if (alpha >= beta) {
				delete[] moves_x;
				delete[] moves_y;
				delete[] values;
				//return make_pair(beta, make_pair(max_i, max_j));
				return beta;
			}
		}
		delete[] moves_x;
		delete[] moves_y;
		delete[] values;
		//return make_pair(beta, make_pair(max_i, max_j));
		return beta;
	}
}