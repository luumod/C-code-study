#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <conio.h>
//int main(void) {
//	FILE* input;
//	input = fopen("woaini", "r");
//	if (input == NULL) {
//		perror("woaini");
//		//û�ҵ����ļ������˳�
//		exit(EXIT_FAILURE);
//	}
//	return 0;
//}
//int main(void) {
//	int d = read_int();
//	printf("d\n", d);
//	return 0;
//}
//int read_int() {
//	int value=0;
//	int ch;
//
//	/*
//	ת���ӱ�׼�����ȡ�����֣����õ�һ��������ʱ��ֹͣ
//	*/
//	while ((ch = getchar()) != EOF && !isdigit(ch)) {
//		value *= 10;
//		value += ch - '0';
//	}
//	/*
//	�ѷ������ַ��˻ص�����,�������Ͳ��ᶪʧ
//	*/
//	ungetc(ch, stdin);
//	return value;
//}

//fscanf�������ļ���ȡ�ַ�
//#define SIZE 100
//int main(void) {
//	int a, b;
//	while (fscanf("input.txt", "%d %d", &a, &b) == 2) {
//		printf("%d %d\n", a, b);
//	}
//
//	return 0;
//}

//int main(void) {
//	int  n, m;
//	/*scanf("%4d %4d", &n,&m);
//	printf("%d %d", n, m);*/
//	return 0;
//}




//��sscnaf�����ж���
//#define SIZE 100
//void func(FILE* p) {
//	int a, b, c, d, e;
//	char str[SIZE];
//	while (fgets(str, SIZE, p) != NULL) {
//		if (sscanf(str, "%d %d %d %d %d", &a, &b, &c, &d, &e) != 4) {
//			printf("%d %d %d %d %d\n", a, b, c, d, e);
//			continue;
//		}
//	}
//}
//int main(void) {
//	FILE* p;
//	p = fopen("input.txt", "r");
//	func(p);
//	return 0;
//}


//��ȡ�ļ�������ͳ���ַ�����
//int main(void) {
//	int ch;
//	FILE* p;
//	unsigned long count = 0;
//	if ((p = fopen("input.txt", "r")) == NULL) {
//		printf("�޷����ļ�\n");
//		exit(EXIT_FAILURE);
//	}
//	while ((ch = getc(p)) != EOF) {
//		putc(ch, stdout);	//putchar(ch);
//		count++;
//	}
//	fclose(p);
//	printf("����ļ���%d���ַ�\n", count);
//	return 0;
//}


//exit(0)�����˳��� ���㲻����
//fopen�Ĵ�ģʽ CPP	P357

/*
ch=getchar()��ȡһ���ַ�
ch=getc(fp)	��ָ����fp�ļ��л�ȡһ���ַ�
putc(fp,fpout);
*/

//һ���򵥵��ļ�ѹ�����򣬰�һ���ļ��������ַ�ѹ��Ϊ��һ���ַ�
//int main(void) {
//	FILE* fp1,*fp2;
//	int ch;
//	int count = 0;
//	if ((fp1 = fopen("input.txt", "r")) == NULL) {
//		fprintf(strerror,"�޷���Դ�ļ�\n");
//		exit(EXIT_FAILURE);
//	}
//	if ((fp2 = fopen("cop.txt", "w+")) == NULL) {
//		fprintf(strerror, "�޷���Ŀ���ļ�\n");
//		exit(EXIT_FAILURE);
//	}
//	while ((ch = getc(fp1)) != EOF) {
//		if (count++ % 3 != 0) {
//			putc(ch, fp2);
//		}
//	}
//	if (fclose(fp1) != 0 || fclose(fp2) != 0)
//		fprintf(strerror, "�ر�ʧ��\n");
//	return 0;
//}


//���ļ����ж�д����
//#define SIZE 40
//int main(void) {
//	FILE* fp;
//	char words[SIZE];
//	if ((fp = fopen("wordy", "a+")) == NULL) {
//		fprintf(strerror, "error");
//		exit(EXIT_FAILURE);
//	}
//	puts("���ļ������뵥��:#�˳�");
//	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
//		fprintf(fp, "%s\n", words);
//	}
//	puts("�ļ�����:");
//	rewind(fp);	//��λ���ļ���ʼ��
//	while (fscanf(fp, "%s", words) == 1) {
//		puts(words);
//	}
//	puts("�������");
//	if (fclose(fp) == NULL)
//		fprintf(stderr,"error");
//	return 0;
//}


//fseek��ftell��������ʾ�ļ�����
//#define SIZE 40
//int main(void) {
//	FILE* fp;
//	char ch;
//	long last, count = 0;
//	char words[SIZE];
//	if ((fp = fopen("input.txt", "r")) == NULL) {
//		fprintf(strerror, "error");
//		exit(EXIT_FAILURE);
//	}
//	fseek(fp, 0l, SEEK_END);	//����ĩβ
//	last = ftell(fp);			//����λ��
//	for (count = 1l; count <= last; count++) {
//		fseek(fp, -count, SEEK_END);	//����������
//		putchar(ch = getc(fp));
//	}
//	putchar('\n');
//	fclose(fp);
//	return 0;
//}


//fflushˢ�»���������Ч��
//#define SIZE 40
//void main(void)
//{
//    int integer;
//    char string[81];
//
//    /* Read each word as a string. */
//    printf("Enter a sentence of four words with scanf: ");
//    for (integer = 0; integer < 4; integer++)
//    {
//        scanf("%s", string);
//        printf("%s\n", string);
//    }
//
//    /* You must flush the input buffer before using gets. */
//    fflush(stdin);
//    printf("Enter the same sentence with gets: ");
//    gets(string);
//    printf("%s\n", string);
//}


//��һϵ���ļ��е�����׷�ӵ���һ���ļ���
//#define BUFSIZE	4096
//#define SIZE 81
//void append(FILE* source, FILE* dest);
//char* s_gets(char* str, int n);
//int main(void) {
//	FILE* p1, * p2;
//	int  files = 0;
//	char file_app[SIZE];	//Ŀ���ļ���
//	char file_src[SIZE];	//Դ�ļ���
//	int ch;
//	puts("������Ŀ���ļ�����:");
//	s_gets(file_app, SIZE);
//	if ((p1 = fopen(file_app, "a+")) == NULL) {
//		fprintf(stderr, "�޷���Ŀ���ļ�:%s\n", file_app);
//		exit(EXIT_FAILURE);
//	}
//	//Ϊ�ļ����仺����
//	if (setvbuf(p1, NULL, _IOFBF, BUFSIZE) != 0) {
//		//����ʧ��
//		fprintf(stderr, "ΪĿ���ļ����仺����ʧ��\n");
//		exit(EXIT_FAILURE);
//	}
//	puts("������Դ�ļ���:");
//	while (s_gets(file_src, SIZE) && file_src[0] != '\0') {
//		if (strcmp(file_app, file_src) == 0) {
//			printf("������ͬһ���ļ�\n");
//		}
//		else if ((p2 = fopen(file_src, "r")) == NULL) {
//			fprintf(stderr, "�޷���Դ�ļ�:%s\n", file_src);
//		}
//		else {
//			//�ɹ���
//			if (setvbuf(p2, NULL, _IOFBF, BUFSIZE) != 0) {
//				fputs("ΪԴ�ļ�������仺����ʧ��\n", p2);
//				continue;
//			}
//			append(p2, p1);
//			if (ferror(p2) != 0)
//				fprintf(stderr, "��ȡԴ�ļ�ʧ��:%s\n", p2);
//			if (ferror(p1) != 0)
//				fprintf(stderr, "д��Ŀ���ļ�ʧ��:%s\n", p1);
//			fclose(p2);
//			files++;
//			printf("Դ�ļ�:%sд��ɹ�!\n", file_src);
//			puts("��������һ��Դ�ļ�:(�ո��˳�)");
//		}
//	}
//	printf("���%d���ļ����!\n",files);
//	//��ʾ����
//	rewind(p1);
//	printf("Ŀ���ļ���������:\n");
//	while ((ch = getc(p1)) != EOF)
//		putchar(ch);
//	fclose(p1);
//	return 0;
//}
//void append(FILE* source, FILE* dest) {
//	//�ļ�����׷�Ӻ���
//	size_t bytes;
//	static char temp[BUFSIZE];
//	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0) {
//		fwrite(temp, sizeof(char), bytes, dest);
//	}
//}
//char* s_gets(char* str, int n) {
//	char* ret_val;
//	char* find;
//	ret_val = fgets(str, n, stdin);
//	if (ret_val) {
//		find = strchr(str, '\n');;
//		if (*find)
//			*find = '\0';
//		else {
//			while (getchar() != '\n')
//				continue;
//		}
//	}
//	return ret_val;
//}



//����setvbuf
//void main(void)
//{
//    char buf[1024];
//    FILE* stream1, * stream2;
//
//    if (((stream1 = fopen("data1", "a")) != NULL) &&
//        ((stream2 = fopen("data2", "w")) != NULL))
//    {
//        if (setvbuf(stream1, buf, _IOFBF, sizeof(buf)) != 0)
//            printf("Incorrect type or size of buffer for stream1\n");
//        else
//            printf("'stream1' now has a buffer of 1024 bytes\n");
//        if (setvbuf(stream2, NULL, _IONBF, 0) != 0)
//            printf("Incorrect type or size of buffer for stream2\n");
//        else
//            printf("'stream2' now has no buffer\n");
//        _fcloseall();
//    }
//}


//fprintf����
//int main(void) {
//	int n = 15;
//	float f = 5.3;
//	char str[10] = "wo ai ni";
//	//FILE* p = fopen("input.txt", "w+");
//	fprintf(stderr, "%s\ndaw", str);
//	//fputs();
//	return 0;
//}



