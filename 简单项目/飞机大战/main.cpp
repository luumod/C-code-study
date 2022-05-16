#include <stdio.h>
#include <easyx.h>	//安装，必须是.cpp文件
#include <mmsystem.h>
#include <time.h>
#pragma comment(lib,"winmm.lib")
#define BULLET_NUM 15
#define ENEMY_NUM 10
IMAGE img_bk;
IMAGE img_player[2];
IMAGE img_bullet[2];
IMAGE img_enemy[2];

//计时器
bool Timer(int ms,int id) {
	static DWORD t[10];
	if (clock() - t[id] > ms) {
		t[id] = clock();
		return true;
	}
	return false;
}
void loadRes()
{
	// “loadimage”: 2 个重载中没有一个可以转换所有参数类型
	loadimage(&img_bk, "./res/images/background.jpg");
	loadimage(img_player + 0, "./res/images/planeNormal_1.jpg");
	loadimage(img_player + 1, "./res/images/planeNormal_2.jpg");
	loadimage(img_bullet + 0, "./res/images/bullet1.jpg");
	loadimage(img_bullet + 1, "./res/images/bullet2.jpg");
	loadimage(img_enemy + 0, "./res/images/enemy_1.jpg");
	loadimage(img_enemy + 1, "./res/images/enemy_2.jpg");
}
a
//飞机：坐标(x,y) 尺寸(w,h)
struct plane
{
	int x;	//坐标
	int y;
	int w;	//尺寸
	int h;
	IMAGE* pimg;
	bool isDie; //是否死亡
};
void spr_init(plane* spr, int x, int y,IMAGE *img,bool isDie)
{
	spr->x = x;
	spr->y = y;
	spr->w = img->getwidth();
	spr->h = img->getheight();
	spr->pimg = img;
	spr->isDie = isDie;
}
void spr_draw(plane* spr)
{
	if (spr->isDie)	//true,表示某个东西已经死亡,不能绘图
		return;
	//绘制某个东西
	putimage(spr->x, spr->y, spr->pimg + 0, NOTSRCERASE);
	putimage(spr->x, spr->y, spr->pimg + 1, SRCINVERT);
}
void spr_moveBy(plane* spr,int dx,int dy)
{
	//处理移动
	spr->x += dx;
	spr->y += dy;
}
void spr_InitPosistion(plane* spr, int x, int y)
{
	spr->x = x;
	spr->y = y;
}
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

plane player;
plane bullet[BULLET_NUM];
plane enemy[ENEMY_NUM];
//初始化数据
void init()
{
	//播放音乐 mci media control interface 
	mciSendString("open ./res/sound/game_music.wav alias bgm", NULL, NULL, NULL);
	mciSendString("play bgm", NULL, NULL, NULL);

	loadRes();	//加载图片
	int x = (getwidth()-img_player->getwidth())/2;
	int y = getheight() - img_player->getheight();;
	spr_init(&player, x, y, img_player,false);
	//初始化子弹
	for (int i = 0; i < BULLET_NUM; i++)
	{
		spr_init(bullet + i, 0, 0, img_bullet,true);
	}
	//初始化敌机
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_init(enemy + i, rand() % getwidth(), rand()%100, img_enemy, false);
	}
}
//绘制界面
void draw()
{
	putimage(0, 0, &img_bk);
	spr_draw(&player);
	//绘制子弹
	for (int i = 0; i < BULLET_NUM; i++)
	{
		spr_draw(bullet + i);
	}
	//绘制敌机
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_draw(enemy + i);
	}
}

//产生一颗子弹
void createBullet()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i].isDie)// 初始状态为true  子弹已死亡  创建子弹
		{
			bullet[i].isDie = false;	//子弹发射  状态变为false
			//确定子弹发射的位置，在我方飞机的中间
			spr_InitPosistion(bullet + i, player.x+player.w/2, player.y);
			break;
		}
	}
}

//创建一个敌军
void createEnemy() {
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy[i].isDie) {
			//如果为true说明敌军 已经销毁了  需要重新创建一个敌机
			spr_init(enemy + i, rand() % getwidth(), rand() % 100, img_enemy,false);
			break;
		}
	}

}
//子弹向上不断地移动
void bulletMove()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		//处理某一颗子弹怎么移动
		spr_moveBy(bullet + i, 0, -1);
		if (bullet[i].y < -bullet[i].h)
		{
			//超出边界
			bullet[i].isDie = true;	//重新初始化为true  类似于回收子弹
		}
	}
}
//敌机不断地往下移动
void enemyMove()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_moveBy(enemy + i, 0, 1);
		if (enemy[i].y > getheight())
		{
			//超出边界，敌机重新产生
			enemy[i].x = rand() % getwidth();
			enemy[i].y = rand()%100;
		}
	}
}

void playerMove()
{
	//获取异步按键状态
	if (GetAsyncKeyState(VK_UP) && player.y > 0)
	{
		spr_moveBy(&player, 0, -1);
	}
	if (GetAsyncKeyState(VK_DOWN) && player.y+player.h <getheight())
	{
		spr_moveBy(&player, 0, 1);
	}
	if (GetAsyncKeyState(VK_LEFT) && player.x+ player.w/2>0)
	{
		spr_moveBy(&player, -1, 0);
	}
	if (GetAsyncKeyState(VK_RIGHT) && player.x+player.w/2 <getwidth())
	{
		spr_moveBy(&player, 1, 0);
	}
	//按空格键发射子弹
	if (GetAsyncKeyState(VK_SPACE) && Timer(100,0))
	{
		createBullet();
	}

	//消息
	/*ExMessage msg = {0};
	while (peekmessage(&msg,EM_KEY))
	{
		if (msg.message == WM_KEYDOWN)
		{
			if (msg.vkcode == VK_SPACE)
			{
				createBullet();
			}
		}
	}*/

}
//玩家打飞机
void palyePlane()
{
	//判断子弹是否与敌机产生了碰撞
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i].isDie)	//如果为true 说明子弹已经消失 跳过这个子弹
			continue;
		for (int k = 0; k < ENEMY_NUM; k++)
		{
			if (enemy[k].isDie)	//如果为true 说明敌军已经死亡 跳过这个敌军
				continue;
			//判断碰撞
			if (spr_collision(bullet + i, enemy + k))
			{
				bullet[i].isDie = true;		//表示子弹和敌机已经消失
				enemy[k].isDie = true;		
				/*enemy[k].x = rand() % getwidth();
				enemy[k].y = rand()%100;*/
			}
		}
	}
}

int main()
{
	initgraph(591, 700);	//创建图形窗口
	init();
	while (true)
	{
		BeginBatchDraw(); //闪屏：双缓冲
		draw();
		EndBatchDraw();

		//玩家的移动(移动坐标)
		playerMove();
		bulletMove();
		createEnemy();
		enemyMove();
		palyePlane();
	}

	getchar();
	return 0;
}
