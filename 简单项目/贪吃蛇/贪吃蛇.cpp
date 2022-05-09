#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <mmsystem.h>
#include <mmsyscom.h>
#pragma comment(lib,"Winmm.lib")
/*
有多少节
蛇的方向，速度
*/
//表示蛇的方向
enum DIR {
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
#define SIZE_SNAKE 500	//蛇的最大节数
//蛇的结构
struct Snake {
	int size;	//蛇的节数
	int dir;	//蛇的方向
	int  speed;	//蛇的移动速度
	POINT coor[SIZE_SNAKE];	//坐标
}snake;
//食物结构
struct Food {
	int x;
	int y;
	int r;			//食物半径
	bool flag;		//食物是否被吃
	DWORD color;	//食物颜色
}food;
//数据的初始化
void GameInit() {
	//播放音乐
	mciSendString(_T("open 7874.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	//设置创建窗口	SHOWCONSOLE显示控制台
	initgraph(800, 600,SHOWCONSOLE);
	//设置随机数种子
	srand(time(0));
	//初始化蛇，一开始有三节
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size;i++) {
		snake.coor[i].x = 40 - 10 * i;
		snake.coor[i].y = 10;
		printf("%d %d ", snake.coor[i].x, snake.coor[i].y);
	}
	//初始化食物,产生随机数
	food.x = rand() % 800;
	food.y = rand() % 600;
	food.color = RGB(rand() % 255, rand() % 255, rand() % 255);
	food.r = rand() % 10 + 5;
	food.flag = true;
}
//绘制
void GameDraw() {
	//双缓冲绘图
	BeginBatchDraw();
	//设置颜色
	setbkcolor(RGB(85, 95, 131));
	cleardevice();
	//绘制蛇
	setfillcolor(BLACK);
	for (int i = 0; i < snake.size; i++) {
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制食物
	if (food.flag) {
		solidcircle(food.x, food.y, food.r);
	}

	EndBatchDraw();
}

//移动蛇
void MoveSnake() {
	//移动蛇,坐标变化
	for (int i = snake.size - 1; i > 0; i--) {
		//每一次移动到上一个的位置
		snake.coor[i] = snake.coor[i - 1];
	}
	switch (snake.dir) {
	case LEFT:snake.coor[0].x-=snake.speed;
		if (snake.coor[0].x+10 <= 0) {
			snake.coor[0].x = 800;
		}
		break;
	case RIGHT:snake.coor[0].x += snake.speed;
		if (snake.coor[0].x - 10 >= 800) {
			snake.coor[0].x = 0;
		}
		break;
	case UP:snake.coor[0].y -= snake.speed;
		if (snake.coor[0].y + 10 <= 0) {
			snake.coor[0].y = 600;
		}
		break;
	case DOWN:snake.coor[0].y += snake.speed;
		if (snake.coor[0].y - 10 >= 600) {
			snake.coor[0].y = 0;
		}
		break;
		
	}
}

//通过按键改变蛇的方向
void keyControl() {
	//首先判断有没有按键
	if (_kbhit()) {
		//有按键则返回真
	//72 80 75 77	上下左右键值
		switch (_getch()) {
		case 'w':
		case 'W':
		case 72:
			//改变方向
			if (snake.dir != DOWN) {
				snake.dir = UP;
			}
			break;
		case 's':
		case 'S':
		case 80:
			if (snake.dir != UP) {
				snake.dir = DOWN;
			}
			break;
		case 'a':
		case 'A':
		case 75:
			if (snake.dir != RIGHT) {
				snake.dir = LEFT;
			}
			break;
		case 'd':
		case 'D':
		case 77:
			if (snake.dir != LEFT) {
				snake.dir = RIGHT;
			}
			break;
		}
	}
}
//判断吃食物
void Eatfood() {
	//dawd
	if (food.flag && snake.coor[0].x >= food.x-food.r && snake.coor[0].x<= food.x+food.r &&
		snake.coor[0].y>=food.y-food.r && snake.coor[0].y<=food.y+food.r) {
		food.flag = false;
		snake.size++;
	}
	if (!food.flag) {
		//食物消失，重新生成一个食物
		food.x = rand() % 800;
		food.y = rand() % 600;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = rand() % 10 + 5;
		food.flag = true;
	}
}
//游戏暂停
void stopgame() {
	//检测键盘判断
	if (_kbhit()) {
		if (_getch() == ' ')
		{
			while (_getch() == ' ');
		}
	}

}
int main(void) {
	GameInit();

	while (1) {
		GameDraw();
		MoveSnake();
		stopgame();
		keyControl();
		Eatfood();
		Sleep(50);
	}

	system("pause");
	return 0;
}