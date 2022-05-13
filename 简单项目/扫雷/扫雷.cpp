/*
ɨ�� 
1.��ά����
2.��ͼ, ������ת��ΪͼƬ�����ܣ����
3.������ ����򿪸���
4.�㵽���Ӻ���ʾ��Χ�ĸ���
5.�ж���Ϸ��Ӯ
6.���� ����
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//����ͼƬ�߿�
#define SIZE 50
//��������
#define ROW 10
#define COL 10
//�׵�����
#define LEI 10
int map[ROW][COL];		//ȫ�ֱ����Զ���ʼ��0
IMAGE img[12];			//����ͼƬ���飬����ͼƬ
int flag = 0;	//��Ϸʤ����־
void ShowMap();
//������Ϸ����
void Music() {
	//������
	mciSendString("open G:\\C����\\ɨ��\\ɨ���ز�\\11638.mp3 alias BGM", 0, 0, 0);
	//��������
	mciSendString("play BGM", 0, 0, 0);
}
//��Ϸ���ݳ�ʼ��
void GameInit() {
	//�������������
	srand(time(0));

	Music();

	//��ʼ������
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			map[i][j] = 0;
		}
	}
	//����,��-1��ʾ��  �����
	for (int i = 0; i < LEI;) {
		//�п��ܻ�����ظ�
		int r = rand() % LEI;
		int c = rand() % LEI;
		if (map[r][c] == 0) {
			//��û��Ϊ��
			map[r][c] = -1;
			i++;	//ÿ����һ�ξͼ�һ
		}
	}
	//������Ϊ���ĵľŹ������ݼ�1  �׳���
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			//�ж��ǲ�����
			if (map[i][j] == -1) {
				//������Χ�Ź���
				for (int m = i - 1; m <= i + 1; m++) {
					for (int n = j - 1; n <= j + 1; n++) {
						//����Χ�ĸ��Ӳ����׵�ʱ�����ݼ�һ 
						if ((m >= 0 && m <= ROW-1 && n >= 0 && n <= COL-1) && map[m][n] != -1)
							map[m][n]++;
					}
				}
			}
		}
	}
	//����ͼƬ,ͨ�������õ����ͼƬ
	for (int i = 0; i < 12; i++) {
		char str[50] = "";	//�洢ÿ���ַ���
		sprintf(str, "G:/C����/ɨ��/ɨ���ز�/image/%d.jpg", i);
		loadimage(&img[i], str,SIZE,SIZE);
	}
	//���ܸ���
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			map[i][j] += 20;
		}
	}
	//ShowMap();
}
//����ͼ�ν���
void GameDraw() {
	//cleardevice();
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			//������
			if (map[i][j] == -1) {
				//��ͼ
				putimage(j * SIZE, i * SIZE, &img[9]);
			}
			//�����������ּ��հ�
			else if (map[i][j] >= 0 && map[i][j] <= 8) {
				putimage(j * SIZE, i * SIZE, &img[map[i][j]]);
			}
			//putimage(j * SIZE, i * SIZE, &img[10]); ����ļ��ܲ���
			else if (map[i][j] >= 19 && map[i][j] <= 28) {
				putimage(j * SIZE, i * SIZE, &img[10]);
			}
			else if (map[i][j] > 30)//���
			{
				putimage(j * SIZE, i * SIZE, &img[11]);
			}
		}
	}
}
void openNull(int row, int col);
//������
int MouseControl() {

		//�ж���û�������Ϣ
	if (MouseHit()) {
		MOUSEMSG msg = GetMouseMsg();
		int row = msg.y / SIZE;	//���������ת��Ϊ�����±�
		int col = msg.x / SIZE;
		//�������Ϣ�ַ�
		switch (msg.uMsg) {
		case WM_LBUTTONDOWN:	
			/*
			�����������ʹ����״̬��ɽ���״̬
			*/
			if (map[row][col] > 8) {
				//����Ǽ���״̬,�ͽ���
				flag++;
				map[row][col] -= 20;
				openNull(row, col);
			}
			break;
		case WM_RBUTTONDOWN:	
			/*
			����Ҽ�������Բ�����ǣ��ٴε������ȡ��
			*/
			if (map[row][col] > 8 && map[row][col]<=28) {
				//��Ǹ���
				map[row][col] += 20;
			}
			else if (map[row][col] > 28) {
				//ֻ��û�򿪵Ĳſ���ȡ�����
				map[row][col] -= 20;
			}
			break;
		}
		return map[row][col];
	}
}
//�������Կհ�Ϊ���ĵľŹ���
void openNull(int row, int col) {
	//�ж��Ƿ��ǿհ�
	if (map[row][col] == 0) {
		//����ǿհ�
		for (int m = row - 1; m <= row + 1; m++) {
			for (int n = col - 1; n <= col + 1; n++) {
				//���û��Խ�磬��������Ϊ�ջ��߲�Ϊ�ף�����û�б���
				if ((m >= 0 && m <= ROW - 1 && n >= 0 && n <= COL - 1) &&
					(map[m][n] == 20 || map[m][n] != 19) && map[m][n] > 8)
				{
					map[m][n] -= 20;	//�Ͱ����Ƿ���
					flag++;
					openNull(m, n);	//�ݹ�ѭ��
				}
			}
		}
	}
}
//�ж���Ϸ��Ӯ
void GameOver() {
	if (MouseControl() == -1) {
		//����
		int isok=MessageBox(GetHWnd(), "�����ˣ��Ƿ�����һ��?", "��ʾ", MB_OKCANCEL);
		mciSendString("close BGM", 0, 0, 0);
		if (IDOK == isok) {
			//ȷ����
			//������һ��
			GameInit();
			flag = 0;
		}
		else {
			exit(666);
		}
	}
	if (flag == ROW * COL - LEI) {
		//Ӯ��
		int isok = MessageBox(GetHWnd(), "��ϲ��!��Ӯ��", "��ʾ", MB_OKCANCEL);
		mciSendString("close BGM", 0, 0, 0);
		if (IDOK == isok) {
			//ȷ����
			//������һ��
			GameInit();
			flag = 0;
		}
		else {
			exit(666);
		}
	}

}
//��ʾ��ά����
void ShowMap() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			printf("%3d  ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}
int main(void) {
	initgraph(ROW * SIZE, COL * SIZE);
	cleardevice();
	GameInit();

	BeginBatchDraw();
	while (1) {
		GameDraw();
		FlushBatchDraw();
		GameOver();
	}
	EndBatchDraw();
	system("pause");
	return 0;
}