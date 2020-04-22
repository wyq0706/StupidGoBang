#include "define.h"
#include "evaluate.h"

int tmp_moves_x[15 * 15];
int tmp_moves_y[15 * 15];
int tmp_values[15 * 15];
int idx[15 * 15];

bool cmp(int a, int b) 
{ 
	return tmp_values[a] > tmp_values[b]; 
}

int createMoves(int* moves_x,int* moves_y,int* values, int player) //����ȫ���Ϸ��߷���
{
	//�������пո�λ�õ�������������������moves��values�У�˳�����Ҫ��
	//���غϷ��߷����ĳ���
	int len = 0;
	for (int i = 1; i < 16; i++) {
		for (int j = 1; j < 16; j++) {
			if (!inboard(i, j)||!inBound(i,j)||chessBoard[i][j]) 
				continue;
			tmp_moves_x[len] = i;
			tmp_moves_y[len] = j;
			tmp_values[len] = evaluate(i, j, player);
			idx[len] = len;
			len++;
		}
	}
	sort(idx, idx + len, cmp);
	if (len > MOVES_AVAILABLE) {
		len = MOVES_AVAILABLE;
	}
	for (int i = 0; i < len; i++) {
		moves_x[i] = tmp_moves_x[idx[i]];
		moves_y[i] = tmp_moves_y[idx[i]];
		values[i] = tmp_values[idx[i]];
	}
	return len;
}
//�������кϷ����ӵ㡣������������˵�������ϵĿհ׵��Ϊ�����߷���