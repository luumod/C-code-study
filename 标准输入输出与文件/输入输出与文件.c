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
//		//没找到此文件将会退出
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
//	转换从标准输入读取的数字，当得到一个非数字时就停止
//	*/
//	while ((ch = getchar()) != EOF && !isdigit(ch)) {
//		value *= 10;
//		value += ch - '0';
//	}
//	/*
//	把非数字字符退回到流中,这样他就不会丢失
//	*/
//	ungetc(ch, stdin);
//	return value;
//}

//fscanf函数从文件读取字符
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




//用sscnaf处理行定向
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


//读取文件，并且统计字符数量
//int main(void) {
//	int ch;
//	FILE* p;
//	unsigned long count = 0;
//	if ((p = fopen("input.txt", "r")) == NULL) {
//		printf("无法打开文件\n");
//		exit(EXIT_FAILURE);
//	}
//	while ((ch = getc(p)) != EOF) {
//		putc(ch, stdout);	//putchar(ch);
//		count++;
//	}
//	fclose(p);
//	printf("这个文件有%d个字符\n", count);
//	return 0;
//}


//exit(0)正常退出， 非零不正常
//fopen的打开模式 CPP	P357

/*
ch=getchar()获取一个字符
ch=getc(fp)	从指定的fp文件中获取一个字符
putc(fp,fpout);
*/

//一个简单的文件压缩程序，把一个文件的三个字符压缩为第一个字符
//int main(void) {
//	FILE* fp1,*fp2;
//	int ch;
//	int count = 0;
//	if ((fp1 = fopen("input.txt", "r")) == NULL) {
//		fprintf(strerror,"无法打开源文件\n");
//		exit(EXIT_FAILURE);
//	}
//	if ((fp2 = fopen("cop.txt", "w+")) == NULL) {
//		fprintf(strerror, "无法打开目标文件\n");
//		exit(EXIT_FAILURE);
//	}
//	while ((ch = getc(fp1)) != EOF) {
//		if (count++ % 3 != 0) {
//			putc(ch, fp2);
//		}
//	}
//	if (fclose(fp1) != 0 || fclose(fp2) != 0)
//		fprintf(strerror, "关闭失败\n");
//	return 0;
//}


//对文件进行读写操作
//#define SIZE 40
//int main(void) {
//	FILE* fp;
//	char words[SIZE];
//	if ((fp = fopen("wordy", "a+")) == NULL) {
//		fprintf(strerror, "error");
//		exit(EXIT_FAILURE);
//	}
//	puts("往文件内输入单词:#退出");
//	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
//		fprintf(fp, "%s\n", words);
//	}
//	puts("文件内容:");
//	rewind(fp);	//定位到文件开始处
//	while (fscanf(fp, "%s", words) == 1) {
//		puts(words);
//	}
//	puts("输入完毕");
//	if (fclose(fp) == NULL)
//		fprintf(stderr,"error");
//	return 0;
//}


//fseek和ftell，倒序显示文件内容
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
//	fseek(fp, 0l, SEEK_END);	//到达末尾
//	last = ftell(fp);			//保存位置
//	for (count = 1l; count <= last; count++) {
//		fseek(fp, -count, SEEK_END);	//依次往回退
//		putchar(ch = getc(fp));
//	}
//	putchar('\n');
//	fclose(fp);
//	return 0;
//}


//fflush刷新缓冲区（无效）
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


//把一系列文件中的内容追加到另一个文件中
//#define BUFSIZE	4096
//#define SIZE 81
//void append(FILE* source, FILE* dest);
//char* s_gets(char* str, int n);
//int main(void) {
//	FILE* p1, * p2;
//	int  files = 0;
//	char file_app[SIZE];	//目标文件名
//	char file_src[SIZE];	//源文件名
//	int ch;
//	puts("请输入目标文件名字:");
//	s_gets(file_app, SIZE);
//	if ((p1 = fopen(file_app, "a+")) == NULL) {
//		fprintf(stderr, "无法打开目标文件:%s\n", file_app);
//		exit(EXIT_FAILURE);
//	}
//	//为文件分配缓冲区
//	if (setvbuf(p1, NULL, _IOFBF, BUFSIZE) != 0) {
//		//分配失败
//		fprintf(stderr, "为目标文件分配缓冲区失败\n");
//		exit(EXIT_FAILURE);
//	}
//	puts("请输入源文件名:");
//	while (s_gets(file_src, SIZE) && file_src[0] != '\0') {
//		if (strcmp(file_app, file_src) == 0) {
//			printf("不能是同一个文件\n");
//		}
//		else if ((p2 = fopen(file_src, "r")) == NULL) {
//			fprintf(stderr, "无法打开源文件:%s\n", file_src);
//		}
//		else {
//			//成功打开
//			if (setvbuf(p2, NULL, _IOFBF, BUFSIZE) != 0) {
//				fputs("为源文件输入分配缓冲区失败\n", p2);
//				continue;
//			}
//			append(p2, p1);
//			if (ferror(p2) != 0)
//				fprintf(stderr, "读取源文件失败:%s\n", p2);
//			if (ferror(p1) != 0)
//				fprintf(stderr, "写入目标文件失败:%s\n", p1);
//			fclose(p2);
//			files++;
//			printf("源文件:%s写入成功!\n", file_src);
//			puts("请输入下一个源文件:(空格退出)");
//		}
//	}
//	printf("添加%d个文件完成!\n",files);
//	//显示内容
//	rewind(p1);
//	printf("目标文件的内容是:\n");
//	while ((ch = getc(p1)) != EOF)
//		putchar(ch);
//	fclose(p1);
//	return 0;
//}
//void append(FILE* source, FILE* dest) {
//	//文件内容追加函数
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



//测试setvbuf
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


//fprintf函数
//int main(void) {
//	int n = 15;
//	float f = 5.3;
//	char str[10] = "wo ai ni";
//	//FILE* p = fopen("input.txt", "w+");
//	fprintf(stderr, "%s\ndaw", str);
//	//fputs();
//	return 0;
//}



