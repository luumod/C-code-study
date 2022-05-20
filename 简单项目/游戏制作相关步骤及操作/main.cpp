#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>

//����ͼƬ�ṹ��
struct Image
{
	IMAGE bk_img[4];
	IMAGE game_img[5];
	IMAGE game_start[2];
}IMG;

//ͼƬ����
int which = 0;
int A_which = 0;
int B_which = 0;
//��ת��λ��
enum menu
{
	About=1,
	Operate,
	Start,
	Author,
	Descirption
};
//�����ť
bool button_click(ExMessage* msg,int x,int y,int width,int height) {
	//���е�����
	if (msg->x >= x && msg->x <= x + width && msg->y >= y && msg->y <= y + height) {
		return true;
	}
	return false;
}
//����ͼƬ
void img_init(struct Image* res)
{
	//������ͼƬ
	for (int i = 0; i < 4; i++)
	{
		char str[50] = "";
		sprintf(str, "./images/%d.png", i);
		loadimage(&res->bk_img[i], str, getwidth(), getheight());
	}
	//����˵�
	for (int i = 4; i < 9; i++)
	{
		char str[50] = "";
		sprintf(str, "./images/%d.png", i);	// 0 1 2 3 4
		loadimage(&res->game_img[i-4], str, getwidth(), getheight());
	}
	//������Ϸ
	loadimage(&res->game_start[0], "./images/9.png");
}
void start_game(ExMessage* m,struct Image* res) {
	//���������������л�
	if (m->message == WM_LBUTTONDOWN) {
		if (which < 3)
		{
			which++;		// 0 1 2 3 
		}
		//whitchΪ3 ˵��������Ϸ�˵��Ľ��棬ѡ�����  
		//����  ����  ��ʼ  ����  ˵��
		/*
		About,
		Operate,
		Start,
		Author,
		Descirption
		*/
		if (button_click(m,73,343 ,175,115) && A_which==0) 
		{
			//����	// 4
			A_which = About;
		}
		else if (button_click(m,365,344,175,115) && A_which == 0)
		{	//���� 5
			A_which = Operate;
		}
		else if (button_click(m,599,344,175,115) && A_which == 0)
		{	//��ʼ 6
			//����ؿ�
			A_which = Start;
		}
		else if (button_click(m,870,344,175,115) && A_which == 0)
		{		//���� 7
			A_which = Author;
		}
		else if (button_click(m,1137,345,175,115) && A_which == 0)
		{		//˵�� 8
			A_which = Descirption;
		}
		//�˵���ѡ���˳�����
		else if (which == 3 && A_which != 0 && B_which==0 && button_click(m,0,0,160,120)) 
		{
			A_which = 0;
		}
		//�����һ��
		else if (A_which == Start && button_click(m,230,306,160,160))
		{
			B_which = 1;
		}
		//����ڶ���
		else if (A_which == Start && button_click(m, 513,305, 160, 160))
		{
			B_which = 1;
		}
		//���������
		else if (A_which == Start && button_click(m, 836,321, 160, 160))
		{
			B_which = 1;
		}
		//��ĳһ�ط���
		else if (B_which == 1 && button_click(m, 0, 0, 160, 120))
		{
			//��һ�أ��˳�
			B_which = 0;
		}
	}

	//�л�ͼƬ
	if (which < 4 && A_which==0) 
	{
		//��Ϸ��ʼǰ�л�
		putimage(0, 0, &res->bk_img[which]);
	}
	else if (which==3 && A_which!=0 && B_which==0) 
	{
		//�˵���ѡ����л�
		putimage(0, 0, &res->game_img[A_which-1]);
	}
	//����ĳһ��
	else if (A_which == Start && B_which == 1)
	{
		putimage(0, 0, &res->game_start[0]);
	}
}


int main(void) {
	initgraph(1389, 645);
	img_init(&IMG);
	//���ص�һ��
	putimage(0, 0, &IMG.bk_img[0]);
	//�����������Ϣʱ���л�ͼƬ
	ExMessage msg;
	while (1) {
		while (peekmessage(&msg, EM_MOUSE)) {
			start_game(&msg, &IMG);
		}
	}
	system("pause");
	return 0;
}




//��װ��ť
//struct Button
//{
//	int x;
//	int y;
//	int width;
//	int height;
//	COLORREF color;
//	char* str;
//}button;
//
////��ť�ĳ�ʼ��
//struct Button* button_init(int x, int y, int width, int height, COLORREF color, const char* pstr)
//{
//	//��װ��ť����
//	struct Button* pb = (struct Button*)malloc(sizeof(struct Button));
//	pb->x = x;
//	pb->y = y;
//	pb->width = width;
//	pb->height = height;
//	pb->color = color;
//	pb->str = (char*)malloc(sizeof(pstr) + 1);
//	strcpy(pb->str, pstr);
//	return pb;
//}
////��ť�Ļ���
//void button_draw(struct Button* pb)
//{
//	setfillcolor(pb->color);
//	fillroundrect(pb->x, pb->y, pb->x + pb->width, pb->y + pb->height, 50, 50);
//	settextcolor(BLACK);
//	setbkmode(TRANSPARENT);
//	settextstyle(80, 0, "΢���ź�");
//	outtextxy(pb->x + pb->width / 2, pb->y + pb->height / 2, pb->str);
//}
////��ť�ĵ��
//void button_click(struct Button* pb)
//{
//
//}
//struct Button* pb1 = button_init(74, 335, 200, 140, YELLOW, "����");
//struct Button* pb2 = button_init(370, 330, 200, 140, YELLOW, "����");
//struct Button* pb3 = button_init(601, 340, 200, 140, YELLOW, "��ʼ");
//struct Button* pb4 = button_init(876, 340, 200, 140, YELLOW, "˵��");
//struct Button* pb5 = button_init(1140, 430, 200, 140, YELLOW, "����");