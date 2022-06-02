#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <graphics.h>
//空地 0 墙 1 箱子 2 人3 目的地 4 箱子到目的地 5 人到目的地 6 
#define SIZE 10
enum Game
{
	SPACE,
	WALL,
	BOX,
	PEOPLE,
	DEST,
};
//增加关卡
enum dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
int level = 0;
int player_dir = DOWN;
//初始化游戏地图
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
//加载图片
IMAGE people[4];
IMAGE space;
IMAGE box;
IMAGE wall;
IMAGE dest;
void Load_res()
{
	loadimage(&people[0], "./images/上.png");
	loadimage(&people[1], "./images/下.png");
	loadimage(&people[2], "./images/左.png");
	loadimage(&people[3], "./images/右.png");

	loadimage(&wall, "./images/wall.png");
	loadimage(&box, "./images/box.png");
	loadimage(&space, "./images/space.png");
	loadimage(&dest, "./images/dest.png");
}
//地图的绘制
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
				//所有可能出现的情况
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
			case BOX:putimage(x, y, &box); //箱子 
				break;
			case DEST:putimage(x,y,&dest); //目的地 
				break;
			case PEOPLE+DEST:putimage(x, y, &people[0]);//人在目的地
				break;
			case BOX+DEST: putimage(x, y, &box);//箱子在目的地
				break;
			}
		}
		printf("\n");
	}
}
//人物的移动
void Game_Move()
{
	int i, j;
	//首先要确定人物的位置
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (map[level][i][j] == PEOPLE || map[level][i][j]==DEST+PEOPLE)
			{
				//goto语句跳出两层for循环
				goto end;
			}
		}
	}
end:;
	//人物的移动 按键 _kbhit() _getch()  conin.h  
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
		case 'W':
		case 72:
			/*
			向上移动，在不推箱子的情况下:
			首先要判断其前方是否是空地  判断其前方是否是目的地，因为只有这几种情况下，人物才能移动
			推箱子的情况下，判断前方是否是箱子，判断箱子前方是什么
			*/
			player_dir = UP;
			if (map[level][i - 1][j] == SPACE || map[level][i - 1][j] == DEST)
			{
				//新的位置添加，旧的位置删除
				map[level][i - 1][j] += PEOPLE;
				map[level][i][j] -= PEOPLE;
			}
			else if (map[level][i - 1][j] == BOX || map[level][i - 1][j] == BOX+DEST)
			{
				//箱子前方是空地或者目的地，都可以进行下一步移动
				if (map[level][i - 2][j] == SPACE || map[level][i-2][j]==DEST)
				{
					map[level][i - 2][j] += BOX;	//箱子往前移动
					map[level][i - 1][j] = map[level][i - 1][j] - BOX + PEOPLE;	//箱子走，人过去
					map[level][i][j] -= PEOPLE;	//人走
				}
			}
			break;
		case 's':
		case 'S':
		case 80:
			player_dir = DOWN;
			if (map[level][i+1][j] == SPACE || map[level][i+1][j] == DEST)
			{
				//新的位置添加，旧的位置删除
				map[level][i+1][j] += PEOPLE;
				map[level][i][j] -= PEOPLE;
			}
			else if (map[level][i+1][j] == BOX || map[level][i+1][j] == BOX + DEST)
			{
				//箱子前方是空地或者目的地，都可以进行下一步移动
				if (map[level][i + 2][j] == SPACE || map[level][i + 2][j] == DEST)
				{
					map[level][i + 2][j] += BOX;	//箱子往前移动
					map[level][i+1][j] = map[level][i+1][j] - BOX + PEOPLE;	//箱子走，人过去
					map[level][i][j] -= PEOPLE;	//人走
				}
			}
			break;
		case 'a':
		case 'A':
		case 75:
			player_dir = LEFT;
			if (map[level][i][j-1] == SPACE || map[level][i][j-1] == DEST)
			{
				//新的位置添加，旧的位置删除
				map[level][i][j-1] += PEOPLE;
				map[level][i][j] -= PEOPLE;
			}
			else if (map[level][i][j-1] == BOX || map[level][i][j-1] == BOX + DEST)
			{
				//箱子前方是空地或者目的地，都可以进行下一步移动
				if (map[level][i][j-2] == SPACE || map[level][i][j-2] == DEST)
				{
					map[level][i][j-2] += BOX;	//箱子往前移动
					map[level][i][j-1] = map[level][i][j-1] - BOX + PEOPLE;	//箱子走，人过去
					map[level][i][j] -= PEOPLE;	//人走
				}
			}
			break;
		case 'd':
		case 'D':
		case 77:
			player_dir = RIGHT;
			if (map[level][i][j + 1] == SPACE || map[level][i][j + 1] == DEST)
			{
				//新的位置添加，旧的位置删除
				map[level][i][j + 1] += PEOPLE;
				map[level][i][j] -= PEOPLE;
			}
			else if (map[level][i][j + 1] == BOX || map[level][i][j + 1] == BOX + DEST)
			{
				//箱子前方是空地或者目的地，都可以进行下一步移动
				if (map[level][i][j + 2] == SPACE || map[level][i][j + 2] == DEST)
				{
					map[level][i][j + 2] += BOX;	//箱子往前移动
					map[level][i][j + 1] = map[level][i][j + 1] - BOX + PEOPLE;	//箱子走，人过去
					map[level][i][j] -= PEOPLE;	//人走
				}
			}
			break;
		}
	}
}
//判断游戏输赢
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
		system("cls");	//清屏
		draw_map();
		if (Game_win_lose())
		{
			level++;
			if (level >= 3)
			{
				MessageBox(NULL, "恭喜你获胜了", "提示", NULL);
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