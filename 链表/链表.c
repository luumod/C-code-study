//ʹ�ýṹ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
//#define TSIZE 45
//struct film {
//	char title[TSIZE];
//	int rating;
//	struct film* next;	//ָ���������һ���ṹ
//};
//char* s_gets(char* str, int n);
//int main(void) {
//	struct film* head = NULL;
//	struct film* prev, * current;
//	char input[TSIZE];
//
//	//�ռ����洢��Ϣ
//	puts("�����һ����Ӱ������:");
//	while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
//		//Ϊ�ṹ��ָ�붯̬�����ڴ�
//		current = (struct film*)malloc(sizeof(struct film));
//
//		//����Ƿ�ɹ���ȡ���ڴ�
//		if (current == NULL) {
//			printf("%s\n", strerror(errno));
//			exit(3);
//		}
//		if (head = NULL) {
//			//��һ���ṹ��
//			head = current;	//�ǵ�һ���ṹ������headͷָ��洢��һ���ṹ����Ϣ
//		}
//		else {
//			//��һ���ṹ��
//			prev->next = current;	//�½ṹ�ĵ�ַ�洢����һ���ṹ��
//		}
//		//�½ṹ��next��Ա����ΪNULL
//		current->next = NULL;
//		strcpy(current->title, input);	//�����Ӱ��
//		puts("�����Ӱ������: (0-10)");
//		scanf("%d", &current->rating);
//		getchar();	//ȥ������
//		puts("����ڶ�����Ӱ������: (�����˳�)");
//		prev = current;
//	}
//
//	//��ʾ��Ӱ�б�
//	if (head == NULL)
//		printf("û�е�Ӱ!\n");
//	else
//		printf("������ĵ�Ӱ�б�:\n");
//	//�ӵ�һ���ṹ�忪ʼ
//	current = head;
//	while (current != NULL) {
//		printf("Movies: %s Rating : %d\n", current->title, current->rating);
//		current = current->next;	//������һ���ṹ��
//	}
//
//	//�������,�ͷ��ѷ�����ڴ�
//	current = head;
//	while (current != NULL) {
//		head = current->next;
//		free(current);
//		current = head;
//	}
//	printf("Bye!\n");
//	return 0;
//}
//char* s_gets(char* str, int n) {
//	char* ret_val;
//	char* find;
//	ret_val = fgets(str, n, stdin);
//	if (ret_val) {
//		find = strchr(str, '\n');
//		if (*find) {
//			*find = '\0';
//		}
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}

//#define TSIZE 45
//typedef struct film{
//	char title[TSIZE];
//	int rating;
//}Item;	//����������
//
////�����ڵ�
//typedef struct node {
//	Item item;		//����������Ϣ
//	struct node* next;	//ָ����һ���ڵ��ָ��
//}Node;
//typedef Node* List;
//List movies;	//������������Ҫ��ָ��movies
////ÿ����������ڵ㣬ÿ���ڵ�����γ��������ݵ���Ϣ��ָ����һ���ڵ��ָ��
//
//typedef struct list {
//	Node* head;	//ָ������ͷ��ָ��
//	int size;	//���������
//}List;
//List movies;	//������һ������



//int main(void) {
//	int num[10][10] = { 0 };
//	for (int i = 0; i < 10; i++) {
//		num[i][0] = 1;
//	}
//	for (int i = 1; i <= 10; i++) {
//		for (int j = 1; j <= i; j++) {
//			num[i][j] = num[i - 1][j] + num[i - 1][j - 1];
//		}
//	}
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < i; j++) {
//			printf("%d ", num[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//���ӳ���
//int main(void) {
//	int sum = 1;
//	for (int i = 1; i < 10; i++) {
//		sum = (sum + 1) * 2;
//	}
//	printf("%d", sum);
//	return 0;
//}


//ţ�ٵ�����
//int main(void) {
//	double x = 1.5, x0, f1, f2;
//	do {
//		x0 = x;
//		f1 = 2 * pow(x, 3) - 4 * x * x + 3 * x - 6;
//		f2 = 6 * x * x - 8 * x + 3;
//		x = x0 - f1 / f2;
//	} while (fabs(x - x0) >= 1e-5);
//	printf("%lf", x);
//	return 0;
//}

//����
//int main(void) {
//	for (int i = 1; i <= 4; i++) {
//		for (int j = 1; j <= 4 - i; j++) {
//			printf(" ");
//		}
//		for (int k = 1; k <= 2 * i - 1; k++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = 3; i >= 1; i--) {
//		for (int j = 1; j <= 4 - i; j++)
//			printf(" ");
//		for (int k = 1; k <= 2 * i - 1; k++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}

