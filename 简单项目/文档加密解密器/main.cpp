#include <stdio.h>
#include <windows.h>
int main(int argc, char* argv[]) {
	char dstFileName[60] = { 0 };
	//2 �������ļ�
	for (int i = 1; i < argc; i++)
	{

		FILE* scpFp = fopen(argv[i], "rb");
		FILE* dstFp = fopen("qs.dk", "wb");
		if (NULL == scpFp || NULL == dstFp) {
			printf("��ʧ��!\n");
		}
		else {
			printf("�򿪳ɹ�!\n");
		}
		//3 ѭ����ȡ Ҫ�������ļ������� ��д�뵽��������ļ���
		char c;	int r;
		while (1) {
			r = fread(&c, 1, 1, scpFp);
			if (r < 1) {//û����
				break;
			}
			//����
			c ^= 0x56;

			fwrite(&c, 1, 1, dstFp);
		}
		//4 �ر������ļ�
		fclose(scpFp);
		fclose(dstFp);

		//5 ɾ�� argv[1](�������ļ�)
		DeleteFile(argv[1]);

		//6 �� "qs.dk"(���ܺ��ļ�) ������ argv[1](�������ļ�)
		MoveFile("qs.dk", argv[1]);
	}
}