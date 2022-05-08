#include <stdio.h>

#define NAME 20
#define ADDRESS 20
#define PHONE 20
#define SEX	5

enum my {
	SHOW=1,
	ADD,
	DEL,
	SEARCH,
	TO_FILE,
	IN_FILE,
	QUIT=0
};

typedef struct info1{
	char name[NAME];	//姓名
	char s[PHONE];		//电话
	char sex[SEX];		//性别
	char address[ADDRESS];	//地址
}INFO;

typedef struct info2{
	INFO people;
	struct info2* next;
}Node;

//菜单
void menu();

//初始化节点
Node* InitialList();

Node* Createnode(INFO data);

//创建新的节点
void Insertnode(Node* head, INFO data);

//显示链表
void ShowList(Node* head);

//删除一个节点
void DelOneLits(Node* head, char* name);

//查找一个节点
void SreachList(Node* head, char* name);

//保存信息到文件
void TO_silt(Node* head);

//从文件读取
void IN_silt(Node* head);







