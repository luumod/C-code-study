/*
ѧ����Ϣ����ϵͳ
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "contact.h"
#include "contact.c"


int main(void) {
	int choice, num;
	Node* p=NULL, * head;
	menu();
	if (isempty(p)) {
		printf("���Ƚ��г�ʼ��!\n");
		p = Initial();
	}
	do {
		menu();
		printf("��������Ҫִ�еĲ���:\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {
		case Initialize:
			if (p->next==NULL)
				//�ж������Ƿ�Ϊ��
				p = Initial();	//����
			else
				printf("����Ҫ��ʼ����!\n");
			break;
		case VallStuinfo:look(p);	//��ʾ
			break;
		case Modify:change(p);	//�޸�
			break;
		case Find:reasch(p);	//����
			break;
		case Add:add(p);		//��� 
			break;
		case Chinese:sqrt_chi(p);	//���ĳɼ�
			break;
		case Math:sqrt_math(p);//��ѧ�ɼ�
			break;
		case Del:del_all(p);	//ɾ��ѧ����¼
			break;
		case Quit:printf("�˳����򣬻�ӭʹ��\n");
			exit(EXIT_SUCCESS);
		default:break;
		}

	} while (choice != 0);
	return 0;
}









