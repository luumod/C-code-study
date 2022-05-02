#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
//筛选法求100以内素数
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
//			//不是素数
//			fg = 1;
//			break;
//		}
//	}
//	if (!fg) {
//		printf("%d ", n);
//	}
//}


//选择法求10个整数的排序
//void choice_sqrt(int*);
//int main(void) {
//	int m, n;
//	int num[10];
//	printf("请输入10个数字:");
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", &num[i]);
//	}
//	choice_sqrt(num);
//	return 0;
//}
//void choice_sqrt(int* num) {
//	//从大到小
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


//3*3的整形矩阵对角线元素之和

//插入数组元素
//int main(void) {
//	int n[10] = { 1,2,3,4,5,7,8,9,10,11 };
//	int a, count = 0;
//	printf("输入一个数:");
//	scanf("%d", &a);
//	for (int i = 0; i < 10; i++) {
//		if (n[i] < a) {
//			//元素一直大
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
//		//如果位于最后面
//		printf("%d", a);
//	return 0;
//}


//数组值逆序排列
//int main(void) {
//	int n[10]={1,2,3,4,5,6,7,8,9,10};
//	int rn[10] = { 0 };
//	for (int i =0; i<10; i++) {
//		rn[i] = n[10-i-1];
//	}
//	printf("原顺序:\n");
//	for (int i = 0; i < 10; i++)
//		printf("%d ", n[i]);
//	printf("\n逆序:\n");
//	for (int i = 0; i < 10; i++)
//		printf("%d ", rn[i]);
//	return 0;
//}


//杨辉三角形
//int main(void) {
//	int n[10][10] = { 0 };
//
//	//首先存储数组元素
//	for (int i = 0; i < 10; i++)
//		n[i][0] = 1;	//第一列都是1
//	for (int i = 1; i <= 10; i++) {
//		//10行
//		for (int j = 1; j <= i; j++) {
//			//每个数是上面两个数之和
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

//魔方阵

//#include<stdio.h>
//void main()
//{
//	int a[10][10];
//	int i, j, ok, n, m;
//
//	for (i = 0; i < 10; i++)                   /*给备用的数组做初始化*/
//	{
//		for (j = 0; j < 10; j++)
//			a[i][j] = 0;
//	}
//
//	ok = 0;                                  /*限定输入的数必须满足要求*/
//	while (ok == 0)
//	{
//		printf("Please input a number as the value of n:(必须是10以内的奇数)\n");
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
//	for (m = 2; m <= n * n; m++)                  /*因为1已经放好了，所以我们从2开始放*/
//	{
//
//		if ((i == 0) && (j != n - 1))            /*算法中的第3步*/
//		{
//			i = n - 1;
//			j = j + 1;
//			if (a[i][j] == 0)                  /*算法中的第7步*/
//				a[i][j] = m;
//			else
//			{
//				i = 1;
//				j = j - 1;
//				a[i][j] = m;
//			}
//		}
//
//		else if ((i != 0) && (j == n - 1))      /*算法中的第4步*/
//		{
//			i = i - 1;
//			j = 0;
//			if (a[i][j] == 0)                /*算法中的第7步*/
//				a[i][j] = m;
//			else
//			{
//				i = i + 1;
//				j = n - 1;
//				a[i][j] = m;
//			}
//		}
//
//		else if ((i == 0) && (j == n - 1))       /*算法中的第5步*/
//		{
//			i = n - 1;
//			j = 0;
//			if (a[i][j] == 0)                 /*算法中的第7步*/
//				a[i][j] = m;
//			else
//			{
//				i = 1;
//				j = n - 1;
//				a[i][j] = m;
//			}
//		}
//
//		else                                 /*算法中的第6步*/
//		{
//			i = i - 1;
//			j = j + 1;
//			if (a[i][j] == 0)                 /*算法中的第7步*/
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
//	printf("%d阶魔方阵:\n", n);
//	for (i = 0; i < n; i++)                        /*输出数组*/
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%4d", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//鞍点
//#define ROW 3
//#define COL 3
//int main(void) {
//	int num[ROW][COL];
//	int max, min, row=0, col=0, fg = 0;
//	printf("请输入数组:\n");
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < COL; j++)
//			scanf("%d", &num[i][j]);
//	}
//	//行循环
//	for (int i = 0; i < ROW; i++) {
//		max = num[i][0];
//		for (int j = 0; j < COL; j++) {
//			if (max < num[i][j]) {
//				//找出一行中的最大值的 列数
//				max = num[i][j];
//				col = j;		//找出最大值对应的列数
//			}
//		}
//		min = num[0][col];
//		//依次遍历最大列中 每一行
//		for (int k = 0; k < ROW; k++) {
//			if (min > num[k][col]) {
//				//找出对应列的最小值的 行数
//				min = num[k][col];
//				row = k;
//			}
//		}
//		//找出行列对应的数之后，比较他们
//		if (max == min && i == row) {
//			fg = 1;
//			printf("鞍点 : %d行 %d列 ：%d\n", row, col, max);
//			break;
//		}
//	}
//	if (fg == 0)
//		printf("没有鞍点\n");
//	return 0;
//}
//第九题:  
//int main(void) {
//	int num;
//	int ar[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
//	int left = 0, right = 14, middle;
//	printf("输入一个数字:");
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
//		printf("位置: %d\n", middle);
//	else
//		printf("no find\n");
//}


//链接字符串
//int main(void) {
//	char str1[40];
//	char str2[40];
//	printf("输入两个字符串:\n");
//	scanf("%s %s", &str1, &str2);
//	char* p1 = str1;
//	char* p2 = str2;
//	for (; *p1 != '\0'; p1++)
//		;	//移动到空字符处
//	while (*p2 != '\0'){
//		*p1++ = *p2++;
//	}
//	*p1++ = '\0';
//	printf("%s\n", str1);
//	return 0;
//}


//第十题 :统计个数
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
//		printf("请输入第%d行:\n", i + 1);
//		fgets(ch[i], 80, stdin);
//		printf("大写字母: %d\n", count_DA(ch[i]));
//		printf("小写字母: %d\n", count_XIAO(ch[i]));
//		printf("数字: %d\n", digit(ch[i]));
//		printf("空格字符 :%d\n", space(ch[i]));
//		printf("其他字符: %d\n", other(ch[i]));
//	}
//	printf("输入完毕\n");
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

//创建一个转移表
//static int(*func[])(char) = {
//	islower,
//	isupper,
//	isspace,
//	isdigit,
//};
//#define NO_CATEAGES (sizeof(func)/sizeof(func[0]))
//#define ROW 3
//#define COL 80
////每种类型的名字
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
//		printf("请输入第%d行: ", a + 1);
//		fgets(ch[a], COL, stdin);
//		for (int j = 0; j < strlen(ch[a]); j++) {
//			total += 1;
//			//为每一个字符调用测试函数
//			for (i = 0; i < NO_CATEAGES; i++) {
//				if (func[i](ch[a][j]))
//					count[i] += 1;
//			}
//			if (!isalnum(ch[a][j]) && !isspace(ch[a][j]))
//				count_other++;
//		}
//	}
//	puts("输入结束\n");
//	if (total == 0)
//		printf("您没有输入\n");
//	else {
//		for (i = 0; i < NO_CATEAGES; i++) {
//			printf("%s : %d\n", type[i], count[i]);
//		}
//		printf("other : %d\n", count_other);
//	}
//	return 0;
//}




//第十四题
//#define SIZE 20
//typedef int 整形;
//typedef char 字符型;
//int comp(char* a, char* b);
//int main(void) {
//	字符型 s1[SIZE];
//	字符型 s2[SIZE];
//	int ret = 0,index = 0;
//	puts("输入第一组字符:(输入回车)");
//	fgets(s1, SIZE,stdin);
//	fgets(s2, SIZE,stdin);
//	while (*s1 !='\n' && *s2 != '\n') {
//		printf("第一个相等的元素的差值: %d\n", comp(s1, s2));
//		printf("输入另一组字符:(输入回车)\n");
//		fgets(s1, SIZE,stdin);
//		fgets(s2, SIZE,stdin);
//	}
//	printf("%d", ret);
//	return 0;
//}
//int comp(char* a, char* b) {
//	while (*a != '\0' && *b != '\0') {
//		if (*a - *b!= 0) {
//			//相等
//			return *a - *b;
//		}
//		else {
//			a++;
//			b++;
//		}
//	}
//	return 0;
//}




//十五题  
//拼接字符串
//#define SIZE 20
//void my_strcat(char* s1, char* s2);
//void my_strcpy(char* s1, char* s2);
//int main(void) {
//	char str1[SIZE];
//	char str2[SIZE];
//	printf("输入两个字符串:");
//	while (scanf("%s %s", str1, str2) == 2) {
//		my_strcat(str1, str2);
//		printf("拼接字符串: %s\n", str1);
//		my_strcpy(str1, str2);
//		printf("拷贝字符串: %s\n", str1);
//		printf("输入两个字符串:");
//	}
//	return;
//}
//void my_strcat(char* s1, char* s2) {
//	int i = 0;
//	for (; *s1 != '\0'; s1++)
//		;	//到达空字符位置
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





//qsort快速排序
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