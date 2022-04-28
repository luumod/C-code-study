#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 5

/*typedef struct NODE {
	struct NODE* next;
	int value;
}Node;*/

//高级指针话题
//指向指针的指针

//常见的指针类型
//int p[8][8];			//内含int类型值的数组的数组，即二维数组
//int** p;				//指向指针的指针，被指向的指针指向int
//int* p[8];				//指针数组: 是一个数组，数组的每个元素都是一个int类型的指针
//int(*p)[8];				//数组指针: 是一个指针，指向一个内含8个int值的数组
//int* p[8][8];			//指针二维数组: 是一个二维数组，每个元素都是一个int的指针，共64个指针
//int(*p)[8][8];			//二维数组指针: 是一个指针，指针指向一个二维数组
//int(*p[4])[8];			//数组指针数组: 是一个数组，内含4个int的指针，同时每个指针又指向内含8个元素的数组


//高级函数声明
//int (*f)();	//函数指针,是一个指针，指向的函数返回int类型的元素
//int* (*f)();	//函数指针，是一个指针，指向的函数返回int*类型的元素
//int (*f[])();	//函数指针数组，是一个数组，数组的每一个值都是指针，每个指针又指向一个返回值是int的函数
//int* (*f[])();	//函数指针数组，是一个数组，数组的每一个值都是指针，每个指针又指向一个返回值是int*的函数
//
//int main(void) {
//	int a = 5;
//	int* p = &a;
//	int** pp = &p;
//	//static int p;
//	//static int* pp;
//	//static int** ppp;	//静态变量，初始化为0
//	//printf("%d\n%d\n%d\n", p, pp, ppp);
//	// 
//	//int a=5;
//	//int* p=&a;
//	//int** pp=&p;	//静态变量，初始化为0
//	//printf("%d\n%p\n%p\n", p, pp, pp);
//
//	//int i = 4;
//	//*pp = &i;	//相当于 p=&i -> *pp=p
//	//printf("%d", *p);
//
//	//a = 5;	
//	//*p = 5;	// p=&a  *p=a
//	//**pp = 5;	//pp=&p *pp=p=&a  **pp=*p=a
//	//printf("%d %d %d\n", a, *p, **pp);
//
//	
//	//int f(int);	//声明一个函数
//	//int (*pf)(int)=&f;	//函数指针。需要初始化指向一个函数,&不是必须的
//	// 
//	//调用函数:
//	/*int a;
//	a = f(25);
//	a = (*pf)(25);
//	a = pf(25);	*/	//完全一样，函数指针的调用
//
//
//	return 0;
//}

//在一个单链表中查找一个指定的值，并与给定的值进行比较操作

//Node* search_value(Node* p, void const* value, int (*pfun)(void*, void*)) {
//	while (p != NULL) {
//		if (pfun(&p->value, &value) == 0)	//查找的节点值与待比较的值进入比较函数
//			break;
//		p = p->next;
//	}
//	return p;
//}
//int compare(void const* a, void const* b) {
//	//比较函数
//	if (*(int*)a == *(int*)b) {
//		//强制类型转换
//		return 0;
//	}
//	else
//		return 1;
//}
////函数调用: 
//Node* p; Node* a;
//Node* desired_node = search_value(p, /*待查找值*/ &a->value, compare);
//



//转移表:
/*
利用函数指针数组在选菜单时来代替switch工作
*/

//给出函数定义
 
//switch (xxx) {
//case 'x':add(); break;
//case 'r':sub(); break;
//case 'u':mul(); break;
//case 'd':div(); break;
//}
////函数指针数组
//double (*pfunc[])(double, double) = { add,sub,mul,div };
//使用:  result=pfunc[操作](o1,o2);

void num(int);
int main(void) {
	int n;
	scanf("%d", &n);
	num(n);
	return 0;
}
void num(int a) {
	int q;
	q = a / 16;
	if (q)
		num(q);
	putchar("123456789ABCDEF"[q % 16]);
}