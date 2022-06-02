#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <graphics.h>
//�յ� 0 ǽ 1 ���� 2 ��3 Ŀ�ĵ� 4 ���ӵ�Ŀ�ĵ� 5 �˵�Ŀ�ĵ� 6 
#define SIZE 10
enum Game
{
	SPACE,
	WALL,
	BOX,
	PEOPLE,
	DEST,
};
//���ӹؿ�
enum dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
int level = 0;
int player_dir = DOWN;
//��ʼ����Ϸ��ͼ
int map[3][SIZE][SIZE] = {
	{
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,0,0},
	{0,1,4,0,0,0,0,4,1,0},
	{0,1,0,0,2,0,2,0,1,0},
	{0,1,0,0,3,0,0,0,1,0},
	{0,1,0,2,0,2,0,0,1,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,4,0,0,0,0,4,1,0},
	{0,0,1,1,1,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	},
	{
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,0,0},
	{0,1,0,0,1,1,1,0,1,0},
	{1,4,0,0,0,1,0,0,4,1},
	{0,1,0,2,3,0,2,0,0,1},
	{0,1,0,2,1,0,2,0,0,1},
	{0,1,0,0,1,0,0,0,0,1},
	{0,1,4,0,0,0,0,4,1,0},
	{0,0,1,1,1,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	},
	{
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,1,4,0,1,1,0,4,1,0},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,2,2,3,2,2,0,0,1},
	{0,1,0,0,0,0,0,0,1,0},
	{0,0,1,4,0,0,4,1,0,0},
	{0,0,0,1,0,0,1,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	},

};
//����ͼƬ
IMAGE people[4];
IMAGE space;
IMAGE box;
IMAGE wall;
IMAGE dest;
void Load_res()
{
	loadimage(&people[0], "./images/��.png");
	loadimage(&people[1], "./images/��.png");
	loadimage(&people[2], "./images/��.png");
	loadimage(&people[3], "./images/��.png");

	loadimage(&wall, "./images/wall.png");
	loadimage(&box, "./images/box.png");
	loadimage(&space, "./images/space.png");
	loadimage(&dest, "./images/dest.png");
}
//��ͼ�Ļ���
void draw_map()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int x = j * 64;
			int y = i * 64;
			switch (map[level][i][j])
			{
				//���п��ܳ��ֵ����
			case SPACE:putimage(x, y, &space);
				break;
			case WALL:putimage(x, y, &wall);
				break;
			case PEOPLE:
				if (player_dir==UP)
					putimage(x, y, &people[0]);
				else if (player_dir==DOWN)
					putimage(x, y, &people[1]);
				else if (player_dir == LEFT)
					putimage(x, y, &people[2]);
				else if (player_dir == RIGHT)
					putimage(x, y, &people[3]);
				break;
			case BOX:putimage(x, y, &box); //���� 
				break;
			case DEST:putimage(x,y,&dest); //Ŀ�ĵ� 
				break;
			case PEOPLE+DEST:putimage(x, y, &people[0]);//����Ŀ�ĵ�
				break;
			case BOX+DEST: putimage(x, y, &box);//������Ŀ�ĵ�
				break;
			}
		}
		printf("\n");
	}
}
//������ƶ�
void Game_Move()
{
	int i, j;
	//����Ҫȷ�������λ��
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (map[level][i][j] == PEOPLE || map[level][i][j]==DEST+PEOPLE)
			{
				//goto�����������forѭ��
				goto end;
			}
		}
	}
end:;
	//������ƶ� ���� _kbhit() _getch()  conin.h  
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
		case 'W':
		case 72:
			/*
			�����ƶ����ڲ������ӵ������:
			����Ҫ�ж���ǰ���Ƿ��ǿյ�  �ж���ǰ���Ƿ���Ŀ�ĵأ���Ϊֻ���⼸������£���������ƶ�
			�����ӵ�����£��ж�ǰ���Ƿ������ӣ��ж�����ǰ����ʲô
			*/
			player_dir = UP;
			if (map[level][i - 1][j] == SPACE || map[level][i - 1][j] == DEST)
			{
				//�µ�λ����ӣ��ɵ�λ��ɾ��
				map[level][i - 1][j] += PEOPLE;
				map[level][i][j] -= PEOPLE;
			}
			else if (map[level][i - 1][j] == BOX || map[level][i - 1][j] == BOX+DEST)
			{
				//����ǰ���ǿյػ���Ŀ�ĵأ������Խ�����һ���ƶ�
				if (map[level][i - 2][j] == SPACE || map[level][i-2][j]==DEST)
				{
					map[level][i - 2][j] += BOX;	//������ǰ�ƶ�
					map[level][i - 1][j] = map[level][i - 1][j] - BOX + PEOPLE;	//�����ߣ��˹�ȥ
					map[level][i][j] -= PEOPLE;	//����
				}
			}
			break;
		case 's':
		case 'S':
		case 80:
			player_dir = DOWN;
			if (map[level][i+1][j] == SPACE || map[level][i+1][j] == DEST)
			{
				//�µ�λ����ӣ��ɵ�λ��ɾ��
				map[level][i+1][j] += PEOPLE;
				map[level][i][j] -= PEOPLE;
			}
			else if (map[level][i+1][j] == BOX || map[level][i+1][j] == BOX + DEST)
			{
				//����ǰ���ǿյػ���Ŀ�ĵأ������Խ�����һ���ƶ�
				if (map[level][i + 2][j] == SPACE || map[level][i + 2][j] == DEST)
				{
					map[level][i + 2][j] += BOX;	//������ǰ�ƶ�
					map[level][i+1][j] = map[level][i+1][j] - BOX + PEOPLE;	//�����ߣ��˹�ȥ
					map[level][i][j] -= PEOPLE;	//����
				}
			}
			break;
		case 'a':
		case 'A':
		case 75:
			player_dir = LEFT;
			if (map[level][i][j-1] == SPACE || map[level][i][j-1] == DEST)
			{
				//�µ�λ����ӣ��ɵ�λ��ɾ��
				map[level][i][j-1] += PEOPLE;
				map[level][i][j] -= PEOPLE;
			}
			else if (map[level][i][j-1] == BOX || map[level][i][j-1] == BOX + DEST)
			{
				//����ǰ���ǿյػ���Ŀ�ĵأ������Խ�����һ���ƶ�
				if (map[level][i][j-2] == SPACE || map[level][i][j-2] == DEST)
				{
					map[level][i][j-2] += BOX;	//������ǰ�ƶ�
					map[level][i][j-1] = map[level][i][j-1] - BOX + PEOPLE;	//�����ߣ��˹�ȥ
					map[level][i][j] -= PEOPLE;	//����
				}
			}
			break;
		case 'd':
		case 'D':
		case 77:
			player_dir = RIGHT;
			if (map[level][i][j + 1] == SPACE || map[level][i][j + 1] == DEST)
			{
				//�µ�λ����ӣ��ɵ�λ��ɾ��
				map[level][i][j + 1] += PEOPLE;
				map[level][i][j] -= PEOPLE;
			}
			else if (map[level][i][j + 1] == BOX || map[level][i][j + 1] == BOX + DEST)
			{
				//����ǰ���ǿյػ���Ŀ�ĵأ������Խ�����һ���ƶ�
				if (map[level][i][j + 2] == SPACE || map[level][i][j + 2] == DEST)
				{
					map[level][i][j + 2] += BOX;	//������ǰ�ƶ�
					map[level][i][j + 1] = map[level][i][j + 1] - BOX + PEOPLE;	//�����ߣ��˹�ȥ
					map[level][i][j] -= PEOPLE;	//����
				}
			}
			break;
		}
	}
}
//�ж���Ϸ��Ӯ
bool Game_win_lose()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (map[level][i][j] == BOX)
				return false;
		}
	}
	return true;
}
int main(void)
{
	initgraph(10 * 64, 10 * 64);
	setbkcolor(WHITE);
	cleardevice();

	Load_res();
#if 1
	while (1)
	{
		system("cls");	//����
		draw_map();
		if (Game_win_lose())
		{
			level++;
			if (level >= 3)
			{
				MessageBox(NULL, "��ϲ���ʤ��", "��ʾ", NULL);
				exit(6);
			}
		}
		Game_Move();
	}
#endif

	putimage(200, 200, &people[0]);
	system("pause");
	return 0;
}