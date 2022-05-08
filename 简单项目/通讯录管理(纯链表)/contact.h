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
	char name[NAME];	//����
	char s[PHONE];		//�绰
	char sex[SEX];		//�Ա�
	char address[ADDRESS];	//��ַ
}INFO;

typedef struct info2{
	INFO people;
	struct info2* next;
}Node;

//�˵�
void menu();

//��ʼ���ڵ�
Node* InitialList();

Node* Createnode(INFO data);

//�����µĽڵ�
void Insertnode(Node* head, INFO data);

//��ʾ����
void ShowList(Node* head);

//ɾ��һ���ڵ�
void DelOneLits(Node* head, char* name);

//����һ���ڵ�
void SreachList(Node* head, char* name);

//������Ϣ���ļ�
void TO_silt(Node* head);

//���ļ���ȡ
void IN_silt(Node* head);







