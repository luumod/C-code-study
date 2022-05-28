#include <stdio.h>
#include <easyx.h>

//首先定义一下爆炸体
IMAGE boomMaskImg[6];  //6张遮罩图
IMAGE boomSrcImg[6];   //6张原图图
struct Boom
{
	int frame;  //爆炸帧数控制
	int x, y;   //爆炸体出现的位置

}boom[5];  //定义5个 有可能同时会有多个飞机爆炸



int main()
{
	initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();
	//先把图片加载进来
	char str1[50],str2[50];
	for (int i = 0; i < 6; i++)
	{
		sprintf(str1, ".\\images\\Yboom%d.png", i + 1);
		sprintf(str2, ".\\images\\boom%d.png", i + 1);
		loadimage(&boomMaskImg[i], str1, 93, 75);
		loadimage(&boomSrcImg[i], str2, 93, 75);
	}

	while (1)
	{
		//绘制
		BeginBatchDraw();
		cleardevice();
		for (int i = 0; i < 5; i++) //找到正在爆炸的
		{
			if (boom[i].frame != 0)  //为0 就说明不是爆炸状态
			{
				//一共6张图片 从触发爆炸开始 1-120帧绘制第1张图片  121-240绘制第二张 。。。
				putimage(boom[i].x, boom[i].y, &boomMaskImg[boom[i].frame / 80], SRCPAINT);
				putimage(boom[i].x, boom[i].y, &boomSrcImg[boom[i].frame / 80], SRCAND);
				
				boom[i].frame++;
				if (boom[i].frame >= 80*6) //当帧数超过80*6说明6张图片都已经绘制结束
				{
					boom[i].frame = 0;  //爆炸体等待下一次爆炸
				}
			}
		}
		EndBatchDraw();


		//触发
		ExMessage m;
		peekmessage(&m, EM_MOUSE);
		if (m.message == WM_LBUTTONDOWN)  //左键触发
		{
			for (int i = 0; i < 5; i++) //5个里面找一个
			{
				if (boom[i].frame == 0) //还没爆炸
				{
					boom[i].x = m.x; //爆炸点在鼠标位置
					boom[i].y = m.y;
					boom[i].frame = 1; //开始爆炸
					break;
				}
			}
		}
	}
	return 0;
}
aaaaaaaaaaaaaaaaaaaaaa





aaaaaaaaaaaaa
aaa
aa

aa

a
a
