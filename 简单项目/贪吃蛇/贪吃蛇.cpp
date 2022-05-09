#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <mmsystem.h>
#include <mmsyscom.h>
#pragma comment(lib,"Winmm.lib")
/*
�ж��ٽ�
�ߵķ����ٶ�
*/
//��ʾ�ߵķ���
enum DIR {
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
#define SIZE_SNAKE 500	//�ߵ�������
//�ߵĽṹ
struct Snake {
	int size;	//�ߵĽ���
	int dir;	//�ߵķ���
	int  speed;	//�ߵ��ƶ��ٶ�
	POINT coor[SIZE_SNAKE];	//����
}snake;
//ʳ��ṹ
struct Food {
	int x;
	int y;
	int r;			//ʳ��뾶
	bool flag;		//ʳ���Ƿ񱻳�
	DWORD color;	//ʳ����ɫ
}food;
//���ݵĳ�ʼ��
void GameInit() {
	//��������
	mciSendString(_T("open 7874.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	//���ô�������	SHOWCONSOLE��ʾ����̨
	initgraph(800, 600,SHOWCONSOLE);
	//�������������
	srand(time(0));
	//��ʼ���ߣ�һ��ʼ������
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.size;i++) {
		snake.coor[i].x = 40 - 10 * i;
		snake.coor[i].y = 10;
		printf("%d %d ", snake.coor[i].x, snake.coor[i].y);
	}
	//��ʼ��ʳ��,���������
	food.x = rand() % 800;
	food.y = rand() % 600;
	food.color = RGB(rand() % 255, rand() % 255, rand() % 255);
	food.r = rand() % 10 + 5;
	food.flag = true;
}
//����
void GameDraw() {
	//˫�����ͼ
	BeginBatchDraw();
	//������ɫ
	setbkcolor(RGB(85, 95, 131));
	cleardevice();
	//������
	setfillcolor(BLACK);
	for (int i = 0; i < snake.size; i++) {
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//����ʳ��
	if (food.flag) {
		solidcircle(food.x, food.y, food.r);
	}

	EndBatchDraw();
}

//�ƶ���
void MoveSnake() {
	//�ƶ���,����仯
	for (int i = snake.size - 1; i > 0; i--) {
		//ÿһ���ƶ�����һ����λ��
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

//ͨ�������ı��ߵķ���
void keyControl() {
	//�����ж���û�а���
	if (_kbhit()) {
		//�а����򷵻���
	//72 80 75 77	�������Ҽ�ֵ
		switch (_getch()) {
		case 'w':
		case 'W':
		case 72:
			//�ı䷽��
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
//�жϳ�ʳ��
void Eatfood() {
	//dawd
	if (food.flag && snake.coor[0].x >= food.x-food.r && snake.coor[0].x<= food.x+food.r &&
		snake.coor[0].y>=food.y-food.r && snake.coor[0].y<=food.y+food.r) {
		food.flag = false;
		snake.size++;
	}
	if (!food.flag) {
		//ʳ����ʧ����������һ��ʳ��
		food.x = rand() % 800;
		food.y = rand() % 600;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = rand() % 10 + 5;
		food.flag = true;
	}
}
//��Ϸ��ͣ
void stopgame() {
	//�������ж�
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