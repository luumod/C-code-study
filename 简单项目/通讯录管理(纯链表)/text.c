/*
通讯录管理
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
		printf("请输入你要执行的操作: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice) {
		case SHOW://显示全部人员信息
			printf("显示全部人员信息:\n");
			ShowList(p);
			system("pause");
			system("cls");
			break;
		case ADD://添加人员信息
			printf("添加一个成员");
			printf("请输入人员姓名:");
			scanf("%s", data.name);
			printf("请输入人员电话:");
			scanf("%s", data.s);
			printf("请输入人员性别:");
			scanf("%s", data.sex);
			printf("请输入人员地址:");
			scanf("%s", data.address);
			//输入信息，把信息与表头传入创建节点的函数
			Insertnode(p, data);
			system("pause");
			system("cls");
			break;
		case DEL://删除一个人的信息
			printf("请输入你要删除的人的名字:");
			scanf("%s", name);
			DelOneLits(p,name);
			system("pause");
			system("cls");
			break;
		case SEARCH://查找
			printf("请输入你要查找的名字:");
			scanf("%s", name);
			SreachList(p, name);
			system("pause");
			system("cls");
			break;
		case TO_FILE: //保存信息到文件
			TO_silt(p);
			system("pause");
			system("cls");
			break;
		case IN_FILE: //从文件读取
			IN_silt(p);
			system("pause");
			system("cls");
			break;
		case QUIT://退出程序
			exit(EXIT_SUCCESS);
		default:printf("请重新输入:");
		}
	} while (choice != QUIT);

	return 0;
}