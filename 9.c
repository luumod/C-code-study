//strlen����ԭ��
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


//strrstr  �������ƥ���λ�ã�strrpbrkͬ��
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
//	//�ڵڶ����ַ�����Ϊ��ʱ����
//	if (*s2 != '\0') {
//		current = strstr(s1, s2);
//	}
//	//ÿ���ҵ��ַ���ʱ����ָ��ָ�����ĳ�ʼλ�ã�Ȼ����Ҹ��ַ���
//	//��һ��ƥ��ĵط�
//	while (current != NULL) {
//		last = current;
//		current = strstr(last + 1, s2);	//�ƶ��ַ�������һ��λ�ã��Ա��������ƥ��λ��
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
//	//����ָ���ַ�����һ���ǿհ��ַ���ָ��
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


//��дmemcpy����
//#include <stdio.h>
//#include <assert.h>
//#define SIZE 10
//void* my_memcpy(void* dest, char* str, size_t n) {
//	//void*ָ�����ͣ�Ҫ������ת��Ϊ������Ҫ��ָ������
//	/**(char*)dest;
//	*(char*)str;*/
//
//	int* c1 = (int*)dest;
//	int* c2 = (int*)str;
//
//	assert(c1 != NULL);
//	assert(c2 != NULL);
//	//n��ӡ�Ĵ������εݼ�
//	while (n--) {
//		*c1 = *c2;
//		c1++;
//		c2++;
//	}
//}
//int main(void) {
//	int ch[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
//	int c2[SIZE];
//	my_memcpy(c2, ch, SIZE);	//��д
//	for (int i = 0; i < SIZE; i++)
//		printf("%d ", c2[i]);
//	return 0;
//}

//malloc��̬�����ڴ�
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//int main(void) {
//	//Ϊnumָ����䶯̬�ڴ�
//	int* num = (int*)malloc(10 * sizeof(int));
//	if (num == NULL) {
//		//����ʧ���򷵻ش���
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
ջ���洢�ֲ�����   �����β�
�ѣ� ��̬������ڴ�
��̬���� ȫ�ֱ���  ��̬static����
*/

/*
�ַ���ϰ�⸴ϰ
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

//2����n���ַ���ֹͣ���������հ�
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
//	//��ȡһ�����ʣ������հ�
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
//		num++;	//�ո��ж�
//	}
//	while (isalpha(*num)) {
//		*ch++ = *num++;
//	}
//	*ch = '\0';
//	return ch;
//}

//ͬ�����⣬����ָ�����ɶ�����
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

//5.strchr������д,�ַ�����
//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//char* my_strchr(char*, char);
//int main(void) {
//	char ar[SIZE];
//	char ch;
//	printf("�����ַ�����Ҫ���ҵ��ַ�:");
//	scanf("%s %c", &ar, &ch);
//	char* da = my_strchr(ar, ch);	//����һ��λ��ָ��
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


////6.is_within����������һ���ַ��Ƿ����ַ�����
//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//#define TRUE 1
//#define FLASE 0
//int is_within(char, char*);
//int main(void) {
//	char ar[SIZE];
//	char ch;
//	printf("�����ַ������������ַ�:");
//	while (scanf("%s %c", &ar, &ch)!=EOF) {
//		int result = is_within(ch, ar);
//		printf("%d\n", result);
//		printf("�����ַ������������ַ�:");
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

//7.��дmy_strncmpy����
//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//char* my_strncpy(char*, char*, int);
//int main(void) {
//	char dest[SIZE];
//	char str[SIZE];
//	int n;
//	printf("������������ַ���������:");
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
//		//���ȴ���nʱ��ֻ����Ԫ��
//		*(dest + count) = *(src + count);
//		count++;
//	}
//	//*dest = '\0';
//	if (count < n) {
//		//����С��n����Ҫ��ӿ��ַ�
//		while (count < n) {
//			*(dest + count) = '\0';
//			count++;
//		}
//	}
//	return dest;
//}


//n�Ľ׳�
//#include <stdio.h>
//long jiecheng(long);
//int main(void) {
//	long n;
//	printf("������n��ֵ������׳�:");
//	while (scanf("%ld", &n) == 1) {
//		if (!jiecheng(n))
//			printf("����û�н׳�!\n");
//		else
//			printf("!%ld = %ld\n", n, jiecheng(n));
//		printf("������n��ֵ,����׳�(����q�˳�):");
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
//	printf("������ԭ�ַ����ʹ����ҵ����ַ���:");
//	while (scanf("%s %s", &ch, &ar) != EOF) {
//		char* result = string_in(ch, ar);
//		printf("%p %c\n", result, *result);
//		printf("������ԭ�ַ����ʹ����ҵ����ַ���:");
//	}
//	return 0;
//}
//char* string_in(char* num,char* ch){
//	//��Դ�ַ�����������ַ���Ԫ���״γ��ֵ�λ��
//	char* look = ch;
//	while (*num != '\0' && *ch != '\0') {
//		for (; *num != '\0'; num++) {
//			for (look = ch; *look != '\0'; look++) {
//				if (*num == *look)
//					return num;
//			}
//		}
//	}
//	return NULL;	//û���ҵ�
//}


//�����ַ���
//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//void string_in(char*);
//int main(void) {
//	char ch[SIZE];
//	int n;
//	printf("�����������ַ���:");
//	while (scanf("%s %d", &ch,&n) != EOF) {
//		string_in(ch,n);
//		printf("%s\n",ch);
//		printf("������ԭ�ַ����ʹ����ҵ����ַ���:");
//	}
//	return 0;
//}
//void string_in(char* num,int n) {
//	//�ַ����������
//	//ͨ��ָ������
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
//	//ͨ���±�����
//	int len = strlen(num);
//	char ch[len];	//��Ҫ�䳤����ʵ��
//	char* next = ch;
//	for (int index=0; index < len; len++) {
//		next[index] = num[len - index - 1];
//	}
//	for (int i = 0; i < len; i++) {
//		num[i] = next[i];
//	}
//}



//ɾ���ַ����еĿո�
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
	//1.ʹ����ʱ�ַ�������ɾ������ַ���,ɾ����ɺ��ڸ��Ƹ�ԭ�ַ���
	//2.ʹ��ָ����±��ƶ��ķ�ʽ���жϺ�ɾ���ո�
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