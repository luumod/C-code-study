#include <stdio.h>
#include <easyx.h>	//��װ��������.cpp�ļ�
#include <mmsystem.h>
#include <time.h>
#pragma comment(lib,"winmm.lib")
#define BULLET_NUM 15
#define ENEMY_NUM 10
IMAGE img_bk;
IMAGE img_player[2];
IMAGE img_bullet[2];
IMAGE img_enemy[2];

//��ʱ��
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
	// ��loadimage��: 2 ��������û��һ������ת�����в�������
	loadimage(&img_bk, "./res/images/background.jpg");
	loadimage(img_player + 0, "./res/images/planeNormal_1.jpg");
	loadimage(img_player + 1, "./res/images/planeNormal_2.jpg");
	loadimage(img_bullet + 0, "./res/images/bullet1.jpg");
	loadimage(img_bullet + 1, "./res/images/bullet2.jpg");
	loadimage(img_enemy + 0, "./res/images/enemy_1.jpg");
	loadimage(img_enemy + 1, "./res/images/enemy_2.jpg");
}

//�ɻ�������(x,y) �ߴ�(w,h)
struct plane
{
	int x;	//����
	int y;
	int w;	//�ߴ�
	int h;
	IMAGE* pimg;
	bool isDie; //�Ƿ�����
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
	if (spr->isDie)	//true,��ʾĳ�������Ѿ�����,���ܻ�ͼ
		return;
	//����ĳ������
	putimage(spr->x, spr->y, spr->pimg + 0, NOTSRCERASE);
	putimage(spr->x, spr->y, spr->pimg + 1, SRCINVERT);
}
void spr_moveBy(plane* spr,int dx,int dy)
{
	//�����ƶ�
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
	//left�����Ͻ���right��
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
//��ʼ������
void init()
{
	//�������� mci media control interface 
	mciSendString("open ./res/sound/game_music.wav alias bgm", NULL, NULL, NULL);
	mciSendString("play bgm", NULL, NULL, NULL);

	loadRes();	//����ͼƬ
	int x = (getwidth()-img_player->getwidth())/2;
	int y = getheight() - img_player->getheight();;
	spr_init(&player, x, y, img_player,false);
	//��ʼ���ӵ�
	for (int i = 0; i < BULLET_NUM; i++)
	{
		spr_init(bullet + i, 0, 0, img_bullet,true);
	}
	//��ʼ���л�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_init(enemy + i, rand() % getwidth(), rand()%100, img_enemy, false);
	}
}
//���ƽ���
void draw()
{
	putimage(0, 0, &img_bk);
	spr_draw(&player);
	//�����ӵ�
	for (int i = 0; i < BULLET_NUM; i++)
	{
		spr_draw(bullet + i);
	}
	//���Ƶл�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_draw(enemy + i);
	}
}

//����һ���ӵ�
void createBullet()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i].isDie)// ��ʼ״̬Ϊtrue  �ӵ�������  �����ӵ�
		{
			bullet[i].isDie = false;	//�ӵ�����  ״̬��Ϊfalse
			//ȷ���ӵ������λ�ã����ҷ��ɻ����м�
			spr_InitPosistion(bullet + i, player.x+player.w/2, player.y);
			break;
		}
	}
}

//����һ���о�
void createEnemy() {
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy[i].isDie) {
			//���Ϊtrue˵���о� �Ѿ�������  ��Ҫ���´���һ���л�
			spr_init(enemy + i, rand() % getwidth(), rand() % 100, img_enemy,false);
			break;
		}
	}

}
//�ӵ����ϲ��ϵ��ƶ�
void bulletMove()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		//����ĳһ���ӵ���ô�ƶ�
		spr_moveBy(bullet + i, 0, -1);
		if (bullet[i].y < -bullet[i].h)
		{
			//�����߽�
			bullet[i].isDie = true;	//���³�ʼ��Ϊtrue  �����ڻ����ӵ�
		}
	}
}
//�л����ϵ������ƶ�
void enemyMove()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_moveBy(enemy + i, 0, 1);
		if (enemy[i].y > getheight())
		{
			//�����߽磬�л����²���
			enemy[i].x = rand() % getwidth();
			enemy[i].y = rand()%100;
		}
	}
}

void playerMove()
{
	//��ȡ�첽����״̬
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
	//���ո�������ӵ�
	if (GetAsyncKeyState(VK_SPACE) && Timer(100,0))
	{
		createBullet();
	}

	//��Ϣ
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
//��Ҵ�ɻ�
void palyePlane()
{
	//�ж��ӵ��Ƿ���л���������ײ
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i].isDie)	//���Ϊtrue ˵���ӵ��Ѿ���ʧ ��������ӵ�
			continue;
		for (int k = 0; k < ENEMY_NUM; k++)
		{
			if (enemy[k].isDie)	//���Ϊtrue ˵���о��Ѿ����� ��������о�
				continue;
			//�ж���ײ
			if (spr_collision(bullet + i, enemy + k))
			{
				bullet[i].isDie = true;		//��ʾ�ӵ��͵л��Ѿ���ʧ
				enemy[k].isDie = true;		
				/*enemy[k].x = rand() % getwidth();
				enemy[k].y = rand()%100;*/
			}
		}
	}
}

int main()
{
	initgraph(591, 700);	//����ͼ�δ���
	init();
	while (true)
	{
		BeginBatchDraw(); //������˫����
		draw();
		EndBatchDraw();

		//��ҵ��ƶ�(�ƶ�����)
		playerMove();
		bulletMove();
		createEnemy();
		enemyMove();
		palyePlane();
	}

	getchar();
	return 0;
}