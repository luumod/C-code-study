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
			printf("����!\n");
			system("pause");
			return 0;
		}
		printf("�򿪳ɹ�!\n");
		char str;	//��ȡ���ַ�
		int num;	//���ζ�ȡ�ĸ���
		while (1)
		{
			num = fread(&str, 1, 1, srcFp);
			if (num > 0)
			{
				//��ȡ��Ч
				str ^= 0x56;	//�����ַ�
				fwrite(&str, 1, num, dstFp);
				count++;
			}
			else
				break;
		}
		printf("���ܳɹ�!\n");
		fclose(srcFp);
		fclose(dstFp);

		//ɾ��ԭ�ļ�
		DeleteFile(argv[i]);

		//���ܺ���ļ�����Ϊԭ�ļ�
		MoveFile("temp.temp", argv[i]);

		printf("��%d���ļ����ܳɹ�! ������%d�ֽ�. \n", i,count);
		count = 0;
	}
	printf("ȫ��%d���ļ��������!\n", argc-1);
	system("pause");
	return 0;
}
//C:/Users/������/Desktop/dst.txt