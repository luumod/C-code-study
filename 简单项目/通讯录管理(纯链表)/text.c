/*
ͨѶ¼����
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.c"


int main(void) {
	int choice=0, cho;
	char name[NAME];
	Node* p = InitialList();
	INFO data;
	do {
		menu();
		printf("��������Ҫִ�еĲ���: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice) {
		case SHOW://��ʾȫ����Ա��Ϣ
			printf("��ʾȫ����Ա��Ϣ:\n");
			ShowList(p);
			system("pause");
			system("cls");
			break;
		case ADD://�����Ա��Ϣ
			printf("���һ����Ա");
			printf("��������Ա����:");
			scanf("%s", data.name);
			printf("��������Ա�绰:");
			scanf("%s", data.s);
			printf("��������Ա�Ա�:");
			scanf("%s", data.sex);
			printf("��������Ա��ַ:");
			scanf("%s", data.address);
			//������Ϣ������Ϣ���ͷ���봴���ڵ�ĺ���
			Insertnode(p, data);
			system("pause");
			system("cls");
			break;
		case DEL://ɾ��һ���˵���Ϣ
			printf("��������Ҫɾ�����˵�����:");
			scanf("%s", name);
			DelOneLits(p,name);
			system("pause");
			system("cls");
			break;
		case SEARCH://����
			printf("��������Ҫ���ҵ�����:");
			scanf("%s", name);
			SreachList(p, name);
			system("pause");
			system("cls");
			break;
		case TO_FILE: //������Ϣ���ļ�
			TO_silt(p);
			system("pause");
			system("cls");
			break;
		case IN_FILE: //���ļ���ȡ
			IN_silt(p);
			system("pause");
			system("cls");
			break;
		case QUIT://�˳�����
			exit(EXIT_SUCCESS);
		default:printf("����������:");
		}
	} while (choice != QUIT);

	return 0;
}