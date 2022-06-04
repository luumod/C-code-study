#include <stdio.h>
#include <stdlib.h>
struct node
{
	int		data;
	struct node* next;
};

typedef struct node Node;
//�����ڵ�
Node* createNode(int data)
{
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return NULL;
	}
	pNew->data = data;
	pNew->next = NULL;
	return pNew;
}

//��ӽڵ� ͷ�巨
void appendNode(Node** pHead, int data)
{
	Node* pNew = createNode(data);
	//��ͷ�Ĳ������
	pNew->next = *pHead;
	*pHead = pNew;
}

//��ӽڵ� β�巨
void appendNodeR(Node** pHead, int data)
{
	Node* pNew = createNode(data);
	//�ж����Ƿ����׽ڵ�
	if (*pHead == NULL)
	{
		*pHead = pNew;
		return;
	}
	Node* pCur = *pHead;
	//pCurҪ����β�ڵ�
	while (pCur->next)
	{
		pCur = pCur->next;
	}
	pCur->next = pNew;
}

//����ĳ��λ�õĽڵ�
Node* FindNode(Node* pHead,int Finddata)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	//���׽ڵ㿪ʼ
	while (pHead)
	{
		if (pHead->data == Finddata)
		{
			return pHead;
		}
		pHead = pHead->next;
	}
	return NULL;
}

//����ڵ�
void InsertNode(Node** pHead, int pos, int Newdata)
{
	Node* pNew = createNode(Newdata);
	if (pos <= 1)
	{
		pNew->next = *pHead;
		*pHead = pNew;
		return;
	}
	Node* pTemp = *pHead;
	for (int i = 0; i < pos - 2; i++)
	{
		if (pTemp->next == NULL)
		{
			printf("û���ҵ���λ��!\n");
			return;
		}
		pTemp = pTemp->next;
	}
	pNew->next = pTemp->next;
	pTemp->next = pNew;
}

//ɾ���ڵ�
void DelNode(Node** pHead,int Deldata)
{
	//���Ȳ��ҵ��ڵ��λ��
	Node* pDel = FindNode(*pHead, Deldata);
	if (pDel == NULL)
	{
		printf("�ڵ㲻����!\n");
		return;
	}
	//���Ҫɾ���Ľڵ�����Ԫ�ڵ�
	if (*pHead == pDel)
	{
		*pHead = pDel->next;
		free(pDel);
		return;
	}
	//���Ҫɾ���Ĳ�����Ԫ�ڵ�
	Node* pPre = *pHead;
	while (pPre->next!=pDel)
	{
		pPre = pPre->next;
	}
	pPre->next = pDel->next;
	free(pDel);
	pDel = NULL;
	printf("ɾ���ɹ�!\n");
	return;
}

//��������
void ShowNode(Node* pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	//��ͷ��ʼ
	while (pHead)
	{
		printf("%d ", pHead->data);
		pHead = pHead->next;
	}
}

int main(void)
{
	Node* List = NULL;
	//��ͷ�����޷�ֱ�Ӵ��뺯������Ϊ����ͷ�ڵ㣬����Ҫ�����ַ
	for (int i = 0; i < 5; i++)
	{
		appendNodeR(&List, i);
	}
	InsertNode(&List, 0, 9);
	DelNode(&List,9);
	ShowNode(List);
	/*for (int i = 0; i < 10; i++)
	{
		appendNodeR(&List, i);
	}
	ShowNode(List);*/
	return 0;
}