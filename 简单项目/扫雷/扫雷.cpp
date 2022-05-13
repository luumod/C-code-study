/*
扫雷 
1.二维数组
2.贴图, 把数字转换为图片，加密，标记
3.鼠标操作 点击打开格子
4.点到格子后，显示周围的格子
5.判断游戏输赢
6.音乐 分数
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//定义图片高宽
#define SIZE 50
//定义行列
#define ROW 10
#define COL 10
//雷的数量
#define LEI 10
int map[ROW][COL];		//全局变量自动初始化0
IMAGE img[12];			//定义图片数组，保存图片
int flag = 0;	//游戏胜利标志
void ShowMap();
//设置游戏音乐
void Music() {
	//打开音乐
	mciSendString("open G:\\C语言\\扫雷\\扫雷素材\\11638.mp3 alias BGM", 0, 0, 0);
	//播放音乐
	mciSendString("play BGM", 0, 0, 0);
}
//游戏数据初始化
void GameInit() {
	//设置随机数种子
	srand(time(0));

	Music();

	//初始化数组
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			map[i][j] = 0;
		}
	}
	//埋雷,用-1表示雷  随机数
	for (int i = 0; i < LEI;) {
		//有可能会出现重复
		int r = rand() % LEI;
		int c = rand() % LEI;
		if (map[r][c] == 0) {
			//还没有为雷
			map[r][c] = -1;
			i++;	//每埋雷一次就加一
		}
	}
	//把以雷为中心的九宫格数据加1  雷除外
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			//判断是不是雷
			if (map[i][j] == -1) {
				//遍历周围九宫格
				for (int m = i - 1; m <= i + 1; m++) {
					for (int n = j - 1; n <= j + 1; n++) {
						//当周围的格子不是雷的时候，数据加一 
						if ((m >= 0 && m <= ROW-1 && n >= 0 && n <= COL-1) && map[m][n] != -1)
							map[m][n]++;
					}
				}
			}
		}
	}
	//记载图片,通过遍历得到多个图片
	for (int i = 0; i < 12; i++) {
		char str[50] = "";	//存储每个字符串
		sprintf(str, "G:/C语言/扫雷/扫雷素材/image/%d.jpg", i);
		loadimage(&img[i], str,SIZE,SIZE);
	}
	//加密格子
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			map[i][j] += 20;
		}
	}
	//ShowMap();
}
//绘制图形界面
void GameDraw() {
	//cleardevice();
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			//绘制雷
			if (map[i][j] == -1) {
				//贴图
				putimage(j * SIZE, i * SIZE, &img[9]);
			}
			//处理其他数字及空白
			else if (map[i][j] >= 0 && map[i][j] <= 8) {
				putimage(j * SIZE, i * SIZE, &img[map[i][j]]);
			}
			//putimage(j * SIZE, i * SIZE, &img[10]); 错误的加密操作
			else if (map[i][j] >= 19 && map[i][j] <= 28) {
				putimage(j * SIZE, i * SIZE, &img[10]);
			}
			else if (map[i][j] > 30)//标记
			{
				putimage(j * SIZE, i * SIZE, &img[11]);
			}
		}
	}
}
void openNull(int row, int col);
//鼠标操作
int MouseControl() {

		//判断有没有鼠标消息
	if (MouseHit()) {
		MOUSEMSG msg = GetMouseMsg();
		int row = msg.y / SIZE;	//把鼠标坐标转换为数组下标
		int col = msg.x / SIZE;
		//对鼠标消息分发
		switch (msg.uMsg) {
		case WM_LBUTTONDOWN:	
			/*
			鼠标左键点击，使加密状态变成解密状态
			*/
			if (map[row][col] > 8) {
				//如果是加密状态,就解密
				flag++;
				map[row][col] -= 20;
				openNull(row, col);
			}
			break;
		case WM_RBUTTONDOWN:	
			/*
			鼠标右键点击可以产生标记，再次点击可以取消
			*/
			if (map[row][col] > 8 && map[row][col]<=28) {
				//标记格子
				map[row][col] += 20;
			}
			else if (map[row][col] > 28) {
				//只有没打开的才可以取消标记
				map[row][col] -= 20;
			}
			break;
		}
		return map[row][col];
	}
}
//打开所有以空白为中心的九宫格
void openNull(int row, int col) {
	//判断是否是空白
	if (map[row][col] == 0) {
		//点的是空白
		for (int m = row - 1; m <= row + 1; m++) {
			for (int n = col - 1; n <= col + 1; n++) {
				//如果没有越界，并且数字为空或者不为雷，并且没有被打开
				if ((m >= 0 && m <= ROW - 1 && n >= 0 && n <= COL - 1) &&
					(map[m][n] == 20 || map[m][n] != 19) && map[m][n] > 8)
				{
					map[m][n] -= 20;	//就把他们翻开
					flag++;
					openNull(m, n);	//递归循环
				}
			}
		}
	}
}
//判断游戏输赢
void GameOver() {
	if (MouseControl() == -1) {
		//输了
		int isok=MessageBox(GetHWnd(), "你输了，是否再玩一次?", "提示", MB_OKCANCEL);
		mciSendString("close BGM", 0, 0, 0);
		if (IDOK == isok) {
			//确定，
			//重新玩一次
			GameInit();
			flag = 0;
		}
		else {
			exit(666);
		}
	}
	if (flag == ROW * COL - LEI) {
		//赢了
		int isok = MessageBox(GetHWnd(), "恭喜你!你赢了", "提示", MB_OKCANCEL);
		mciSendString("close BGM", 0, 0, 0);
		if (IDOK == isok) {
			//确定，
			//重新玩一次
			GameInit();
			flag = 0;
		}
		else {
			exit(666);
		}
	}

}
//显示二维数组
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