//使用结构链表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
//#define TSIZE 45
//struct film {
//	char title[TSIZE];
//	int rating;
//	struct film* next;	//指向链表的下一个结构
//};
//char* s_gets(char* str, int n);
//int main(void) {
//	struct film* head = NULL;
//	struct film* prev, * current;
//	char input[TSIZE];
//
//	//收集并存储信息
//	puts("输入第一个电影的名称:");
//	while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
//		//为结构体指针动态分配内存
//		current = (struct film*)malloc(sizeof(struct film));
//
//		//检查是否成功获取到内存
//		if (current == NULL) {
//			printf("%s\n", strerror(errno));
//			exit(3);
//		}
//		if (head = NULL) {
//			//第一个结构体
//			head = current;	//是第一个结构，则用head头指针存储下一个结构的信息
//		}
//		else {
//			//下一个结构体
//			prev->next = current;	//新结构的地址存储在上一个结构中
//		}
//		//新结构的next成员设置为NULL
//		current->next = NULL;
//		strcpy(current->title, input);	//输入电影名
//		puts("输入电影的评分: (0-10)");
//		scanf("%d", &current->rating);
//		getchar();	//去除换行
//		puts("输入第二个电影的名称: (空行退出)");
//		prev = current;
//	}
//
//	//显示电影列表
//	if (head == NULL)
//		printf("没有电影!\n");
//	else
//		printf("这是你的电影列表:\n");
//	//从第一个结构体开始
//	current = head;
//	while (current != NULL) {
//		printf("Movies: %s Rating : %d\n", current->title, current->rating);
//		current = current->next;	//进入下一个结构体
//	}
//
//	//完成任务,释放已分配的内存
//	current = head;
//	while (current != NULL) {
//		head = current->next;
//		free(current);
//		current = head;
//	}
//	printf("Bye!\n");
//	return 0;
//}
//char* s_gets(char* str, int n) {
//	char* ret_val;
//	char* find;
//	ret_val = fgets(str, n, stdin);
//	if (ret_val) {
//		find = strchr(str, '\n');
//		if (*find) {
//			*find = '\0';
//		}
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}

//#define TSIZE 45
//typedef struct film{
//	char title[TSIZE];
//	int rating;
//}Item;	//创建新类型
//
////创建节点
//typedef struct node {
//	Item item;		//链表内容信息
//	struct node* next;	//指向下一个节点的指针
//}Node;
//typedef Node* List;
//List movies;	//创建链表所需要的指针movies
////每个链结叫做节点，每个节点包含形成链表内容的信息和指向下一个节点的指针
//
//typedef struct list {
//	Node* head;	//指向链表头的指针
//	int size;	//链表的项数
//}List;
//List movies;	//创建了一个链表



//int main(void) {
//	int num[10][10] = { 0 };
//	for (int i = 0; i < 10; i++) {
//		num[i][0] = 1;
//	}
//	for (int i = 1; i <= 10; i++) {
//		for (int j = 1; j <= i; j++) {
//			num[i][j] = num[i - 1][j] + num[i - 1][j - 1];
//		}
//	}
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < i; j++) {
//			printf("%d ", num[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//猴子吃桃
//int main(void) {
//	int sum = 1;
//	for (int i = 1; i < 10; i++) {
//		sum = (sum + 1) * 2;
//	}
//	printf("%d", sum);
//	return 0;
//}


//牛顿迭代法
//int main(void) {
//	double x = 1.5, x0, f1, f2;
//	do {
//		x0 = x;
//		f1 = 2 * pow(x, 3) - 4 * x * x + 3 * x - 6;
//		f2 = 6 * x * x - 8 * x + 3;
//		x = x0 - f1 / f2;
//	} while (fabs(x - x0) >= 1e-5);
//	printf("%lf", x);
//	return 0;
//}

//菱形
//int main(void) {
//	for (int i = 1; i <= 4; i++) {
//		for (int j = 1; j <= 4 - i; j++) {
//			printf(" ");
//		}
//		for (int k = 1; k <= 2 * i - 1; k++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = 3; i >= 1; i--) {
//		for (int j = 1; j <= 4 - i; j++)
//			printf(" ");
//		for (int k = 1; k <= 2 * i - 1; k++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}

