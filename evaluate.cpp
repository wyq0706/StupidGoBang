#include "define.h"

int getLine(int x, int y, int i, int j);// i:���� j:���x,y��˳��ֵ����x,yΪ0�� x,y:��ǰ��
int evaluate_one(int, int, int, int);

int evaluate(int x, int y,int player)
{
    return evaluate_one(x, y, player, black) + evaluate_one(x, y, player, white);
}

int evaluate_one(int x,int y,int me,int plyer)//��ֵ�㷨�����ع�ֵ
{
    int value = 0;
    int numoftwo = 0;
    for (int i = 1; i <= 8; i++) { // 8������
        // ���� 01111* *����ǰ��λ��  0����������λ��    ��ͬ 
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) == plyer && getLine(x,y, i, -4) == plyer
            && getLine(x,y, i, -5) == 0) {
            value += 300000;
            if (me != plyer) { value -=500; }
            continue;
        }
        // ����A 21111*
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) == plyer && getLine(x,y, i, -4) == plyer
            && (getLine(x,y, i, -5) == 3 - plyer || getLine(x,y, i, -5) == -1)) {
            value += 250000;
            if (me != plyer) { value -=500; }
            continue;
        }
        // ����B 111*1
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) == plyer && getLine(x,y, i, 1) == plyer) {
            value += 240000;
            if (me != plyer) { value -=500; }
            continue;
        }
        // ����C 11*11
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, 1) == plyer && getLine(x,y, i, 2) == plyer) {
            value += 230000;
            if (me != plyer) { value -= 500; }
            continue;
        }
        // ���� ��3λ�� 111*0
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) == plyer) {
            if (getLine(x,y, i, 1) == 0) {
                value += 750;
                if (getLine(x,y, i, -4) == 0) {
                    value += 3150;
                    if (me != plyer) { value-=500; }
                }
            }
            if ((getLine(x,y, i, 1) == 3 - plyer || getLine(x,y, i, 1) == -1) && getLine(x,y, i, -4) == 0) {
                value += 500;
            }
            continue;
        }
        // ���� Զ3λ�� 1110*
        if (getLine(x,y, i, -1) == 0 && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) == plyer && getLine(x,y, i, -4) == plyer) {
            value += 350;
            continue;
        }
        // ���� 11*1
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, 1) == plyer) {
            value += 600;
            if (getLine(x,y, i, -3) == 0 && getLine(x,y, i, 2) == 0) {
                value += 3150;
                continue;
            }
            if ((getLine(x,y, i, -3) == 3 - plyer || getLine(x,y, i, -3) == -1) && (getLine(x,y, i, 2) == 3 - plyer || getLine(x,y, i, 2) == -1)) {
                continue;
            }
            else {
                value += 700;
                continue;
            }
        }
        //����ĸ���   
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) != 3 - plyer && getLine(x,y, i, 1) != 3 - plyer) {
            numoftwo++;
        }
        //����ɢ��
        int numOfplyer = 0; // ��Ϊ����������Σ�
        for (int k = -4; k <= 0; k++) { // ++++* +++*+ ++*++ +*+++ *++++
            int temp = 0;
            for (int l = 0; l <= 4; l++) {
                if (getLine(x,y, i, k + l) == plyer) {
                    temp++;
                }
                else
                    if (getLine(x,y, i, k + l) == 3 - plyer
                        || getLine(x,y, i, k + l) == -1) {
                        temp = 0;
                        break;
                    }
            }
            numOfplyer += temp;
        }
        value += numOfplyer * 15;
        if (numOfplyer != 0) {
        }
    }
    if (numoftwo >= 2) {
        value += 3000;
        if (me != plyer) {
            value -= 100;
        }
    }
    return value;
}
//����������������֧�Ӵ�ͨ���޷�ֱ��������ʤ���վ֣���������һ�����ʱ��Ҫ���ݾ��淵�����������
//�ο����ϣ�
//������, �⿡, ���. �������������ϵͳ�������������[J]. �����Ӧ��, 2012, 32(07):1969-1972.
//�Ჩ��. �������˹�����Ȩ�ع�ֵ�㷨[J]. ���Ա�̼�����ά��, 2008(6):69-75.
//httx,ys://www.cnblogs.com/maxuewei2/x,y/4825520.html

int getLine(int x,int y, int i, int j) {
    switch (i) {
    case 1:
        x = x + j;
        break;
    case 2:
        x = x + j;
        y = y + j;
        break;
    case 3:
        y = y + j;
        break;
    case 4:
        x = x - j;
        y = y + j;
        break;
    case 5:
        x = x - j;
        break;
    case 6:
        x = x - j;
        y = y - j;
        break;
    case 7:
        y = y - j;
        break;
    case 8:
        x = x + j;
        y = y - j;
    }
    if (!inboard(x,y)) {
        return -1;
    }
    return chessBoard[x][y];
}