#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <math.h>
//int main(void) {
//	/*
//	һ��Բ�Ĺ���
//	*/
//	initgraph(800, 648);
//	setbkcolor(WHITE);
//	cleardevice();
//
//	setfillcolor(RED);	//�����ɫ
//	setfillstyle(BS_SOLID);	//�����ʽ
//	BeginBatchDraw();	//������ͼ
//	for (int i = 50; i <= 800; i++) {
//		fillcircle(i, 200, 50);
//		FlushBatchDraw();	//ִ�л�������
//		Sleep(10);
//	}
//	EndBatchDraw();	//������������
//	system("pause");
//	return 0;
//}


//
//int main(void) {
//	/*
//	������ģ��
//	*/
//	double h = 500;	//ԭʼ�߶�
//	double v = 0;	//���ٶ�Ϊ��
//	double dv = 9.8 / 50;	//���ٶ� 1/50��
//	initgraph(600, 500);
//	setbkcolor(WHITE);
//	cleardevice();
//	//��ƽ��
//	setlinecolor(GREEN);
//	setlinestyle(PS_SOLID, 3);
//	line(50, 450, 450, 450);
//	while (!_kbhit()) {
//		v += dv;				// ���ݼ��ٶȼ����ٶ�
//		h -= (v - dv / 2);		// ����߶�
//		// ����߶ȵ��ڵ�ƽ�ߣ�ʵ�ַ������ٶȷ���ȡ��
//		if (h <= 0)
//		{
//			h += (v - dv / 2);
//			v = -v * 0.9;		// ����ʱ������� 10%
//		}
//		//����
//		BeginBatchDraw();
//		setfillcolor(GREEN);
//		fillcircle(250, 400-(int)h, 30);
//		Sleep(20);
//		FlushBatchDraw();	//����ͼ��������˸
//		cleardevice();	//ʹ�õ�ǰ����ɫ��ջ�ͼ�豸
//	}
//	EndBatchDraw();
//	return 0;
//}




//int main(void) {
//	initgraph(800, 648);
//	int c, a, b;
//	//������ɫ
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
//	//�����Բ��
//	initgraph(700, 648);
//	int c;
//	int x, y, r=200;	//԰������λ��
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
//	Χ������ 19*19
//	*/
//	int spa = 30;	//ÿ���ߵļ��	19*30=570<600
//	initgraph(600, 600);
//	setbkcolor(YELLOW);
//	cleardevice();
//	int a, b;
//
//	setlinecolor(BLACK);
//	for (int i = 1; i <= 19; i++) {
//		line(1 * spa, i * spa, 19 * spa, i * spa);	//��
//		line(i * spa, 1 * spa, i * spa, 19 * spa);	//��
//	}
//	system("pause");
//	return 0;
//}




//int main(void) {
//	/*
//	��������
//	*/
//	int spa = 50; //���γ���
//	initgraph(600, 600);
//	setbkcolor(YELLOW);
//	cleardevice();
//
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 8; j++) {
//			if ((i+j) % 2 == 1) {
//				//��ɫ
//				setfillcolor(BLACK);
//				solidrectangle(i * spa, j * spa, (i + 1) * spa, (j + 1) * spa);
//			}
//			else {
//				//��ɫ
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
		line(temp,i*temp,19*temp,i*temp); //��
		line(i*temp,temp,i*temp,19*temp);	//��
	}

	//����һ�ź�������
	setfillcolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	fillcircle(300, 300, 15);
	//����һ�Ű���
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	fillcircle(300, 270, 15);
	system("pause");
	return 0;
}