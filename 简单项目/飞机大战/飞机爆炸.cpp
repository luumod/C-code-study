#include <stdio.h>
#include <easyx.h>

//���ȶ���һ�±�ը��
IMAGE boomMaskImg[6];  //6������ͼ
IMAGE boomSrcImg[6];   //6��ԭͼͼ
struct Boom
{
	int frame;  //��ը֡������
	int x, y;   //��ը����ֵ�λ��

}boom[5];  //����5�� �п���ͬʱ���ж���ɻ���ը



int main()
{
	initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();
	//�Ȱ�ͼƬ���ؽ���
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
		//����
		BeginBatchDraw();
		cleardevice();
		for (int i = 0; i < 5; i++) //�ҵ����ڱ�ը��
		{
			if (boom[i].frame != 0)  //Ϊ0 ��˵�����Ǳ�ը״̬
			{
				//һ��6��ͼƬ �Ӵ�����ը��ʼ 1-120֡���Ƶ�1��ͼƬ  121-240���Ƶڶ��� ������
				putimage(boom[i].x, boom[i].y, &boomMaskImg[boom[i].frame / 80], SRCPAINT);
				putimage(boom[i].x, boom[i].y, &boomSrcImg[boom[i].frame / 80], SRCAND);
				
				boom[i].frame++;
				if (boom[i].frame >= 80*6) //��֡������80*6˵��6��ͼƬ���Ѿ����ƽ���
				{
					boom[i].frame = 0;  //��ը��ȴ���һ�α�ը
				}
			}
		}
		EndBatchDraw();


		//����
		ExMessage m;
		peekmessage(&m, EM_MOUSE);
		if (m.message == WM_LBUTTONDOWN)  //�������
		{
			for (int i = 0; i < 5; i++) //5��������һ��
			{
				if (boom[i].frame == 0) //��û��ը
				{
					boom[i].x = m.x; //��ը�������λ��
					boom[i].y = m.y;
					boom[i].frame = 1; //��ʼ��ը
					break;
				}
			}
		}
	}
	return 0;
}