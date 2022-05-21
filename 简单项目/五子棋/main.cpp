#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define SPACE 30	//��֮��Ŀհ׼��
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
//�����ͼ����   
int map[ROW][COL];
struct Pos
{
	int row;
	int col;
	bool isShow;		//�Ƿ���ʾ��
	int player;
	int fg;
}pos = { -1,-1,false,Black };

void put()
{
	loadimage(&bk_img, "������.jpg");
}
void Draw() {

	putimage(0, 0, &bk_img);
	setlinecolor(BLACK);
	//������������
	for (int i = 0; i < 15; i++)
	{
		line(A_SPACE, i * SPACE + A_SPACE, (COL - 1) * SPACE + A_SPACE, i * SPACE + A_SPACE);	//������
		line(i * SPACE + A_SPACE, A_SPACE, i * SPACE + A_SPACE, (ROW - 1) * SPACE + A_SPACE);	//������
	}
	//�߿�Ӵ�
	setlinestyle(PS_SOLID, 2);
	rectangle(A_SPACE, A_SPACE, A_SPACE + (COL - 1) * SPACE, A_SPACE + (ROW - 1) * SPACE);

	//���������ɫ
	setfillcolor(BLACK);
	solidcircle(A_SPACE + 7 * SPACE, A_SPACE + 7 * SPACE, 7);
	solidcircle(A_SPACE + (7 - 4) * SPACE, A_SPACE + (7 + 4) * SPACE, 7);
	solidcircle(A_SPACE + (7 - 4) * SPACE, A_SPACE + (7 - 4) * SPACE, 7);
	solidcircle(A_SPACE + (7 + 4) * SPACE, A_SPACE + (7 + 4) * SPACE, 7);
	solidcircle(A_SPACE + (7 + 4) * SPACE, A_SPACE + (7 - 4) * SPACE, 7);

	//��������
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

//����ƶ�
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
//��갴��
void Mouse_press_message(ExMessage* msg)
{
	if (msg->message == WM_LBUTTONDOWN)
	{
		//����
		if (map[pos.row][pos.col] != Black && map[pos.row][pos.col] != White)
		{
			map[pos.row][pos.col] = pos.player;
		}
		//�ж���Ӯ
		bool fg = Victor(pos.row, pos.col);
		if (pos.player==Black && fg)
		{
			MessageBox(NULL, "�����ʤ��", "��ϲ��", MB_OK | MB_SYSTEMMODAL);
			exit(1);
		}
		else if (pos.player == White && fg)
		{
			MessageBox(NULL, "�����ʤ��", "��ϲ��", MB_OK | MB_SYSTEMMODAL);
			exit(1);
		}
		//��������
		pos.player = (pos.player == Black) ? White : Black;
	}
}
bool Victor(int row,int col) {
	/*
	����ĳһ�к�ĳһ��
	*/
	//ĳһ�����
	for (int i = col - 4; i <= col; i++) {
		if (i >= 0 && i <= COL && map[row][i] == pos.player && map[row][i + 1] == pos.player &&
			map[row][i + 2] == pos.player && map[row][i + 3] == pos.player && map[row][i + 4] == pos.player)
		{
			return true;
		}
	}
	//ĳһ�����
	for (int i = row - 4; i <= row; i++) {
		if (i >= 0 && i <= ROW && map[i][col] == pos.player && map[i+1][col] == pos.player &&
			map[i+2][col] == pos.player && map[i+3][col] == pos.player && map[i+4][col] == pos.player)
		{
			return true;
		}
	}
	//��б�����
	for (int i = row + 4,j=col-4; i >= row && j<=col; i--,j++)
	{
		if (i >= 0 && j >= 0 && i <= ROW && j <= COL && map[i][j] == pos.player && map[i - 1][j + 1] == pos.player
			&& map[i - 2][j + 2] == pos.player && map[i - 3][j + 3] == pos.player && map[i - 4][j + 4] == pos.player)
		{
			return true;
		}
	}
	//��б�����
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
	//����ͼƬ
	put();
	putimage(0, 0, &bk_img);

	while (1)
	{
		//˫�����ͼ
		BeginBatchDraw();
		Draw();
		EndBatchDraw();

		/*
		������Ϣ
		*/
		ExMessage msg;	//��Ϣ�ṹ��
		if (peekmessage(&msg, EM_MOUSE))	//������Ϣ
		{
			switch (msg.message)
			{
			case WM_MOUSEMOVE:
				//����ƶ���Ϣ
				mouse_move_message(&msg);
				break;
			case WM_LBUTTONDOWN:
				//���������
				Mouse_press_message(&msg);
				break;
			}

		}
	}
	system("pause");
}

