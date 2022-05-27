//#include <stdio.h>
//#include <graphics.h>
//#include <time.h>
//#include <stdlib.h>
//IMAGE hero[2], bullet[2];
//
//struct Plane
//{
//	int x, y;
//}plane={300,300};
//
////创建子弹结构体
//typedef struct Bullet
//{
//	double x, y;
//	double vx, vy;
//	bool isdie;
//	struct Bullet* next;
//}Node;	//别名
//
////创建一个链表
//Node* Bullet_List = NULL;
//
//void create_listR(Node** head, Node* bullet);
//Node* create_bullet(double vx, double vy);
//void Draw_bullet();
////计时器
//bool Timer(time_t ms, int id) {
//	static DWORD t[10];		//10个计时器
//	if (clock() - t[id] > ms) {
//		t[id] = clock();
//		return true;
//	}
//	return false;
//}
//
////绘制
//void draw()
//{
//	putimage(plane.x,plane.y, &hero[1], SRCPAINT);
//	putimage(plane.x, plane.y , &hero[0], SRCAND);
//
//	Draw_bullet();
//}
//
////飞机移动
//void playerMove()
//{
//	//获取异步按键状态
//	if (GetAsyncKeyState(VK_UP) && plane.y > 0)
//	{
//		plane.y -= 1;
//	}
//	if (GetAsyncKeyState(VK_DOWN) && plane.y + 50 < getheight())
//	{
//		plane.y += 1;
//	}
//	if (GetAsyncKeyState(VK_LEFT) && plane.x + 50 / 2 > 0)
//	{
//		plane.x -= 1;
//	}
//	if (GetAsyncKeyState(VK_RIGHT) && plane.x + 50 / 2 < getwidth())
//	{
//		plane.x += 1;
//	}
//	if (GetAsyncKeyState(VK_SPACE) && Timer(10,0))
//	{
//		//函数的返回节点直接插入到链表中
//		create_listR(&Bullet_List, create_bullet(0, -20));
//		create_listR(&Bullet_List, create_bullet(-8, -17.32));
//		create_listR(&Bullet_List, create_bullet(8, -17.32));
//	}
//}
//
////图片绘制
//void Draw(int x,int y)
//{
//	putimage(x,y, &bullet[1], SRCPAINT);
//	putimage(x,y, &bullet[0], SRCAND);
//}
////发射子弹
///*
//利用链表
//*/
//
////首先创建子弹
//Node* create_bullet(double vx,double vy)
//{
//	//为子弹分配空间
//	Node* head = (Node*)malloc(sizeof(Node));	
//	//子弹的起始位置
//	head->x = plane.x+25;
//	head->y = plane.y-35;
//	//子弹的偏移
//	head->vx = vx;
//	head->vy = vy;
//	head->isdie = false;
//	head->next = NULL;
//	//返回子弹节点
//	return head;
//}
//
////然后将子弹尾插，形成一串链表，直接在函数里修改，没有返回值
//void create_listR(Node** head,Node* bullet)
//{
//	Node* p = *head;
//	/*
//	二级指针，是一个指向的 一个链表的地址，即链表头节点 的指针
//	使用 *head 获得头节点
//	*/
//	//如果头节点是空，则直接插入，退出
//	if (*head == NULL)
//	{
//		*head = bullet;
//		return;
//	}
//	//遍历到链表的末尾，尾插节点
//	while (p->next)
//	{
//		p = p->next;
//	}
//	//插入节点
//	p->next = bullet;
//	p = bullet;
//	p->next = NULL;
//	//直接在函数内修改，无需返回值
//}
//
////子弹的xy偏移
//void Bullet_xymove(Node** head)
//{
//	Node* p = *head;	//存储第一个节点
//	//链表为空，直接返回
//	if (*head == NULL)
//	{
//		return;
//	}
//	//遍历整个链表
//	while (p)
//	{
//		p->x += p->vx;
//		p->y += p->vy;
//		//判断子弹是否离开视野
//		if (p->x <= 0 || p->x >= getwidth() || p->y <= 0 || p->y >= getheight())
//		{
//			p->isdie = true;	//标记子弹
//		}
//		p = p->next;
//	}
//	//printf("子弹偏移\n");
//}
//
////子弹的删除
//void Remove_bullet(Node** head)
//{
//	Node* cur = *head, * pre = NULL;	//一个节点记录上一个节点位置
//	if (*head == NULL)
//	{
//		return;
//	}
//	//遍历链表,找出节点为true的子弹，说明其已经消失，删除它
//	while (cur)
//	{
//		if (cur->isdie)
//		{
//			if (cur==*head)
//			{
//				//第一个节点被删除
//				*head = cur->next;	//改变链表的头节点，让下一个节点作为头节点
//				free(cur);
//				cur = *head;
//			}
//			else
//			{
//				//删除其他的节点
//				pre->next=cur->next;	//跳过节点，实现删除
//				free(cur);				//释放空间
//				cur = pre;				//返回上一个节点
//			}
//		}
//		else
//		{
//			pre = cur;			//存储上一个节点的位置
//			cur = cur->next;	//移动到下一个节点
//		}
//	}
//	//printf("删除子弹\n");
//}
//
////绘制子弹
//void Draw_bullet()
//{
//	Bullet_xymove(&Bullet_List);	//计算子弹的偏移
//	Remove_bullet(&Bullet_List);	//删除越界的子弹
//	for (Node* p = Bullet_List; p != NULL; p = p->next)
//	{
//		//子弹的绘制
//		Draw(p->x, p->y);
//	}
//}
//int main(void)
//{
//	initgraph(800, 680, SHOWCONSOLE);
//	setbkcolor(YELLOW);
//	cleardevice();
//	//加载
//	loadimage(&hero[0], "./images/plane1.png");
//	loadimage(&hero[1], "./images/Yplane1.png");
//	loadimage(&bullet[0], "./images/biu1.png");
//	loadimage(&bullet[1], "./images/Ybiu1.png");
//
//	while (1)
//	{
//
//		BeginBatchDraw();
//		cleardevice();
//		draw();
//		EndBatchDraw();
//
//		playerMove();
//	}
//	system("pause");
//	return 0;
//}




































#include <stdio.h>
//#include <easyx.h>	//安装，必须是.cpp文件
#include <time.h>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//窗口宽高
#define INIT_WIDTH 520 
#define INIT_HEIGHT 800

//敌人一次性出现的数量
#define ENEMY_NUM 10

//敌人种类
enum enemy
{
	Small,
	Middle,
	Big
};
//分数
int score = 0;

IMAGE img_bk;
IMAGE img_player[2];
IMAGE img_bullet[2];
IMAGE img_enemy1[2], img_enemy2[2], img_enemy3[2];
IMAGE img_enemy_bullet[2];
IMAGE boom_img[6], Yboom_img[6];

//计时器
bool Timer(time_t ms, int id) {
	static DWORD t[10];		//10个计时器
	if (clock() - t[id] > ms) {
		t[id] = clock();
		return true;
	}
	return false;
}
//加载图片
void loadRes()
{
	// “loadimage”: 2 个重载中没有一个可以转换所有参数类型
	loadimage(&img_bk, ".\\images\\bg5.jpg");
	//我方
	loadimage(img_player + 0, ".\\images\\plane1.png");
	loadimage(img_player + 1, ".\\images\\Yplane1.png");
	//子弹
	loadimage(img_bullet + 0, ".\\images\\biu1.png");
	loadimage(img_bullet + 1, ".\\images\\Ybiu1.png");
	loadimage(img_enemy_bullet + 0, ".\\images\\enemy_bullet2.png");
	loadimage(img_enemy_bullet + 1, ".\\images\\Yenemy_bullet2.png");
	//敌人
	loadimage(img_enemy1 + 0, ".\\images\\enemy1.png");
	loadimage(img_enemy1 + 1, ".\\images\\Yenemy1.png");
	loadimage(img_enemy2 + 0, ".\\images\\enemy2.png");
	loadimage(img_enemy2 + 1, ".\\images\\Yenemy2.png");
	loadimage(img_enemy3 + 0, ".\\images\\enemy3.png");
	loadimage(img_enemy3 + 1, ".\\images\\Yenemy3.png");
	//爆炸
	for (int i = 0; i < 6; i++)
	{
		char str1[50] = { 0 };
		char str2[50] = { 0 };
		sprintf(str1, ".\\images\\boom%d.png", i + 1);	//原图
		sprintf(str2, ".\\images\\Yboom%d.png", i + 1);	//掩码图
		loadimage(&boom_img[i], str1, 93, 75);
		loadimage(&Yboom_img[i], str2, 93, 75);
	}
}

//飞机：坐标(x,y) 尺寸(w,h)
struct plane
{
	double x;	//坐标
	double y;
	int w;	//尺寸
	int h;
	IMAGE* img;
	int type;
	int HP;		//飞机血量
	bool isDie; //是否死亡
}player,enemy[ENEMY_NUM];

//爆炸结构体
struct Boom
{
	int frame;	//爆炸的帧数
	int x, y;
}boom[5];	//可以同时存储5个飞机爆炸

//子弹发射结构体
typedef struct Bullet
{
	int x;
	int y;
	double vx;	//水平方向速度偏移
	double vy;	//垂直方向速度偏移
	IMAGE* img;	//子弹图形
	bool isdie;	//子弹存活状态
	struct Bullet* next;	//存储下一个节点
}Node;

//创建子弹链表
Node* My_plane_node = NULL;

void Draw_bullet(Node** spr);

//精灵初始化
void spr_init(plane* spr, double x, double y, IMAGE* img, bool isDie, int type, int HP)
{
	spr->x = x;
	spr->y = y;
	spr->w = img->getwidth();
	spr->h = img->getheight();
	spr->img = img;
	spr->isDie = isDie;
	spr->type = type;
	spr->HP = HP;
}

//精灵绘制
void spr_draw(plane* spr)
{
	if (spr->isDie)//true,表示某个东西已经死亡,不能绘图
	{
		return;
	}
	//绘制某个东西
	putimage(spr->x, spr->y, spr->img + 1, SRCPAINT);
	putimage(spr->x, spr->y, spr->img + 0, SRCAND);
}

//子弹的绘制
void bullet_draw(Node* spr)
{
	putimage(spr->x, spr->y, spr->img + 1, SRCPAINT);
	putimage(spr->x, spr->y, spr->img + 0, SRCAND);
}
//精灵移动
void spr_moveBy(plane* spr, double dx, double dy)
{
	//处理移动
	spr->x += dx;
	spr->y += dy;
}

//精灵位置更新
void spr_InitPosistion(plane* spr, double x, double y)
{
	spr->x = x;
	spr->y = y;
}

//精灵的碰撞检测
bool spr_collision(plane* left, plane* right)
{
	//left的左上角在right内
	if (left->x > right->x && left->x <right->x + right->w &&
		left->y >right->y && left->y < right->y + right->h)
	{
		return true;
	}
	if (right->x > left->x && right->x <left->x + left->w &&
		right->y >left->y && right->y < left->y + left->h)
	{
		return true;
	}
	return false;
}

//子弹的碰撞与越界
bool bullet_collision(Node* spr1)
{
	//子弹撞墙
	if (spr1->x <= 0 || spr1->y <= 0 || spr1->x >= getwidth() || spr1->y >= getheight())
	{
		return true;
	}
	return false;
}

//处理爆炸效果
void boom_Die(plane* spr)
{
	for (int j = 0; j < 5; j++)
	{
		//把位置的信息传给爆炸体
		if (boom[j].frame == 0)
		{
			boom[j].frame = 1;	//开始发生爆炸
			boom[j].x = spr->x;
			boom[j].y = spr->y;
			break;
		}
	}
}

//初始化数据
void init()
{

	srand(time(0));

	loadRes();	//加载图片

	//我方飞机初始位置
	int x = (getwidth() - img_player->getwidth()) / 2;
	int y = getheight() - img_player->getheight();;
	spr_init(&player, x, y, img_player, false, -1, 20);

	//初始化爆炸
	for (int i = 0; i < 5; i++)
	{
		boom[i].frame = 0;	//没有发生过爆炸
		boom[i].x = 0;
		boom[i].y = 0;
	}

	//初始化敌机
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//一开始只产生小型敌机
		spr_init(enemy + i, rand() % (getwidth() - 93), -100, img_enemy1, false, Small, 1);
	}
}

//绘制界面
void draw()
{
	putimage(0, 0, &img_bk);
	spr_draw(&player);

	//绘制爆炸
	for (int i = 0; i < 5; i++)
	{
		//判断哪个发生了爆炸
		if (boom[i].frame != 0)
		{
			//发生爆炸
			putimage(boom[i].x, boom[i].y, &Yboom_img[boom[i].frame / 40], SRCPAINT);
			putimage(boom[i].x, boom[i].y, &boom_img[boom[i].frame / 40], SRCAND);
			boom[i].frame++;	//帧数递增
			if (boom[i].frame > 40 * 6)
			{
				//超过了12张图片就重置为0
				boom[i].frame = 0;
			}
		}
	}

	//绘制敌机
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_draw(enemy + i);
	}
	//绘制我方飞机子弹信息
	Draw_bullet(&My_plane_node);
}

/*
使用链表创建更精准的子弹效果
*/
//创建子弹封装子弹信息
Node* Create_bullet(double vx,double vy,plane* spr,IMAGE* img)
{
	Node* bullet = (Node*)malloc(sizeof(Node));
	//子弹节点信息封装
	bullet->x = spr->x + spr->w / 2;
	bullet->y = spr->y;
	bullet->vx = vx;
	bullet->vy = vy;
	bullet->img = img;
	bullet->isdie = false;
	bullet->next = NULL;
	return bullet;	//返回节点
}

//尾插法连接链表，创建新的子弹
void List_Pink_bullet(Node** head, Node* bullet)
{
	Node* p = *head;
	if (*head == NULL)
	{
		//链表为空，新节点为第一个节点
		*head = bullet;	
		return;
	}
	//找到最后的节点，尾插进去
	while (p->next)
	{
		p = p->next;
	}
	//节点连接
	p->next = bullet;
	p = bullet;
	p->next = NULL;
}

//子弹的水平和垂直的偏移计算
void Change_Bullet_XY(Node** head)
{
	Node* p = *head;
	//没有节点，直接退出
	if (*head == NULL)
	{
		return;
	}
	//遍历每一个子弹，改变其偏移
	while (p)
	{
		p->x += p->vx;
		p->y += p->vy;
		if (p->isdie)
		{
			//如果子弹越界或者打中敌机，子弹消失
			if (bullet_collision(p))
			{
				p->isdie = true;
			}
		}
		p = p->next;
	}
}

//子弹的销毁删除
void Delete_Bullet(Node** head)
{
	Node* cur = *head;	//处理当前的子弹
	Node* pre = NULL;	//保存上一个子弹的节点
	if (*head == NULL)
	{
		//无需删除
		return;
	}
	//遍历子弹
	while (cur)
	{
		if (cur->isdie)
		{
			if (cur == *head)
			{
				//第一个节点被删除
				*head = cur->next;	//改变链表的头节点，让下一个节点作为头节点
				free(cur);
				cur = *head;
			}
			else
			{
				//删除其他的节点
				pre->next=cur->next;	//跳过节点，实现删除
				free(cur);				//释放空间
				cur = pre;				//返回上一个节点
			}
		}
		else
		{
			//节点依次变化
			pre = cur;					//存储上一个节点的位置
			cur = cur->next;			//前进到下一个节点
		}
	}
}

//最后的总结，绘制子弹
void Draw_bullet(Node** spr)
{
	Change_Bullet_XY(spr);
	Delete_Bullet(spr);
	//绘制工作
	for (Node* cur = *spr; cur != NULL; cur = cur->next)
	{
		//把子弹传入
		bullet_draw(cur);
	}
}


/*
当分数大于1000时，产生新的敌军
*/
void EnemyType(int i)
{
	//创建敌机类型
	if (score < 1000)
	{
		//小型敌机
		spr_init(&enemy[i], rand() % (getwidth() - enemy[i].w), -100, img_enemy1, false, Small, 1);
	}
	else if (score >= 1000 && score <= 2500)
	{
		//有一定几率产生小型飞机和中型飞机
		if ((10 + rand() % 15) == 13)
		{
			spr_init(&enemy[i], rand() % (getwidth() - enemy[i].w), -100, img_enemy1, false, Small, 1);
		}
		else
		{
			spr_init(enemy + i, rand() % (getwidth() - enemy[i].w), -100, img_enemy2, false, Middle, 3);
		}
	}
	else if (score >= 2500)
	{
		////有一定几率产生小型飞机和中型飞机和大型飞机
		if ((10 + rand() % 15) == 10)
		{
			spr_init(enemy + i, rand() % (getwidth() - enemy[i].w), -100, img_enemy2, false, Big, 10);
			//CreateEnemyBullet();	//给大飞机创建子弹
		}
		else if ((10 + rand() % 15) == 11 || (10 + rand() % 15) == 12)
		{
			spr_init(enemy + i, rand() % (getwidth() - enemy[i].w), -100, img_enemy3, false, Big, 10);
		}
		else
		{
			spr_init(&enemy[i], rand() % (getwidth() - enemy[i].w), -100, img_enemy1, false, Small, 1);
		}
	}

}

//创建一个敌军
void createEnemy() {
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy[i].isDie) {
			//如果为true说明敌军 已经销毁了  需要重新创建一个敌机
			//CreateEnemyBullet();
			EnemyType(i);
			/*if (enemy[i].type == Big)
			{
				for (int i=0;i<ENEMY_BULLET_NUM;i++)
					CreateEnemyBullet();
			}*/
			break;
		}
	}
}

//敌机不断地往下移动
void enemyMove()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_moveBy(enemy + i, 0, 0.6);
		if (enemy[i].y > getheight())
		{
			//超出边界，敌机重新产生
			enemy[i].x = rand() % (getwidth() - enemy[i].w);
			enemy[i].y = -100;
		}
	}
}

//飞机的移动
void playerMove()
{
#if 1
	//获取异步按键状态
	if (GetAsyncKeyState(VK_UP) && player.y > 0)
	{
		spr_moveBy(&player, 0, -1.5);
	}
	if (GetAsyncKeyState(VK_DOWN) && player.y + player.h < getheight())
	{
		spr_moveBy(&player, 0, 1.5);
	}
	if (GetAsyncKeyState(VK_LEFT) && player.x + player.w / 2 > 0)
	{
		spr_moveBy(&player, -1.5, 0);
	}
	if (GetAsyncKeyState(VK_RIGHT) && player.x + player.w / 2 < getwidth())
	{
		spr_moveBy(&player, 1.5, 0);
	}
	//按空格键发射子弹
	if (GetAsyncKeyState(VK_SPACE)&& Timer(100,0))
	{
		List_Pink_bullet(&My_plane_node, Create_bullet(0, -6, &player, img_bullet));
	}
#elif 0
	//鼠标操作
	MOUSEMSG msg = GetMouseMsg();
	if (MouseHit())
	{
		//如果有鼠标消息
		player.x = msg.x;
		player.y = msg.y;
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			createBullet();
		}
	}
#elif 0
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE))
	{
		player.x = msg.x;
		player.y = msg.y;
	}
#endif

}

//玩家打飞机
void playPlane()
{

}

//我方飞机阵亡
void GameOver()
{

	//我方飞机相撞
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (spr_collision(&player, &enemy[i]))
		{
			player.isDie = true;
			//游戏结束
			boom_Die(&player);
			int ret = MessageBox(GetHWnd(), "你输了,要重新开始吗", "提示", MB_YESNO);
			{
				if (ret == IDOK)
				{
					init();
				}
				else if (ret == IDNO)
				{
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
}

//绘制分数及其他
void draw_other()
{
	settextstyle(50, 0, "微软雅黑");
	settextcolor(RGB(241, 255, 129));
	setbkmode(TRANSPARENT);
	char str[50] = { 0 };
	sprintf(str, "分数:%d", score);
	outtextxy(20, 20, str);
}

int main()
{
	initgraph(INIT_WIDTH, INIT_HEIGHT, SHOWCONSOLE);	//创建图形窗口
	setbkcolor(WHITE);
	cleardevice();
	init();

#if 1
	while (true)
	{
		BeginBatchDraw(); //闪屏：双缓冲
		draw();
		draw_other();
		EndBatchDraw();

		playerMove();
		createEnemy();
		enemyMove();
		playPlane();
		GameOver();
	}
#endif
	getchar();
	return 0;
}
