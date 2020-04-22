#include "define.h"

int getLine(int x, int y, int i, int j);// i:方向 j:相对x,y的顺序值（以x,y为0） x,y:当前点
int evaluate_one(int, int, int, int);

int evaluate(int x, int y,int player)
{
    return evaluate_one(x, y, player, black) + evaluate_one(x, y, player, white);
}

int evaluate_one(int x,int y,int me,int plyer)//估值算法，返回估值
{
    int value = 0;
    int numoftwo = 0;
    for (int i = 1; i <= 8; i++) { // 8个方向
        // 活四 01111* *代表当前空位置  0代表其他空位置    下同 
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) == plyer && getLine(x,y, i, -4) == plyer
            && getLine(x,y, i, -5) == 0) {
            value += 300000;
            if (me != plyer) { value -=500; }
            continue;
        }
        // 死四A 21111*
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) == plyer && getLine(x,y, i, -4) == plyer
            && (getLine(x,y, i, -5) == 3 - plyer || getLine(x,y, i, -5) == -1)) {
            value += 250000;
            if (me != plyer) { value -=500; }
            continue;
        }
        // 死四B 111*1
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) == plyer && getLine(x,y, i, 1) == plyer) {
            value += 240000;
            if (me != plyer) { value -=500; }
            continue;
        }
        // 死四C 11*11
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, 1) == plyer && getLine(x,y, i, 2) == plyer) {
            value += 230000;
            if (me != plyer) { value -= 500; }
            continue;
        }
        // 活三 近3位置 111*0
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
        // 活三 远3位置 1110*
        if (getLine(x,y, i, -1) == 0 && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) == plyer && getLine(x,y, i, -4) == plyer) {
            value += 350;
            continue;
        }
        // 死三 11*1
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
        //活二的个数   
        if (getLine(x,y, i, -1) == plyer && getLine(x,y, i, -2) == plyer
            && getLine(x,y, i, -3) != 3 - plyer && getLine(x,y, i, 1) != 3 - plyer) {
            numoftwo++;
        }
        //其余散棋
        int numOfplyer = 0; // 因为方向会算两次？
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
//由于五子棋搜索分支庞大，通常无法直接搜索到胜负终局，当搜索到一定深度时需要根据局面返回搜索结果。
//参考资料：
//张明亮, 吴俊, 李凡长. 五子棋机器博弈系统评估函数的设计[J]. 计算机应用, 2012, 32(07):1969-1972.
//裴博文. 五子棋人工智能权重估值算法[J]. 电脑编程技巧与维护, 2008(6):69-75.
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