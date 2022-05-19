
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
//游戏结束
void GameOver() {
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(100, 0, "楷体");
	outtextxy(250, 100, "游戏结束");
	outtextxy(100, 500, "重新开始");
	outtextxy(750, 500, "退出");

}
int main(void) {
	/*
	捕捉字母小游戏
	*/
	srand(time(0));
	initgraph(911, 680);

	IMAGE bk_img, apple[2];
	ExMessage msg;
	loadimage(&bk_img, "bk2.png");
	loadimage(&apple[0], "apple0.jpg");
	loadimage(&apple[1], "apple1.jpg");

	mciSendString("open 本草纲目.mp3", 0, 0, 0);
	mciSendString("open 告白气球.mp3", 0, 0, 0);
	mciSendString("play 告白气球.mp3", 0, 0, 0);
	LET.x = rand() % 900;	//定义x出现的范围
	LET.y = 0;
	LET.speed = 5;
	LET.num =(char) 65 + rand() % 26;	//26个大写英文字母随机出现
	LET.score = 0;
	LET.time = 60;	//倒计时
	putimage(0, 0, &bk_img);

	while (1) {
		//绘图
		LET.x = rand() % 900;	//定义x出现的范围
		LET.num = (char)65 + rand() % 26;
		for (LET.y = 0; LET.y < 680; LET.y += LET.speed) {

			char str[2][50] = { 0 };
			BeginBatchDraw();
			//cleardevice();
			putimage(0, 0, &bk_img);	//图片覆盖
			//设置字体
			settextcolor(BLUE);
			setbkmode(TRANSPARENT);
			settextstyle(30, 0, "楷体");
			//分数
			sprintf(str[0], "%d", LET.score);
			outtextxy(50, 50, "分数:");
			outtextxy(150, 50, str[0]);
			//倒计时

			putimage(LET.x - 20, LET.y - 20, &apple[0], SRCPAINT);	
			putimage(LET.x - 20, LET.y - 20, &apple[1], SRCAND);
			outtextxy(LET.x,LET.y, LET.num);
			EndBatchDraw();

			if (LET.y+20 >= 680) {
				GameOver();
			}
			peekmessage(&msg, EM_KEY);		//接受键盘鼠标消息
			//判断按键
			if (msg.message==WM_KEYDOWN) {
				if (msg.vkcode == LET.num) {
					LET.score += LET.speed;
					break;
				}
				else if (msg.vkcode == '1' || msg.vkcode==VK_NUMPAD1) {
					//加速
					LET.speed = 10;
					mciSendString("close 告白气球.mp3", 0, 0, 0);
					mciSendString("play 本草纲目.mp3", 0, 0, 0);
				}
				else if (msg.vkcode == '2' || msg.vkcode==VK_NUMPAD2) {
					//减速
					LET.speed = 2;
					mciSendString("close 本草纲目.mp3", 0, 0, 0);
					mciSendString("play 告白气球.mp3", 0, 0, 0);
				}
			}
			Sleep(20);
		}
	}

	system("pause");
	return 0;

}