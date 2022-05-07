#pragma once
/*
函数及变量声明
*/

/*
学生姓名 学号 性别  年龄 语文成绩 数学成绩 总成绩
*/
#define NAME 20
#define SEX 10
#define SIZE 100

enum my_option {
	Initialize=1,
	VallStuinfo,
	Modify,
	Find,
	Add,
	Chinese,
	Math,
	Del,
	Quit=0
};
typedef struct info {
	char name[NAME];
	long number;
	char sex[SEX];
	int age;
	int chinese;
	int math;
	int all;
}STUDENT;
typedef struct info2{
	STUDENT people;
	struct info2* next;
}Node;
//菜单
void menu(void);
//初始化输入学生信息
Node* Initial();

//判断链表是否为空
int isempty(Node* head);

//查看所有学生信息
void look(Node* head);

//修改某个学生信息
void change(Node* head);

//查找某个学生 (学号 性名）
void reasch(Node* head);

//添加学生信息
void add(Node* head);

//语文成绩排序
void sqrt_chi(Node* head);

//数学 
void sqrt_math(Node* head);

//总成绩排序
void sqrt_all(Node* head);

//删除所有学生记录
void del_all(Node* head);

//排序函数
void sort(Node* p, Node* q);