#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
#define TRUE 1
#define FALSE 0
//my_strlen����
//��ȫ��strnlen����
//int my_strnlen(char* str,int n);
//int main(void) {
//	char ch[SIZE];
//	while (scanf("%s", ch) == 1) {
//		printf("�ַ�������: %d\n", my_strnlen(ch,SIZE));
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

//my_strcpy����
//void my_strcpy(char* dest, char* str);
//int main(void) {
//	char ch[SIZE];
//	char ch2[SIZE];
//	puts("���������ַ���:");
//	while (scanf("%s %s", ch,ch2) == 2) {
//		my_strcpy(ch, ch2);
//		printf("��������ַ���: %s\n", ch);
//		puts("���������ַ���:");
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


//my_strcat����
//void my_strcat(char* dest, char* str);
//int main(void) {
//	char ch[SIZE];
//	char ch2[SIZE];
//	puts("���������ַ���:");
//	while (scanf("%s %s", ch,ch2) == 2) {
//		my_strcat(ch, ch2);
//		printf("ƴ�Ӻ���ַ���:  %s\n", ch);
//		puts("���������ַ���:");
//	}
//	return 0;
//}
//void my_strcat(char* dest, char* str) {
//	//strƴ�ӵ�dest��ĩβ
//	for (; *dest != '\0'; dest++)
//		;	//����Ŀ���ַ���ĩβ
//	while (*str != '\0') {
//		*dest++ = *str++;
//	}
//	if (*str == '\0')
//		*dest = '\0';
//}



//my_strncat����,����һ�����ȣ�ƴ�Ӻ󲻻�Խ��
//void my_strcat(char* dest, char* str,int dest_len);
//int main(void) {
//	char ch[SIZE];
//	char ch2[SIZE];
//	puts("���������ַ���:");
//	while (scanf("%s %s", ch,ch2) == 2) {
//		my_strcat(ch, ch2,SIZE);
//		printf("ƴ�Ӻ���ַ���:  %s\n", ch);
//		puts("���������ַ���:");
//	}
//	return 0;
//}
//void my_strcat(char* dest, char* str,int dest_len) {
//	strƴ�ӵ�dest��ĩβ
//	int i = 0;
//	for (; *dest != '\0'; dest++)
//		i++;	//Ҫ��¼ԭ����ĳ���
//	while (i < dest_len) {
//		if (*str != '\0')
//			*dest++ = *str++;
//		i++;
//	}
//	*dest = '\0';
//}


//my_strchr����
//char* my_strchr(char* str, char ch);
//int main(void) {
//	char ch[SIZE];
//	char value[SIZE];
//	puts("�������ַ����ʹ������ַ�:");
//	while (scanf("%s %s", ch,value) == 2) {
//		printf("�ַ�%s��λ��:%p\n", value, my_strchr(ch, value[0]));
//		puts("�������ַ����ʹ������ַ�:");
//	}
//	return 0;
//}
//char* my_strchr(char* str, char ch) {
//	//����ch�ַ����һ�γ�����str��ָ��
//	register char* last=NULL;
//	register char* next=NULL;
//	while (*str++ != '\0') {		//��ѭ��
//		next = strchr(str, ch);
//		while (next != NULL) {
//			//�����������
//			last = next;
//			next = strchr(last + 1, ch);
//		}
//	}
//	return last;
	//���ַ���
	/*for (; (str= strchr(str, ch)) != NULL; str++)
		next = str;*/

	/*return next;*/
//}


//my_strnchr����
//char* my_strnchr(char* str, char ch,int len);
//int main(void) {
//	char ch[SIZE];
//	char value[SIZE];
//	int n;
//	puts("�������ַ����ʹ������ַ���ָ���Ĵ���:");
//	while (scanf("%s %s %d", ch, value,&n) == 3) {
//		printf("�ַ�%s��λ��:%p\n", value, my_strnchr(ch, value[0],n));
//		puts("�������ַ����ʹ������ַ�:");
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


//count_char�����ַ����ַ���������
//int count_char(char* str, char ch);
//int main(void) {
//	char ch[SIZE];
//	char value[SIZE];
//	puts("�������ַ����ʹ������ַ�:");
//	while (scanf("%s %s", ch, value) == 2) {
//		printf("�ַ�����: %d \n",count_char(ch, value[0]));
//		puts("�������ַ����ʹ������ַ�:");
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



//�жϻ����ַ���
//int huiwen(const char* str);
//int main(void) {
//	char ch[SIZE];
//	puts("����һ���ַ����жϻ���:");
//	while (scanf("%s", ch) == 1) {
//		printf("%d\n", huiwen(ch));
//		puts("����һ���ַ����жϻ���:");
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



//�жϵ��� the ���ֵĴ���
//int count_the(const char* str);
//int main(void) {
//	char str[SIZE];
//	printf("�����ַ���:\n");
//	while (scanf("%s", str) == 1) {
//		printf("the ���ֵĴ���:%d\n", count_the(str));
//		printf("�����ַ���:\n");
//	}
//	return 0;
//}
//int count_the(const char* str) {
//	int word = 0;
//
//}




