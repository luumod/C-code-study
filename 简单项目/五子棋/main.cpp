#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define SPACE 30	//线之间的空白间距
#define A_SPACE 3*SPACE
#define ROW 15
#define COL 15

IMAGE bk_img;
enum Chress
{
	None,
	Black,
	White
};
//定义地图数组   
int map[ROW][COL];
struct Pos
{
	int row;
	int col;
	bool isShow;		//是否显示框
	int player;
	int fg;
}pos = { -1,-1,false,Black };

void put()
{
	loadimage(&bk_img, "五子棋.jpg");
}
void Draw() {

	putimage(0, 0, &bk_img);
	setlinecolor(BLACK);
	//画五子棋棋盘
	for (int i = 0; i < 15; i++)
	{
		line(A_SPACE, i * SPACE + A_SPACE, (COL - 1) * SPACE + A_SPACE, i * SPACE + A_SPACE);	//画横线
		line(i * SPACE + A_SPACE, A_SPACE, i * SPACE + A_SPACE, (ROW - 1) * SPACE + A_SPACE);	//画竖线
	}
	//边框加粗
	setlinestyle(PS_SOLID, 2);
	rectangle(A_SPACE, A_SPACE, A_SPACE + (COL - 1) * SPACE, A_SPACE + (ROW - 1) * SPACE);

	//设置填充颜色
	setfillcolor(BLACK);
	solidcircle(A_SPACE + 7 * SPACE, A_SPACE + 7 * SPACE, 7);
	solidcircle(A_SPACE + (7 - 4) * SPACE, A_SPACE + (7 + 4) * SPACE, 7);
	solidcircle(A_SPACE + (7 - 4) * SPACE, A_SPACE + (7 - 4) * SPACE, 7);
	solidcircle(A_SPACE + (7 + 4) * SPACE, A_SPACE + (7 + 4) * SPACE, 7);
	solidcircle(A_SPACE + (7 + 4) * SPACE, A_SPACE + (7 - 4) * SPACE, 7);

	//绘制棋子
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == Black)
			{
				setfillcolor(BLACK);
				solidcircle(A_SPACE + j * SPACE, A_SPACE + i * SPACE, 10);
			}
			else if (map[i][j] == White)
			{
				setfillcolor(WHITE);
				solidcircle(A_SPACE + j * SPACE, A_SPACE + i * SPACE, 10);
			}

		}
	}

	if (pos.isShow)
	{
		rectangle(pos.col*SPACE+A_SPACE - 12, pos.row * SPACE + A_SPACE - 12, pos.col * SPACE + A_SPACE + 12, pos.row * SPACE + A_SPACE + 12);
	}
}

//鼠标移动
void mouse_move_message(ExMessage* msg)
{
	pos.isShow = false;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			int gradx = A_SPACE + j * SPACE;
			int grady = A_SPACE + i * SPACE;
			if ((abs(gradx-msg->x)<=12) && (abs(msg->y-grady)<=12))
			{
				pos.isShow = true;
				pos.row = i;
				pos.col = j;
			}
		}
	}

}
bool Victor(int x, int y);
//鼠标按下
void Mouse_press_message(ExMessage* msg)
{
	if (msg->message == WM_LBUTTONDOWN)
	{
		//下棋
		if (map[pos.row][pos.col] != Black && map[pos.row][pos.col] != White)
		{
			map[pos.row][pos.col] = pos.player;
		}
		//判断输赢
		bool fg = Victor(pos.row, pos.col);
		if (pos.player==Black && fg)
		{
			MessageBox(NULL, "黑棋获胜了", "恭喜你", MB_OK | MB_SYSTEMMODAL);
			exit(1);
		}
		else if (pos.player == White && fg)
		{
			MessageBox(NULL, "白棋获胜了", "恭喜你", MB_OK | MB_SYSTEMMODAL);
			exit(1);
		}
		//更换棋子
		pos.player = (pos.player == Black) ? White : Black;
	}
}
bool Victor(int row,int col) {
	/*
	传入某一行和某一列
	*/
	//某一行五个
	for (int i = col - 4; i <= col; i++) {
		if (i >= 0 && i <= COL && map[row][i] == pos.player && map[row][i + 1] == pos.player &&
			map[row][i + 2] == pos.player && map[row][i + 3] == pos.player && map[row][i + 4] == pos.player)
		{
			return true;
		}
	}
	//某一列五个
	for (int i = row - 4; i <= row; i++) {
		if (i >= 0 && i <= ROW && map[i][col] == pos.player && map[i+1][col] == pos.player &&
			map[i+2][col] == pos.player && map[i+3][col] == pos.player && map[i+4][col] == pos.player)
		{
			return true;
		}
	}
	//右斜着五个
	for (int i = row + 4,j=col-4; i >= row && j<=col; i--,j++)
	{
		if (i >= 0 && j >= 0 && i <= ROW && j <= COL && map[i][j] == pos.player && map[i - 1][j + 1] == pos.player
			&& map[i - 2][j + 2] == pos.player && map[i - 3][j + 3] == pos.player && map[i - 4][j + 4] == pos.player)
		{
			return true;
		}
	}
	//左斜着五个
	for (int i = row + 4, j = col + 4; i >= row && j >= col; i--, j--)
	{
		if (i >= 0 && j >= 0 && i <= ROW && j <= COL && map[i][j] == pos.player && map[i-1][j-1] == pos.player
			&& map[i-2][j-2] == pos.player && map[i-3][j-3] == pos.player && map[i-4][j-4] == pos.player)
		{
			return true;
		}
	}

	return false;
}

int main(void) {
	initgraph(600, 600);
	//加载图片
	put();
	putimage(0, 0, &bk_img);

	while (1)
	{
		//双缓冲绘图
		BeginBatchDraw();
		Draw();
		EndBatchDraw();

		/*
		处理消息
		*/
		ExMessage msg;	//消息结构体
		if (peekmessage(&msg, EM_MOUSE))	//接收消息
		{
			switch (msg.message)
			{
			case WM_MOUSEMOVE:
				//鼠标移动消息
				mouse_move_message(&msg);
				break;
			case WM_LBUTTONDOWN:
				//鼠标左键点击
				Mouse_press_message(&msg);
				break;
			}

		}
	}
	system("pause");
}

