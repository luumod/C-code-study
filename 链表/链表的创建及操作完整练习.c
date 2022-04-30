#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#define SIZE 10
//����ͷ�ڵ�
typedef struct node {
	int value;
	struct node* next;
}Node;

//����һ��ͷ���
Node* InitList();
//ͷ�巨����������
void createListH(Node* head);

//β�巨����������
Node* createListrR(Node* head);

//�ض��±괦����ֵ
Node* insert(Node* head, int pos, int val);

// ɾ��ĳ���ڵ�
void listDelete(Node* head, int pos);
//Node* listDelete(Node* head, int pos);

//�����������ݽڵ�ĸ���
int listLength(Node* head);

//�����Ƿ�Ϊ��
void is_empty(Node* head);

//����ֵ
int find(Node* head,int key);

//����ʾ�����޸�
void showList(Node* head);

//�ͷŵ�����
void shifang(Node* head);

//����
void reverse(Node* head);

//ð������
void buttle_sqrt(Node* head);

int main(void) {
	int i, n;

	Node* plist = InitList();	//��ʼ��

	createListH(plist);	//��ʼ��Ԫ��

	showList(plist);	//��ʾ�ڵ�Ԫ��

	//�����½ڵ�
	printf("\n������Ҫ�����λ��:");
	scanf("%d", &i);
	printf("�������µ�Ԫ��:");
	scanf("%d", &n);
	insert(plist, i, n);
	showList(plist);

	buttle_sqrt(plist);
	showList(plist);

	int sum = listLength(plist);
	printf("����ĳ�����: %d\n", sum);

	//ɾ���ڵ�
	printf("\n������Ҫɾ�����±�λ��:");
	scanf("%d", &i);
	listDelete(plist, i);
	showList(plist);

	//�жϷǿ�
	is_empty(plist);

	//����ڵ�����
	sum = listLength(plist);
	printf("����ĳ�����: %d\n", sum);

	//����ĳ���ڵ�Ԫ��:
	int s;
	printf("������Ҫ���ҵ�Ԫ��:");
	scanf("%d", &s);
	if (find(plist, s))
		printf("���ҳɹ����±�λ��:%d\n", find(plist, s));
	else
		printf("û���ҵ�\n");

	reverse(plist);
	showList(plist);

	shifang(plist);
	return 0;
}
Node* InitList() {
	//��ʼ��������
	Node* head;
	head = (Node*)malloc(sizeof(Node));
	head->value = 0;
	head->next = NULL;
	return head;
}
void createListH(Node* head) {
	//ͷ�巨����������
	Node* s;
	for (int i = 1; i <= SIZE; i++) {
		s = (Node*)malloc(sizeof(Node));	//Ϊ�����ڵ����ռ�
		//Ϊ�ڵ㸳ֵ	
		s->value = i;
		//�ѽڵ����
		s->next = head->next;	//s->next=NULL
		head->next = s;		//head->next=s ������Ԫ�ڵ�
	}
	//return head;

}
Node* createListR(Node* head) {
	//β�巨����������
	Node* s, * p;	//һ��βָ��pָ��ĩβ
	p = head;	//pһ��ʼ��ͷ�ڵ�
	for (int i = 0; i < SIZE; i++) {
		Node* s = (Node*)malloc(sizeof(Node));
		s->value = i;
		s->next = NULL;
		p->next = s;
		p = s;	//βָ���ƶ������һ���ڵ�
	}
	return head;
}
Node* insert(Node* head, int pos, int val) {
	//�ض�λ�ô�����һ���µĽڵ�
	Node* p = head->next;
	int j = 0;
	while (p && j < pos - 1) {
		p = p->next;
		j++;
	}
	//����ָ��λ�ú󣬲���Ԫ��
	Node* s = (Node*)malloc(sizeof(Node));
	s->value = val;
	s->next = p->next;		//�½ڵ�������һ���ڵ�
	p->next = s;			//ǰ�������½ڵ�

	return head;
}

void listDelete(Node* head, int pos) {
	//ɾ��ĳ���ڵ�
	int j = 0;
	Node* p = head;
	Node* q;
	while (p && j < pos) {
		p = p->next;
		j++;
	}
	if (p == NULL || j != pos)
		printf("û���ҵ���λ��\n");
	//�����ɾ����ǰһ���ڵ�
	q = p->next;
	p->next = q->next;	//�Թ��ڵ�
	free(q);
	//q->next = NULL;
}

void is_empty(Node* head) {
	//�жϷǿ�
	Node* p=head->next;
	if (p != NULL)
		printf("�����ǿյ�!\n");
	else
		printf("�����ǿյ�!\n");
}

int listLength(Node* head) {
	//����ڵ������
	Node* p = head->next;
	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

int find(Node* head, int key) {
	//����ĳ���ڵ�
	Node* p = head->next;
	int count = 0;
	while (p) {
		count++;
		//��ֵ����
		if (p->value == key)
			return count;
		p = p->next;
	}
	return 0;
}
void showList(Node* head) {
	//��ӡ����
	Node* p = head->next;
	while (p!=NULL) {
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
}
void shifang(Node* head) {
	//�ͷŵ�����ͷ�ڵ�Ϊ��
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
	//��������
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
	//ð������
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
////	puts("1.��ʾ�������Ϣ             2.���㵱ǰ�ڵ������");
////	puts("3.����һ���µĽڵ�           4.ɾ��һ���ڵ�");
////	puts("5.�ͷŽڵ�                   6.�˳���ɾ���ڵ�");
////	puts("7.������������");
////	puts("0.�˳�");
////	puts("************************************************");
////}
////
////void Initial(Node* p);		//��ʼ���ڵ�
////int show_info(Node* p);	//��ʾ�������Ϣ
////int sum(Node* p);			//����ڵ������
////int insert(Node* p,int i,int n);		//����һ���µ�Ԫ��
////int delet_node(Node* p, int i,int e);			//ɾ��һ���ڵ�Ԫ��
////int sqrt(Node* p);					//������������
////int  Empty(Node* p);		//�ͷŽڵ�
////int delet(Node* p);		//ɾ��������
////int main(void) {
////	int num=0;
////	int n, i;
////	int choice=0, result=0;
////	int va = 0;
////	//Ϊͷ�ڵ����ռ�
////	printf("��������ڵ����:");
////	scanf("%d", &num);
////	getchar();
////	Node* plast=NULL;
////	Node* phead=NULL;
////	Initial(phead);
////	//Initial(phead);	//�ڵ��ʼ��
////	for (int i = 0; i < num; i++) {
////		//Ϊ�½ڵ㴴���ռ�
////		Node* current = (Node*)malloc(sizeof(Node));
////		if (current == NULL) {
////			printf("%s\n", strerror(errno));
////			exit(EXIT_FAILURE);
////		}
////		if (phead == NULL)
////			phead = current;
////		else
////			plast->next = current;
////		current->next = NULL;	//������һ��Ϊ��
////		scanf("%d", &current->value);	//�ڵ�ǰλ��������Ϣ
////		getchar();
////		plast = current;
////	}
////	printf("�������!\n");
////	do {
////		show_menu();
////		printf("��������Ҫִ�еĲ���:");
////		scanf("%d", &choice);
////		getchar();
////		switch (choice) {
////		case 1:result = show_info(phead); break;	//��ʾ��Ϣ
////		case 2:result = sum(phead); printf("��������%d���ڵ�\n", result); break;			//��������
////		case 3: printf("������Ҫ���������:");		
////				scanf("%d", &n);
////				printf("�������ĸ�����λ�ú����?");
////				scanf("%d", &i); 
////				result = insert(phead,i,n); break;	//����Ԫ��
////		case 4:
////			printf("������Ҫɾ���Ľڵ�λ��:");
////			scanf("%d", &i);
////			delet_node(phead, i, va); printf("%d���ݽڵ㱻ɾ��",va);
////			break;									//ɾ���ڵ�
////		case 5:result = Empty(phead); break;		//��սڵ�
////		case 6:result = delet(phead); break;		//ɾ���ڵ�
////		case 7:result = sqrt(phead);				//��������ڵ�
////			if (result == OK)
////				printf("��������ɹ�\n"); break;
////		case 0:printf("�����˳�"); exit(EXIT_FAILURE);
////		}
////	} while (choice!=0);
////
////	return 0;
////}
////
////void Initial(Node* p) {
////	//��ʼ������
////	p = (Node*)malloc(sizeof(Node));
////	p = NULL;
////}
////
////int  show_info(Node* p) {
////	Node* q = p;
////	printf("���������Ϣ��:\n");
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
////	//���ҵ������Ԫ��λ��
////	while (L && j < i - 1) {
////		p = p->next;	//ָ��������ǰһ��Ԫ��
////		j++;
////	}
////	//���û���ҵ����߳�����Χ
////	if (j>i - 1 || p == NULL) {
////		printf("%s\n", strerror(errno));
////		exit(EXIT_FAILURE);
////	}
////	//�ҵ��˴�λ��
////	Node* s = (Node*)malloc(sizeof(Node));
////	if (s == NULL)
////		exit(EXIT_FAILURE);
////	s->value = n;	//Ϊ�½ڵ㸳ֵ
////	//�ؼ�����
////	s->next = p->next;
////	p->next = s;
////	return OK;
////}
////
////int delet_node(Node* p, int i, int e) {
////	int j = 0;
////	Node* L, * q;	//��ʱ�洢�ڵ�
////	L = p;
////	while (L && j < i - 1) {
////		L = L->next;
////		j++;
////	}
////	if (j > i || L == NULL) {
////		printf("%s\n", strerror(errno));
////		exit(EXIT_FAILURE);
////	}
////	//ɾ���ڵ�
////	q = L->next;
////	e = q->value;			//�������ݣ���ѡ
////	L->next = q->next;		//�޸�ɾ����ָ����
////	free(q);
////	return e;
////
////}
////
////int sqrt(Node* p) {
////	// ��ͷ��㣡����������������
////	// ��ͷ���!!!!!!!!!!!!!!!!!
////
////	//���뷨
////	Node* cur, * next;
////
////	cur = p->next;	//ָ��ڶ����ڵ�
////	p->next = NULL;	//��һ���ڵ�����ÿ�
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
////	//�ͷŵ�����
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
////	//ɾ��������
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