#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int		data;
	struct node* next;
	struct node* prev;
};

typedef struct node Node;

Node* pHead;	//头节点
Node* pTail;	//尾节点

//创建节点
Node* createNode(int data)
{
	Node* pNew = (Node*) malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return NULL;
	}
	memset(pNew, 0, sizeof(Node));	//全部置零
	pNew->data = data;
	return pNew;
}

//插入节点 
/*
	flag<0 头插
	flag>0	尾插
	flag=0		中间插入
*/
void InsertNode(int data, int flag,int pos)
{
	Node* pNew = createNode(data);
	//如果链表为空
	if (pHead == NULL)
	{
		pHead = pTail = pNew;
		return;
	}
	if (flag < 0)
	{
		//头插
		//新节点的next指针指向首元节点
		pNew->next = pHead;
		//首元节点的prev指针指向新节点
		pHead->prev = pNew;
		//新节点成为首元节点
		pHead = pNew;
	}
	else if (flag>0)
	{
		//尾插
		//新节点的prev指针指向尾节点
		pNew->prev = pTail;
		//尾节点的next指针指向新节点
		pTail->next = pNew;
		//新节点成为尾节点
		pTail = pNew;
	}
	else if (flag==0)
	{
		//中间插入
		Node* pTemp = pHead;
		for (int i = 0; i < pos - 2; i++)
		{
			if (pTemp == NULL)
			{
				printf("链表太短了!\n");
				return;
			}
			pTemp = pTemp->next;
		}
		//到达前一个位置
		//新节点连接后面节点
		pNew->next = pTemp->next;
		pTemp->next->prev = pNew;
		//新节点连接前面节点
		pTemp->next = pNew;
		pNew->prev = pTemp;
	}
}

//统计当前链表有多少个节点
int CountNode()
{
	if (pHead == NULL)
	{
		return 0;
	}
	if (pHead == pTail)
	{
		return 1;
	}
	Node* pTemp = pHead;
	int count = 0;
	for (pTemp = pHead; pTemp; pTemp = pTemp->next)
	{
		count++;
	}
	return count;
}

//删除链表的某个位置的节点
void DelNode(int pos)
{
	int count = CountNode();
	if (pos <= 0 || pos > count)
	{
		printf("无此节点\n");
		return;
	}

	Node* pDel;
	if (pos == 1)
	{
		pDel = pHead;
		//整个链表只有一个节点
		if (count == 1)
		{
			free(pHead);
			pHead = pTail = NULL;
			return;
		}
		//整个链表有多个节点，但是删除第一个
		//先保存第一个节点
		pDel = pHead;
		//第一个节点的下一个节点的prev指针置空
		pHead->next->prev = NULL;
		//第一个节点更新
		pHead = pHead->next;
		//释放第一个节点
		free(pDel);
	}
	else if (pos == count)
	{
		//删除最后一个
		//保存最后一个的位置
		pDel = pTail;
		//最后一个节点的上一个节点的next置空
		pTail->prev->next = NULL;
		//最后一个节点更新
		pTail = pTail->prev;
		//释放最后一个节点
		free(pDel);
	}
	//在前半部分，从头到尾删
	else if (pos<=(count/2))
	{
		pDel = pHead;
		for (int i = 0; i < pos - 1; i++)
		{
			pDel = pDel->next;
		}
		//移动到待删除的节点
		//待删除节点的下一个节点的prev指向其前一个结点
		pDel->next->prev = pDel->prev;
		//待删除节点的前一个节点的next指向其下一个节点
		pDel->prev->next = pDel->next;
		//释放
		free(pDel);
	}
	//在后半部分，从尾到头删
	else
	{
		pDel = pTail;
		for (int i = 0; i < count - pos; i++)
		{
			pDel = pDel->prev;
		}
		//移动到待删除的节点
		//待删除节点的前一个节点的next指向其下一个节点
		pDel->prev->next = pDel->next;
		//待删除节点的下一个节点的prev指向其前一个节点
		pDel->next->prev = pDel->prev;
		//释放
		free(pDel);
	}
	printf("删除成功!\n");
}

//遍历节点
//flag为0 从头到尾 : flag为1 从尾到头
void ShowNode(int flag)
{
	if (pHead == NULL)
	{
		printf("这是个空链表!\n");
		return;
	}
	Node* pTemp;
	if (flag == 0)
	{
		pTemp = pHead;
		printf("从头到尾: ");
		while (pTemp)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->next;
		}
	}
	else if (flag == 1)
	{
		pTemp = pTail;
		printf("从尾到头: ");
		while (pTemp)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->prev;
		}
	}
	printf("\n");
}

//双链表的修改
void FindNode(int pos, int Newdata)
{
	if (pos<=0 || pos>CountNode())
	{
		printf("未找到该节点\n");
		return;
	}
	Node* pTemp = pHead;
	for (int i = 0; i < pos - 1; i++)
	{
		pTemp = pTemp->next;
	}
	pTemp->data = Newdata;
	printf("修改成功!\n");
}

int main(void)
{
	pHead = pTail = NULL;
	for (int i = 0; i < 10; i++)
	{
		InsertNode(i, 1,-1);
	}
	printf("插入成功!\n");
	//从头到尾遍历
	ShowNode(0);

	//flag=0  中间插入，在位置5插入99元素
	InsertNode(99, 0, 5);
	ShowNode(0);

	//修改第四个元素为100
	FindNode(4, 100);
	ShowNode(0);

	//删除第8个元素
	DelNode(8);
	ShowNode( 0);
	return 0;
}