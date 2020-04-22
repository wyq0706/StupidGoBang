#include "define.h"
#include "searchmove.h"
#include "printchessboard.h"
#include "makemove.h"
#include<ctime>

int main()
{
	cout << "*************五子棋人机对弈AI*************" << endl;
	cout << "【规则】输入: newblack  电脑先手" << endl;
	cout << "【规则】输入: newwhite  电脑后手" << endl;

	clock_t start, end;
	char cmd[15];
	cin >> cmd;
	int x, y;
	if (strcmp(cmd, "newblack")==0) {
		makeMove(8, 8, white);
	}
	cout << "【规则】输入: x y  表示落子点" << endl;
	cout << "【规则】输入: -1 -1 表示悔棋" << endl;
	print();
	while (true) {
		cin >> x >> y;
		if(x==-1&&y==-1){
			regretMove();
			// system("cls");
			print();
			continue;
		}
		else{
			if (!makeMove(x, y, black)) {
				cout << "落子有误" << endl;
				continue;
			};
			if (steps.size() >= 255) {
				print();
				cout << "平局！" << endl;
			}
			if (gameover(x, y, black)) {
				// system("cls");
				print();
				cout << "黑子赢了！" << endl;
				break;
			}
			cout << "电脑下棋中..." << endl;
			start = clock();
			auto choice = searchMove(white);
			end = clock();
			makeMove(choice.first, choice.second, white);
			if (gameover(choice.first, choice.second, white)) {
				// system("cls");
				print();
				cout << "白子赢了！" << endl;
				//break;
			}
			if (steps.size() >= 255) {
				print();
				cout << "平局！" << endl;
			}
			// system("cls");
			print();
			cout << "电脑下棋完成。(耗时" << end - start << "ms)" << endl;
			cout << "【规则】输入: x y  表示落子点" << endl;
			cout << "【规则】输入: -1 -1 表示悔棋" << endl;
		}
	}
}
