#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#define SIZE 10
//创建头节点
typedef struct node {
	int value;
	struct node* next;
}Node;

//创建一个头结点
Node* InitList();
//头插法建立单链表
void createListH(Node* head);

//尾插法建立单链表
Node* createListrR(Node* head);

//特定下标处插入值
Node* insert(Node* head, int pos, int val);

// 删除某个节点
void listDelete(Node* head, int pos);
//Node* listDelete(Node* head, int pos);

//单链表中数据节点的个数
int listLength(Node* head);

//链表是否为空
void is_empty(Node* head);

//查找值
int find(Node* head,int key);

//仅显示，不修改
void showList(Node* head);

//释放单链表
void shifang(Node* head);

//逆置
void reverse(Node* head);

//冒泡排序
void buttle_sqrt(Node* head);

int main(void) {
	int i, n;

	Node* plist = InitList();	//初始化

	createListH(plist);	//初始化元素

	showList(plist);	//显示节点元素

	//插入新节点
	printf("\n请输入要插入的位置:");
	scanf("%d", &i);
	printf("请输入新的元素:");
	scanf("%d", &n);
	insert(plist, i, n);
	showList(plist);

	buttle_sqrt(plist);
	showList(plist);

	int sum = listLength(plist);
	printf("链表的长度是: %d\n", sum);

	//删除节点
	printf("\n请输入要删除的下标位置:");
	scanf("%d", &i);
	listDelete(plist, i);
	showList(plist);

	//判断非空
	is_empty(plist);

	//计算节点数量
	sum = listLength(plist);
	printf("链表的长度是: %d\n", sum);

	//查找某个节点元素:
	int s;
	printf("请输入要查找的元素:");
	scanf("%d", &s);
	if (find(plist, s))
		printf("查找成功，下标位置:%d\n", find(plist, s));
	else
		printf("没有找到\n");

	reverse(plist);
	showList(plist);

	shifang(plist);
	return 0;
}
Node* InitList() {
	//初始化单链表
	Node* head;
	head = (Node*)malloc(sizeof(Node));
	head->value = 0;
	head->next = NULL;
	return head;
}
void createListH(Node* head) {
	//头插法创建单链表
	Node* s;
	for (int i = 1; i <= SIZE; i++) {
		s = (Node*)malloc(sizeof(Node));	//为单个节点分配空间
		//为节点赋值	
		s->value = i;
		//把节点插入
		s->next = head->next;	//s->next=NULL
		head->next = s;		//head->next=s 连接首元节点
	}
	//return head;

}
Node* createListR(Node* head) {
	//尾插法创建单链表
	Node* s, * p;	//一个尾指针p指向末尾
	p = head;	//p一开始在头节点
	for (int i = 0; i < SIZE; i++) {
		Node* s = (Node*)malloc(sizeof(Node));
		s->value = i;
		s->next = NULL;
		p->next = s;
		p = s;	//尾指针移动到最后一个节点
	}
	return head;
}
Node* insert(Node* head, int pos, int val) {
	//特定位置处插入一个新的节点
	Node* p = head->next;
	int j = 0;
	while (p && j < pos - 1) {
		p = p->next;
		j++;
	}
	//到达指定位置后，插入元素
	Node* s = (Node*)malloc(sizeof(Node));
	s->value = val;
	s->next = p->next;		//新节点连接下一个节点
	p->next = s;			//前驱连接新节点

	return head;
}

void listDelete(Node* head, int pos) {
	//删除某个节点
	int j = 0;
	Node* p = head;
	Node* q;
	while (p && j < pos) {
		p = p->next;
		j++;
	}
	if (p == NULL || j != pos)
		printf("没有找到此位置\n");
	//到达待删除的前一个节点
	q = p->next;
	p->next = q->next;	//略过节点
	free(q);
	//q->next = NULL;
}

void is_empty(Node* head) {
	//判断非空
	Node* p=head->next;
	if (p != NULL)
		printf("链表不是空的!\n");
	else
		printf("链表是空的!\n");
}

int listLength(Node* head) {
	//结算节点的数量
	Node* p = head->next;
	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

int find(Node* head, int key) {
	//查找某个节点
	Node* p = head->next;
	int count = 0;
	while (p) {
		count++;
		//按值查找
		if (p->value == key)
			return count;
		p = p->next;
	}
	return 0;
}
void showList(Node* head) {
	//打印链表
	Node* p = head->next;
	while (p!=NULL) {
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
}
void shifang(Node* head) {
	//释放单链表，头节点为空
	Node* p = head->next;
	Node* q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	head->next = NULL;
}


void reverse(Node* head) {
	//逆置链表
	Node* cur, * pnext;
	cur = head->next;
	pnext = cur;
	head->next = NULL;
	while (cur) {
		pnext = cur->next;
		cur->next = head->next;
		head->next = cur;
		cur = pnext;
	}
}


void buttle_sqrt(Node* head) {
	//冒泡升序
	Node* cur, * pnext;
	cur = head->next;
	pnext = cur->next;

	for (; cur != NULL; cur = cur->next) {
		for (pnext = cur->next; pnext != NULL; pnext = pnext->next) {
			if (cur->value > pnext->value) {
				int temp = cur->value;
				cur->value = pnext->value;
				pnext->value = temp;
			}
		}
	}

}
////#define SIZE 10
////
////#define OK 1
////#define NO 0
////
////typedef struct node {
////	int value;
////	struct node* next;
////}Node;
////
////void show_menu(void) {
////	puts("************************************************");
////	puts("1.显示链表的信息             2.计算当前节点的数量");
////	puts("3.插入一个新的节点           4.删除一个节点");
////	puts("5.释放节点                   6.退出，删除节点");
////	puts("7.逆序排序链表");
////	puts("0.退出");
////	puts("************************************************");
////}
////
////void Initial(Node* p);		//初始化节点
////int show_info(Node* p);	//显示链表的信息
////int sum(Node* p);			//计算节点的数量
////int insert(Node* p,int i,int n);		//插入一个新的元素
////int delet_node(Node* p, int i,int e);			//删除一个节点元素
////int sqrt(Node* p);					//逆序排列链表
////int  Empty(Node* p);		//释放节点
////int delet(Node* p);		//删除单链表
////int main(void) {
////	int num=0;
////	int n, i;
////	int choice=0, result=0;
////	int va = 0;
////	//为头节点分配空间
////	printf("输入链表节点个数:");
////	scanf("%d", &num);
////	getchar();
////	Node* plast=NULL;
////	Node* phead=NULL;
////	Initial(phead);
////	//Initial(phead);	//节点初始化
////	for (int i = 0; i < num; i++) {
////		//为新节点创建空间
////		Node* current = (Node*)malloc(sizeof(Node));
////		if (current == NULL) {
////			printf("%s\n", strerror(errno));
////			exit(EXIT_FAILURE);
////		}
////		if (phead == NULL)
////			phead = current;
////		else
////			plast->next = current;
////		current->next = NULL;	//设置下一个为空
////		scanf("%d", &current->value);	//在当前位置输入信息
////		getchar();
////		plast = current;
////	}
////	printf("输入完成!\n");
////	do {
////		show_menu();
////		printf("请输入你要执行的操作:");
////		scanf("%d", &choice);
////		getchar();
////		switch (choice) {
////		case 1:result = show_info(phead); break;	//显示信息
////		case 2:result = sum(phead); printf("此链表共有%d个节点\n", result); break;			//计算数量
////		case 3: printf("请输入要插入的数字:");		
////				scanf("%d", &n);
////				printf("你想在哪个索引位置后插入?");
////				scanf("%d", &i); 
////				result = insert(phead,i,n); break;	//插入元素
////		case 4:
////			printf("请输入要删除的节点位置:");
////			scanf("%d", &i);
////			delet_node(phead, i, va); printf("%d数据节点被删除",va);
////			break;									//删除节点
////		case 5:result = Empty(phead); break;		//清空节点
////		case 6:result = delet(phead); break;		//删除节点
////		case 7:result = sqrt(phead);				//逆序链表节点
////			if (result == OK)
////				printf("链表逆序成功\n"); break;
////		case 0:printf("程序退出"); exit(EXIT_FAILURE);
////		}
////	} while (choice!=0);
////
////	return 0;
////}
////
////void Initial(Node* p) {
////	//初始化链表
////	p = (Node*)malloc(sizeof(Node));
////	p = NULL;
////}
////
////int  show_info(Node* p) {
////	Node* q = p;
////	printf("您输入的信息是:\n");
////	while (q) {
////		printf("%d ", q->value);
////		q = q->next;
////	}
////	printf("\n");
////	return OK;
////}
////
////int insert(Node* p, int i, int n) {
////	Node* L = p;
////	int j = 0;
////	//先找到插入的元素位置
////	while (L && j < i - 1) {
////		p = p->next;	//指向待插入的前一个元素
////		j++;
////	}
////	//如果没有找到或者超出范围
////	if (j>i - 1 || p == NULL) {
////		printf("%s\n", strerror(errno));
////		exit(EXIT_FAILURE);
////	}
////	//找到了此位置
////	Node* s = (Node*)malloc(sizeof(Node));
////	if (s == NULL)
////		exit(EXIT_FAILURE);
////	s->value = n;	//为新节点赋值
////	//关键两步
////	s->next = p->next;
////	p->next = s;
////	return OK;
////}
////
////int delet_node(Node* p, int i, int e) {
////	int j = 0;
////	Node* L, * q;	//临时存储节点
////	L = p;
////	while (L && j < i - 1) {
////		L = L->next;
////		j++;
////	}
////	if (j > i || L == NULL) {
////		printf("%s\n", strerror(errno));
////		exit(EXIT_FAILURE);
////	}
////	//删除节点
////	q = L->next;
////	e = q->value;			//保存数据，可选
////	L->next = q->next;		//修改删除的指针域
////	free(q);
////	return e;
////
////}
////
////int sqrt(Node* p) {
////	// 无头结点！！！！！！！！！
////	// 无头结点!!!!!!!!!!!!!!!!!
////
////	//插入法
////	Node* cur, * next;
////
////	cur = p->next;	//指向第二个节点
////	p->next = NULL;	//第一个节点后面置空
////
////	while (cur) {
////		next = cur->next;
////		cur->next = p;
////		p = cur;
////		cur = next;
////	}
////	return OK;
////}
////int sum(Node* p) {
////	int count = 0;
////	while (p) {
////		count++;
////		p = p->next;
////	}
////	return count;
////}
////
////int Empty(Node* p) {
////	//释放单链表
////	Node* q, * r;
////	q = p->next;
////	while (q) {
////		r = q->next;
////		free(q);
////		q = r;
////	}
////	p->next = NULL;
////	return OK;
////}
////
////int delet(Node* p) {
////	//删除单链表
////	Node* q;
////	while (p) {
////		q = p;	
////		p = p->next;
////		free(q);
////	}
////	return NO;
////}
//
//