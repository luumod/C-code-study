#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>

//加载图片结构体
struct Image
{
	IMAGE bk_img[4];
	IMAGE game_img[5];
	IMAGE game_start[2];
}IMG;

//图片张数
int which = 0;
int A_which = 0;
int B_which = 0;
//跳转的位置
enum menu
{
	About=1,
	Operate,
	Start,
	Author,
	Descirption
};
//点击按钮
bool button_click(ExMessage* msg,int x,int y,int width,int height) {
	//进行点击检测
	if (msg->x >= x && msg->x <= x + width && msg->y >= y && msg->y <= y + height) {
		return true;
	}
	return false;
}
//加载图片
void img_init(struct Image* res)
{
	//有四张图片
	for (int i = 0; i < 4; i++)
	{
		char str[50] = "";
		sprintf(str, "./images/%d.png", i);
		loadimage(&res->bk_img[i], str, getwidth(), getheight());
	}
	//进入菜单
	for (int i = 4; i < 9; i++)
	{
		char str[50] = "";
		sprintf(str, "./images/%d.png", i);	// 0 1 2 3 4
		loadimage(&res->game_img[i-4], str, getwidth(), getheight());
	}
	//进入游戏
	loadimage(&res->game_start[0], "./images/9.png");
}
void start_game(ExMessage* m,struct Image* res) {
	//如果鼠标左键点击，切换
	if (m->message == WM_LBUTTONDOWN) {
		if (which < 3)
		{
			which++;		// 0 1 2 3 
		}
		//whitch为3 说明到了游戏菜单的界面，选择操作  
		//关于  操作  开始  作者  说明
		/*
		About,
		Operate,
		Start,
		Author,
		Descirption
		*/
		if (button_click(m,73,343 ,175,115) && A_which==0) 
		{
			//关于	// 4
			A_which = About;
		}
		else if (button_click(m,365,344,175,115) && A_which == 0)
		{	//操作 5
			A_which = Operate;
		}
		else if (button_click(m,599,344,175,115) && A_which == 0)
		{	//开始 6
			//进入关卡
			A_which = Start;
		}
		else if (button_click(m,870,344,175,115) && A_which == 0)
		{		//作者 7
			A_which = Author;
		}
		else if (button_click(m,1137,345,175,115) && A_which == 0)
		{		//说明 8
			A_which = Descirption;
		}
		//菜单各选项退出操作
		else if (which == 3 && A_which != 0 && B_which==0 && button_click(m,0,0,160,120)) 
		{
			A_which = 0;
		}
		//进入第一关
		else if (A_which == Start && button_click(m,230,306,160,160))
		{
			B_which = 1;
		}
		//进入第二关
		else if (A_which == Start && button_click(m, 513,305, 160, 160))
		{
			B_which = 1;
		}
		//进入第三关
		else if (A_which == Start && button_click(m, 836,321, 160, 160))
		{
			B_which = 1;
		}
		//在某一关返回
		else if (B_which == 1 && button_click(m, 0, 0, 160, 120))
		{
			//第一关，退出
			B_which = 0;
		}
	}

	//切换图片
	if (which < 4 && A_which==0) 
	{
		//游戏开始前切换
		putimage(0, 0, &res->bk_img[which]);
	}
	else if (which==3 && A_which!=0 && B_which==0) 
	{
		//菜单各选项的切换
		putimage(0, 0, &res->game_img[A_which-1]);
	}
	//进入某一关
	else if (A_which == Start && B_which == 1)
	{
		putimage(0, 0, &res->game_start[0]);
	}
}


int main(void) {
	initgraph(1389, 645);
	img_init(&IMG);
	//加载第一张
	putimage(0, 0, &IMG.bk_img[0]);
	//当我有鼠标信息时，切换图片
	ExMessage msg;
	while (1) {
		while (peekmessage(&msg, EM_MOUSE)) {
			start_game(&msg, &IMG);
		}
	}
	system("pause");
	return 0;
}




//封装按钮
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
////按钮的初始化
//struct Button* button_init(int x, int y, int width, int height, COLORREF color, const char* pstr)
//{
//	//封装按钮属性
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
////按钮的绘制
//void button_draw(struct Button* pb)
//{
//	setfillcolor(pb->color);
//	fillroundrect(pb->x, pb->y, pb->x + pb->width, pb->y + pb->height, 50, 50);
//	settextcolor(BLACK);
//	setbkmode(TRANSPARENT);
//	settextstyle(80, 0, "微软雅黑");
//	outtextxy(pb->x + pb->width / 2, pb->y + pb->height / 2, pb->str);
//}
////按钮的点击
//void button_click(struct Button* pb)
//{
//
//}
//struct Button* pb1 = button_init(74, 335, 200, 140, YELLOW, "作者");
//struct Button* pb2 = button_init(370, 330, 200, 140, YELLOW, "关于");
//struct Button* pb3 = button_init(601, 340, 200, 140, YELLOW, "开始");
//struct Button* pb4 = button_init(876, 340, 200, 140, YELLOW, "说明");
//struct Button* pb5 = button_init(1140, 430, 200, 140, YELLOW, "操作");