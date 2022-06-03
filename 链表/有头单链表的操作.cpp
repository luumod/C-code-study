#include <stdio.h>
#include <stdlib.h>

typedef double TYPE;

struct node
{
	TYPE	data;
	node*	next;
};

typedef struct node Node;

//创建节点
Node* create_node(TYPE Newdata)
{
	Node* pTemp = (Node*)malloc(sizeof(Node));
	if (pTemp == NULL)
	{
		//节点分配失败，则返回空，防御性编程
		return NULL;
	}
	pTemp->data = Newdata;
	pTemp->next = NULL;
	//返回分配好空间的节点
	return pTemp;
}

//头插法创建节点
void PushNodeH(Node* pHead,TYPE Newdata)
{
	//创建一个节点
	Node* pNew = create_node(Newdata);
	if (pNew == NULL)
	{
		//如果为空则返回
		return;
	}
	//头插法连接,两步走
	pNew->next = pHead->next;
	pHead->next = pNew;
}

//尾插法创建节点
void PushNodeR(Node* pHead, TYPE Newdata)
{
	//创建一个节点
	Node* pNew = create_node(Newdata);
	if (pNew == NULL)
	{
		//如果为空则返回
		return;
	}
	//尾插法需要移动到链表的尾部
	Node* pCur = pHead;
	while (pCur->next)
	{
		pCur = pCur->next;
	}
	//此时移动到了链表的尾节点,进行尾部的连接
	pCur->next = pNew;
}

//在链表的中间插入一个元素
void InsertNode(Node* pHead,TYPE insert_pos,TYPE Newdata)
{
	Node* pNew = create_node(Newdata);
	if (pNew == NULL)
	{
		return;
	}
	//找到待插入的位置
	for (TYPE i = 0; i < insert_pos - 1; i++)
	{
		if (pHead->next == NULL)
		{
			printf("没有找到此位置!\n");
			return;
		}
		pHead = pHead->next;
	} 
	pNew->next = pHead->next;
	pHead->next = pNew;
}

//查找某个节点
Node* FindNodePos(Node* pHead, TYPE FindNodedata)
{
	if (pHead == NULL)
	{
		printf("此链表为空!\n");
		return NULL;
	}
	//查找节点，略过头节点
	Node* pFind = pHead->next;
	while (pFind)
	{
		if (pFind->data == FindNodedata)
		{
			//找到了此节点,并返回此节点的位置
			return pFind;
		}
		pFind = pFind->next;
	}
	//没有找到返回空
	return NULL;
}

//删除链表的节点
void DelNode(Node* pHead,TYPE Deldata)
{
	//查找某个节点的位置
	Node* pDel = FindNodePos(pHead, Deldata);
	if (pDel == NULL)
	{
		printf("要删除的节点不存在!\n");
		return;
	}
	//删除操作
	//到达要删除的前一个节点
	//要删除的节点包括第一个节点，因此只能让其从头节点开始
	Node* pDelPre = pHead;
	while (pDelPre->next != pDel)
	{
		pDelPre = pDelPre->next;
	}
	//节点略过操作，实现删除
	pDelPre->next = pDel->next;
	//删除后释放节点
	free(pDel);
	pDel = NULL;
	printf("删除成功!\n");
}

//修改节点数据
void ChangeNodedata(Node* pHead, TYPE Newdata,TYPE Predata)
{
	Node* pChange = FindNodePos(pHead, Predata);
	if (pChange == NULL)
	{
		printf("没有找到此节点!\n");
		return;
	}
	pChange->data = Newdata;
	printf("修改节点成功!\n");
}

//链表的遍历
void ShowNodeList(Node* pHead)
{
	//从第一个节点开始
	if (pHead == NULL)
	{
		printf("此链表为空!\n");
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
	//初始化一个头节点
	Node* ListH = NULL, *ListR = NULL;
	ListH = create_node(0);
	ListR = create_node(0);
	for (TYPE i = 0; i < 5; i++)
	{
		//头插法
		PushNodeH(ListH, i);
	}
	//在坐标为3的位置插入10
	InsertNode(ListH, 0, 999);
	DelNode(ListH, 0);
	ShowNodeList(ListH);
	//for (TYPE i = 0; i < 5; i++)
	//{
	//	//尾插法
	//	PushNodeR(ListR, i);
	//}
	//InsertNode(ListR, 3, 10);
	//遍历链表
	//printf("头插法: ");
	/*printf("\n尾插法: ");
	ShowNodeList(ListR);*/
	return 0;
}