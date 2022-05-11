#include <stdio.h>
#include <graphics.h>
int main(void)
{

	char str[1000] = {0};
	char str1[1000] ="yanma.png";//b站会将引号给删了
	printf("请输入你要掩码的图片的名字，需要加上文件的格式 \n");
	printf("如果图片的路径和该程序路径不一致的话，需要输入绝对路径，文件格式就是：jpg，png，ico等\n");
	printf("请输入：\n");
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
	saveimage(_T(str1), &img);//功能为将指向img的地址开始的以那一片空间的内容保存为：人物1改.png 文件
	printf("已经为您在程序的文件夹创建了名为掩码图片开头的图片文件！如果你没找到，说明程序有错误，最好将图片和程序放到同一目录下，那样就不会出错了\n");
	return 0;
}