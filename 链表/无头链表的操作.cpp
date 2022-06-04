#include <stdio.h>
#include <stdlib.h>
struct node
{
	int		data;
	struct node* next;
};

typedef struct node Node;
//创建节点
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

//添加节点 头插法
void appendNode(Node** pHead, int data)
{
	Node* pNew = createNode(data);
	//无头的插入操作
	pNew->next = *pHead;
	*pHead = pNew;
}

//添加节点 尾插法
void appendNodeR(Node** pHead, int data)
{
	Node* pNew = createNode(data);
	//判断其是否是首节点
	if (*pHead == NULL)
	{
		*pHead = pNew;
		return;
	}
	Node* pCur = *pHead;
	//pCur要到达尾节点
	while (pCur->next)
	{
		pCur = pCur->next;
	}
	pCur->next = pNew;
}

//查找某个位置的节点
Node* FindNode(Node* pHead,int Finddata)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	//从首节点开始
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

//插入节点
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
			printf("没有找到此位置!\n");
			return;
		}
		pTemp = pTemp->next;
	}
	pNew->next = pTemp->next;
	pTemp->next = pNew;
}

//删除节点
void DelNode(Node** pHead,int Deldata)
{
	//首先查找到节点的位置
	Node* pDel = FindNode(*pHead, Deldata);
	if (pDel == NULL)
	{
		printf("节点不存在!\n");
		return;
	}
	//如果要删除的节点是首元节点
	if (*pHead == pDel)
	{
		*pHead = pDel->next;
		free(pDel);
		return;
	}
	//如果要删除的不是首元节点
	Node* pPre = *pHead;
	while (pPre->next!=pDel)
	{
		pPre = pPre->next;
	}
	pPre->next = pDel->next;
	free(pDel);
	pDel = NULL;
	printf("删除成功!\n");
	return;
}

//遍历链表
void ShowNode(Node* pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	//从头开始
	while (pHead)
	{
		printf("%d ", pHead->data);
		pHead = pHead->next;
	}
}

int main(void)
{
	Node* List = NULL;
	//无头链表无法直接传入函数，因为其无头节点，所以要传入地址
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