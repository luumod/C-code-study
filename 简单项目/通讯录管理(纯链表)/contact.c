#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <errno.h>


void menu() {
	puts("*******************通讯录管理*********************");
	puts("********1.查看所有成员信息     2.添加一个成员*****");
	puts("********3.删除一个成员信息     4.查找一个成员*****");
	puts("********5.保存到文件           6.导入文件*********");
	puts("********0.退出程序             *******************");
	puts("**************************************************");

}

//初始化节点
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
	//新的节点指向你输入的数据
	s->people = data;
	s->next = NULL;
	return s;
}

//插入新的节点
void Insertnode(Node* head,INFO data) {
	//创建人员节点
	Node* s = Createnode(data);
	//连接链表，头插法
	s->next = head->next;
	head->next = s;
}

//显示链表
void ShowList(Node* head) {
	Node* p = head->next;
	printf("%20s\t%20s\t%5s\t%20s\n", "姓名", "电话", "性别", "地址");
	while (p) {
		printf("%20s\t%20s\t%5s\t%20s\n", p->people.name, p->people.s, p->people.sex,
			p->people.address);
		p = p->next;
	}
	printf("显示完毕\n");
}

//删除一个节点
void DelOneLits(Node* head, char* name) {
	//给出删除的标志
	Node* p = head->next;
	Node* q = head;	//p的前驱节点
	if (p == NULL) {
		printf("没有人员信息!\n");
		return;
	}
	while (strcmp(p->people.name,name)!=0) {
		q = p;
		p = p->next;
		if (p->next == NULL) {
			printf("没有找到该成员\n");
			return;
		}
	}
	q->next = p->next;
	free(p);
	printf("姓名%s : 删除成功!\n", name);
}

//查找一个节点
void SreachList(Node* head, char* name) {

	Node* p = head->next;
	if (p == NULL) {
		printf("没有人员信息!\n");
		return;
	}
	while (p) {
		if (!strcmp(p->people.name,name)) {
			printf("查找成功!\n");
			printf("%20s\t%20s\t%5s\t%20s\n", "姓名", "电话", "性别", "地址");
			printf("%20s\t%20s\t%5s\t%20s\n", p->people.name, p->people.s, p->people.sex,
				p->people.address);
			return;
		}
		p = p->next;
	}
	printf("查找失败!\n");
}

//保存信息到文件
void TO_silt(Node* head) {
	FILE* fp1;
	Node* p = head->next;
	if ((fp1 = fopen("通讯录.txt", "w")) == NULL) {
		fp1 = fopen("通讯录.txt", "w+");
	}
	fprintf(fp1, "%20s\t%20s\t%5s\t%20s\n", "姓名", "电话", "性别", "地址");
	while (p) {
		fprintf(fp1, "%20s\t%20s\t%5s\t%20s\n", p->people.name, p->people.s, p->people.sex,
			p->people.address);
		p = p->next;
	}
	printf("保存成功!\n");
	fclose(fp1);
}

//从文件读取
void IN_silt(Node* head) {
	FILE* fp1;
	INFO data;
	if ((fp1 = fopen("通讯录.txt", "r+")) == NULL) {
		fprintf(stderr,"没有这个文件\n");
		return;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	while (fscanf(fp1, "%s %s %s %s", data.name,data.s,data.sex,data.address)==4){
		Insertnode(head, data);
	}
	printf("导入成功!\n");
	fclose(fp1);
}