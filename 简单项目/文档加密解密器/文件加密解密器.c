#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(int argc, char* argv[])
{
	int count = 0;
	for (int i = 1; i < argc; i++)
	{
		FILE* srcFp = fopen(argv[i], "rb");
		FILE* dstFp = fopen("temp.temp", "wb");
		if (srcFp == NULL || dstFp == NULL)
		{
			printf("错误!\n");
			system("pause");
			return 0;
		}
		printf("打开成功!\n");
		char str;	//读取的字符
		int num;	//单次读取的个数
		while (1)
		{
			num = fread(&str, 1, 1, srcFp);
			if (num > 0)
			{
				//读取有效
				str ^= 0x56;	//加密字符
				fwrite(&str, 1, num, dstFp);
				count++;
			}
			else
				break;
		}
		printf("加密成功!\n");
		fclose(srcFp);
		fclose(dstFp);

		//删除原文件
		DeleteFile(argv[i]);

		//加密后的文件改名为原文件
		MoveFile("temp.temp", argv[i]);

		printf("第%d个文件加密成功! 共处理%d字节. \n", i,count);
		count = 0;
	}
	printf("全部%d个文件加密完成!\n", argc-1);
	system("pause");
	return 0;
}
//C:/Users/于良浩/Desktop/dst.txt