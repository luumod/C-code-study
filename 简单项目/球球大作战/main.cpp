#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define SPACE 10	//格子的宽度
//绘制界面

//玩家，食物，AI
/*
坐标  颜色  半径  标记(isDie)
*/
//加载图片
IMAGE img[3];
int which = 0;
int A_which = 0;

enum menu
{
	operate=1,
	author,
	close,
	go,
};
//食物数量
#define FOOD_NUM 50
//AI数量
#define AI_NUM 10
//存活的AI总数量
int ALL_SUM = AI_NUM;
//结构体封装
struct Sprite
{
	double x;	//坐标
	double y;
	COLORREF color;	//颜色
	double r;	//半径
	bool isDie;	//是否存活
	char name[20];
	bool showname;

	int index_food=-1;	//专门为AI设计的追击食物的标记
}gamer, food[FOOD_NUM], AI[AI_NUM];	//玩家  食物

//AI列表
const char* AI_name[AI_NUM] = {
	"沙雕","彩笔","辣鸡","我是煞笔","鞍点",
	"徐梦瑶","卢本伟","PDD","旭旭宝宝","张良"
};
void Init();
void Game();
//加载图片音乐
void load_img()
{
	for (int i = 0; i < 3; i++)
	{
		char str[50] = { 0 };
		sprintf(str, "./images/%d.png", i + 1);
		loadimage(&img[i], str, getwidth(), getheight(), 0);
	}
	mciSendString("open ./images/jou.mp3 alias BGM", 0, 0, 0);
	mciSendString("play BGM repeat", 0, 0, 0);
}

//鼠标点击
bool Mouse_Click(ExMessage* msg,int x,int y,int width,int height)
{
	if (msg->x >= x && msg->x <= x + width && msg->y >= y && msg->y <= y + height)
	{
		return true;
	}
	return false;
	
}
//开始游戏
void start_game(ExMessage* msg)
{
	if (msg->message == WM_LBUTTONDOWN) {
		//进入游戏菜单
		//which=0代表此时为主菜单界面
		if (Mouse_Click(msg, 30, 410, 150, 100) && which == 0)
		{
			which = 1;
			A_which = operate;
		}
		else if (Mouse_Click(msg, 265, 410, 150, 100) && which == 0)
		{
			which = 1;
			A_which = author;
		}
		else if (Mouse_Click(msg, 510, 410, 150, 100) && which == 0)
		{
			A_which = close;
		}
		else if (Mouse_Click(msg, 770, 410, 150, 100) && which == 0)
		{
			A_which = go;
		}
		//两个选择返回操作
		else if (Mouse_Click(msg, 0, 0, 180, 130) && A_which == operate)
		{
			A_which = 0;
			which = 0;
		}
		else if (Mouse_Click(msg, 0, 0, 180, 130) && A_which == author)
		{
			A_which = 0;
			which = 0;
		}
		else if (Mouse_Click(msg, 0, 0, 180, 130) && A_which == 0 && which == 0)
		{
			exit(EXIT_SUCCESS);
		}
	}

	//判断绘制图片
	if (which == 0 && A_which==0)
	{
		putimage(0, 0, &img[which]);
	}
	else if (which != 0 && A_which != 0)
	{
		putimage(0, 0, &img[A_which]);
	}
	if (A_which == close)
	{
		mciSendString("close BGM", 0, 0, 0);
	}
}

//初始化Sprite结构体	name具有默认实参的功能
void sprite_init(struct Sprite* spr, double x, double y, double r, bool showname, const char* name = "Sprite")
{
	spr->x = x;
	spr->y = y;
	spr->color = RGB(rand() % 256, rand() % 256, rand() % 256);
	spr->r = r;
	spr->isDie = false;
	spr->showname = showname;
	strcpy(spr->name, name);
}

//绘制精灵
void sprite_draw(struct Sprite* spr)
{
	if (!spr->isDie)
	{
		//填充颜色
		setfillcolor(spr->color);
		//画一个圆
		solidcircle(spr->x, spr->y, spr->r);
		/*
		绘制名字
		*/
		//设置字体颜色
		if (spr->showname)
		{
			settextcolor(BLACK);
			//设置字体透明
			setbkmode(TRANSPARENT);
			//设置字体样式
			settextstyle(28, 0, "微软雅黑");
			//绘制文字
			outtextxy(spr->x - textwidth(spr->name) / 2, spr->y - textheight(spr->name) / 2, spr->name);
		}
	}
}

//移动函数
void sprite_move(struct Sprite* spr,double dx,double dy)
{
	spr->x += dx;
	spr->y += dy;
}

//获得两个圆心之间的距离
double sprite_distance(struct Sprite* spr1,struct Sprite* spr2)
{
	return sqrt(pow(spr1->x - spr2->x, 2) + pow(spr1->y - spr2->y, 2));	//两点之间的距离
}

//初始化
void Init()
{
	//重新归零
	A_which = 0;

	srand(time(0));
	//初始化玩家
	sprite_init(&gamer, 100, 100, 15,true, "于良浩");

	//初始化食物
	for (int i = 0; i < FOOD_NUM; i++)
	{
		sprite_init(&food[i], rand() % getwidth(), rand() % getheight(), 1 + rand() % 5, false);
	}
	//初始化AI
	for (int i = 0; i < AI_NUM; i++)
	{
		sprite_init(&AI[i], rand() % getwidth(), rand() % getheight(),5+rand()%15, true, AI_name[i]);
	}
}

//绘制
void Draw()
{
	cleardevice();
	//绘制背景
	setlinecolor(RGB(182, 102, 193));

	for (int i = 0; i < getheight() / 10; i++)
	{
		line(0, i*SPACE, getwidth(), i*SPACE);
	}
	for (int i = 0; i < getwidth() / 10; i++)
	{
		line(i * SPACE, 0,i*SPACE, getheight());
	}
	//绘制玩家
	sprite_draw(&gamer);
	//绘制食物
	for (int i = 0; i < FOOD_NUM; i++)
	{
		sprite_draw(&food[i]);
	}
	//绘制AI
	for (int i = 0; i < AI_NUM; i++)
	{
		sprite_draw(&AI[i]);
	}
}

//食物的再生
void foodlive()
{
	for (int i = 0; i < FOOD_NUM; i++)
	{
		//如果食物已经消失就重新产生一个
		if (food[i].isDie)
		{
			food[i].isDie = false;
			sprite_init(&food[i], rand() % getwidth(), rand() % getheight(), 1 + rand() % 5, false);
			break;
		}
	}
}

//按键处理
void KeyControl()
{
	int speed = 2;
	if (GetAsyncKeyState(VK_UP))
	{
		if (gamer.y>=0)
		{
			sprite_move(&gamer, 0, -speed);
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (gamer.y <= getheight())
		{
			sprite_move(&gamer, 0, speed);
		}
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (gamer.x >= 0)
		{
			sprite_move(&gamer, -speed, 0);
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (gamer.x <= getwidth())
		{
			sprite_move(&gamer, speed, 0);
		}
	}
}

//判断游戏互吃的关系
void GameEatFood()
{
	//玩家吃食物
	for (int i = 0; i < FOOD_NUM; i++)
	{
		if (!food[i].isDie && sprite_distance(&gamer, &food[i]) < gamer.r)
		{
			food[i].isDie = true;	//食物消失
			gamer.r += food[i].r / 8;
		}
	}
	for (int i = 0; i < AI_NUM; i++)
	{
	//玩家吃AI
		if (!gamer.isDie && !AI[i].isDie && sprite_distance(&gamer, &AI[i]) <gamer.r && gamer.r >AI[i].r)
		{
			AI[i].isDie = true;	//AI消失
			ALL_SUM--;
			gamer.r += AI[i].r / 8;
		}
	//AI吃玩家
		if (!gamer.isDie && !AI[i].isDie && sprite_distance(&gamer, &AI[i]) <AI[i].r && gamer.r < AI[i].r)
		{
			gamer.isDie = true;	//玩家死亡
			AI[i].r += gamer.r / 8;
		}
	//AI吃AI
		for (int j = 0; j < AI_NUM; j++)
		{
			if ( i!=j && !AI[i].isDie&& !AI[j].isDie && sprite_distance(&AI[i], &AI[j]) <=AI[i].r && AI[i].r > AI[j].r)
			{
				AI[j].isDie = true;	//另一个AI消失
				ALL_SUM--;
				AI[i].r += AI[j].r / 8;
			}
		}
	//AI吃食物
		for (int j = 0; j < FOOD_NUM; j++)
		{
			if (!AI[i].isDie && !food[j].isDie && sprite_distance(&AI[i], &food[j]) < AI[i].r)
			{
				food[j].isDie = true;
				AI[i].r += food[j].r / 8;
			}
		}

	}
}

//追击算法
void Chase(struct Sprite* run,struct Sprite* num)
{
	//如果追击者的x小于被追的x，则++，反之，--
	if (num->x < run->x)
	{
		num->x++;
	}
	else
	{
		num->x--;
	}
	//如果追击者的y小于被追的y，则++，反之，--
	if (num->y < run->y)
	{
		num->y++;
	}
	else
	{
		num->y--;
	}
}

//让AI动起来
void AI_move()
{
	for (int i = 0; i < AI_NUM; i++)
	{
		//遍历每一个AI,确认他们是否存活
		if (!AI[i].isDie)
		{
			//如果存在，就去追这个食物
			//要首先判断，追击的食物是否合法
			if (AI[i].index_food!=-1 && !food[AI[i].index_food].isDie)
			{
				//AI追食物
				Chase(&food[AI[i].index_food], &AI[i]);
			}
			//如果不存在，就重新找一个
			else
			{
				AI[i].index_food = rand() % FOOD_NUM;
			}
		}
	}
}

//判断游戏结束
void GameOver()
{
	if (gamer.isDie)
	{
		ALL_SUM = AI_NUM;
		//玩家死亡
		int ret=MessageBox(NULL, "你死了,要重新开始吗", "提示",MB_SYSTEMMODAL | MB_YESNO);
		if (ret == IDYES)
		{
			//重新开始
			Init();
		}
		else if (ret == IDNO)
		{
			Game();
		}
	}
	//最后AI全部死亡，玩家获胜
	if (!ALL_SUM) {
		ALL_SUM = AI_NUM;	//在这个地方归零， 即重新初始化游戏敌人数量
		int ret = MessageBox(NULL, "恭喜你获胜了", "提示", MB_SYSTEMMODAL | MB_YESNO);
		if (ret == IDYES)
		{
			//返回菜单
			Game();
		}
		else if (ret == IDNO)
		{
			Game();
		}
	}
}

//游戏完整循环
void Game()
{
	while (A_which != go)
	{
		//双缓冲绘图
		ExMessage msg;
		while (peekmessage(&msg, EM_MOUSE))
		{
			start_game(&msg);
		}
	}

	Init();
	setbkcolor(WHITE);
	cleardevice();
	//开始游戏
	while (1)
	{
		BeginBatchDraw();
		Draw();
		EndBatchDraw();

		foodlive();
		KeyControl();
		GameEatFood();
		AI_move();
		GameOver();
	}
}

int main(void)
{
	initgraph(1024, 640);

	load_img();
	//菜单环节
	Game();

	system("pause");
	return 0;
}