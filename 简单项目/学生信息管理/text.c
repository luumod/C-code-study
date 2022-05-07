/*
学生信息管理系统
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
		printf("请先进行初始化!\n");
		p = Initial();
	}
	do {
		menu();
		printf("请输入你要执行的操作:\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {
		case Initialize:
			if (p->next==NULL)
				//判断链表是否为空
				p = Initial();	//输入
			else
				printf("不需要初始化了!\n");
			break;
		case VallStuinfo:look(p);	//显示
			break;
		case Modify:change(p);	//修改
			break;
		case Find:reasch(p);	//查找
			break;
		case Add:add(p);		//添加 
			break;
		case Chinese:sqrt_chi(p);	//语文成绩
			break;
		case Math:sqrt_math(p);//数学成绩
			break;
		case Del:del_all(p);	//删除学生记录
			break;
		case Quit:printf("退出程序，欢迎使用\n");
			exit(EXIT_SUCCESS);
		default:break;
		}

	} while (choice != 0);
	return 0;
}









