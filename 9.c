//strlen函数原型
//#include <stdio.h>
//#include <string.h>
//#define SIZE 1000
//int main(void) {
//	char ch[SIZE];
//	scanf("%s", &ch);
//	char* ar = strstr(ch, "ylh");
//	printf("%p", ar);
//	/*int count = strlen(ch);
//	printf("%d", count);*/
//	return 0;
//}


//strrstr  查找最后匹配的位置，strrpbrk同理
//#include <stdio.h>
//#include <string.h>
//#define SIZE 1000
//char* my_strrstr(char const* s1, char const* s2);
//int main(void) {
//	char ch[SIZE];
//	scanf("%s", &ch);
//	//char* c1 = strstr(ch, "ylh");
//	char* c2 = my_strrstr(ch, "ylh");
//	printf("%p\n", c2);
//
//	return 0;
//}
//char* my_strrstr(char const* s1, char const* s2) {
//	register char* last;
//	register char* current;
//
//	last = NULL;
//
//	//在第二个字符串不为空时查找
//	if (*s2 != '\0') {
//		current = strstr(s1, s2);
//	}
//	//每次找到字符串时，让指针指向它的初始位置，然后查找该字符串
//	//下一次匹配的地方
//	while (current != NULL) {
//		last = current;
//		current = strstr(last + 1, s2);	//移动字符串到下一个位置，以便查找最后的匹配位置
//	}
//	return last;
//
//}

//#include <stdio.h>
//#include <string.h>
//int main(void) {
//	char ch[1000];
//	scanf("%s", ch);
//	int count = strspn(ch, "\n\f\v\r\t");
//	//计算指向字符串第一个非空白字符的指针
//	char* pt = ch + strspn(ch, "\n\f\t\v\r");
//	printf("%d", count);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main(void) {
//	int ch[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	double cg[5] = { 1.2,5.6,3.2,5.9,13.7 };
//	int target[10];
//	//memcpy(target, ch, 10*sizeof(int));
//	//memcpy(target, cg, 5 * sizeof(double));
//	memmove(ch + 2, ch, 5 * sizeof(int));
//	memcpy(target, ch, 10 * sizeof(int));
//	for (int i = 0; i < 10; i++)
//		printf("%d ", ch[i]);
//	printf("\n");
//	for (int i = 0; i < 10; i++)
//		printf("%d ", target[i]);
//	return 0;
//}


//重写memcpy函数
//#include <stdio.h>
//#include <assert.h>
//#define SIZE 10
//void* my_memcpy(void* dest, char* str, size_t n) {
//	//void*指针类型，要把他们转换为你所需要的指针类型
//	/**(char*)dest;
//	*(char*)str;*/
//
//	int* c1 = (int*)dest;
//	int* c2 = (int*)str;
//
//	assert(c1 != NULL);
//	assert(c2 != NULL);
//	//n打印的次数依次递减
//	while (n--) {
//		*c1 = *c2;
//		c1++;
//		c2++;
//	}
//}
//int main(void) {
//	int ch[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
//	int c2[SIZE];
//	my_memcpy(c2, ch, SIZE);	//重写
//	for (int i = 0; i < SIZE; i++)
//		printf("%d ", c2[i]);
//	return 0;
//}

//malloc动态分配内存
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//int main(void) {
//	//为num指针分配动态内存
//	int* num = (int*)malloc(10 * sizeof(int));
//	if (num == NULL) {
//		//分配失败则返回错误
//		printf("%s\n", strerror(errno));
//	}
//	else{
//		for (int i = 0; i < 10; i++)
//			*(num + i) = i;
//		for (int i = 0; i < 10; i++)
//			printf("%d ", *(num + i));
//	}
//	free(num);
//	return 0;
//}

/*
栈：存储局部变量   函数形参
堆： 动态分配的内存
静态区： 全局变量  静态static变量
*/

/*
字符串习题复习
*/

//1
//#include <stdio.h>
//#include <string.h>
//#define SIZE 10
//char* s_gets(char*,int);
//int main(void) {
//	char dest[SIZE];
//	s_gets(dest, SIZE);
//	int count = strlen(dest);
//	//dest[count - 1] = '\0';
//	printf("%s\n", dest);
//	return 0;
//}
//char* s_gets(char* ch,int n) {
//	int i = 0;
//	do {
//		*(ch + i) = getchar();
//	} while (*(ch + i) != EOF && ++i < n);
//	ch[i]='\0';
//	return ch;
//}

//2读到n个字符后停止或者遇到空白
//#include <stdio.h>
//#define SIZE 100
//char* read_chars(char*, int);
//int main(void) {
//	char ch[SIZE];
//	read_chars(ch, SIZE);
//	printf("%s\n", ch);
//	return 0;
//}
//char* read_chars(char* ch, int n) {
//	int i = 0;
//	do {
//		ch[i] = getchar();
//		if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n' || ch[i] == '\v')
//			break;
//	} while (ch[i] != EOF && ++i < n);
//	ch[i] = '\0';
//	return ch;
//}

//3.
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#define SIZE 100
//char* str(char*);
//int main(void) {
//	char ar[SIZE];
//	str(ar);
//	printf("%s\n", ar);
//	return 0;
//}
//char* str(char* ch) {
//	//读取一个单词，跳过空白
//	/*char input[SIZE];
//	char* num = input;
//	fgets(input, SIZE, stdin);
//	while (*num == ' ' || *num == '\n' || *num == '\t')
//		num++;
//	while (*num != '\n' && *num != ' ' && *num != '\t')
//		*ch++ = *num++;
//	*ch = '\0';*/
//	char input[SIZE];
//	char* num = input;
//	fgets(input, SIZE, stdin);
//	while (isspace(*num)) {
//		num++;	//空格判断
//	}
//	while (isalpha(*num)) {
//		*ch++ = *num++;
//	}
//	*ch = '\0';
//	return ch;
//}

//同第三题，不过指明最大可读数量
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#define SIZE 100
//char* str(char*, int);
//int main(void) {
//	char ch[SIZE];
//	str(ch, SIZE);
//	puts(ch);
//	return 0;
//}
//char* str(char* ch, int n) {
//	int i = 0;
//	char input[SIZE];
//	char* in = input;
//	fgets(input, SIZE, stdin);
//	while (isspace(*in))
//		in++;
//	while (isalpha(*in) && i < n) {
//		*ch++ = *in++;
//		i++;
//	}
//	*ch = '\0';
//	return ch;
//}

//5.strchr函数重写,字符查找
//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//char* my_strchr(char*, char);
//int main(void) {
//	char ar[SIZE];
//	char ch;
//	printf("输入字符串及要查找的字符:");
//	scanf("%s %c", &ar, &ch);
//	char* da = my_strchr(ar, ch);	//返回一个位置指针
//	printf("%p %c", da, *da);
//
//	return 0;
//}
//char* my_strchr(char* ch, char i) {
//	while (*ch != '\0') {
//		if (*ch == i)
//			return ch;
//		else{
//			ch++;
//		}
//	}
//	return NULL;
//}


////6.is_within函数，测试一个字符是否在字符串中
//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//#define TRUE 1
//#define FLASE 0
//int is_within(char, char*);
//int main(void) {
//	char ar[SIZE];
//	char ch;
//	printf("输入字符串及待查找字符:");
//	while (scanf("%s %c", &ar, &ch)!=EOF) {
//		int result = is_within(ch, ar);
//		printf("%d\n", result);
//		printf("输入字符串及待查找字符:");
//	}
//	return 0;
//}
//int is_within(char ch, char* ar) {
//	while (*ar != '\0') {
//		if (*ar == ch)
//			return TRUE;
//		else
//			ar++;
//	}
//	return FLASE;
//}

//7.重写my_strncmpy函数
//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//char* my_strncpy(char*, char*, int);
//int main(void) {
//	char dest[SIZE];
//	char str[SIZE];
//	int n;
//	printf("输入待拷贝的字符串及长度:");
//	scanf("%s %d", &str, &n);
//	char* result = my_strncpy(dest, str, n);
//	printf("%s\n", result);
//
//	return
//		;
//}
//char* my_strncpy(char* dest, char* src, int n) {
//	int count = 0;
//
//	while (*src != '\0' && count<n ) {
//		//长度大于n时，只复制元素
//		*(dest + count) = *(src + count);
//		count++;
//	}
//	//*dest = '\0';
//	if (count < n) {
//		//长度小于n，需要添加空字符
//		while (count < n) {
//			*(dest + count) = '\0';
//			count++;
//		}
//	}
//	return dest;
//}


//n的阶乘
//#include <stdio.h>
//long jiecheng(long);
//int main(void) {
//	long n;
//	printf("请输入n的值，计算阶乘:");
//	while (scanf("%ld", &n) == 1) {
//		if (!jiecheng(n))
//			printf("负数没有阶乘!\n");
//		else
//			printf("!%ld = %ld\n", n, jiecheng(n));
//		printf("请输入n的值,计算阶乘(输入q退出):");
//	}
//
//	return 0;
//}
//long jiecheng(long num) {
//	if (num <= 1) {
//		if (num < 0)
//			return 0;
//		else
//			return 1;
//	}
//	else
//		return num*jiecheng(num - 1);
//}


//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//char* string_in(char*,char*);
//int main(void) {
//	char ch[SIZE];
//	char ar[SIZE];
//	printf("请输入原字符串和待查找的子字符串:");
//	while (scanf("%s %s", &ch, &ar) != EOF) {
//		char* result = string_in(ch, ar);
//		printf("%p %c\n", result, *result);
//		printf("请输入原字符串和待查找的子字符串:");
//	}
//	return 0;
//}
//char* string_in(char* num,char* ch){
//	//在源字符串里查找子字符串元素首次出现的位置
//	char* look = ch;
//	while (*num != '\0' && *ch != '\0') {
//		for (; *num != '\0'; num++) {
//			for (look = ch; *look != '\0'; look++) {
//				if (*num == *look)
//					return num;
//			}
//		}
//	}
//	return NULL;	//没有找到
//}


//逆序字符串
//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//void string_in(char*);
//int main(void) {
//	char ch[SIZE];
//	int n;
//	printf("请输入逆序字符串:");
//	while (scanf("%s %d", &ch,&n) != EOF) {
//		string_in(ch,n);
//		printf("%s\n",ch);
//		printf("请输入原字符串和待查找的子字符串:");
//	}
//	return 0;
//}
//void string_in(char* num,int n) {
//	//字符串逆序输出
//	//通过指针排序
//	/*char* next = num;
//	for (; *next != '\0'; next++)
//		;
//	next--;
//	char temp;
//	while (num < next) {
//		temp = *num;
//		*num = *next;
//		*next = temp;
//		num++;
//		next--;
//	}*/
//	//通过下标排序
//	int len = strlen(num);
//	char ch[len];	//需要变长数组实现
//	char* next = ch;
//	for (int index=0; index < len; len++) {
//		next[index] = num[len - index - 1];
//	}
//	for (int i = 0; i < len; i++) {
//		num[i] = next[i];
//	}
//}



//删除字符串中的空格
#include <stdio.h>
#include <string.h>
#define SIZE 100
char* del_space(char* ch);
int main(void) {
	char ch[SIZE];
	fgets(ch, SIZE, stdin);
	char* p=del_space(ch);
	printf("%s", p);

	return 0;
}
char* del_space(char* ch) {
	//1.使用临时字符串保存删除后的字符串,删除完成后在复制给原字符串
	//2.使用指针的下标移动的方式，判断和删除空格
	char* cg = ch;
	int count = 0;
	while (*ch != '\0') {
		if (*ch != ' ') {
			*cg++ = *ch++;
		}
		else {
			ch++;
			count++;
		}
	}
	while (count) {
		*cg++ = '\0';
		count--;
	}
	return cg;
}