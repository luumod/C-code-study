#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
#define TRUE 1
#define FALSE 0
//my_strlen函数
//安全的strnlen函数
//int my_strnlen(char* str,int n);
//int main(void) {
//	char ch[SIZE];
//	while (scanf("%s", ch) == 1) {
//		printf("字符串长度: %d\n", my_strnlen(ch,SIZE));
//	}
//	return 0;
//}
//int my_strnlen(char* str,int n){
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		for (; *str != '\0'; str++)
//			count++;
//		if (*str == '\0')
//			break;
//	}
//	return count;
//}

//my_strcpy函数
//void my_strcpy(char* dest, char* str);
//int main(void) {
//	char ch[SIZE];
//	char ch2[SIZE];
//	puts("输入两个字符串:");
//	while (scanf("%s %s", ch,ch2) == 2) {
//		my_strcpy(ch, ch2);
//		printf("拷贝后的字符串: %s\n", ch);
//		puts("输入两个字符串:");
//	}
//	return 0;
//}
//void my_strcpy(char* dest, char* str) {
//	while (*str != '\0') {
//		*dest++ = *str++;
//	}
//	if (*str == '\0')
//		*dest = '\0';
//}


//my_strcat函数
//void my_strcat(char* dest, char* str);
//int main(void) {
//	char ch[SIZE];
//	char ch2[SIZE];
//	puts("输入两个字符串:");
//	while (scanf("%s %s", ch,ch2) == 2) {
//		my_strcat(ch, ch2);
//		printf("拼接后的字符串:  %s\n", ch);
//		puts("输入两个字符串:");
//	}
//	return 0;
//}
//void my_strcat(char* dest, char* str) {
//	//str拼接到dest的末尾
//	for (; *dest != '\0'; dest++)
//		;	//到达目标字符串末尾
//	while (*str != '\0') {
//		*dest++ = *str++;
//	}
//	if (*str == '\0')
//		*dest = '\0';
//}



//my_strncat函数,设置一个长度，拼接后不会越界
//void my_strcat(char* dest, char* str,int dest_len);
//int main(void) {
//	char ch[SIZE];
//	char ch2[SIZE];
//	puts("输入两个字符串:");
//	while (scanf("%s %s", ch,ch2) == 2) {
//		my_strcat(ch, ch2,SIZE);
//		printf("拼接后的字符串:  %s\n", ch);
//		puts("输入两个字符串:");
//	}
//	return 0;
//}
//void my_strcat(char* dest, char* str,int dest_len) {
//	str拼接到dest的末尾
//	int i = 0;
//	for (; *dest != '\0'; dest++)
//		i++;	//要记录原数组的长度
//	while (i < dest_len) {
//		if (*str != '\0')
//			*dest++ = *str++;
//		i++;
//	}
//	*dest = '\0';
//}


//my_strchr函数
//char* my_strchr(char* str, char ch);
//int main(void) {
//	char ch[SIZE];
//	char value[SIZE];
//	puts("请输入字符串和待查找字符:");
//	while (scanf("%s %s", ch,value) == 2) {
//		printf("字符%s，位置:%p\n", value, my_strchr(ch, value[0]));
//		puts("请输入字符串和待查找字符:");
//	}
//	return 0;
//}
//char* my_strchr(char* str, char ch) {
//	//查找ch字符最后一次出现再str的指针
//	register char* last=NULL;
//	register char* next=NULL;
//	while (*str++ != '\0') {		//死循环
//		next = strchr(str, ch);
//		while (next != NULL) {
//			//继续往后查找
//			last = next;
//			next = strchr(last + 1, ch);
//		}
//	}
//	return last;
	//两种方法
	/*for (; (str= strchr(str, ch)) != NULL; str++)
		next = str;*/

	/*return next;*/
//}


//my_strnchr函数
//char* my_strnchr(char* str, char ch,int len);
//int main(void) {
//	char ch[SIZE];
//	char value[SIZE];
//	int n;
//	puts("请输入字符串和待查找字符和指定的次数:");
//	while (scanf("%s %s %d", ch, value,&n) == 3) {
//		printf("字符%s，位置:%p\n", value, my_strnchr(ch, value[0],n));
//		puts("请输入字符串和待查找字符:");
//	}
//	return 0;
//}
//char* my_strnchr(char* str, char ch,int len) {
//	register char* next = NULL;
//	int i = 0;
//	for (; (str = strchr(str, ch))!=NULL && i < len; str++, i++)
//		next = str;
//
//	return next;
//}


//count_char返回字符再字符串的数量
//int count_char(char* str, char ch);
//int main(void) {
//	char ch[SIZE];
//	char value[SIZE];
//	puts("请输入字符串和待查找字符:");
//	while (scanf("%s %s", ch, value) == 2) {
//		printf("字符个数: %d \n",count_char(ch, value[0]));
//		puts("请输入字符串和待查找字符:");
//	}
//	return 0;
//}
//int count_char(char* str, char ch) {
//	int count = 0;
//	for (; *str != '\0'; str++) {
//		if (*str == ch)
//			count++;
//	}
//	return count;
//}



//判断回文字符串
//int huiwen(const char* str);
//int main(void) {
//	char ch[SIZE];
//	puts("输入一个字符串判断回文:");
//	while (scanf("%s", ch) == 1) {
//		printf("%d\n", huiwen(ch));
//		puts("输入一个字符串判断回文:");
//	}
//	return 0;
//}
//int huiwen(const char* str) {
//	int res = 0;
//	char* s = str;
//	for (; *s != '\0'; s++)
//		;
//	s--;
//	while (str < s) {
//		if (*str == *s) {
//			res = 1;
//		}
//		else {
//			res = 0;
//			break;
//		}
//		str++;
//		s--;
//	}
//	if (res)
//		return TRUE;
//	else
//		return FALSE;
//}



//判断单词 the 出现的次数
//int count_the(const char* str);
//int main(void) {
//	char str[SIZE];
//	printf("输入字符串:\n");
//	while (scanf("%s", str) == 1) {
//		printf("the 出现的次数:%d\n", count_the(str));
//		printf("输入字符串:\n");
//	}
//	return 0;
//}
//int count_the(const char* str) {
//	int word = 0;
//
//}




