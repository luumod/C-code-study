#include <stdio.h>
#include <windows.h>
int main(int argc, char* argv[]) {
	char dstFileName[60] = { 0 };
	//2 打开两个文件
	for (int i = 1; i < argc; i++)
	{

		FILE* scpFp = fopen(argv[i], "rb");
		FILE* dstFp = fopen("qs.dk", "wb");
		if (NULL == scpFp || NULL == dstFp) {
			printf("打开失败!\n");
		}
		else {
			printf("打开成功!\n");
		}
		//3 循环读取 要拷贝的文件的内容 并写入到拷贝后的文件中
		char c;	int r;
		while (1) {
			r = fread(&c, 1, 1, scpFp);
			if (r < 1) {//没读到
				break;
			}
			//加密
			c ^= 0x56;

			fwrite(&c, 1, 1, dstFp);
		}
		//4 关闭两个文件
		fclose(scpFp);
		fclose(dstFp);

		//5 删掉 argv[1](待加密文件)
		DeleteFile(argv[1]);

		//6 把 "qs.dk"(加密后文件) 改名成 argv[1](待加密文件)
		MoveFile("qs.dk", argv[1]);
	}
}