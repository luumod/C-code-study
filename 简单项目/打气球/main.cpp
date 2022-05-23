#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int score = 0;
//气球个数
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
//创建炮台
struct Battery
{
	double x;
	double y;
	double cx;	//变化的坐标
	double cy;
	double rad;	//弧度
	double len;	//炮管长度
}battery;
//结构体初始化
void Ballon_init(struct Ballon* ball, double x, double y)
{
	ball->x = x;
	ball->y = y;
	ball->color = RGB(rand()%256,rand()%256,rand()%256);
	ball->vx = 0;	// 1 2 3
	ball->vy = -(5 + rand() % 10);
	ball->isdie = false;;
}
//绘制气球 
void ballon_draw(struct Ballon* ball)
{
	if (!ball->isdie)
	{
		setfillcolor(ball->color);
		setlinecolor(WHITE);
		//绘制一个椭圆
		solidellipse(ball->x, ball->y, ball->x + 30, ball->y + 60);
		//绘制一个圆弧
		arc(ball->x + 5, ball->y + 5, ball->x + 30 - 5, ball->y + 60 - 5, 0, 1.2);
		//绘制尾巴
		arc(ball->x + 0, ball->y + 60, ball->x + 30 - 10, ball->y + 60 + 20, 0, 1.2);
	}
}
//气球的随机移动
void ballon_move(Ballon* ball, double dx, double dy)
{
	ball->x += dx;
	ball->y += dy;
	//如果气球飞出边界，重新往上升
	if (ball->y + 60 <= 0)
	{
		Ballon_init(ball, rand() % getwidth(), getheight());
	}
}
//炮台初始化
void bat_init(Battery* bat,double x,double y)
{
	bat->x = x;
	bat->y = y;
	bat->len = 70;
	bat->cx = bat->x;
	bat->cy = bat->y + bat->len;
	bat->rad = 0;
}
//创建炮台
void bat_draw(Battery* bat)
{
	//绘制炮台
	//设置线条的样式
	setlinestyle(PS_SOLID, 3);
	setlinecolor(BLACK);
	circle(bat->x, bat->y, 50);
	//绘制圆心
	setfillcolor(WHITE);
	solidcircle(bat->x, bat->y, 5);
	//绘制炮管
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 5);
	line(bat->x, bat->y, bat->cx, bat->cy);
}
//获取炮管的位置
void Mouse_bat(Battery* bat, ExMessage* msg)
{
	bat->rad = atan2(bat->y - msg->y, msg->x - bat->x);	//获取角度
	bat->cx = bat->x + cos(bat->rad) * bat->len;
	bat->cy = bat->y - sin(bat->rad) * bat->len;
}

//发射子弹
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
	//绘制分数
	//格式化字符串
	char str[50] = { 0 };
	sprintf(str,"score:%d", score);
	outtextxy(0, 0, str);
}
int main(void)
{
	initgraph(480, 640,SHOWCONSOLE);
	//随机数种子 
	srand(time(0));
	setbkmode(TRANSPARENT);
	IMAGE img;
	loadimage(&img, "1.jpeg", getwidth(), getheight());
	for (int i = 0; i < 10; i++)
	{
		Ballon_init(&ball[i], rand() % getwidth(), rand() % getheight());
		ballon_draw(&ball[i]);
	}
	//炮台
	bat_init(&battery, getwidth() / 2, getheight() - 10);
	bat_draw(&battery);
	//让气球移动起来
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		//绘制背景图片
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
		
		//获取鼠标消息
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