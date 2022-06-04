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

Node* pHead;	//ͷ�ڵ�
Node* pTail;	//β�ڵ�

//�����ڵ�
Node* createNode(int data)
{
	Node* pNew = (Node*) malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return NULL;
	}
	memset(pNew, 0, sizeof(Node));	//ȫ������
	pNew->data = data;
	return pNew;
}

//����ڵ� 
/*
	flag<0 ͷ��
	flag>0	β��
	flag=0		�м����
*/
void InsertNode(int data, int flag,int pos)
{
	Node* pNew = createNode(data);
	//�������Ϊ��
	if (pHead == NULL)
	{
		pHead = pTail = pNew;
		return;
	}
	if (flag < 0)
	{
		//ͷ��
		//�½ڵ��nextָ��ָ����Ԫ�ڵ�
		pNew->next = pHead;
		//��Ԫ�ڵ��prevָ��ָ���½ڵ�
		pHead->prev = pNew;
		//�½ڵ��Ϊ��Ԫ�ڵ�
		pHead = pNew;
	}
	else if (flag>0)
	{
		//β��
		//�½ڵ��prevָ��ָ��β�ڵ�
		pNew->prev = pTail;
		//β�ڵ��nextָ��ָ���½ڵ�
		pTail->next = pNew;
		//�½ڵ��Ϊβ�ڵ�
		pTail = pNew;
	}
	else if (flag==0)
	{
		//�м����
		Node* pTemp = pHead;
		for (int i = 0; i < pos - 2; i++)
		{
			if (pTemp == NULL)
			{
				printf("����̫����!\n");
				return;
			}
			pTemp = pTemp->next;
		}
		//����ǰһ��λ��
		//�½ڵ����Ӻ���ڵ�
		pNew->next = pTemp->next;
		pTemp->next->prev = pNew;
		//�½ڵ�����ǰ��ڵ�
		pTemp->next = pNew;
		pNew->prev = pTemp;
	}
}

//ͳ�Ƶ�ǰ�����ж��ٸ��ڵ�
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

//ɾ�������ĳ��λ�õĽڵ�
void DelNode(int pos)
{
	int count = CountNode();
	if (pos <= 0 || pos > count)
	{
		printf("�޴˽ڵ�\n");
		return;
	}

	Node* pDel;
	if (pos == 1)
	{
		pDel = pHead;
		//��������ֻ��һ���ڵ�
		if (count == 1)
		{
			free(pHead);
			pHead = pTail = NULL;
			return;
		}
		//���������ж���ڵ㣬����ɾ����һ��
		//�ȱ����һ���ڵ�
		pDel = pHead;
		//��һ���ڵ����һ���ڵ��prevָ���ÿ�
		pHead->next->prev = NULL;
		//��һ���ڵ����
		pHead = pHead->next;
		//�ͷŵ�һ���ڵ�
		free(pDel);
	}
	else if (pos == count)
	{
		//ɾ�����һ��
		//�������һ����λ��
		pDel = pTail;
		//���һ���ڵ����һ���ڵ��next�ÿ�
		pTail->prev->next = NULL;
		//���һ���ڵ����
		pTail = pTail->prev;
		//�ͷ����һ���ڵ�
		free(pDel);
	}
	//��ǰ�벿�֣���ͷ��βɾ
	else if (pos<=(count/2))
	{
		pDel = pHead;
		for (int i = 0; i < pos - 1; i++)
		{
			pDel = pDel->next;
		}
		//�ƶ�����ɾ���Ľڵ�
		//��ɾ���ڵ����һ���ڵ��prevָ����ǰһ�����
		pDel->next->prev = pDel->prev;
		//��ɾ���ڵ��ǰһ���ڵ��nextָ������һ���ڵ�
		pDel->prev->next = pDel->next;
		//�ͷ�
		free(pDel);
	}
	//�ں�벿�֣���β��ͷɾ
	else
	{
		pDel = pTail;
		for (int i = 0; i < count - pos; i++)
		{
			pDel = pDel->prev;
		}
		//�ƶ�����ɾ���Ľڵ�
		//��ɾ���ڵ��ǰһ���ڵ��nextָ������һ���ڵ�
		pDel->prev->next = pDel->next;
		//��ɾ���ڵ����һ���ڵ��prevָ����ǰһ���ڵ�
		pDel->next->prev = pDel->prev;
		//�ͷ�
		free(pDel);
	}
	printf("ɾ���ɹ�!\n");
}

//�����ڵ�
//flagΪ0 ��ͷ��β : flagΪ1 ��β��ͷ
void ShowNode(int flag)
{
	if (pHead == NULL)
	{
		printf("���Ǹ�������!\n");
		return;
	}
	Node* pTemp;
	if (flag == 0)
	{
		pTemp = pHead;
		printf("��ͷ��β: ");
		while (pTemp)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->next;
		}
	}
	else if (flag == 1)
	{
		pTemp = pTail;
		printf("��β��ͷ: ");
		while (pTemp)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->prev;
		}
	}
	printf("\n");
}

//˫������޸�
void FindNode(int pos, int Newdata)
{
	if (pos<=0 || pos>CountNode())
	{
		printf("δ�ҵ��ýڵ�\n");
		return;
	}
	Node* pTemp = pHead;
	for (int i = 0; i < pos - 1; i++)
	{
		pTemp = pTemp->next;
	}
	pTemp->data = Newdata;
	printf("�޸ĳɹ�!\n");
}

int main(void)
{
	pHead = pTail = NULL;
	for (int i = 0; i < 10; i++)
	{
		InsertNode(i, 1,-1);
	}
	printf("����ɹ�!\n");
	//��ͷ��β����
	ShowNode(0);

	//flag=0  �м���룬��λ��5����99Ԫ��
	InsertNode(99, 0, 5);
	ShowNode(0);

	//�޸ĵ��ĸ�Ԫ��Ϊ100
	FindNode(4, 100);
	ShowNode(0);

	//ɾ����8��Ԫ��
	DelNode(8);
	ShowNode( 0);
	return 0;
}