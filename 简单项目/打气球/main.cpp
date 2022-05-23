#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int score = 0;
//�������
#define NUM 15
struct Ballon
{
	double x;
	double y;
	COLORREF color;
	double vx;
	double vy;
	int isdie;
}ball[NUM];
//������̨
struct Battery
{
	double x;
	double y;
	double cx;	//�仯������
	double cy;
	double rad;	//����
	double len;	//�ڹܳ���
}battery;
//�ṹ���ʼ��
void Ballon_init(struct Ballon* ball, double x, double y)
{
	ball->x = x;
	ball->y = y;
	ball->color = RGB(rand()%256,rand()%256,rand()%256);
	ball->vx = 0;	// 1 2 3
	ball->vy = -(5 + rand() % 10);
	ball->isdie = false;;
}
//�������� 
void ballon_draw(struct Ballon* ball)
{
	if (!ball->isdie)
	{
		setfillcolor(ball->color);
		setlinecolor(WHITE);
		//����һ����Բ
		solidellipse(ball->x, ball->y, ball->x + 30, ball->y + 60);
		//����һ��Բ��
		arc(ball->x + 5, ball->y + 5, ball->x + 30 - 5, ball->y + 60 - 5, 0, 1.2);
		//����β��
		arc(ball->x + 0, ball->y + 60, ball->x + 30 - 10, ball->y + 60 + 20, 0, 1.2);
	}
}
//���������ƶ�
void ballon_move(Ballon* ball, double dx, double dy)
{
	ball->x += dx;
	ball->y += dy;
	//�������ɳ��߽磬����������
	if (ball->y + 60 <= 0)
	{
		Ballon_init(ball, rand() % getwidth(), getheight());
	}
}
//��̨��ʼ��
void bat_init(Battery* bat,double x,double y)
{
	bat->x = x;
	bat->y = y;
	bat->len = 70;
	bat->cx = bat->x;
	bat->cy = bat->y + bat->len;
	bat->rad = 0;
}
//������̨
void bat_draw(Battery* bat)
{
	//������̨
	//������������ʽ
	setlinestyle(PS_SOLID, 3);
	setlinecolor(BLACK);
	circle(bat->x, bat->y, 50);
	//����Բ��
	setfillcolor(WHITE);
	solidcircle(bat->x, bat->y, 5);
	//�����ڹ�
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 5);
	line(bat->x, bat->y, bat->cx, bat->cy);
}
//��ȡ�ڹܵ�λ��
void Mouse_bat(Battery* bat, ExMessage* msg)
{
	bat->rad = atan2(bat->y - msg->y, msg->x - bat->x);	//��ȡ�Ƕ�
	bat->cx = bat->x + cos(bat->rad) * bat->len;
	bat->cy = bat->y - sin(bat->rad) * bat->len;
}

//�����ӵ�
void shotBattery(ExMessage* msg)
{
	for (int i = 0; i < NUM; i++)
	{
		if (msg->x >= ball->x && msg->x <= ball->x + 30 && msg->y >= ball->y && msg->y <= ball->y + 60)
		{
			ball->isdie = true;
		}
	}
	ball->isdie= false;
}
void score_draw()
{
	//���Ʒ���
	//��ʽ���ַ���
	char str[50] = { 0 };
	sprintf(str,"score:%d", score);
	outtextxy(0, 0, str);
}
int main(void)
{
	initgraph(480, 640,SHOWCONSOLE);
	//��������� 
	srand(time(0));
	setbkmode(TRANSPARENT);
	IMAGE img;
	loadimage(&img, "1.jpeg", getwidth(), getheight());
	for (int i = 0; i < 10; i++)
	{
		Ballon_init(&ball[i], rand() % getwidth(), rand() % getheight());
		ballon_draw(&ball[i]);
	}
	//��̨
	bat_init(&battery, getwidth() / 2, getheight() - 10);
	bat_draw(&battery);
	//�������ƶ�����
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		//���Ʊ���ͼƬ
		putimage(0, 0, &img);
		for (int i = 0; i < NUM; i++)
		{
			ballon_move(&ball[i], ball[i].vx, ball[i].vy);
			ballon_draw(&ball[i]);
		}
		bat_draw(&battery);
		score_draw();
		EndBatchDraw();
		score++;
		
		//��ȡ�����Ϣ
		ExMessage msg;
		while (peekmessage(&msg, EM_MOUSE)) {
			Mouse_bat(&battery, &msg);
			if (msg.message == WM_LBUTTONDOWN)
			{
				shotBattery(&msg);
			}
		}
		Sleep(20);
	}
	system("pause");
	return 0;
}