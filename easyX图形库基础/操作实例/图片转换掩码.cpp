#include <stdio.h>
#include <graphics.h>
int main(void)
{

	char str[1000] = {0};
	char str1[1000] ="yanma.png";//bվ�Ὣ���Ÿ�ɾ��
	printf("��������Ҫ�����ͼƬ�����֣���Ҫ�����ļ��ĸ�ʽ \n");
	printf("���ͼƬ��·���͸ó���·����һ�µĻ�����Ҫ�������·�����ļ���ʽ���ǣ�jpg��png��ico��\n");
	printf("�����룺\n");
	scanf("%s", str);

	IMAGE img;
	loadimage(&img, _T(str));
	unsigned long color;
	DWORD* p = GetImageBuffer(&img);
	color = p[0];
	int w = img.getwidth();
	int h = img.getheight();
	for (int i = 1; i <w * h; ++i)
	{
		color == p[i] ? p[i] = WHITE : p[i] = BLACK;
	}
	strcat(str1, str);
	saveimage(_T(str1), &img);//����Ϊ��ָ��img�ĵ�ַ��ʼ������һƬ�ռ�����ݱ���Ϊ������1��.png �ļ�
	printf("�Ѿ�Ϊ���ڳ�����ļ��д�������Ϊ����ͼƬ��ͷ��ͼƬ�ļ��������û�ҵ���˵�������д�����ý�ͼƬ�ͳ���ŵ�ͬһĿ¼�£������Ͳ��������\n");
	return 0;
}