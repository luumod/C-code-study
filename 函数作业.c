/*
*************************函数************************
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
////计算最大公约数最小公倍数
//void number(int a, int b) {
//	int res = 0;
//	float c = 0;
//	res = a % b;
//	while (res!=0) {
//		a = b;
//		b = res;
//		res = a % b;
//	}
//	printf("最大公约数:%d\n", b);
//	c = (a * b) / b;
//	printf("最小公倍数:%.2f\n", c);
//}
//int main(void) {
//	int a, b;
//	printf("请输入两个数字:");
//	while (scanf("%d %d", &a, &b) == 2) {
//		number(a, b);
//		printf("请输入两个数字:");
//	}
//	puts("BYE!");
//	return 0;
//}



//求方程的根 
//void result1(float a, float b, float c) {
//	//德尔塔大于零
//	printf("两个根:%.3f %.3f\n",
//		((-1) * b + sqrt(b * b - 4 * a * c)) / (2 * a),
//		((-1) * b - sqrt(b * b - 4 * a * c)) / (2 * a));
//}
//void result2(float a, float b, float c) {
//	printf("没有根\n");
//}
//void result3(float a, float b, float c) {
//	printf("有一个根:%.3f\n",
//		((-1) * b / (2 * a)));
//}
//int main(void) {
//	float a, b, c;
//	int i, j;
//	printf("请输入三个系数:");
//	while (scanf("%f %f %f", &a, &b, &c) == 3) {
//		i = b * b - 4 * a * c;
//		if (i > 0)
//			result1(a, b, c);
//		else if (i < 0)
//			result2(a, b, c);
//		else
//			result3(a, b, c);
//		printf("请输入三个系数:");
//	}
//	return 0;
//}


//判断素数
//int isprime(int a) {
//	for (int i = 2; i <= sqrt(a); i++) {
//		if (a % i == 0)
//			return 1;
//	}
//	return 0;
//}
//int main(void) {
//	int num;
//	printf("请输入一个数:");
//	while (scanf("%d", &num) == 1) {
//		if (isprime(num))
//			printf("%d是素数\n", num);
//		else
//			printf("%d不是素数\n", num);
//		printf("请输入一个数:");
//	}
//	printf("Bye!\n");
//	return 0;
//}



//3*3二维数组转置
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
//	printf("原来数组:\n");
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++)
//			printf("%d ", num[i][j]);
//		printf("\n");
//	}
//	printf("转置之后的数组:\n");
//	change(num);
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++)
//			printf("%d ", num[i][j]);
//		printf("\n");
//	}
//	return 0;
//}




//字符串反序
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
//	printf("请输入字符串:");
//	while (scanf("%s",&str)==1) {
//		reverse(&str);
//		printf("反序字符串:%s\n", str);
//		printf("请输入字符串:");
//	}
//	return 0;
//}




//两个字符串拼接
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
//	printf("请输入两个字符串:");
//	while (gets_s(ch1,SIZE)!=NULL && gets_s(ch2,SIZE)!=NULL) {
//		if (strcmp(ch1, "\0") == 0 && strcmp(ch2, "\0") == 0)
//			exit(EXIT_SUCCESS);
//		my_strcat(ch1, ch2);
//		printf("拼接后的字符串:%s\n", ch1);
//		printf("请输入两个字符串:");
//	}
//
//	return 0;
//}


//元音字母复制
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
//	printf("请输入字符串:");
//	while (gets_s(s, SIZE) != NULL) {
//		char* str = cpy(s);
//		printf("元音字母:%s\n", str);
//		printf("请输入字符串:");
//	}
//
//	return 0;
//}




//分隔输出字符数字
//#define SIZE 100
//void PRINT(int num) {
//	char ch[SIZE];
//	int i = 0, res = 0;
//	while (num) {
//		res = num % 10;
//		ch[i++] = res+'0';	//转换为字符型
//		num /= 10;
//	}
//	ch[i] = '\0';
//	for (int j = i - 1; j >= 0; j--)
//		printf("%c ", ch[j]);
//	printf("\n");
//}
//int main(void) {
//	int num;
//	printf("请输入一个整数:");
//	while (scanf("%d", &num) == 1) {
//		PRINT(num);
//		printf("请输入一个整数:");
//	}
//
//	return 0;
//}




//统计字符的个数

//输出一行字符串的最长的一个单词
//#define SIZE 100
//void print(char* s) {
//	int fg = 0;
//	char string[SIZE];	//存储最长字符串
//	for (int i = 0; i < strlen(s); i++) {
//		if (fg==0) {
//			//开始一个单词
//			fg = 1;
//			for (;*s!=' ';)
//		}
//	}
//}
//int main(void) {
//	char ch[SIZE];
//	printf("请输入一行字符:");
//	while (gets_s(ch, SIZE) != NULL) {
//		print(ch);
//		printf("请输入一行字符:");
//	}
//	return 0;
//}
//



//冒泡排序

//牛顿迭代法


//递归
//void print(int num,int n) {
//	if (n < 0) {
//		printf("不能有负值哦\n");
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
//	printf("请输入数字与阶数:");
//	while (scanf("%d %d", &n,&a) == 2) {
//		print(n,a);
//		printf("请输入数字:");
//	}
//	return 0;
//}



//计算成绩
//#define NUM 5	//科目
//#define SIZE 10	//学生数量
//typedef struct node{
//	float score[NUM];
//	struct node* next;
//}Node;
//
//Node* Initial() {
//	float score = 0;
//	//创建头节点
//	Node* head = (Node*)malloc(sizeof(Node));
//	Node* r = head;
//	if (head == NULL) {
//		printf("%s\n", strerror(errno));
//		exit(EXIT_FAILURE);
//	}
//	head->next = NULL;
//	printf("请输入%d个学生的%d个科目的成绩信息:\n", SIZE, NUM);
//	for (int i = 0; i < SIZE; i++) {
//		Node* s = (Node*)malloc(sizeof(Node));
//		printf("第%d个学生:\n", i + 1);
//		for (int j = 0; j < NUM; j++) {
//			scanf("%f", &score);
//			getchar();
//			//每个学生的成绩存入
//			s->score[j] = score;
//		}
//		//节点连接尾插法
//		r->next = s;
//		s->next = NULL;
//		r = s;
//	}
//	r->next = NULL;
//	//10个学生的5门课程连接完成
//	return head;
//}
//
//void fangcha(float* a) {
//	float sum1 = 0, sum2 = 0;
//	for (int i = 0; i < SIZE; i++) {
//		sum1 += pow(a[i], 2);
//		sum2 += a[i];
//	}
//	printf("全部学生的平均分方差是:%.3f\n",
//		sum1 / SIZE - pow(sum2 / SIZE, 2));
//}
//
//void av_score_peo(Node* head) {
//	//计算每个学生的平均分
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
//		//计算平均分方差
//		printf("第%d个学生的成绩平均分:%.3f\n",
//			count, av_num / NUM);
//		num[i++] = av_num / NUM;
//		p = p->next;
//	}
//	//平均分方差
//	fangcha(num);
//}
//
//void av_score_ke(Node* head) {
//	//计算每科的平均分
//	float av_num = 0;
//	int count = 0;
//	for (int i = 0; i < NUM; i++) {
//		Node* p = head->next;	//每次都从头开始
//		av_num = 0;
//		while (p) {
//			//每一科，把n名学生成绩相加
//			av_num += p->score[i];
//			p = p->next;	//转到下一个学生
//		}
//		printf("第%d科的平均分是%.3f\n",i+1, av_num / SIZE);
//	}
//}
//
//void max_score(Node* head) {
//	//成绩最高的一个人
//	float max_sco;
//	int a, b, count = 0;
//	Node* p = head->next;
//	max_sco = p->score[0];
//	//按科查找
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
//	printf("最高成绩是第%d个学生的%d门科目,分数是:%.3f\n", a, b, max_sco);
//}
//
//void show(Node* head) {
//	//显示学生列表
//	Node* p = head->next;
//	int count = 0;
//	printf("10名学生的成绩列表:\n");
//	while (p && count<SIZE) {
//		count++;
//		printf("第%d名学生: ", count);
//		for (int j = 0; j < NUM; j++) {
//			printf("%.2f ", p->score[j]);
//		}
//		printf("\n");
//		p = p->next;
//	}
//}
//int main(void) {
//	Node* p = Initial();	//链表名称
//	show(p);
//	av_score_peo(p);
//	av_score_ke(p);
//	max_score(p);
//	return 0;
//}



//十六进制数转十进制数
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
//			default:printf("不是十六进制数!\n");
//				exit(EXIT_FAILURE);
//			}
//		}
//		if (isdigit(n[i])) {
//			num1 = (n[i]-'0') * pow(16, len - i - 1);
//		}
//		sum += num1;
//	}
//	printf("十进制数:%d\n", sum);
//}
//int main(void) {
//	char n[SIZE];
//	printf("请输入十六进制数:");
//	while (scanf("%s", &n) == 1) {
//		change(n);
//		printf("请输入十六进制数字:");
//	}
//	return 0;
//}



//递归法将整形转换为字符串 483->"483"
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
//	printf("请输入数字:");
//	while (scanf("%ld", &n) == 1) {
//		change(n);
//		printf("请输入数字:");
//	}
//	return 0;
//}




//给出年月日，计算天数
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
//		//闰年 2 29
//		for (int i = 1; i < b; i++) {
//			m = days1(i);
//			sum += m;
//		}
//	}
//	else {
//		//平年 2 28
//		for (int i = 1; i < b; i++) {
//			m = days1(i);
//			sum += m;
//		}
//		sum -= 1;
//	}
//	sum += c;
//	printf("总天数:%d\n", sum);
//}
//int main(void) {
//	int n, j, k;
//	printf("请输入年月日:");
//	scanf("%d %d %d", &n, &j, &k);
//	days(n, j, k);
//
//	return 0;
//}



//职工信息
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
//	//号码排序
//	printf("按照职工号从小到大排序:\n");
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
//	//号码排序完成
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			if (num[i] == p[j].number) {
//				printf("%s : %d\n", p[j].name, p[j].number);
//			}
//		}
//	}
//	printf("排序完成\n");
//}
//void look(long name,PEOPLE* p) {
//	//已经从小到大排序了
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
//		printf("查找成功: %s : %d\n", p[middle].name, p[middle].number);
//	}
//	else
//		printf("没有找到该员工\n");
//}
//void Initial(PEOPLE* p) {
//	//输入员工信息
//	for (int i = 0; i < SIZE; i++) {
//		printf("请输入第%d个员工的信息:\n姓名:", i + 1);
//		scanf("%s", p[i].name);
//		printf("员工号:");
//		scanf("%ld", &p[i].number);
//	}
//	puts("输入完成!\n");
//}
//void show(PEOPLE* p) {
//	for (int i = 0; i < SIZE; i++) {
//		printf("第%d个员工的信息:\n姓名:%s\n", i + 1,p[i].name);
//		printf("员工号:%ld\n", p[i].number);
//	}
//}
//int main(void) {
//	PEOPLE peo[SIZE];
//	long num = 0;
//	Initial(peo);	//输入信息
//	//sqrt_peo(peo);	//排序职工号
//	qsort(peo, SIZE, sizeof(peo[0]), comp);	//可以把修改传回主调函数
//	show(peo);		//显示初始信息
//	printf("你要查找谁，请输入职工号码: ");
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
	//初始化
	Node* head = (Node*)malloc(sizeof(Node));
	Node* r = head;
	head->next = NULL;
	//尾插法
	for (int i = 0; i < SIZE; i++) {
		Node* s = (Node*)malloc(sizeof(Node));
		printf("请输入第%d个员工姓名:\n", i + 1);
		scanf("%s", s->name);
		printf("请输入工号:\n");
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
	Node* temp = head;	//存储临时信息
	for (; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->number > q->number) {
				//原内容移走
				strcpy(temp->name, p->name);
				temp->number = p->number;
				//内容更新
				strcpy(p->name, q->name);
				p->number = q->number;
				//转移
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