/*
*************************����************************
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
////�������Լ����С������
//void number(int a, int b) {
//	int res = 0;
//	float c = 0;
//	res = a % b;
//	while (res!=0) {
//		a = b;
//		b = res;
//		res = a % b;
//	}
//	printf("���Լ��:%d\n", b);
//	c = (a * b) / b;
//	printf("��С������:%.2f\n", c);
//}
//int main(void) {
//	int a, b;
//	printf("��������������:");
//	while (scanf("%d %d", &a, &b) == 2) {
//		number(a, b);
//		printf("��������������:");
//	}
//	puts("BYE!");
//	return 0;
//}



//�󷽳̵ĸ� 
//void result1(float a, float b, float c) {
//	//�¶���������
//	printf("������:%.3f %.3f\n",
//		((-1) * b + sqrt(b * b - 4 * a * c)) / (2 * a),
//		((-1) * b - sqrt(b * b - 4 * a * c)) / (2 * a));
//}
//void result2(float a, float b, float c) {
//	printf("û�и�\n");
//}
//void result3(float a, float b, float c) {
//	printf("��һ����:%.3f\n",
//		((-1) * b / (2 * a)));
//}
//int main(void) {
//	float a, b, c;
//	int i, j;
//	printf("����������ϵ��:");
//	while (scanf("%f %f %f", &a, &b, &c) == 3) {
//		i = b * b - 4 * a * c;
//		if (i > 0)
//			result1(a, b, c);
//		else if (i < 0)
//			result2(a, b, c);
//		else
//			result3(a, b, c);
//		printf("����������ϵ��:");
//	}
//	return 0;
//}


//�ж�����
//int isprime(int a) {
//	for (int i = 2; i <= sqrt(a); i++) {
//		if (a % i == 0)
//			return 1;
//	}
//	return 0;
//}
//int main(void) {
//	int num;
//	printf("������һ����:");
//	while (scanf("%d", &num) == 1) {
//		if (isprime(num))
//			printf("%d������\n", num);
//		else
//			printf("%d��������\n", num);
//		printf("������һ����:");
//	}
//	printf("Bye!\n");
//	return 0;
//}



//3*3��ά����ת��
//#define SIZE 3
//void change(int (* a)[SIZE]) {
//	int ar[SIZE][SIZE];
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			ar[j][i] = a[i][j];
//		}
//	}
//	for (int i = 0; i < SIZE; i++)
//		memcpy(a[i], ar[i], sizeof(int) * SIZE);
//}
//int main(void) {
//	int num[SIZE][SIZE] = {
//		1,2,3,
//		4,5,6,
//		7,8,9
//	};
//	int dest;
//	printf("ԭ������:\n");
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++)
//			printf("%d ", num[i][j]);
//		printf("\n");
//	}
//	printf("ת��֮�������:\n");
//	change(num);
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++)
//			printf("%d ", num[i][j]);
//		printf("\n");
//	}
//	return 0;
//}




//�ַ�������
//#define SIZE 100
//void reverse(char* s) {
//	/*char* string=(char*) malloc(sizeof(char)*(strlen(s)));
//	for (int i = 0; i < strlen(s); i++) {
//		string[i] = s[strlen(s) - i-1];
//	}
//	for (int i = 0; i < strlen(s); i++) {
//		s[i] = string[i];
//	}
//	free(string);
//	string = NULL;*/
//	char temp;
//	char* string = s;
//	for (; *string != '\0'; string++)
//		;
//	string--;
//	while (s<string) {
//		temp = *s;
//		*s = *string;
//		*string = temp;
//		s++;
//		string--;
//	}
//}
//int main(void) {
//	char str[SIZE];
//	printf("�������ַ���:");
//	while (scanf("%s",&str)==1) {
//		reverse(&str);
//		printf("�����ַ���:%s\n", str);
//		printf("�������ַ���:");
//	}
//	return 0;
//}




//�����ַ���ƴ��
//#define SIZE 100
//void my_strcat(char* s1, char* s2) {
//	for (; *s1 != '\0'; s1++)
//		;
//	while (*s2 != '\0')
//		*s1++ = *s2++;
//	*s1 = '\0';
//}
//int main(void) {
//	char ch1[SIZE];
//	char ch2[SIZE];
//	printf("�����������ַ���:");
//	while (gets_s(ch1,SIZE)!=NULL && gets_s(ch2,SIZE)!=NULL) {
//		if (strcmp(ch1, "\0") == 0 && strcmp(ch2, "\0") == 0)
//			exit(EXIT_SUCCESS);
//		my_strcat(ch1, ch2);
//		printf("ƴ�Ӻ���ַ���:%s\n", ch1);
//		printf("�����������ַ���:");
//	}
//
//	return 0;
//}


//Ԫ����ĸ����
//#define SIZE 100
//char* cpy(char* s) {
//	//a e i o u
//	char string[SIZE];
//	int j = 0;
//	for (int i = 0; i < strlen(s); i++) {
//		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
//			|| s[i] == 'u') {
//			string[j++] = s[i];
//		}
//		else {
//			continue;
//		}
//	}
//	string[j] = '\0';
//	if (*string == '\0')
//		return NULL;
//	else
//		return string;
//}
//int main(void) {
//	char s[SIZE];
//	printf("�������ַ���:");
//	while (gets_s(s, SIZE) != NULL) {
//		char* str = cpy(s);
//		printf("Ԫ����ĸ:%s\n", str);
//		printf("�������ַ���:");
//	}
//
//	return 0;
//}




//�ָ�����ַ�����
//#define SIZE 100
//void PRINT(int num) {
//	char ch[SIZE];
//	int i = 0, res = 0;
//	while (num) {
//		res = num % 10;
//		ch[i++] = res+'0';	//ת��Ϊ�ַ���
//		num /= 10;
//	}
//	ch[i] = '\0';
//	for (int j = i - 1; j >= 0; j--)
//		printf("%c ", ch[j]);
//	printf("\n");
//}
//int main(void) {
//	int num;
//	printf("������һ������:");
//	while (scanf("%d", &num) == 1) {
//		PRINT(num);
//		printf("������һ������:");
//	}
//
//	return 0;
//}




//ͳ���ַ��ĸ���

//���һ���ַ��������һ������
//#define SIZE 100
//void print(char* s) {
//	int fg = 0;
//	char string[SIZE];	//�洢��ַ���
//	for (int i = 0; i < strlen(s); i++) {
//		if (fg==0) {
//			//��ʼһ������
//			fg = 1;
//			for (;*s!=' ';)
//		}
//	}
//}
//int main(void) {
//	char ch[SIZE];
//	printf("������һ���ַ�:");
//	while (gets_s(ch, SIZE) != NULL) {
//		print(ch);
//		printf("������һ���ַ�:");
//	}
//	return 0;
//}
//



//ð������

//ţ�ٵ�����


//�ݹ�
//void print(int num,int n) {
//	if (n < 0) {
//		printf("�����и�ֵŶ\n");
//		exit(EXIT_FAILURE);
//	}
//	else if (n == 0)
//		printf("1\n");
//	else if (n == 1)
//		printf("%d\n", num);
//	else {
//
//	}
//
//}
//int main(void) {
//	int n, a;
//	printf("���������������:");
//	while (scanf("%d %d", &n,&a) == 2) {
//		print(n,a);
//		printf("����������:");
//	}
//	return 0;
//}



//����ɼ�
//#define NUM 5	//��Ŀ
//#define SIZE 10	//ѧ������
//typedef struct node{
//	float score[NUM];
//	struct node* next;
//}Node;
//
//Node* Initial() {
//	float score = 0;
//	//����ͷ�ڵ�
//	Node* head = (Node*)malloc(sizeof(Node));
//	Node* r = head;
//	if (head == NULL) {
//		printf("%s\n", strerror(errno));
//		exit(EXIT_FAILURE);
//	}
//	head->next = NULL;
//	printf("������%d��ѧ����%d����Ŀ�ĳɼ���Ϣ:\n", SIZE, NUM);
//	for (int i = 0; i < SIZE; i++) {
//		Node* s = (Node*)malloc(sizeof(Node));
//		printf("��%d��ѧ��:\n", i + 1);
//		for (int j = 0; j < NUM; j++) {
//			scanf("%f", &score);
//			getchar();
//			//ÿ��ѧ���ĳɼ�����
//			s->score[j] = score;
//		}
//		//�ڵ�����β�巨
//		r->next = s;
//		s->next = NULL;
//		r = s;
//	}
//	r->next = NULL;
//	//10��ѧ����5�ſγ��������
//	return head;
//}
//
//void fangcha(float* a) {
//	float sum1 = 0, sum2 = 0;
//	for (int i = 0; i < SIZE; i++) {
//		sum1 += pow(a[i], 2);
//		sum2 += a[i];
//	}
//	printf("ȫ��ѧ����ƽ���ַ�����:%.3f\n",
//		sum1 / SIZE - pow(sum2 / SIZE, 2));
//}
//
//void av_score_peo(Node* head) {
//	//����ÿ��ѧ����ƽ����
//	Node* p = head->next;
//	float num[SIZE] = { 0 };
//	float av_num = 0;
//	int count = 0, i = 0;
//	while (p && count < SIZE) {
//		count++;
//		av_num = 0;
//		for (int j = 0; j < NUM; j++) {
//			av_num += p->score[j];
//		}
//		//����ƽ���ַ���
//		printf("��%d��ѧ���ĳɼ�ƽ����:%.3f\n",
//			count, av_num / NUM);
//		num[i++] = av_num / NUM;
//		p = p->next;
//	}
//	//ƽ���ַ���
//	fangcha(num);
//}
//
//void av_score_ke(Node* head) {
//	//����ÿ�Ƶ�ƽ����
//	float av_num = 0;
//	int count = 0;
//	for (int i = 0; i < NUM; i++) {
//		Node* p = head->next;	//ÿ�ζ���ͷ��ʼ
//		av_num = 0;
//		while (p) {
//			//ÿһ�ƣ���n��ѧ���ɼ����
//			av_num += p->score[i];
//			p = p->next;	//ת����һ��ѧ��
//		}
//		printf("��%d�Ƶ�ƽ������%.3f\n",i+1, av_num / SIZE);
//	}
//}
//
//void max_score(Node* head) {
//	//�ɼ���ߵ�һ����
//	float max_sco;
//	int a, b, count = 0;
//	Node* p = head->next;
//	max_sco = p->score[0];
//	//���Ʋ���
//	for (int i = 0; i < NUM; i++) {
//		p = head->next;
//		count = 0;
//		while (p) {
//			count++;
//			if (max_sco < p->score[i]) {
//				max_sco = p->score[i];
//				a = count;
//				b = i+1;
//			}
//			p = p->next;
//		}
//	}
//	printf("��߳ɼ��ǵ�%d��ѧ����%d�ſ�Ŀ,������:%.3f\n", a, b, max_sco);
//}
//
//void show(Node* head) {
//	//��ʾѧ���б�
//	Node* p = head->next;
//	int count = 0;
//	printf("10��ѧ���ĳɼ��б�:\n");
//	while (p && count<SIZE) {
//		count++;
//		printf("��%d��ѧ��: ", count);
//		for (int j = 0; j < NUM; j++) {
//			printf("%.2f ", p->score[j]);
//		}
//		printf("\n");
//		p = p->next;
//	}
//}
//int main(void) {
//	Node* p = Initial();	//��������
//	show(p);
//	av_score_peo(p);
//	av_score_ke(p);
//	max_score(p);
//	return 0;
//}



//ʮ��������תʮ������
//#define SIZE 20
//void change(char* n) {
//	// 9 8 2
//	int num1 = 0, sum = 0;
//	int len = strlen(n);
//	for (int i = 0; i < len; i++) {
//		num1 = 0;
//		if (isalpha(n[i])) {
//			switch (n[i]) {
//			case 'A':num1 = 10 * pow(16, len - i - 1); break;
//			case 'B':num1 = 11 * pow(16, len - i - 1); break;
//			case 'C':num1 = 12 * pow(16, len - i - 1); break;
//			case 'D':num1 = 13 * pow(16, len - i - 1); break;
//			case 'E':num1 = 14 * pow(16, len - i - 1); break;
//			case 'F':num1 = 15 * pow(16, len - i - 1); break;
//			default:printf("����ʮ��������!\n");
//				exit(EXIT_FAILURE);
//			}
//		}
//		if (isdigit(n[i])) {
//			num1 = (n[i]-'0') * pow(16, len - i - 1);
//		}
//		sum += num1;
//	}
//	printf("ʮ������:%d\n", sum);
//}
//int main(void) {
//	char n[SIZE];
//	printf("������ʮ��������:");
//	while (scanf("%s", &n) == 1) {
//		change(n);
//		printf("������ʮ����������:");
//	}
//	return 0;
//}



//�ݹ鷨������ת��Ϊ�ַ��� 483->"483"
//#define SIZE 100
//void change(int n) {
//	char num[SIZE], i = 0;
//	while (n) {
//		num[i++] = (n % 10 + '0');
//		n /= 10;
//	}
//	num[i] = '\0';
//	for (int i = strlen(num) - 1; i >= 0; i--)
//		printf("%c", num[i]);
//	printf("\n");
//}
//int main(void) {
//	long n;
//	printf("����������:");
//	while (scanf("%ld", &n) == 1) {
//		change(n);
//		printf("����������:");
//	}
//	return 0;
//}




//���������գ���������
//int days1(int n) {
//	int num;
//	switch (n) {
//	case 1:num = 31; break;
//	case 2:num = 29; break;
//	case 3:num = 31; break;
//	case 4:num = 30; break;
//	case 5:num = 31; break;
//	case 6:num = 30; break;
//	case 7:num = 31; break;
//	case 8:num = 31; break;
//	case 9:num = 30; break;
//	case 10:num = 31; break;
//	case 11:num = 30; break;
//	case 12:num = 31; break;
//	default:break;
//	}
//	return num;
//}
//void days(int a, int b, int c) {
//	int sum = 0, num = 0, m;
//	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
//		//���� 2 29
//		for (int i = 1; i < b; i++) {
//			m = days1(i);
//			sum += m;
//		}
//	}
//	else {
//		//ƽ�� 2 28
//		for (int i = 1; i < b; i++) {
//			m = days1(i);
//			sum += m;
//		}
//		sum -= 1;
//	}
//	sum += c;
//	printf("������:%d\n", sum);
//}
//int main(void) {
//	int n, j, k;
//	printf("������������:");
//	scanf("%d %d %d", &n, &j, &k);
//	days(n, j, k);
//
//	return 0;
//}



//ְ����Ϣ
//#define SIZE 5
//#define NAME_SIZE 20
//typedef struct {
//	char name[NAME_SIZE];
//	long number;
//}PEOPLE;
//int comp(PEOPLE a, PEOPLE b) {
//	return a.number - b.number;
//}
//void sqrt_peo(PEOPLE* p) {
//	//��������
//	printf("����ְ���Ŵ�С��������:\n");
//	int num[SIZE];
//	for (int i = 0; i < SIZE; i++)
//		num[i] = p[i].number;
//	for (int i = 1; i < SIZE; i++) {
//		long temp = num[i];
//		int j = i - 1;
//		while (j >= 0 && num[j] > temp) {
//			num[j + 1] = num[j];
//			j--;
//		}
//		num[j + 1] = temp;
//	}
//	//�����������
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			if (num[i] == p[j].number) {
//				printf("%s : %d\n", p[j].name, p[j].number);
//			}
//		}
//	}
//	printf("�������\n");
//}
//void look(long name,PEOPLE* p) {
//	//�Ѿ���С����������
//	int left = 0, right = SIZE - 1;
//	int middle;
//	while (left <= right) {
//		middle = left + (right - left) / 2;
//		if (name==p[middle].number)
//			break;
//		else if (name > p[middle].number) {
//			left = middle + 1;
//		}
//		else {
//			right = middle;
//		}
//	}
//	if (left <= right) {
//		printf("���ҳɹ�: %s : %d\n", p[middle].name, p[middle].number);
//	}
//	else
//		printf("û���ҵ���Ա��\n");
//}
//void Initial(PEOPLE* p) {
//	//����Ա����Ϣ
//	for (int i = 0; i < SIZE; i++) {
//		printf("�������%d��Ա������Ϣ:\n����:", i + 1);
//		scanf("%s", p[i].name);
//		printf("Ա����:");
//		scanf("%ld", &p[i].number);
//	}
//	puts("�������!\n");
//}
//void show(PEOPLE* p) {
//	for (int i = 0; i < SIZE; i++) {
//		printf("��%d��Ա������Ϣ:\n����:%s\n", i + 1,p[i].name);
//		printf("Ա����:%ld\n", p[i].number);
//	}
//}
//int main(void) {
//	PEOPLE peo[SIZE];
//	long num = 0;
//	Initial(peo);	//������Ϣ
//	//sqrt_peo(peo);	//����ְ����
//	qsort(peo, SIZE, sizeof(peo[0]), comp);	//���԰��޸Ĵ�����������
//	show(peo);		//��ʾ��ʼ��Ϣ
//	printf("��Ҫ����˭��������ְ������: ");
//	while (1) {
//		scanf("%ld", &num);
//		getchar();
//		look(num, peo);
//	}
//	return 0;	
//}


#define SIZE 5
#define NAME 20
typedef struct node{
	char name[NAME];
	long number;
	struct node* next;
}Node;
Node* Initial() {
	//��ʼ��
	Node* head = (Node*)malloc(sizeof(Node));
	Node* r = head;
	head->next = NULL;
	//β�巨
	for (int i = 0; i < SIZE; i++) {
		Node* s = (Node*)malloc(sizeof(Node));
		printf("�������%d��Ա������:\n", i + 1);
		scanf("%s", s->name);
		printf("�����빤��:\n");
		scanf("%ld", &s->number);
		r->next = s;
		s->next = NULL;
		r = s;
	}
	return head;
}
Node* bubblesort(Node* head)
{
	Node* p = NULL, * q = NULL;
	p = head->next;
	q = p->next;
	Node* temp = head;	//�洢��ʱ��Ϣ
	for (; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->number > q->number) {
				//ԭ��������
				strcpy(temp->name, p->name);
				temp->number = p->number;
				//���ݸ���
				strcpy(p->name, q->name);
				p->number = q->number;
				//ת��
				strcpy(q->name, temp->name);
				q->number = temp->number;
			}
		}
	}
	return temp;
}

void look(Node* p) {

}
void show(Node* head) {
	Node* p = head->next;
	while (p) {
		printf("%s : %d\n", p->name,p->number);
		p = p->next;
	}
}
int main(void) {
	Node* p = Initial();
	p=bubblesort(p);
	show(p);
	return 0;
}