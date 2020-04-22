#include "define.h"
#include "searchmove.h"
#include "printchessboard.h"
#include "makemove.h"
#include<ctime>

int main()
{
	cout << "*************�������˻�����AI*************" << endl;
	cout << "����������: newblack  ��������" << endl;
	cout << "����������: newwhite  ���Ժ���" << endl;

	clock_t start, end;
	char cmd[15];
	cin >> cmd;
	int x, y;
	if (strcmp(cmd, "newblack")==0) {
		makeMove(8, 8, white);
	}
	cout << "����������: x y  ��ʾ���ӵ�" << endl;
	cout << "����������: -1 -1 ��ʾ����" << endl;
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
				cout << "��������" << endl;
				continue;
			};
			if (steps.size() >= 255) {
				print();
				cout << "ƽ�֣�" << endl;
			}
			if (gameover(x, y, black)) {
				// system("cls");
				print();
				cout << "����Ӯ�ˣ�" << endl;
				break;
			}
			cout << "����������..." << endl;
			start = clock();
			auto choice = searchMove(white);
			end = clock();
			makeMove(choice.first, choice.second, white);
			if (gameover(choice.first, choice.second, white)) {
				// system("cls");
				print();
				cout << "����Ӯ�ˣ�" << endl;
				//break;
			}
			if (steps.size() >= 255) {
				print();
				cout << "ƽ�֣�" << endl;
			}
			// system("cls");
			print();
			cout << "����������ɡ�(��ʱ" << end - start << "ms)" << endl;
			cout << "����������: x y  ��ʾ���ӵ�" << endl;
			cout << "����������: -1 -1 ��ʾ����" << endl;
		}
	}
}
