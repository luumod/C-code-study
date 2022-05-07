#pragma once
/*
����ԭ��
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "contact.h"

/*
ѧ������ ѧ�� �Ա�  ���� ���ĳɼ� ��ѧ�ɼ� �ܳɼ� 
*/

//�˵�
void menu(void) {
	puts("******************��ӭ����ѧ����Ϣ����ϵͳ*****************");
	puts("******1.��ʼ��ѧ����Ϣ             2.�鿴����ѧ����Ϣ******");
	puts("*******3.�޸�ѧ����Ϣ             4.����ѧ����Ϣ***********");
	puts("*******5.���ĳ��ѧ��             6.���ĳɼ�����***********");
	puts("*******7.��ѧ�ɼ�����             8.ɾ������ѧ��***********");
	puts("*******0.�˳����� *****************************************");
	puts("***********************************************************");

}
int isempty(Node* head) {
	if (head == NULL)
		return 1; //����Ϊ��
	return 0;	//����Ϊ��
}
//��ʼ��ѧ����Ϣ
Node* Initial() {
	static int n;
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	Node* r = head;
	printf("������ѧ������: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("�������%d��ѧ����Ϣ: \n", i + 1);
		Node* s= (Node*)calloc(1,sizeof(Node));
		printf("������ѧ������: ");
		scanf("%s", s->people.name);
		printf("������ѧ��ѧ��: ");
		scanf("%ld", &s->people.number);
		printf("������ѧ���Ա�: ");
		scanf("%s", s->people.sex);
		printf("������ѧ������: ");
		scanf("%d", &s->people.age);
		printf("������ѧ�����ĳɼ�: ");
		scanf("%d", &s->people.chinese);
		printf("������ѧ����ѧ�ɼ�: ");
		scanf("%d", &s->people.math);
		s->people.all = s->people.chinese + s->people.math;
		//β�巨
		r->next = s;
		s->next = NULL;
		r = s;
	}
	printf("ѧ����Ϣ�������\n");
	return head;
}


//�鿴����ѧ����Ϣ
void look(Node* head) {
	if (head == NULL) {
		printf("���Ƚ��г�ʼ��!\n");
	}
	else {
		printf("��ʾ����ѧ����Ϣ:\n");
		Node* p = head->next;
		//printf("����\t\tѧ��\t\t\t�Ա�\t\t����\t\t���ĳɼ�\t\t��ѧ�ɼ�\t�ܳɼ�\n");
		printf("%20s\t%8s\t%4s\t%4s\t%4s\t%4s\t%4s\n", "����", "ѧ��", "�Ա�", "����",
			"���ĳɼ�", "��ѧ�ɼ�", "�ܳɼ�");
		while (p) {
			printf("%20s\t%8ld\t%4s\t%4d\t%4d\t%12d\t%12d\n", p->people.name, p->people.number, p->people.sex, p->people.age,
				p->people.chinese, p->people.math, p->people.all);
			p = p->next;
		}
	}
}

//�޸�ĳ��ѧ����Ϣ
void change(Node* head) {
	if (head == NULL) {
		printf("���Ƚ��г�ʼ��!\n");
	}
	else {
		static int number, count = 0, choice;
		static name[NAME];
		Node* p = head->next;
		printf("��������Ҫ�޸ĵ�ѧ������:\n");
		scanf("%s", name);
		while (p) {
			//����ָ��������ѧ�������ҵ��˾��˳�
			if (strcmp(name, p->people.name) == 0) {
				count = 1;
				break;
			}
			p = p->next;
		}
		if (count) {
			printf("%20s\t%8s\t%4s\t%4s\t%4s\t%4s\t%4s\n", "����", "ѧ��", "�Ա�", "����",
				"���ĳɼ�", "��ѧ�ɼ�", "�ܳɼ�");
			printf("%20s\t%8ld\t%4s\t%4d\t%4d\t%12d\t%12d\n", p->people.name, p->people.number, p->people.sex, p->people.age,
				p->people.chinese, p->people.math, p->people.all);
			printf("����Ҫ�޸���һ�1.���� 2.ѧ��3.�Ա�4.���� 5.���ĳɼ� 6.��ѧ�ɼ� 0.���ز˵�\n");
			scanf("%d", &choice);
			getchar();
			do {
				switch (choice) {
				case 1:printf("�������޸ĺ������: ");
					scanf("%s", p->people.name);
					printf("�޸ĳɹ�!");
					break;
				case 2:printf("�������޸ĺ��ѧ��: ");
					scanf("%ld", &p->people.number);
					printf("�޸ĳɹ�!");
					break;
				case 3:printf("�������޸ĺ���Ա�: ");
					scanf("%s", p->people.sex);
					printf("�޸ĳɹ�!");
					break;
				case 4:printf("�������޸ĺ������: ");
					scanf("%d", &p->people.age);
					printf("�޸ĳɹ�!");
					break;
				case 5:printf("�������޸ĺ�����ĳɼ�: ");
					scanf("%d", &p->people.chinese);
					printf("�޸ĳɹ�!");
					break;
				case 6:printf("�������޸ĺ����ѧ�ɼ�: ");
					scanf("%d", &p->people.math);
					printf("�޸ĳɹ�!");
					break;
				case 0:printf("�˻ز˵�\n");
					break;
				default:break;
				}
				printf("�㻹��Ҫ�޸���һ�1.���� 2.ѧ��3.�Ա�4.���� 5.���ĳɼ� 6.��ѧ�ɼ� 0.���ز˵�\n");
				scanf("%d", &choice);
				getchar();
			} while (choice != 0);
		}
		else
			printf("û���ҵ���ѧ��\n");
	}
}

//����ĳ��ѧ�� (ѧ�� ������
void reasch(Node* head) {
	if (head == NULL) {
		printf("���Ƚ��г�ʼ��!\n");
	}
	else {
		static int number;
		int count = 0;
		static name[NAME];
		Node* p = head->next;
		printf("��������Ҫ�鿴�ĵ�ѧ������:\n");
		scanf("%s", name);
		while (p) {
			//����ָ��������ѧ�������ҵ��˾��˳�
			if (strcmp(name, p->people.name) == 0) {
				count = 1;
				break;
			}
			p = p->next;
		}
		if (count) {
			printf("���ҳɹ�!\n");
			printf("%20s\t%8s\t%4s\t%4s\t%4s\t%4s\t%4s\n", "����", "ѧ��", "�Ա�", "����",
				"���ĳɼ�", "��ѧ�ɼ�", "�ܳɼ�");
			printf("%20s\t%8ld\t%4s\t%4d\t%4d\t%12d\t%12d\n", p->people.name, p->people.number, p->people.sex, p->people.age,
				p->people.chinese, p->people.math, p->people.all);
		}
		else
			printf("û���ҵ���ѧ��!\n");
	}
}

//���ѧ����Ϣ
void add(Node* head){	
	//β�巨���µĽڵ���ӵ�ĩβ
	if (head == NULL) {
		printf("���Ƚ��г�ʼ��!\n");
	}
	else {

		int count = 0;
		Node* p = head->next;
		Node* r = head->next;
		Node* s = (Node*)malloc(sizeof(Node));
		printf("��������Ҫ��ӵ�ѧ������:");
		scanf("%s", s->people.name);
		printf("��������Ҫ��ӵ�ѧ��ѧ��:");
		scanf("%ld", &s->people.number);
		printf("��������Ҫ��ӵ�ѧ���Ա�:");
		scanf("%s", s->people.sex);
		printf("��������Ҫ��ӵ�ѧ������:");
		scanf("%d", &s->people.age);
		printf("��������Ҫ��ӵ�ѧ�����ĳɼ�:");
		scanf("%d", &s->people.chinese);
		printf("��������Ҫ��ӵ�ѧ����ѧ�ɼ�:");
		scanf("%d", &s->people.math);
		s->people.all = s->people.math + s->people.chinese;
		while (p) {
			count++;
			p = p->next;
		}
		//�ƶ������λ��
		for (int i = 0; i < count - 1; i++) {
			r = r->next;
		}
		r->next = s;
		s->next = NULL;
		r = s;
		printf("ѧ����Ϣ������\n");
	}
}
void del_all(Node* head) {
	//ɾ������ѧ��(�ڵ�)
	Node* p = head->next;
	Node* q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	head->next= NULL;
}
//���ĳɼ�����
void sqrt_chi(Node* head) {
	//�Ӵ�С���ĳɼ�����
	if (head == NULL) {
		printf("���Ƚ��г�ʼ��!\n");
	}
	else {
		Node* p = head->next;
		Node* q = p->next;
		Node* temp = head;
		for (p = head->next; p != NULL; p = p->next) {
			for (q = p->next; q != NULL; q = q->next) {
				if (p->people.chinese < q->people.chinese) {
					sort(temp, p);
					sort(p, q);
					sort(q, temp);
				}
			}
		}
		printf("���ĳɼ�����ɹ�!\n");
	}
}
//��ѧ�ɼ�����
void sqrt_math(Node* head) {
	//�Ӵ�С��ѧ�ɼ�����
	if (head == NULL) {
		printf("���Ƚ��г�ʼ��!\n");
	}
	else {
		Node* p = head->next;
		Node* q = p->next;
		Node* temp = head;
		for (p = head->next; p != NULL; p = p->next) {
			for (q = p->next; q != NULL; q = q->next) {
				if (p->people.math < q->people.math) {
					sort(temp, p);
					sort(p, q);
					sort(q, temp);
				}
			}
		}
		printf("��ѧ�ɼ�����ɹ�!\n");
	}
}
void sqrt_all(Node* head) {
	//�Ӵ�С�ܳɼ��ɼ�����
	if (head == NULL) {
		printf("���Ƚ��г�ʼ��!\n");
	}
	else {
		Node* p = head->next;
		Node* q = p->next;
		Node* temp = head;
		for (p = head->next; p != NULL; p = p->next) {
			for (q = p->next; q != NULL; q = q->next) {
				if (p->people.all < q->people.all) {
					sort(temp, p);
					sort(p, q);
					sort(q, temp);
				}
			}
		}
		printf("�ܳɼ�����ɹ�!\n");
	}
}
void sort(Node* p, Node* q) {
	strcpy(p->people.name, q->people.name);
	p->people.number = q->people.number;
	strcpy(p->people.sex, q->people.sex);
	p->people.age = q->people.age;
	p->people.chinese = q->people.chinese;
	p->people.math = q->people.math;
	p->people.all = q->people.all;
}
