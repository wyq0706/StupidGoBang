
#ifndef _DEFINE_
#define _DEFINE_
//ȫ�ֱ�������

#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include<stack>
using namespace std;

#define blank 0		//�հ׵�
#define black 1		//�ڷ�
#define white 2		//�׷�
#define inf 1000000		
#define inboard(a,b) (a>0 && a<=15 && b>0 && b<=15)		//���ڼ����з��Ƿ���������

#define GRID_NUM 16	//���̹�ģ	
#define MOVES_AVAILABLE 30 //ÿ����������߷�������
extern int chessBoard[GRID_NUM][GRID_NUM]; //����
bool gameover(int x, int y, int player); //�ж��Ƿ���Ϸ����
extern stack<pair<int, int>> steps;
bool inBound(int, int);
#endif


