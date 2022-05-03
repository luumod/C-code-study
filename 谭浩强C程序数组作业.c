/*
********************谭浩强C语言数组作业*********************
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
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
//int main(void) {
//	int sum = 0;
//	int num[3][3] = {
//		1,2,3,
//		2,3,4,
//		4,5,6
//	};
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (i == j || 3 - j-1 == i)
//				sum += num[i][j];
//		}
//	}
//	printf("对角线之和:%d\n", sum);
//	return 0;
//}

//插入数组元素并且保持顺序
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




//第九题: ,折半查找法 
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


//创建一个转移表，统计个数
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






/*
********************************绿本*************************************
*/

//排序10个整数，并且插入一个数字，保持顺序
//#define SIZE 10
//int comp(int* a, int* b) {
//	if (*a > *b)
//		return 1;
//	else if (*a == *b)
//		return 0;
//	else
//		return -1;
//}
//int main(void) {
//	int ar[SIZE];
//	int a, count = 0;
//	printf("输入十个整数:");
//	for (int i = 0; i < SIZE; i++)
//		scanf("%d", &ar[i]);
//	//排序
//	qsort(ar, SIZE, sizeof(ar[0]), comp);
//
//	for (int i = 0; i < SIZE; i++)
//		printf("%d ", ar[i]);
//	printf("请插入一个数字:");
//	scanf("%d", &a);
//	for (int i = 0; i < SIZE; i++) {
//		if (a > ar[i])
//			printf("%d ", ar[i]);
//		else if (a <= ar[i] && count==0) {
//			printf("%d %d ", a, ar[i]);
//			count++;
//		}
//		else
//			printf("%d ", ar[i]);
//	}
//	if (count == 0)
//		printf("%d\n", a);
//	return 0;
//}




//对于数列的操作
//#define SIZE 4
//int main(void) {
//	int ar[SIZE][SIZE];
//	int sum = 0, J=1, a, b;
//	printf("请输入%d*%d的数组:\n", SIZE,SIZE);
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++)
//			scanf("%d", &ar[i][j]);
//	}
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			if (i == j || SIZE - i - 1 == j)
//				sum += ar[i][j];
//		}
//	}
//	printf("对角线元素之和:%d\n", sum);
//	
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			if (i == j || SIZE - i - 1 == j) {
//				if (i%2==0 && j%2==0)
//					J *= ar[i][j];
//			}
//		}
//	}
//	printf("对角线上下标为偶数元素之积:%d\n", J);
//	int max_val = ar[0][0];
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			if (i == j || SIZE-i-1==j) {
//				if (max_val < ar[i][j]) {
//					max_val = ar[i][j];
//					a = i;
//					b = j;
//				}
//			}
//		}
//	}
//	printf("对角线值最大的元素是%d，位置:%d行%d列\n", max_val, a, b);
//	return 0;
//}




//调试
//int main(void) {
//	char a[100], b[100], g[100];
//	int c, k, d;
//	char ch;
//	scanf("%s", &a);
//	scanf("%s", &b);
//	printf("a=%s,b=%s\n", a, b);
//	c = strlen(a);
//	d = strlen(b);
//	memcpy(g, b, sizeof(char) * d);
//	g[d] = '\0';
//	if (c>d)
//		//c长b短交换
//		strcpy(b, a);	//长放b
//	strcpy(a, g);	//短放a
//	printf("a=%s\n", a);
//	printf("b=%s\n", b);
//	return 0;
//
//}





//输出最长的一个字符串
//#define SIZE 10
//#define NUM 100
//char* gets_s(char* str, int n) {
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
//int main() {
//	char input[NUM] = { 0 };
//	char a[SIZE][NUM] = { 0 };
//	int t[SIZE];
//	int i = 0;
//	while (gets_s(input,NUM) != NULL && strcmp(input, "stop") != 0) {
//		strcpy(a[i], input);	//把每行输入存放到二维数组
//		t[i] = strlen(a[i]);
//		i++;
//	}
//	//找到长度最长的那一个
//	int len = t[0];
//	for (int j = 0; j < i; j++) {
//		if (len < t[j])
//			len = t[j];	//最长的长度
//	}
//	for (int j = 0; j < i; j++) {
//		if (len == t[j])
//			printf("最长的字符串: %s\n", a[j]);
//	}
//
//	return 0;
//}
//


//长度最长的字符串,方法二
//#define SIZE 100
//int main(void) {
//	char str1[SIZE];
//	char string[SIZE];
//	int len = 0, max_len = 0;
//	printf("请输入字符串:");
//	gets_s(str1, SIZE);
//	max_len = strlen(str1);
//	strcpy(string, str1);
//	printf("请输入下一个字符串:");
//	while (strcmp(str1, "stop") != 0) {
//		gets_s(str1, SIZE);
//		len = strlen(str1);
//		if (len > max_len) {
//			max_len = len;
//			strcpy(string, str1);
//		}
//	}
//	puts("输出完毕!");
//	printf("最长的字符串:%s,长度为:%d\n", string, max_len);
//
//	return 0;
//}




//删除指定位置字符
//#define SIZE 100
//void delete(char*);
//int main(void) {
//	char ch[SIZE];
//	int n;
//	printf("请输入字符串:\n");
//	while (scanf("%s",&ch)) {
//		getchar();
//		printf("请输入删除的位置:");
//		scanf("%d", &n);
//		if (n > strlen(ch)) {
//			printf("%s\n", strerror(errno));
//			exit(EXIT_FAILURE);
//		}
//		delete(ch, n);
//		printf("删除成功: %s\n", ch);
//	}
//
//	return 0;
//}
//void delete(char* str,int n) {
//	char* s = str;
//	int i = 0;
//	for (; i < n; i++) {
//		str++;
//		s++;
//	}
//	s++;	//略过那个位置
//	while (*s!= '\0') {
//		*str++ = *s++;
//	}
//	*str = '\0';
//}





//在指定位置插入字符串
//#define SIZE 100
//char* insert(char*,char*,int);
//int main(void) {
//	char ch[SIZE];
//	char ch2[SIZE];
//	int n;
//	printf("请输入字符串和待插入字符串:");
//	while (gets_s(ch,SIZE)!=NULL && gets_s(ch2,SIZE)!=NULL) {
//		printf("请输入指定位置:");
//		scanf("%d", &n);
//		getchar();
//		char* str = insert(ch, ch2, n);
//		printf("新的字符串: %s\n", str);
//	}
//	return 0;
//}
//char* insert(char* ch, char* ch2, int n) {
//	char string[SIZE];
//	char* dest;
//	//复制第一部分
//	for (int i = 0; i < n; i++)
//		string[i] = ch[i];	
//	string[n] = '\0';
//	//复制第二部分
//	dest=strcat(string, ch2);
//	//复制第三部分
//	int i = strlen(dest), j = n;
//	while (j<strlen(ch)) {
//		dest[i] = ch[j];
//		j++;
//		i++;
//	}
//	dest[i] = '\0';
//	return dest;
//}




//合并两个字符串，并且排序
//#define SIZE 100
//int comp(char* a, char* b) {
//	if (*a > *b)
//		return 1;
//	else if (*b == *a)
//		return 0;
//	else
//		return -1;
//}
//int main(void) {
//	char str1[SIZE]={0};
//	char str2[SIZE]={0};
//	puts("请输入两个字符串:");
//	while (scanf("%s %s", &str1, &str2) == 2 ) {
//		printf(str1);
//		printf(str2);
//		//合并
//		printf("\n合并后的字符串: %s \n", strcat(str1, str2));
//		qsort(str1, strlen(str1), sizeof(str1[0]), comp);
//		printf("排序后的字符串: %s\n", str1);
//		puts("请输入两个字符串:");
//	}
//
//	return 0;
//}


