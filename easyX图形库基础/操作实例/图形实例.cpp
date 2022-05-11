#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <math.h>
//int main(void) {
//	/*
//	一个圆的滚动
//	*/
//	initgraph(800, 648);
//	setbkcolor(WHITE);
//	cleardevice();
//
//	setfillcolor(RED);	//填充颜色
//	setfillstyle(BS_SOLID);	//填充样式
//	BeginBatchDraw();	//批量绘图
//	for (int i = 50; i <= 800; i++) {
//		fillcircle(i, 200, 50);
//		FlushBatchDraw();	//执行绘制任务
//		Sleep(10);
//	}
//	EndBatchDraw();	//结束批量绘制
//	system("pause");
//	return 0;
//}


//
//int main(void) {
//	/*
//	弹跳球模拟
//	*/
//	double h = 500;	//原始高度
//	double v = 0;	//初速度为零
//	double dv = 9.8 / 50;	//加速度 1/50秒
//	initgraph(600, 500);
//	setbkcolor(WHITE);
//	cleardevice();
//	//地平线
//	setlinecolor(GREEN);
//	setlinestyle(PS_SOLID, 3);
//	line(50, 450, 450, 450);
//	while (!_kbhit()) {
//		v += dv;				// 根据加速度计算速度
//		h -= (v - dv / 2);		// 计算高度
//		// 如果高度低于地平线，实现反弹，速度方向取反
//		if (h <= 0)
//		{
//			h += (v - dv / 2);
//			v = -v * 0.9;		// 反弹时能量损耗 10%
//		}
//		//画球
//		BeginBatchDraw();
//		setfillcolor(GREEN);
//		fillcircle(250, 400-(int)h, 30);
//		Sleep(20);
//		FlushBatchDraw();	//批绘图，消除闪烁
//		cleardevice();	//使用当前背景色清空绘图设备
//	}
//	EndBatchDraw();
//	return 0;
//}




//int main(void) {
//	initgraph(800, 648);
//	int c, a, b;
//	//渐变颜色
//	srand(time(0));
//	a = rand() % 256;
//	b = rand() % 256;
//	for (int i = 0; i < 648; i++) {
//		c = i * 255 / 648;
//		setcolor(RGB(a,b, c));
//		line(0, i, 799, i);
//		//cleardevice();
//	}
//
//	system("pause");
//	return 0;
//}

//#define PI 3.14
//int main(void) {
//	//渐变的圆形
//	initgraph(700, 648);
//	int c;
//	int x, y, r=200;	//园的坐标位置
//	for (double i=0; i <PI*2; i+=0.0001) {
//		x = (int)(r * cos(i) + 350 + 0.5);
//		y = (int)(r * sin(i) + 324 + 0.5);
//		c = (int)(i * 255 / (2 * PI) + 0.5);
//		setcolor(RGB(0, 255, c));
//		line(350, 324, x, y);
//	}
//
//	system("pause");
//	return 0;
//}



//int main(void) {
//	/*
//	围棋棋盘 19*19
//	*/
//	int spa = 30;	//每条线的间隔	19*30=570<600
//	initgraph(600, 600);
//	setbkcolor(YELLOW);
//	cleardevice();
//	int a, b;
//
//	setlinecolor(BLACK);
//	for (int i = 1; i <= 19; i++) {
//		line(1 * spa, i * spa, 19 * spa, i * spa);	//行
//		line(i * spa, 1 * spa, i * spa, 19 * spa);	//列
//	}
//	system("pause");
//	return 0;
//}




//int main(void) {
//	/*
//	国际象棋
//	*/
//	int spa = 50; //矩形长度
//	initgraph(600, 600);
//	setbkcolor(YELLOW);
//	cleardevice();
//
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 8; j++) {
//			if ((i+j) % 2 == 1) {
//				//黑色
//				setfillcolor(BLACK);
//				solidrectangle(i * spa, j * spa, (i + 1) * spa, (j + 1) * spa);
//			}
//			else {
//				//白色
//				setfillcolor(WHITE);
//				solidrectangle(i * spa, j * spa, (i + 1) * spa, (j + 1) * spa);
//			}
//		}
//	}
//
//	system("pause");
//	return 0;
//}


int main(void) {
	int temp = 30;
	initgraph(600, 600);
	setbkcolor(RGB(209, 154, 102));
	cleardevice();

	setlinecolor(BLACK);
	for (int i = 1; i <= 19; i++) {
		line(temp,i*temp,19*temp,i*temp); //行
		line(i*temp,temp,i*temp,19*temp);	//列
	}

	//绘制一颗黑棋棋子
	setfillcolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	fillcircle(300, 300, 15);
	//绘制一颗白棋
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	fillcircle(300, 270, 15);
	system("pause");
	return 0;
}