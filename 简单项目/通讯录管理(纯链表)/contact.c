#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <errno.h>


void menu() {
	puts("*******************ͨѶ¼����*********************");
	puts("********1.�鿴���г�Ա��Ϣ     2.���һ����Ա*****");
	puts("********3.ɾ��һ����Ա��Ϣ     4.����һ����Ա*****");
	puts("********5.���浽�ļ�           6.�����ļ�*********");
	puts("********0.�˳�����             *******************");
	puts("**************************************************");

}

//��ʼ���ڵ�
Node* InitialList() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		fprintf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	head->next = NULL;
	return head;
}

Node* Createnode(INFO data) {
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) {
		fprintf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	//�µĽڵ�ָ�������������
	s->people = data;
	s->next = NULL;
	return s;
}

//�����µĽڵ�
void Insertnode(Node* head,INFO data) {
	//������Ա�ڵ�
	Node* s = Createnode(data);
	//��������ͷ�巨
	s->next = head->next;
	head->next = s;
}

//��ʾ����
void ShowList(Node* head) {
	Node* p = head->next;
	printf("%20s\t%20s\t%5s\t%20s\n", "����", "�绰", "�Ա�", "��ַ");
	while (p) {
		printf("%20s\t%20s\t%5s\t%20s\n", p->people.name, p->people.s, p->people.sex,
			p->people.address);
		p = p->next;
	}
	printf("��ʾ���\n");
}

//ɾ��һ���ڵ�
void DelOneLits(Node* head, char* name) {
	//����ɾ���ı�־
	Node* p = head->next;
	Node* q = head;	//p��ǰ���ڵ�
	if (p == NULL) {
		printf("û����Ա��Ϣ!\n");
		return;
	}
	while (strcmp(p->people.name,name)!=0) {
		q = p;
		p = p->next;
		if (p->next == NULL) {
			printf("û���ҵ��ó�Ա\n");
			return;
		}
	}
	q->next = p->next;
	free(p);
	printf("����%s : ɾ���ɹ�!\n", name);
}

//����һ���ڵ�
void SreachList(Node* head, char* name) {

	Node* p = head->next;
	if (p == NULL) {
		printf("û����Ա��Ϣ!\n");
		return;
	}
	while (p) {
		if (!strcmp(p->people.name,name)) {
			printf("���ҳɹ�!\n");
			printf("%20s\t%20s\t%5s\t%20s\n", "����", "�绰", "�Ա�", "��ַ");
			printf("%20s\t%20s\t%5s\t%20s\n", p->people.name, p->people.s, p->people.sex,
				p->people.address);
			return;
		}
		p = p->next;
	}
	printf("����ʧ��!\n");
}

//������Ϣ���ļ�
void TO_silt(Node* head) {
	FILE* fp1;
	Node* p = head->next;
	if ((fp1 = fopen("ͨѶ¼.txt", "w")) == NULL) {
		fp1 = fopen("ͨѶ¼.txt", "w+");
	}
	fprintf(fp1, "%20s\t%20s\t%5s\t%20s\n", "����", "�绰", "�Ա�", "��ַ");
	while (p) {
		fprintf(fp1, "%20s\t%20s\t%5s\t%20s\n", p->people.name, p->people.s, p->people.sex,
			p->people.address);
		p = p->next;
	}
	printf("����ɹ�!\n");
	fclose(fp1);
}

//���ļ���ȡ
void IN_silt(Node* head) {
	FILE* fp1;
	INFO data;
	if ((fp1 = fopen("ͨѶ¼.txt", "r+")) == NULL) {
		fprintf(stderr,"û������ļ�\n");
		return;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	while (fscanf(fp1, "%s %s %s %s", data.name,data.s,data.sex,data.address)==4){
		Insertnode(head, data);
	}
	printf("����ɹ�!\n");
	fclose(fp1);
}