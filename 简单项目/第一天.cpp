
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
struct letter {
	int x;
	int y;
	int speed;
	char num;
	int score;
	int time;
}LET;
//��Ϸ����
void GameOver() {
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(100, 0, "����");
	outtextxy(250, 100, "��Ϸ����");
	outtextxy(100, 500, "���¿�ʼ");
	outtextxy(750, 500, "�˳�");

}
int main(void) {
	/*
	��׽��ĸС��Ϸ
	*/
	srand(time(0));
	initgraph(911, 680);

	IMAGE bk_img, apple[2];
	ExMessage msg;
	loadimage(&bk_img, "bk2.png");
	loadimage(&apple[0], "apple0.jpg");
	loadimage(&apple[1], "apple1.jpg");

	mciSendString("open ���ݸ�Ŀ.mp3", 0, 0, 0);
	mciSendString("open �������.mp3", 0, 0, 0);
	mciSendString("play �������.mp3", 0, 0, 0);
	LET.x = rand() % 900;	//����x���ֵķ�Χ
	LET.y = 0;
	LET.speed = 5;
	LET.num =(char) 65 + rand() % 26;	//26����дӢ����ĸ�������
	LET.score = 0;
	LET.time = 60;	//����ʱ
	putimage(0, 0, &bk_img);

	while (1) {
		//��ͼ
		LET.x = rand() % 900;	//����x���ֵķ�Χ
		LET.num = (char)65 + rand() % 26;
		for (LET.y = 0; LET.y < 680; LET.y += LET.speed) {

			char str[2][50] = { 0 };
			BeginBatchDraw();
			//cleardevice();
			putimage(0, 0, &bk_img);	//ͼƬ����
			//��������
			settextcolor(BLUE);
			setbkmode(TRANSPARENT);
			settextstyle(30, 0, "����");
			//����
			sprintf(str[0], "%d", LET.score);
			outtextxy(50, 50, "����:");
			outtextxy(150, 50, str[0]);
			//����ʱ

			putimage(LET.x - 20, LET.y - 20, &apple[0], SRCPAINT);	
			putimage(LET.x - 20, LET.y - 20, &apple[1], SRCAND);
			outtextxy(LET.x,LET.y, LET.num);
			EndBatchDraw();

			if (LET.y+20 >= 680) {
				GameOver();
			}
			peekmessage(&msg, EM_KEY);		//���ܼ��������Ϣ
			//�жϰ���
			if (msg.message==WM_KEYDOWN) {
				if (msg.vkcode == LET.num) {
					LET.score += LET.speed;
					break;
				}
				else if (msg.vkcode == '1' || msg.vkcode==VK_NUMPAD1) {
					//����
					LET.speed = 10;
					mciSendString("close �������.mp3", 0, 0, 0);
					mciSendString("play ���ݸ�Ŀ.mp3", 0, 0, 0);
				}
				else if (msg.vkcode == '2' || msg.vkcode==VK_NUMPAD2) {
					//����
					LET.speed = 2;
					mciSendString("close ���ݸ�Ŀ.mp3", 0, 0, 0);
					mciSendString("play �������.mp3", 0, 0, 0);
				}
			}
			Sleep(20);
		}
	}

	system("pause");
	return 0;

}