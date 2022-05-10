#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <math.h>

//#define PI 3.14159265359
//int main()
//{
//	// 创建绘图窗口
//	initgraph(640, 480);
//
//	// 定义数组，保存五角星的五个顶点坐标
//	POINT pts[5];
//	char s[] = "你的分数是:";
//	// 计算五角星的五个顶点坐标
//	double a = PI / 2;
//	for (int i = 0; i < 5; i++)
//	{
//		pts[i].x = int(320 + cos(a) * 100);
//		pts[i].y = int(240 - sin(a) * 100);
//		a += PI * 4 / 5;
//	}
//	outtextxy(400, 100, s);
//	// 设置填充模式为 WINDING
//	setpolyfillmode(WINDING);
//	// 设置填充颜色为红色
//	setfillcolor(RED);
//	// 绘制五角星(无边框)
//	solidpolygon(pts, 5);
//
//	// 按任意键退出
//	_getch();
//	closegraph();
//}


//int main(void) {
//	//initgraph(640, 480, EW_SHOWCONSOLE | EW_NOCLOSE);
//	////设置背景色为黄色
//	//setbkcolor(YELLOW);
//	////背景色清空屏幕
//	//cleardevice();
//
//	////设置绘图色为绿色
//	//setcolor(GREEN);
//	////画矩形
//	//rectangle(100, 200, 300, 400);
//	//setbkmode(TRANSPARENT);
//	//
//	////设置当前设备填充颜色
//	//setfillcolor(BLUE);
//	//solidrectangle(50,100,150,200);
//
//	//setfillcolor(RED);
//	//solidrectangle(200, 250, 300, 350);
//
//	////画一个三角形
//	//POINT pa[] = {{30,330},{130,70},{50,00}};
//	//solidpolygon(pa, 3);
//
//	initgraph(650, 650);
//
//	setbkcolor(RGB(49, 50, 64));
//	cleardevice();
//	//画线的类型 图形的填充颜色 线的颜色 
//	/*
//	三步走 : 线的类型 线的颜色 图形填充颜色
//	*/
//	setlinestyle(PS_SOLID, 3);
//	setfillcolor(BLUE);	//填充颜色蓝色
//	setlinecolor(RED);	//线的颜色
//	//绘制图形
//	circle(100, 100, 50);
//	fillcircle(100, 200, 50);
//	solidcircle(100, 300, 50);
//
//
//	//重新绘制一个矩形
//	setfillcolor(RGB(0, 130, 114));
//	setlinecolor(RGB(244, 92, 102));
//	rectangle(200, 50, 400, 150);
//	fillrectangle(200, 160, 400, 260);
//	solidrectangle(200, 270, 400, 370);
//
//	char c[10];
//	int a = 5;
//	sprintf(c, "%d", a);	//整形转换为字符串型，在输入
//	settextcolor(YELLOW);
//	outtextxy(400, 580, c);
//	rectangle(500, 570, 400, 600);
//
//	system("pause");
//	return 0;
//}
//
//int main(void) {
//	initgraph(640, 480);
//
//	setbkcolor(WHITE);
//	cleardevice();
//
//	setfillcolor(GREEN);
//	setlinecolor(BLUE);
//	
//	roundrect(200, 50, 400, 150, 50, 50);
//	fillroundrect(200, 160, 400, 260, 50, 50);
//
//	system("pause");
//	closegraph();
//	return 0;
//}



//int main(void) {
//	//创建窗口
//	initgraph(1000, 1000);
//	//填充背景颜色
//	setbkcolor(YELLOW);
//	cleardevice();
//
//	//画图前三步走:
//	setfillcolor(RED);
//	setlinecolor(BLUE);
//	setlinestyle(PS_SOLID, 3);
//
//	//画图
//	circle(500, 100, 50);
//	fillcircle(500, 250, 100);	//填充颜色的圆形
//	solidcircle(500, 550, 200);	//无边框的图形
//
//
//	system("pause");
//	return 0;
//}


//可爱的矩形
//
//int main(void) {
//	//一个粉色的圆角矩形
//	initgraph(700, 600);
//
//	setbkcolor(WHITE);
//	cleardevice();
//	//设置图形
//	setlinecolor(BLACK);	//线条颜色
//	setfillcolor(RGB(255, 210, 223));	//填充颜色
//	fillroundrect(200, 150, 500, 300, 50, 50);	//填充圆角矩形
//	//设置字体
//	settextstyle(25, 0, "楷体");	//字体高度宽度字体
//	setbkmode(TRANSPARENT);		//字体背景透明
//	settextcolor(BLUE);			//字体颜色
//
//	char s[] = "我是你爸爸~~";	//把字符串放在中间
//	int x = (300 - textwidth(s)) / 2;	
//	int y = (150 - textheight(s)) / 2;
//	
//	outtextxy(200 + x, 150 + y, s);
//
//	system("pause");
//	return 0;
//}



//鼠标操作:
//void button(int left,int top,int right,int bottom,const char* str) {
//	//设计一个按钮
//	setfillcolor(GREEN);	//填充颜色
//	setlinecolor(RED);		//填充线条颜色
//	//创建一个按钮图形
//	fillroundrect(left, top, right, bottom, 50, 50);
//
//	//创建文本
//	settextcolor(BLUE);
//	setbkmode(TRANSPARENT);
//	settextstyle(25, 0, "楷体");
//	char str1[50] = { 0 };
//	strcpy(str1, str);
//	int x = ((right-left) - textwidth(str1)) / 2;
//	int y = ((bottom-top) - textheight(str1)) / 2;
//	//填充按钮
//	outtextxy(left+ x, top + y, str);
//}
//int main(void) {
//	initgraph(700, 700, EW_SHOWCONSOLE);
//	//背景颜色
//	setbkcolor(WHITE);
//	cleardevice();
//	button(200, 250, 400, 500, "我是个按钮..");
//
//	ExMessage msg;
//	while (1) {
//		if (peekmessage(&msg, EM_MOUSE)) {
//			//有鼠标消息返回真,没有返回假
//			switch (msg.message) {
//			case WM_LBUTTONDOWN:
//				//判断在按钮范围内
//				if (msg.x >= 200 && msg.x <= 400 && msg.y >= 250 && msg.y <= 500) {
//					printf("哈哈，被左键点击了!\n");
//				}
//				break;
//			case WM_RBUTTONDOWN:
//				if (msg.x >= 200 && msg.x <= 400 && msg.y >= 250 && msg.y <= 500) {
//					printf("哈哈，被右键点击了!\n");
//				}
//				break;
//			default:
//				break;
//			}
//		}
//	}
//	system("pause");
//	closegraph();
//	return 0;
//}





//键盘移动
//int main(void) {
//	initgraph(800, 800);
//	int x = 50, y = 50;
//	//监听键盘操作
//	while (1) {
//		//背景区，双缓冲绘图
//		BeginBatchDraw();
//		setbkcolor(BLACK);
//		cleardevice();
//		//创建一个小球
//		setfillcolor(GREEN);
//		fillcircle(x, y, 50);
//		FlushBatchDraw();
//
//		if (_kbhit()) {
//			switch (_getch()) {
//			case 'w':
//			case 'W':
//			case 72:
//				y -= 20;
//				break;
//			case 'a':
//			case 'A':
//			case 75:
//				x -= 20;
//				break;
//			case 's':
//			case 'S':
//			case 80:
//				y += 20;
//				break;
//			case 'd':
//			case 'D':
//			case 77:
//				x += 20;
//				break;
//			}
//		}
//	}
//
//	system("pause");
//	return 0;
//}


// 瞎搞!!!!!!!!!!!!!!!!!!
//int main(void) {
//	//I LOVE U
//	initgraph(1500, 600);
//	//填充背景
//	setbkcolor(GREEN);
//	cleardevice();
//	//设置填充颜色
//	setfillcolor(RED);
//	setlinecolor(RED);
//	setlinestyle(PS_SOLID, 16);
//
//	line(50, 50, 200, 80);
//	solidrectangle(120, 80, 135, 480);
//	line(50, 480, 200, 510);
//
//	solidrectangle(300,50,320,510);
//	solidrectangle(300,490, 450,510);
//
//	ellipse(460, 50, 610, 510);
//	
//	line(670, 50, 750, 510);
//	line(750, 510, 830, 50);
//
//	line(890, 50, 890, 510);
//	line(890, 50, 1070, 50);
//	line(890, 280, 1070, 280);
//	line(890, 510, 1070, 510);
//
//	roundrect(1180, 50, 1400,510,100, 100);
//
//	setfillcolor(GREEN);
//	solidrectangle(1160, 40, 1430, 100);
//
//	line(1180, 65, 1180, 100);
//	line(1400, 65, 1400, 100);
//	system("pause");
//	return 0;
//}