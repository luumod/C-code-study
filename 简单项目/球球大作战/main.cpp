#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define SPACE 10	//���ӵĿ��
//���ƽ���

//��ң�ʳ�AI
/*
����  ��ɫ  �뾶  ���(isDie)
*/
//����ͼƬ
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
//ʳ������
#define FOOD_NUM 50
//AI����
#define AI_NUM 10
//����AI������
int ALL_SUM = AI_NUM;
//�ṹ���װ
struct Sprite
{
	double x;	//����
	double y;
	COLORREF color;	//��ɫ
	double r;	//�뾶
	bool isDie;	//�Ƿ���
	char name[20];
	bool showname;

	int index_food=-1;	//ר��ΪAI��Ƶ�׷��ʳ��ı��
}gamer, food[FOOD_NUM], AI[AI_NUM];	//���  ʳ��

//AI�б�
const char* AI_name[AI_NUM] = {
	"ɳ��","�ʱ�","����","����ɷ��","����",
	"������","¬��ΰ","PDD","���񱦱�","����"
};
void Init();
void Game();
//����ͼƬ����
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

//�����
bool Mouse_Click(ExMessage* msg,int x,int y,int width,int height)
{
	if (msg->x >= x && msg->x <= x + width && msg->y >= y && msg->y <= y + height)
	{
		return true;
	}
	return false;
	
}
//��ʼ��Ϸ
void start_game(ExMessage* msg)
{
	if (msg->message == WM_LBUTTONDOWN) {
		//������Ϸ�˵�
		//which=0�����ʱΪ���˵�����
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
		//����ѡ�񷵻ز���
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

	//�жϻ���ͼƬ
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

//��ʼ��Sprite�ṹ��	name����Ĭ��ʵ�εĹ���
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

//���ƾ���
void sprite_draw(struct Sprite* spr)
{
	if (!spr->isDie)
	{
		//�����ɫ
		setfillcolor(spr->color);
		//��һ��Բ
		solidcircle(spr->x, spr->y, spr->r);
		/*
		��������
		*/
		//����������ɫ
		if (spr->showname)
		{
			settextcolor(BLACK);
			//��������͸��
			setbkmode(TRANSPARENT);
			//����������ʽ
			settextstyle(28, 0, "΢���ź�");
			//��������
			outtextxy(spr->x - textwidth(spr->name) / 2, spr->y - textheight(spr->name) / 2, spr->name);
		}
	}
}

//�ƶ�����
void sprite_move(struct Sprite* spr,double dx,double dy)
{
	spr->x += dx;
	spr->y += dy;
}

//�������Բ��֮��ľ���
double sprite_distance(struct Sprite* spr1,struct Sprite* spr2)
{
	return sqrt(pow(spr1->x - spr2->x, 2) + pow(spr1->y - spr2->y, 2));	//����֮��ľ���
}

//��ʼ��
void Init()
{
	//���¹���
	A_which = 0;

	srand(time(0));
	//��ʼ�����
	sprite_init(&gamer, 100, 100, 15,true, "������");

	//��ʼ��ʳ��
	for (int i = 0; i < FOOD_NUM; i++)
	{
		sprite_init(&food[i], rand() % getwidth(), rand() % getheight(), 1 + rand() % 5, false);
	}
	//��ʼ��AI
	for (int i = 0; i < AI_NUM; i++)
	{
		sprite_init(&AI[i], rand() % getwidth(), rand() % getheight(),5+rand()%15, true, AI_name[i]);
	}
}

//����
void Draw()
{
	cleardevice();
	//���Ʊ���
	setlinecolor(RGB(182, 102, 193));

	for (int i = 0; i < getheight() / 10; i++)
	{
		line(0, i*SPACE, getwidth(), i*SPACE);
	}
	for (int i = 0; i < getwidth() / 10; i++)
	{
		line(i * SPACE, 0,i*SPACE, getheight());
	}
	//�������
	sprite_draw(&gamer);
	//����ʳ��
	for (int i = 0; i < FOOD_NUM; i++)
	{
		sprite_draw(&food[i]);
	}
	//����AI
	for (int i = 0; i < AI_NUM; i++)
	{
		sprite_draw(&AI[i]);
	}
}

//ʳ�������
void foodlive()
{
	for (int i = 0; i < FOOD_NUM; i++)
	{
		//���ʳ���Ѿ���ʧ�����²���һ��
		if (food[i].isDie)
		{
			food[i].isDie = false;
			sprite_init(&food[i], rand() % getwidth(), rand() % getheight(), 1 + rand() % 5, false);
			break;
		}
	}
}

//��������
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

//�ж���Ϸ���ԵĹ�ϵ
void GameEatFood()
{
	//��ҳ�ʳ��
	for (int i = 0; i < FOOD_NUM; i++)
	{
		if (!food[i].isDie && sprite_distance(&gamer, &food[i]) < gamer.r)
		{
			food[i].isDie = true;	//ʳ����ʧ
			gamer.r += food[i].r / 8;
		}
	}
	for (int i = 0; i < AI_NUM; i++)
	{
	//��ҳ�AI
		if (!gamer.isDie && !AI[i].isDie && sprite_distance(&gamer, &AI[i]) <gamer.r && gamer.r >AI[i].r)
		{
			AI[i].isDie = true;	//AI��ʧ
			ALL_SUM--;
			gamer.r += AI[i].r / 8;
		}
	//AI�����
		if (!gamer.isDie && !AI[i].isDie && sprite_distance(&gamer, &AI[i]) <AI[i].r && gamer.r < AI[i].r)
		{
			gamer.isDie = true;	//�������
			AI[i].r += gamer.r / 8;
		}
	//AI��AI
		for (int j = 0; j < AI_NUM; j++)
		{
			if ( i!=j && !AI[i].isDie&& !AI[j].isDie && sprite_distance(&AI[i], &AI[j]) <=AI[i].r && AI[i].r > AI[j].r)
			{
				AI[j].isDie = true;	//��һ��AI��ʧ
				ALL_SUM--;
				AI[i].r += AI[j].r / 8;
			}
		}
	//AI��ʳ��
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

//׷���㷨
void Chase(struct Sprite* run,struct Sprite* num)
{
	//���׷���ߵ�xС�ڱ�׷��x����++����֮��--
	if (num->x < run->x)
	{
		num->x++;
	}
	else
	{
		num->x--;
	}
	//���׷���ߵ�yС�ڱ�׷��y����++����֮��--
	if (num->y < run->y)
	{
		num->y++;
	}
	else
	{
		num->y--;
	}
}

//��AI������
void AI_move()
{
	for (int i = 0; i < AI_NUM; i++)
	{
		//����ÿһ��AI,ȷ�������Ƿ���
		if (!AI[i].isDie)
		{
			//������ڣ���ȥ׷���ʳ��
			//Ҫ�����жϣ�׷����ʳ���Ƿ�Ϸ�
			if (AI[i].index_food!=-1 && !food[AI[i].index_food].isDie)
			{
				//AI׷ʳ��
				Chase(&food[AI[i].index_food], &AI[i]);
			}
			//��������ڣ���������һ��
			else
			{
				AI[i].index_food = rand() % FOOD_NUM;
			}
		}
	}
}

//�ж���Ϸ����
void GameOver()
{
	if (gamer.isDie)
	{
		ALL_SUM = AI_NUM;
		//�������
		int ret=MessageBox(NULL, "������,Ҫ���¿�ʼ��", "��ʾ",MB_SYSTEMMODAL | MB_YESNO);
		if (ret == IDYES)
		{
			//���¿�ʼ
			Init();
		}
		else if (ret == IDNO)
		{
			Game();
		}
	}
	//���AIȫ����������һ�ʤ
	if (!ALL_SUM) {
		ALL_SUM = AI_NUM;	//������ط����㣬 �����³�ʼ����Ϸ��������
		int ret = MessageBox(NULL, "��ϲ���ʤ��", "��ʾ", MB_SYSTEMMODAL | MB_YESNO);
		if (ret == IDYES)
		{
			//���ز˵�
			Game();
		}
		else if (ret == IDNO)
		{
			Game();
		}
	}
}

//��Ϸ����ѭ��
void Game()
{
	while (A_which != go)
	{
		//˫�����ͼ
		ExMessage msg;
		while (peekmessage(&msg, EM_MOUSE))
		{
			start_game(&msg);
		}
	}

	Init();
	setbkcolor(WHITE);
	cleardevice();
	//��ʼ��Ϸ
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
	//�˵�����
	Game();

	system("pause");
	return 0;
}