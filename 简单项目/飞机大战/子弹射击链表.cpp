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
////�����ӵ��ṹ��
//typedef struct Bullet
//{
//	double x, y;
//	double vx, vy;
//	bool isdie;
//	struct Bullet* next;
//}Node;	//����
//
////����һ������
//Node* Bullet_List = NULL;
//
//void create_listR(Node** head, Node* bullet);
//Node* create_bullet(double vx, double vy);
//void Draw_bullet();
////��ʱ��
//bool Timer(time_t ms, int id) {
//	static DWORD t[10];		//10����ʱ��
//	if (clock() - t[id] > ms) {
//		t[id] = clock();
//		return true;
//	}
//	return false;
//}
//
////����
//void draw()
//{
//	putimage(plane.x,plane.y, &hero[1], SRCPAINT);
//	putimage(plane.x, plane.y , &hero[0], SRCAND);
//
//	Draw_bullet();
//}
//
////�ɻ��ƶ�
//void playerMove()
//{
//	//��ȡ�첽����״̬
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
//		//�����ķ��ؽڵ�ֱ�Ӳ��뵽������
//		create_listR(&Bullet_List, create_bullet(0, -20));
//		create_listR(&Bullet_List, create_bullet(-8, -17.32));
//		create_listR(&Bullet_List, create_bullet(8, -17.32));
//	}
//}
//
////ͼƬ����
//void Draw(int x,int y)
//{
//	putimage(x,y, &bullet[1], SRCPAINT);
//	putimage(x,y, &bullet[0], SRCAND);
//}
////�����ӵ�
///*
//��������
//*/
//
////���ȴ����ӵ�
//Node* create_bullet(double vx,double vy)
//{
//	//Ϊ�ӵ�����ռ�
//	Node* head = (Node*)malloc(sizeof(Node));	
//	//�ӵ�����ʼλ��
//	head->x = plane.x+25;
//	head->y = plane.y-35;
//	//�ӵ���ƫ��
//	head->vx = vx;
//	head->vy = vy;
//	head->isdie = false;
//	head->next = NULL;
//	//�����ӵ��ڵ�
//	return head;
//}
//
////Ȼ���ӵ�β�壬�γ�һ������ֱ���ں������޸ģ�û�з���ֵ
//void create_listR(Node** head,Node* bullet)
//{
//	Node* p = *head;
//	/*
//	����ָ�룬��һ��ָ��� һ������ĵ�ַ��������ͷ�ڵ� ��ָ��
//	ʹ�� *head ���ͷ�ڵ�
//	*/
//	//���ͷ�ڵ��ǿգ���ֱ�Ӳ��룬�˳�
//	if (*head == NULL)
//	{
//		*head = bullet;
//		return;
//	}
//	//�����������ĩβ��β��ڵ�
//	while (p->next)
//	{
//		p = p->next;
//	}
//	//����ڵ�
//	p->next = bullet;
//	p = bullet;
//	p->next = NULL;
//	//ֱ���ں������޸ģ����践��ֵ
//}
//
////�ӵ���xyƫ��
//void Bullet_xymove(Node** head)
//{
//	Node* p = *head;	//�洢��һ���ڵ�
//	//����Ϊ�գ�ֱ�ӷ���
//	if (*head == NULL)
//	{
//		return;
//	}
//	//������������
//	while (p)
//	{
//		p->x += p->vx;
//		p->y += p->vy;
//		//�ж��ӵ��Ƿ��뿪��Ұ
//		if (p->x <= 0 || p->x >= getwidth() || p->y <= 0 || p->y >= getheight())
//		{
//			p->isdie = true;	//����ӵ�
//		}
//		p = p->next;
//	}
//	//printf("�ӵ�ƫ��\n");
//}
//
////�ӵ���ɾ��
//void Remove_bullet(Node** head)
//{
//	Node* cur = *head, * pre = NULL;	//һ���ڵ��¼��һ���ڵ�λ��
//	if (*head == NULL)
//	{
//		return;
//	}
//	//��������,�ҳ��ڵ�Ϊtrue���ӵ���˵�����Ѿ���ʧ��ɾ����
//	while (cur)
//	{
//		if (cur->isdie)
//		{
//			if (cur==*head)
//			{
//				//��һ���ڵ㱻ɾ��
//				*head = cur->next;	//�ı������ͷ�ڵ㣬����һ���ڵ���Ϊͷ�ڵ�
//				free(cur);
//				cur = *head;
//			}
//			else
//			{
//				//ɾ�������Ľڵ�
//				pre->next=cur->next;	//�����ڵ㣬ʵ��ɾ��
//				free(cur);				//�ͷſռ�
//				cur = pre;				//������һ���ڵ�
//			}
//		}
//		else
//		{
//			pre = cur;			//�洢��һ���ڵ��λ��
//			cur = cur->next;	//�ƶ�����һ���ڵ�
//		}
//	}
//	//printf("ɾ���ӵ�\n");
//}
//
////�����ӵ�
//void Draw_bullet()
//{
//	Bullet_xymove(&Bullet_List);	//�����ӵ���ƫ��
//	Remove_bullet(&Bullet_List);	//ɾ��Խ����ӵ�
//	for (Node* p = Bullet_List; p != NULL; p = p->next)
//	{
//		//�ӵ��Ļ���
//		Draw(p->x, p->y);
//	}
//}
//int main(void)
//{
//	initgraph(800, 680, SHOWCONSOLE);
//	setbkcolor(YELLOW);
//	cleardevice();
//	//����
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
//#include <easyx.h>	//��װ��������.cpp�ļ�
#include <time.h>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//���ڿ��
#define INIT_WIDTH 520 
#define INIT_HEIGHT 800

//����һ���Գ��ֵ�����
#define ENEMY_NUM 10

//��������
enum enemy
{
	Small,
	Middle,
	Big
};
//����
int score = 0;

IMAGE img_bk;
IMAGE img_player[2];
IMAGE img_bullet[2];
IMAGE img_enemy1[2], img_enemy2[2], img_enemy3[2];
IMAGE img_enemy_bullet[2];
IMAGE boom_img[6], Yboom_img[6];

//��ʱ��
bool Timer(time_t ms, int id) {
	static DWORD t[10];		//10����ʱ��
	if (clock() - t[id] > ms) {
		t[id] = clock();
		return true;
	}
	return false;
}
//����ͼƬ
void loadRes()
{
	// ��loadimage��: 2 ��������û��һ������ת�����в�������
	loadimage(&img_bk, ".\\images\\bg5.jpg");
	//�ҷ�
	loadimage(img_player + 0, ".\\images\\plane1.png");
	loadimage(img_player + 1, ".\\images\\Yplane1.png");
	//�ӵ�
	loadimage(img_bullet + 0, ".\\images\\biu1.png");
	loadimage(img_bullet + 1, ".\\images\\Ybiu1.png");
	loadimage(img_enemy_bullet + 0, ".\\images\\enemy_bullet2.png");
	loadimage(img_enemy_bullet + 1, ".\\images\\Yenemy_bullet2.png");
	//����
	loadimage(img_enemy1 + 0, ".\\images\\enemy1.png");
	loadimage(img_enemy1 + 1, ".\\images\\Yenemy1.png");
	loadimage(img_enemy2 + 0, ".\\images\\enemy2.png");
	loadimage(img_enemy2 + 1, ".\\images\\Yenemy2.png");
	loadimage(img_enemy3 + 0, ".\\images\\enemy3.png");
	loadimage(img_enemy3 + 1, ".\\images\\Yenemy3.png");
	//��ը
	for (int i = 0; i < 6; i++)
	{
		char str1[50] = { 0 };
		char str2[50] = { 0 };
		sprintf(str1, ".\\images\\boom%d.png", i + 1);	//ԭͼ
		sprintf(str2, ".\\images\\Yboom%d.png", i + 1);	//����ͼ
		loadimage(&boom_img[i], str1, 93, 75);
		loadimage(&Yboom_img[i], str2, 93, 75);
	}
}

//�ɻ�������(x,y) �ߴ�(w,h)
struct plane
{
	double x;	//����
	double y;
	int w;	//�ߴ�
	int h;
	IMAGE* img;
	int type;
	int HP;		//�ɻ�Ѫ��
	bool isDie; //�Ƿ�����
}player,enemy[ENEMY_NUM];

//��ը�ṹ��
struct Boom
{
	int frame;	//��ը��֡��
	int x, y;
}boom[5];	//����ͬʱ�洢5���ɻ���ը

//�ӵ�����ṹ��
typedef struct Bullet
{
	int x;
	int y;
	double vx;	//ˮƽ�����ٶ�ƫ��
	double vy;	//��ֱ�����ٶ�ƫ��
	IMAGE* img;	//�ӵ�ͼ��
	bool isdie;	//�ӵ����״̬
	struct Bullet* next;	//�洢��һ���ڵ�
}Node;

//�����ӵ�����
Node* My_plane_node = NULL;

void Draw_bullet(Node** spr);

//�����ʼ��
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

//�������
void spr_draw(plane* spr)
{
	if (spr->isDie)//true,��ʾĳ�������Ѿ�����,���ܻ�ͼ
	{
		return;
	}
	//����ĳ������
	putimage(spr->x, spr->y, spr->img + 1, SRCPAINT);
	putimage(spr->x, spr->y, spr->img + 0, SRCAND);
}

//�ӵ��Ļ���
void bullet_draw(Node* spr)
{
	putimage(spr->x, spr->y, spr->img + 1, SRCPAINT);
	putimage(spr->x, spr->y, spr->img + 0, SRCAND);
}
//�����ƶ�
void spr_moveBy(plane* spr, double dx, double dy)
{
	//�����ƶ�
	spr->x += dx;
	spr->y += dy;
}

//����λ�ø���
void spr_InitPosistion(plane* spr, double x, double y)
{
	spr->x = x;
	spr->y = y;
}

//�������ײ���
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

//�ӵ�����ײ��Խ��
bool bullet_collision(Node* spr1)
{
	//�ӵ�ײǽ
	if (spr1->x <= 0 || spr1->y <= 0 || spr1->x >= getwidth() || spr1->y >= getheight())
	{
		return true;
	}
	return false;
}

//����ըЧ��
void boom_Die(plane* spr)
{
	for (int j = 0; j < 5; j++)
	{
		//��λ�õ���Ϣ������ը��
		if (boom[j].frame == 0)
		{
			boom[j].frame = 1;	//��ʼ������ը
			boom[j].x = spr->x;
			boom[j].y = spr->y;
			break;
		}
	}
}

//��ʼ������
void init()
{

	srand(time(0));

	loadRes();	//����ͼƬ

	//�ҷ��ɻ���ʼλ��
	int x = (getwidth() - img_player->getwidth()) / 2;
	int y = getheight() - img_player->getheight();;
	spr_init(&player, x, y, img_player, false, -1, 20);

	//��ʼ����ը
	for (int i = 0; i < 5; i++)
	{
		boom[i].frame = 0;	//û�з�������ը
		boom[i].x = 0;
		boom[i].y = 0;
	}

	//��ʼ���л�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//һ��ʼֻ����С�͵л�
		spr_init(enemy + i, rand() % (getwidth() - 93), -100, img_enemy1, false, Small, 1);
	}
}

//���ƽ���
void draw()
{
	putimage(0, 0, &img_bk);
	spr_draw(&player);

	//���Ʊ�ը
	for (int i = 0; i < 5; i++)
	{
		//�ж��ĸ������˱�ը
		if (boom[i].frame != 0)
		{
			//������ը
			putimage(boom[i].x, boom[i].y, &Yboom_img[boom[i].frame / 40], SRCPAINT);
			putimage(boom[i].x, boom[i].y, &boom_img[boom[i].frame / 40], SRCAND);
			boom[i].frame++;	//֡������
			if (boom[i].frame > 40 * 6)
			{
				//������12��ͼƬ������Ϊ0
				boom[i].frame = 0;
			}
		}
	}

	//���Ƶл�
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_draw(enemy + i);
	}
	//�����ҷ��ɻ��ӵ���Ϣ
	Draw_bullet(&My_plane_node);
}

/*
ʹ������������׼���ӵ�Ч��
*/
//�����ӵ���װ�ӵ���Ϣ
Node* Create_bullet(double vx,double vy,plane* spr,IMAGE* img)
{
	Node* bullet = (Node*)malloc(sizeof(Node));
	//�ӵ��ڵ���Ϣ��װ
	bullet->x = spr->x + spr->w / 2;
	bullet->y = spr->y;
	bullet->vx = vx;
	bullet->vy = vy;
	bullet->img = img;
	bullet->isdie = false;
	bullet->next = NULL;
	return bullet;	//���ؽڵ�
}

//β�巨�������������µ��ӵ�
void List_Pink_bullet(Node** head, Node* bullet)
{
	Node* p = *head;
	if (*head == NULL)
	{
		//����Ϊ�գ��½ڵ�Ϊ��һ���ڵ�
		*head = bullet;	
		return;
	}
	//�ҵ����Ľڵ㣬β���ȥ
	while (p->next)
	{
		p = p->next;
	}
	//�ڵ�����
	p->next = bullet;
	p = bullet;
	p->next = NULL;
}

//�ӵ���ˮƽ�ʹ�ֱ��ƫ�Ƽ���
void Change_Bullet_XY(Node** head)
{
	Node* p = *head;
	//û�нڵ㣬ֱ���˳�
	if (*head == NULL)
	{
		return;
	}
	//����ÿһ���ӵ����ı���ƫ��
	while (p)
	{
		p->x += p->vx;
		p->y += p->vy;
		if (p->isdie)
		{
			//����ӵ�Խ����ߴ��ел����ӵ���ʧ
			if (bullet_collision(p))
			{
				p->isdie = true;
			}
		}
		p = p->next;
	}
}

//�ӵ�������ɾ��
void Delete_Bullet(Node** head)
{
	Node* cur = *head;	//����ǰ���ӵ�
	Node* pre = NULL;	//������һ���ӵ��Ľڵ�
	if (*head == NULL)
	{
		//����ɾ��
		return;
	}
	//�����ӵ�
	while (cur)
	{
		if (cur->isdie)
		{
			if (cur == *head)
			{
				//��һ���ڵ㱻ɾ��
				*head = cur->next;	//�ı������ͷ�ڵ㣬����һ���ڵ���Ϊͷ�ڵ�
				free(cur);
				cur = *head;
			}
			else
			{
				//ɾ�������Ľڵ�
				pre->next=cur->next;	//�����ڵ㣬ʵ��ɾ��
				free(cur);				//�ͷſռ�
				cur = pre;				//������һ���ڵ�
			}
		}
		else
		{
			//�ڵ����α仯
			pre = cur;					//�洢��һ���ڵ��λ��
			cur = cur->next;			//ǰ������һ���ڵ�
		}
	}
}

//�����ܽᣬ�����ӵ�
void Draw_bullet(Node** spr)
{
	Change_Bullet_XY(spr);
	Delete_Bullet(spr);
	//���ƹ���
	for (Node* cur = *spr; cur != NULL; cur = cur->next)
	{
		//���ӵ�����
		bullet_draw(cur);
	}
}


/*
����������1000ʱ�������µĵо�
*/
void EnemyType(int i)
{
	//�����л�����
	if (score < 1000)
	{
		//С�͵л�
		spr_init(&enemy[i], rand() % (getwidth() - enemy[i].w), -100, img_enemy1, false, Small, 1);
	}
	else if (score >= 1000 && score <= 2500)
	{
		//��һ�����ʲ���С�ͷɻ������ͷɻ�
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
		////��һ�����ʲ���С�ͷɻ������ͷɻ��ʹ��ͷɻ�
		if ((10 + rand() % 15) == 10)
		{
			spr_init(enemy + i, rand() % (getwidth() - enemy[i].w), -100, img_enemy2, false, Big, 10);
			//CreateEnemyBullet();	//����ɻ������ӵ�
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

//����һ���о�
void createEnemy() {
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy[i].isDie) {
			//���Ϊtrue˵���о� �Ѿ�������  ��Ҫ���´���һ���л�
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

//�л����ϵ������ƶ�
void enemyMove()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		spr_moveBy(enemy + i, 0, 0.6);
		if (enemy[i].y > getheight())
		{
			//�����߽磬�л����²���
			enemy[i].x = rand() % (getwidth() - enemy[i].w);
			enemy[i].y = -100;
		}
	}
}

//�ɻ����ƶ�
void playerMove()
{
#if 1
	//��ȡ�첽����״̬
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
	//���ո�������ӵ�
	if (GetAsyncKeyState(VK_SPACE)&& Timer(100,0))
	{
		List_Pink_bullet(&My_plane_node, Create_bullet(0, -6, &player, img_bullet));
	}
#elif 0
	//������
	MOUSEMSG msg = GetMouseMsg();
	if (MouseHit())
	{
		//����������Ϣ
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

//��Ҵ�ɻ�
void playPlane()
{

}

//�ҷ��ɻ�����
void GameOver()
{

	//�ҷ��ɻ���ײ
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (spr_collision(&player, &enemy[i]))
		{
			player.isDie = true;
			//��Ϸ����
			boom_Die(&player);
			int ret = MessageBox(GetHWnd(), "������,Ҫ���¿�ʼ��", "��ʾ", MB_YESNO);
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

//���Ʒ���������
void draw_other()
{
	settextstyle(50, 0, "΢���ź�");
	settextcolor(RGB(241, 255, 129));
	setbkmode(TRANSPARENT);
	char str[50] = { 0 };
	sprintf(str, "����:%d", score);
	outtextxy(20, 20, str);
}

int main()
{
	initgraph(INIT_WIDTH, INIT_HEIGHT, SHOWCONSOLE);	//����ͼ�δ���
	setbkcolor(WHITE);
	cleardevice();
	init();

#if 1
	while (true)
	{
		BeginBatchDraw(); //������˫����
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
