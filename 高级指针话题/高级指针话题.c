#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 5

/*typedef struct NODE {
	struct NODE* next;
	int value;
}Node;*/

//�߼�ָ�뻰��
//ָ��ָ���ָ��

//������ָ������
//int p[8][8];			//�ں�int����ֵ����������飬����ά����
//int** p;				//ָ��ָ���ָ�룬��ָ���ָ��ָ��int
//int* p[8];				//ָ������: ��һ�����飬�����ÿ��Ԫ�ض���һ��int���͵�ָ��
//int(*p)[8];				//����ָ��: ��һ��ָ�룬ָ��һ���ں�8��intֵ������
//int* p[8][8];			//ָ���ά����: ��һ����ά���飬ÿ��Ԫ�ض���һ��int��ָ�룬��64��ָ��
//int(*p)[8][8];			//��ά����ָ��: ��һ��ָ�룬ָ��ָ��һ����ά����
//int(*p[4])[8];			//����ָ������: ��һ�����飬�ں�4��int��ָ�룬ͬʱÿ��ָ����ָ���ں�8��Ԫ�ص�����


//�߼���������
//int (*f)();	//����ָ��,��һ��ָ�룬ָ��ĺ�������int���͵�Ԫ��
//int* (*f)();	//����ָ�룬��һ��ָ�룬ָ��ĺ�������int*���͵�Ԫ��
//int (*f[])();	//����ָ�����飬��һ�����飬�����ÿһ��ֵ����ָ�룬ÿ��ָ����ָ��һ������ֵ��int�ĺ���
//int* (*f[])();	//����ָ�����飬��һ�����飬�����ÿһ��ֵ����ָ�룬ÿ��ָ����ָ��һ������ֵ��int*�ĺ���
//
//int main(void) {
//	int a = 5;
//	int* p = &a;
//	int** pp = &p;
//	//static int p;
//	//static int* pp;
//	//static int** ppp;	//��̬��������ʼ��Ϊ0
//	//printf("%d\n%d\n%d\n", p, pp, ppp);
//	// 
//	//int a=5;
//	//int* p=&a;
//	//int** pp=&p;	//��̬��������ʼ��Ϊ0
//	//printf("%d\n%p\n%p\n", p, pp, pp);
//
//	//int i = 4;
//	//*pp = &i;	//�൱�� p=&i -> *pp=p
//	//printf("%d", *p);
//
//	//a = 5;	
//	//*p = 5;	// p=&a  *p=a
//	//**pp = 5;	//pp=&p *pp=p=&a  **pp=*p=a
//	//printf("%d %d %d\n", a, *p, **pp);
//
//	
//	//int f(int);	//����һ������
//	//int (*pf)(int)=&f;	//����ָ�롣��Ҫ��ʼ��ָ��һ������,&���Ǳ����
//	// 
//	//���ú���:
//	/*int a;
//	a = f(25);
//	a = (*pf)(25);
//	a = pf(25);	*/	//��ȫһ��������ָ��ĵ���
//
//
//	return 0;
//}

//��һ���������в���һ��ָ����ֵ�����������ֵ���бȽϲ���

//Node* search_value(Node* p, void const* value, int (*pfun)(void*, void*)) {
//	while (p != NULL) {
//		if (pfun(&p->value, &value) == 0)	//���ҵĽڵ�ֵ����Ƚϵ�ֵ����ȽϺ���
//			break;
//		p = p->next;
//	}
//	return p;
//}
//int compare(void const* a, void const* b) {
//	//�ȽϺ���
//	if (*(int*)a == *(int*)b) {
//		//ǿ������ת��
//		return 0;
//	}
//	else
//		return 1;
//}
////��������: 
//Node* p; Node* a;
//Node* desired_node = search_value(p, /*������ֵ*/ &a->value, compare);
//



//ת�Ʊ�:
/*
���ú���ָ��������ѡ�˵�ʱ������switch����
*/

//������������
 
//switch (xxx) {
//case 'x':add(); break;
//case 'r':sub(); break;
//case 'u':mul(); break;
//case 'd':div(); break;
//}
////����ָ������
//double (*pfunc[])(double, double) = { add,sub,mul,div };
//ʹ��:  result=pfunc[����](o1,o2);

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