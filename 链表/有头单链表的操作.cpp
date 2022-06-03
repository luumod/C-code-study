#include <stdio.h>
#include <stdlib.h>

typedef double TYPE;

struct node
{
	TYPE	data;
	node*	next;
};

typedef struct node Node;

//�����ڵ�
Node* create_node(TYPE Newdata)
{
	Node* pTemp = (Node*)malloc(sizeof(Node));
	if (pTemp == NULL)
	{
		//�ڵ����ʧ�ܣ��򷵻ؿգ������Ա��
		return NULL;
	}
	pTemp->data = Newdata;
	pTemp->next = NULL;
	//���ط���ÿռ�Ľڵ�
	return pTemp;
}

//ͷ�巨�����ڵ�
void PushNodeH(Node* pHead,TYPE Newdata)
{
	//����һ���ڵ�
	Node* pNew = create_node(Newdata);
	if (pNew == NULL)
	{
		//���Ϊ���򷵻�
		return;
	}
	//ͷ�巨����,������
	pNew->next = pHead->next;
	pHead->next = pNew;
}

//β�巨�����ڵ�
void PushNodeR(Node* pHead, TYPE Newdata)
{
	//����һ���ڵ�
	Node* pNew = create_node(Newdata);
	if (pNew == NULL)
	{
		//���Ϊ���򷵻�
		return;
	}
	//β�巨��Ҫ�ƶ��������β��
	Node* pCur = pHead;
	while (pCur->next)
	{
		pCur = pCur->next;
	}
	//��ʱ�ƶ����������β�ڵ�,����β��������
	pCur->next = pNew;
}

//��������м����һ��Ԫ��
void InsertNode(Node* pHead,TYPE insert_pos,TYPE Newdata)
{
	Node* pNew = create_node(Newdata);
	if (pNew == NULL)
	{
		return;
	}
	//�ҵ��������λ��
	for (TYPE i = 0; i < insert_pos - 1; i++)
	{
		if (pHead->next == NULL)
		{
			printf("û���ҵ���λ��!\n");
			return;
		}
		pHead = pHead->next;
	} 
	pNew->next = pHead->next;
	pHead->next = pNew;
}

//����ĳ���ڵ�
Node* FindNodePos(Node* pHead, TYPE FindNodedata)
{
	if (pHead == NULL)
	{
		printf("������Ϊ��!\n");
		return NULL;
	}
	//���ҽڵ㣬�Թ�ͷ�ڵ�
	Node* pFind = pHead->next;
	while (pFind)
	{
		if (pFind->data == FindNodedata)
		{
			//�ҵ��˴˽ڵ�,�����ش˽ڵ��λ��
			return pFind;
		}
		pFind = pFind->next;
	}
	//û���ҵ����ؿ�
	return NULL;
}

//ɾ������Ľڵ�
void DelNode(Node* pHead,TYPE Deldata)
{
	//����ĳ���ڵ��λ��
	Node* pDel = FindNodePos(pHead, Deldata);
	if (pDel == NULL)
	{
		printf("Ҫɾ���Ľڵ㲻����!\n");
		return;
	}
	//ɾ������
	//����Ҫɾ����ǰһ���ڵ�
	//Ҫɾ���Ľڵ������һ���ڵ㣬���ֻ�������ͷ�ڵ㿪ʼ
	Node* pDelPre = pHead;
	while (pDelPre->next != pDel)
	{
		pDelPre = pDelPre->next;
	}
	//�ڵ��Թ�������ʵ��ɾ��
	pDelPre->next = pDel->next;
	//ɾ�����ͷŽڵ�
	free(pDel);
	pDel = NULL;
	printf("ɾ���ɹ�!\n");
}

//�޸Ľڵ�����
void ChangeNodedata(Node* pHead, TYPE Newdata,TYPE Predata)
{
	Node* pChange = FindNodePos(pHead, Predata);
	if (pChange == NULL)
	{
		printf("û���ҵ��˽ڵ�!\n");
		return;
	}
	pChange->data = Newdata;
	printf("�޸Ľڵ�ɹ�!\n");
}

//����ı���
void ShowNodeList(Node* pHead)
{
	//�ӵ�һ���ڵ㿪ʼ
	if (pHead == NULL)
	{
		printf("������Ϊ��!\n");
		return;
	}
	Node* pCur = pHead->next;
	while (pCur)
	{
		printf("%.2lf ", pCur->data);
		pCur = pCur->next;
	}
}

int main(void)
{
	//��ʼ��һ��ͷ�ڵ�
	Node* ListH = NULL, *ListR = NULL;
	ListH = create_node(0);
	ListR = create_node(0);
	for (TYPE i = 0; i < 5; i++)
	{
		//ͷ�巨
		PushNodeH(ListH, i);
	}
	//������Ϊ3��λ�ò���10
	InsertNode(ListH, 0, 999);
	DelNode(ListH, 0);
	ShowNodeList(ListH);
	//for (TYPE i = 0; i < 5; i++)
	//{
	//	//β�巨
	//	PushNodeR(ListR, i);
	//}
	//InsertNode(ListR, 3, 10);
	//��������
	//printf("ͷ�巨: ");
	/*printf("\nβ�巨: ");
	ShowNodeList(ListR);*/
	return 0;
}