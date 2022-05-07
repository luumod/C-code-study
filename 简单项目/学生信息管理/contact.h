#pragma once
/*
��������������
*/

/*
ѧ������ ѧ�� �Ա�  ���� ���ĳɼ� ��ѧ�ɼ� �ܳɼ�
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
//�˵�
void menu(void);
//��ʼ������ѧ����Ϣ
Node* Initial();

//�ж������Ƿ�Ϊ��
int isempty(Node* head);

//�鿴����ѧ����Ϣ
void look(Node* head);

//�޸�ĳ��ѧ����Ϣ
void change(Node* head);

//����ĳ��ѧ�� (ѧ�� ������
void reasch(Node* head);

//���ѧ����Ϣ
void add(Node* head);

//���ĳɼ�����
void sqrt_chi(Node* head);

//��ѧ 
void sqrt_math(Node* head);

//�ܳɼ�����
void sqrt_all(Node* head);

//ɾ������ѧ����¼
void del_all(Node* head);

//������
void sort(Node* p, Node* q);