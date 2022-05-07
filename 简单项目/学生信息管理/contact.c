#pragma once
/*
函数原型
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "contact.h"

/*
学生姓名 学号 性别  年龄 语文成绩 数学成绩 总成绩 
*/

//菜单
void menu(void) {
	puts("******************欢迎进入学生信息管理系统*****************");
	puts("******1.初始化学生信息             2.查看所有学生信息******");
	puts("*******3.修改学生信息             4.查找学生信息***********");
	puts("*******5.添加某个学生             6.语文成绩排序***********");
	puts("*******7.数学成绩排序             8.删除所有学生***********");
	puts("*******0.退出程序 *****************************************");
	puts("***********************************************************");

}
int isempty(Node* head) {
	if (head == NULL)
		return 1; //链表为空
	return 0;	//链表不为空
}
//初始化学生信息
Node* Initial() {
	static int n;
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	Node* r = head;
	printf("请输入学生人数: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("请输入第%d个学生信息: \n", i + 1);
		Node* s= (Node*)calloc(1,sizeof(Node));
		printf("请输入学生姓名: ");
		scanf("%s", s->people.name);
		printf("请输入学生学号: ");
		scanf("%ld", &s->people.number);
		printf("请输入学生性别: ");
		scanf("%s", s->people.sex);
		printf("请输入学生年龄: ");
		scanf("%d", &s->people.age);
		printf("请输入学生语文成绩: ");
		scanf("%d", &s->people.chinese);
		printf("请输入学生数学成绩: ");
		scanf("%d", &s->people.math);
		s->people.all = s->people.chinese + s->people.math;
		//尾插法
		r->next = s;
		s->next = NULL;
		r = s;
	}
	printf("学生信息输入完成\n");
	return head;
}


//查看所有学生信息
void look(Node* head) {
	if (head == NULL) {
		printf("请先进行初始化!\n");
	}
	else {
		printf("显示所有学生信息:\n");
		Node* p = head->next;
		//printf("姓名\t\t学号\t\t\t性别\t\t年龄\t\t语文成绩\t\t数学成绩\t总成绩\n");
		printf("%20s\t%8s\t%4s\t%4s\t%4s\t%4s\t%4s\n", "姓名", "学号", "性别", "年龄",
			"语文成绩", "数学成绩", "总成绩");
		while (p) {
			printf("%20s\t%8ld\t%4s\t%4d\t%4d\t%12d\t%12d\n", p->people.name, p->people.number, p->people.sex, p->people.age,
				p->people.chinese, p->people.math, p->people.all);
			p = p->next;
		}
	}
}

//修改某个学生信息
void change(Node* head) {
	if (head == NULL) {
		printf("请先进行初始化!\n");
	}
	else {
		static int number, count = 0, choice;
		static name[NAME];
		Node* p = head->next;
		printf("请输入你要修改的学生姓名:\n");
		scanf("%s", name);
		while (p) {
			//查找指定姓名的学生，查找到了就退出
			if (strcmp(name, p->people.name) == 0) {
				count = 1;
				break;
			}
			p = p->next;
		}
		if (count) {
			printf("%20s\t%8s\t%4s\t%4s\t%4s\t%4s\t%4s\n", "姓名", "学号", "性别", "年龄",
				"语文成绩", "数学成绩", "总成绩");
			printf("%20s\t%8ld\t%4s\t%4d\t%4d\t%12d\t%12d\n", p->people.name, p->people.number, p->people.sex, p->people.age,
				p->people.chinese, p->people.math, p->people.all);
			printf("你想要修改哪一项：1.姓名 2.学号3.性别4.年龄 5.语文成绩 6.数学成绩 0.返回菜单\n");
			scanf("%d", &choice);
			getchar();
			do {
				switch (choice) {
				case 1:printf("请输入修改后的姓名: ");
					scanf("%s", p->people.name);
					printf("修改成功!");
					break;
				case 2:printf("请输入修改后的学号: ");
					scanf("%ld", &p->people.number);
					printf("修改成功!");
					break;
				case 3:printf("请输入修改后的性别: ");
					scanf("%s", p->people.sex);
					printf("修改成功!");
					break;
				case 4:printf("请输入修改后的年龄: ");
					scanf("%d", &p->people.age);
					printf("修改成功!");
					break;
				case 5:printf("请输入修改后的语文成绩: ");
					scanf("%d", &p->people.chinese);
					printf("修改成功!");
					break;
				case 6:printf("请输入修改后的数学成绩: ");
					scanf("%d", &p->people.math);
					printf("修改成功!");
					break;
				case 0:printf("退回菜单\n");
					break;
				default:break;
				}
				printf("你还想要修改哪一项：1.姓名 2.学号3.性别4.年龄 5.语文成绩 6.数学成绩 0.返回菜单\n");
				scanf("%d", &choice);
				getchar();
			} while (choice != 0);
		}
		else
			printf("没有找到该学生\n");
	}
}

//查找某个学生 (学号 性名）
void reasch(Node* head) {
	if (head == NULL) {
		printf("请先进行初始化!\n");
	}
	else {
		static int number;
		int count = 0;
		static name[NAME];
		Node* p = head->next;
		printf("请输入你要查看的的学生姓名:\n");
		scanf("%s", name);
		while (p) {
			//查找指定姓名的学生，查找到了就退出
			if (strcmp(name, p->people.name) == 0) {
				count = 1;
				break;
			}
			p = p->next;
		}
		if (count) {
			printf("查找成功!\n");
			printf("%20s\t%8s\t%4s\t%4s\t%4s\t%4s\t%4s\n", "姓名", "学号", "性别", "年龄",
				"语文成绩", "数学成绩", "总成绩");
			printf("%20s\t%8ld\t%4s\t%4d\t%4d\t%12d\t%12d\n", p->people.name, p->people.number, p->people.sex, p->people.age,
				p->people.chinese, p->people.math, p->people.all);
		}
		else
			printf("没有找到该学生!\n");
	}
}

//添加学生信息
void add(Node* head){	
	//尾插法把新的节点添加到末尾
	if (head == NULL) {
		printf("请先进行初始化!\n");
	}
	else {

		int count = 0;
		Node* p = head->next;
		Node* r = head->next;
		Node* s = (Node*)malloc(sizeof(Node));
		printf("请输入你要添加的学生姓名:");
		scanf("%s", s->people.name);
		printf("请输入你要添加的学生学号:");
		scanf("%ld", &s->people.number);
		printf("请输入你要添加的学生性别:");
		scanf("%s", s->people.sex);
		printf("请输入你要添加的学生年龄:");
		scanf("%d", &s->people.age);
		printf("请输入你要添加的学生语文成绩:");
		scanf("%d", &s->people.chinese);
		printf("请输入你要添加的学生数学成绩:");
		scanf("%d", &s->people.math);
		s->people.all = s->people.math + s->people.chinese;
		while (p) {
			count++;
			p = p->next;
		}
		//移动到最后位置
		for (int i = 0; i < count - 1; i++) {
			r = r->next;
		}
		r->next = s;
		s->next = NULL;
		r = s;
		printf("学生信息添加完成\n");
	}
}
void del_all(Node* head) {
	//删除所有学生(节点)
	Node* p = head->next;
	Node* q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	head->next= NULL;
}
//语文成绩排序
void sqrt_chi(Node* head) {
	//从大到小语文成绩排序
	if (head == NULL) {
		printf("请先进行初始化!\n");
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
		printf("语文成绩排序成功!\n");
	}
}
//数学成绩排序
void sqrt_math(Node* head) {
	//从大到小数学成绩排序
	if (head == NULL) {
		printf("请先进行初始化!\n");
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
		printf("数学成绩排序成功!\n");
	}
}
void sqrt_all(Node* head) {
	//从大到小总成绩成绩排序
	if (head == NULL) {
		printf("请先进行初始化!\n");
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
		printf("总成绩排序成功!\n");
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
