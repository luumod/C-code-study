#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
//ɸѡ����100��������
//void isprime(int);
//int main(void) {
//	int num[100] = {0};
//	for (int i = 1; i <= 100; i++)
//		num[i - 1] = i;
//
//	for (int i = 0; i < 100; i++) {
//		isprime(num[i]);
//	}
//	return 0;
//}
//void isprime(int n) {
//	int fg = 0;
//	for (int i = 2; i <= sqrt(n); i++) {
//		if (n % i == 0) {
//			//��������
//			fg = 1;
//			break;
//		}
//	}
//	if (!fg) {
//		printf("%d ", n);
//	}
//}


//ѡ����10������������
//void choice_sqrt(int*);
//int main(void) {
//	int m, n;
//	int num[10];
//	printf("������10������:");
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", &num[i]);
//	}
//	choice_sqrt(num);
//	return 0;
//}
//void choice_sqrt(int* num) {
//	//�Ӵ�С
//	int minIdx, temp;
//	for (int i = 0; i < 10 - 1; i++) {
//		minIdx = i;
//		for (int j = i; j < 10; j++) {
//			minIdx = (num[j] > num[minIdx]) ? j : minIdx;
//		}
//		temp = num[i];
//		num[i] = num[minIdx];
//		num[minIdx] = temp;
//	}
//	for (int i = 0; i < 10; i++)
//		printf("%d ", num[i]);
//}


//3*3�����ξ���Խ���Ԫ��֮��

//��������Ԫ��
//int main(void) {
//	int n[10] = { 1,2,3,4,5,7,8,9,10,11 };
//	int a, count = 0;
//	printf("����һ����:");
//	scanf("%d", &a);
//	for (int i = 0; i < 10; i++) {
//		if (n[i] < a) {
//			//Ԫ��һֱ��
//			printf("%d ", n[i]);
//		}
//		else if (n[i] >= a && count == 0) {
//			printf("%d %d ", a, n[i]);
//			count++;
//		}
//		else
//			printf("%d ", n[i]);
//	}
//	if (count == 0)
//		//���λ�������
//		printf("%d", a);
//	return 0;
//}


//����ֵ��������
//int main(void) {
//	int n[10]={1,2,3,4,5,6,7,8,9,10};
//	int rn[10] = { 0 };
//	for (int i =0; i<10; i++) {
//		rn[i] = n[10-i-1];
//	}
//	printf("ԭ˳��:\n");
//	for (int i = 0; i < 10; i++)
//		printf("%d ", n[i]);
//	printf("\n����:\n");
//	for (int i = 0; i < 10; i++)
//		printf("%d ", rn[i]);
//	return 0;
//}


//���������
//int main(void) {
//	int n[10][10] = { 0 };
//
//	//���ȴ洢����Ԫ��
//	for (int i = 0; i < 10; i++)
//		n[i][0] = 1;	//��һ�ж���1
//	for (int i = 1; i <= 10; i++) {
//		//10��
//		for (int j = 1; j <= i; j++) {
//			//ÿ����������������֮��
//			n[i][j] = n[i - 1][j] + n[i-1][j - 1];
//		}
//	}
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j <= i; j++) {
//			printf("%d ", n[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//ħ����

//#include<stdio.h>
//void main()
//{
//	int a[10][10];
//	int i, j, ok, n, m;
//
//	for (i = 0; i < 10; i++)                   /*�����õ���������ʼ��*/
//	{
//		for (j = 0; j < 10; j++)
//			a[i][j] = 0;
//	}
//
//	ok = 0;                                  /*�޶����������������Ҫ��*/
//	while (ok == 0)
//	{
//		printf("Please input a number as the value of n:(������10���ڵ�����)\n");
//		scanf("%d", &n);
//		if (n % 2 != 0 && n > 0 && n < 10)
//			ok = 1;
//		else
//			ok = 0;
//	}
//
//	i = 0;
//	j = n / 2;
//	a[i][j] = 1;
//	for (m = 2; m <= n * n; m++)                  /*��Ϊ1�Ѿ��ź��ˣ��������Ǵ�2��ʼ��*/
//	{
//
//		if ((i == 0) && (j != n - 1))            /*�㷨�еĵ�3��*/
//		{
//			i = n - 1;
//			j = j + 1;
//			if (a[i][j] == 0)                  /*�㷨�еĵ�7��*/
//				a[i][j] = m;
//			else
//			{
//				i = 1;
//				j = j - 1;
//				a[i][j] = m;
//			}
//		}
//
//		else if ((i != 0) && (j == n - 1))      /*�㷨�еĵ�4��*/
//		{
//			i = i - 1;
//			j = 0;
//			if (a[i][j] == 0)                /*�㷨�еĵ�7��*/
//				a[i][j] = m;
//			else
//			{
//				i = i + 1;
//				j = n - 1;
//				a[i][j] = m;
//			}
//		}
//
//		else if ((i == 0) && (j == n - 1))       /*�㷨�еĵ�5��*/
//		{
//			i = n - 1;
//			j = 0;
//			if (a[i][j] == 0)                 /*�㷨�еĵ�7��*/
//				a[i][j] = m;
//			else
//			{
//				i = 1;
//				j = n - 1;
//				a[i][j] = m;
//			}
//		}
//
//		else                                 /*�㷨�еĵ�6��*/
//		{
//			i = i - 1;
//			j = j + 1;
//			if (a[i][j] == 0)                 /*�㷨�еĵ�7��*/
//				a[i][j] = m;
//			else
//			{
//				i = i + 2;
//				j = j - 1;
//				a[i][j] = m;
//			}
//		}
//	}
//
//	printf("%d��ħ����:\n", n);
//	for (i = 0; i < n; i++)                        /*�������*/
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%4d", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//����
//#define ROW 3
//#define COL 3
//int main(void) {
//	int num[ROW][COL];
//	int max, min, row=0, col=0, fg = 0;
//	printf("����������:\n");
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < COL; j++)
//			scanf("%d", &num[i][j]);
//	}
//	//��ѭ��
//	for (int i = 0; i < ROW; i++) {
//		max = num[i][0];
//		for (int j = 0; j < COL; j++) {
//			if (max < num[i][j]) {
//				//�ҳ�һ���е����ֵ�� ����
//				max = num[i][j];
//				col = j;		//�ҳ����ֵ��Ӧ������
//			}
//		}
//		min = num[0][col];
//		//���α���������� ÿһ��
//		for (int k = 0; k < ROW; k++) {
//			if (min > num[k][col]) {
//				//�ҳ���Ӧ�е���Сֵ�� ����
//				min = num[k][col];
//				row = k;
//			}
//		}
//		//�ҳ����ж�Ӧ����֮�󣬱Ƚ�����
//		if (max == min && i == row) {
//			fg = 1;
//			printf("���� : %d�� %d�� ��%d\n", row, col, max);
//			break;
//		}
//	}
//	if (fg == 0)
//		printf("û�а���\n");
//	return 0;
//}
//�ھ���:  
//int main(void) {
//	int num;
//	int ar[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
//	int left = 0, right = 14, middle;
//	printf("����һ������:");
//	scanf("%d", &num);
//	while (left <= right) {
//		middle = left + (right - left) / 2;
//		if (ar[middle] == num)
//			break;
//		else if (ar[middle] > num)
//			right = middle - 1;
//		else if (ar[middle] < num)
//			left = middle + 1;
//	}
//	if (left <= right)
//		printf("λ��: %d\n", middle);
//	else
//		printf("no find\n");
//}


//�����ַ���
//int main(void) {
//	char str1[40];
//	char str2[40];
//	printf("���������ַ���:\n");
//	scanf("%s %s", &str1, &str2);
//	char* p1 = str1;
//	char* p2 = str2;
//	for (; *p1 != '\0'; p1++)
//		;	//�ƶ������ַ���
//	while (*p2 != '\0'){
//		*p1++ = *p2++;
//	}
//	*p1++ = '\0';
//	printf("%s\n", str1);
//	return 0;
//}


//��ʮ�� :ͳ�Ƹ���
//#define ROW 3
//#define COL 80
//int count_DA(char*);
//int count_XIAO(char*);
//int digit(char*);
//int space(char*);
//int other(char*);
//int main(void) {
//	char ch[3][80];
//	int i = 0;
//	for (int i = 0; i < 3; i++) {
//		printf("�������%d��:\n", i + 1);
//		fgets(ch[i], 80, stdin);
//		printf("��д��ĸ: %d\n", count_DA(ch[i]));
//		printf("Сд��ĸ: %d\n", count_XIAO(ch[i]));
//		printf("����: %d\n", digit(ch[i]));
//		printf("�ո��ַ� :%d\n", space(ch[i]));
//		printf("�����ַ�: %d\n", other(ch[i]));
//	}
//	printf("�������\n");
//	return 0;
//}
//int count_DA(char* str) {
//	int count = 0;
//	for (; *str != '\0'; str++) {
//		if (isupper(*str))
//			count++;
//	}
//	return count;
//}
//int count_XIAO(char* str) {
//	int count = 0;
//	for (; *str != '\0'; str++) {
//		if (islower(*str))
//			count++;
//	}
//	return count;
//}
//int digit(char* str) {
//	int count = 0;
//	for (; *str != '\0'; str++) {
//		if (isdigit(*str))
//			count++;
//	}
//	return count;
//}
//int space(char* str) {
//	int count = 0;
//	for (; *str != '\0'; str++) {
//		if (isspace(*str))
//			count++;
//	}
//	return count;
//
//}
//int other(char* str) {
//	int count = 0;
//	for (; *str != '\0'; str++) {
//		if (!islower(*str) && !isupper(*str)&& !isspace(*str)&&!isdigit(*str))
//			count++;
//	}
//	return count;
//}
//

//����һ��ת�Ʊ�
//static int(*func[])(char) = {
//	islower,
//	isupper,
//	isspace,
//	isdigit,
//};
//#define NO_CATEAGES (sizeof(func)/sizeof(func[0]))
//#define ROW 3
//#define COL 80
////ÿ�����͵�����
//char* type[] = {
//	"lower",
//	"upper",
//	"space",
//	"digit",
//};
//int main(void) {
//	int count[NO_CATEAGES] = { 0 };
//	int i = 0;
//	char ch[ROW][COL];
//	int total = 0, count_other = 0;
//	for (int a = 0; a < ROW; a++) {
//		printf("�������%d��: ", a + 1);
//		fgets(ch[a], COL, stdin);
//		for (int j = 0; j < strlen(ch[a]); j++) {
//			total += 1;
//			//Ϊÿһ���ַ����ò��Ժ���
//			for (i = 0; i < NO_CATEAGES; i++) {
//				if (func[i](ch[a][j]))
//					count[i] += 1;
//			}
//			if (!isalnum(ch[a][j]) && !isspace(ch[a][j]))
//				count_other++;
//		}
//	}
//	puts("�������\n");
//	if (total == 0)
//		printf("��û������\n");
//	else {
//		for (i = 0; i < NO_CATEAGES; i++) {
//			printf("%s : %d\n", type[i], count[i]);
//		}
//		printf("other : %d\n", count_other);
//	}
//	return 0;
//}




//��ʮ����
//#define SIZE 20
//typedef int ����;
//typedef char �ַ���;
//int comp(char* a, char* b);
//int main(void) {
//	�ַ��� s1[SIZE];
//	�ַ��� s2[SIZE];
//	int ret = 0,index = 0;
//	puts("�����һ���ַ�:(����س�)");
//	fgets(s1, SIZE,stdin);
//	fgets(s2, SIZE,stdin);
//	while (*s1 !='\n' && *s2 != '\n') {
//		printf("��һ����ȵ�Ԫ�صĲ�ֵ: %d\n", comp(s1, s2));
//		printf("������һ���ַ�:(����س�)\n");
//		fgets(s1, SIZE,stdin);
//		fgets(s2, SIZE,stdin);
//	}
//	printf("%d", ret);
//	return 0;
//}
//int comp(char* a, char* b) {
//	while (*a != '\0' && *b != '\0') {
//		if (*a - *b!= 0) {
//			//���
//			return *a - *b;
//		}
//		else {
//			a++;
//			b++;
//		}
//	}
//	return 0;
//}




//ʮ����  
//ƴ���ַ���
//#define SIZE 20
//void my_strcat(char* s1, char* s2);
//void my_strcpy(char* s1, char* s2);
//int main(void) {
//	char str1[SIZE];
//	char str2[SIZE];
//	printf("���������ַ���:");
//	while (scanf("%s %s", str1, str2) == 2) {
//		my_strcat(str1, str2);
//		printf("ƴ���ַ���: %s\n", str1);
//		my_strcpy(str1, str2);
//		printf("�����ַ���: %s\n", str1);
//		printf("���������ַ���:");
//	}
//	return;
//}
//void my_strcat(char* s1, char* s2) {
//	int i = 0;
//	for (; *s1 != '\0'; s1++)
//		;	//������ַ�λ��
//	while (*s2 != '\0') {
//		*s1++ = *s2++;
//	}
//	if (*s2 == '\0')
//		*s1 = '\0';
//}
//void my_strcpy(char* s1, char* s2) {
//	while (*s1 != '\0' && *s2 != '\0') {
//		*s1++ = *s2++;
//	}
//	if (*s2 == '\0')
//		*s1 = '\0';
//}





//qsort��������
//#define SIZE 30
//void show(int* num, int n) {
//	for (int i = 0; i < SIZE; i++) {
//		printf("%d ", num[i]);
//		if (i % 10 == 0)
//			printf("\n");
//	}
//}
//int comp(void const* p1, void const* p2);
//int main(void) {
//	int nums[SIZE];
//	for (int i = 0; i < SIZE; i++) {
//		nums[i] = rand() % 10000;
//	}
//	show(nums, SIZE);
//	printf("\n");
//	qsort(nums, SIZE, sizeof(int), comp);
//	show(nums, SIZE);
//	return 0;
//}
//int comp(void const* p1,void const* p2){
//	
//	const int* a1 = (const int*)p1;
//	const int* a2 = (const int*)p2;
//
//	if (*a1 < *a2)
//		return -1;
//	else if (*a1 == *a2)
//		return 0;
//	else
//		return 1;
//}