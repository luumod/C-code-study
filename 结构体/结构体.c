
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
//typedef struct {
//	int a;
//	short b[2];
//}EX2;
//typedef struct EX {
//	int a;
//	char b[3];
//	EX2 c;
//	struct EX* d;
//}EX;
//int main(void) {
//	EX x = {
//		{10},
//		"woa",
//		{5,{1,2}},
//		NULL
//	};
//	EX* px = &x;	//�ṹָ��
//	//����ָ��
//	//px��һ��ָ������������ڼ�ӷ��ʲ������������Ϊ��ֵ����px������
//	//��Ϊ��ֵ��һ����ַ
//	
//	//���ʽṹ
//	//*px��Ϊ��ֵ��һ��ֵ��ָ�������ṹ
//	//*px��Ϊ��ֵ��ʾ������һ����ֵ
//
//	//���ʽṹ��Ա
//	//px->a�õ�a�ĳ�Աֵ
//	//px������Ϊָ��ṹ��ָ�룬*px�Ľ���������ṹ,���ǵ�һ����Ա��ֵ
//
//	/*
//	int* pi;   �ܷ���piָ�����γ�Աa? 
//	pi=px;	�Ƿ�
//	pi=(int*) px;	Σ��
//	pi=&px->a;	��ȫ
//	*/
//
//	//px->b 
//
//	//����Ƕ�׵Ľṹ
//	//px->���ʽṹ��
//	//ֻ��ʹ�ýṹ��ָ��ʹ��->�����
//
//	//����ָ���ԱҪע��ṹ��ָ�벻��ָ��NULL
//
//
//	return 0;
//}


//5 �û��ṩ�ºţ�����һ���е�ĿǰΪֹ��������
//#define SIZE 20
//typedef struct {
//	char month_name[SIZE];
//	char month[SIZE];
//	int day;
//	int month_num;
//}MONTH;	//�����ṹģ��
//int all_days(MONTH* p,int n);
//int main(void) {
//	MONTH months[12] = {
//		{"January","Jan",31,1},
//		{"February","Feb",28,2},
//		{"Marth","Mar",31,3},
//		{"April","Apr",30,4},
//		{"May","May",31,5},
//		{"June","Jun",30,6},
//		{"July","July",31,7},
//		{"Auguest","Aug",31,8},
//		{"September","Sep",30,9},
//		{"October","Oct",31,10},
//		{"November","Nov",30,11},
//		{"December","Dec",31,12}
//	};	//�����ṹ���飬�洢12������Ϣ
//	int sum = 0;
//	int n;
//	printf("�����·ݺ�:");
//	scanf("%d", &n);
//	sum = all_days(months, n);
//	printf("��������:%d\n", sum);
//
//	return 0;
//}
//int all_days(MONTH func[], int n) {
//	int sum = 0;
//	if (n < 1 || n>12) {
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		for (int i = 0; i < n; i++) {
//			sum += func[i].day;
//		}
//	}
//	return sum;
//}


//������
//typedef struct {
//	float foclen;
//	float fstop;
//	char brand[30];
//}LEN;
//
//int main(void) {
//	LEN fun[10];	//10��ָ���ṹ������
//	fun[2].foclen = 500;
//	fun[2].fstop = 2.0;
//	//fun[2].brand = "Remarkata";	//����������ʼ���ַ���
//	strcpy(fun[2].brand, "Remarkata");
//
//	LEN func[10] = { 500,2.0,"Remarkata" };	//��ʼ����
//	return 0;
//}


//������
//struct name {
//	char fname[20];
//	char lname[20];
//};
//struct bem {
//	int limbs;
//	struct name title;
//	char type[30];
//};
//struct bem* pb;
//struct bem deb = {	//�����ṹ����
//	6,{"woaini","yulianghao"},"woshishuabi"
//};
//
////pb = &deb;	//pb�ṹָ��ָ��deb�Ľṹ
//
//void print(struct bem* px);
////�������
//int main(void) {
//	//��ӡָ�����ݣ�����ṹ��ַ
//	print(&deb);
//
//	return 0;
//}
//void print(struct bem* px) {
//	printf("%s %s is a %d-limbed %s\n",
//		px->title.fname, px->title.lname, px->limbs, px->type);
//
//}


//�ڰ���
//struct fullname {
//	char fname[20];
//	char lname[20];
//};
//struct bard {
//	struct fullname name;
//	int born;
//	int died;
//};
//struct bard will = {
//	{"woaini","ylhwad"},8,6
//};	//�����ṹ����
//struct bard* p = &will;
//int main(void) {
//	//����born��Աֵ,�ýṹ
//	scanf("%d", &will.born);
//	//��ָ�����born
//	scanf("%d", &p->born);
//	scanf("%s", &will.name.fname);
//	scanf("%s", &p->name.lname);
//	printf("%c\n", will.name.lname[3]);
//	printf("%d\n", strlen(will.name.fname) + strlen(p->name.lname));
//
//	return 0;
//}


//����ö��
//enum lab{no,yes,maybe};
//int main(void) {
//	printf("%d %d %d", no, yes, maybe);
//	return 0;
//}

//1.���·��������·ݺ�
//#define SIZE 20
//struct month{
//	char month_name[SIZE];
//	char month[SIZE];
//	int day;
//	int month_num;
//}months[12]={
//		{"January","Jan",31,1},
//		{"February","Feb",28,2},
//		{"Marth","Mar",31,3},
//		{"April","Apr",30,4},
//		{"May","May",31,5},
//		{"June","Jun",30,6},
//		{"July","July",31,7},
//		{"Auguest","Aug",31,8},
//		{"September","Sep",30,9},
//		{"October","Oct",31,10},
//		{"November","Nov",30,11},
//		{"December","Dec",31,12}
//};	//��ʼ���ṹģ��
//int all_days(char*);
//int main(void) {
//	int sum = 0;
//	char chars[SIZE];
//	printf("�����·�����д:");
//	scanf("%s", chars);
//	sum = all_days(chars);
//	printf("��������:%d\n", sum);
//
//	return 0;
//}
//int all_days(char* month) {
//	int sum = 0;
//	for (int i = 0; i < 12; i++) {
//		if (strcmp(month, months[i].month) == 0) {
//			return sum;
//		}
//		else
//			sum += months[i].day;
//	}
//	return -1;
//}


//�ڶ��⣺
//#define SIZE 20
//struct month{
//	char month_name[SIZE];
//	char month[SIZE];
//	int day;
//	int month_num;
//}months[12]={
//		{"January","Jan",31,1},
//		{"February","Feb",28,2},
//		{"Marth","Mar",31,3},
//		{"April","Apr",30,4},
//		{"May","May",31,5},
//		{"June","Jun",30,6},
//		{"July","July",31,7},
//		{"Auguest","Aug",31,8},
//		{"September","Sep",30,9},
//		{"October","Oct",31,10},
//		{"November","Nov",30,11},
//		{"December","Dec",31,12}
//};	//��ʼ���ṹģ��
//int all_days(int, int, int);
//int main(void) {
//	int day, month, year;
//	printf("������������:");
//	scanf("%d %d %d", &year, &month, &day);
//	int sum = all_days(year, month, day);
//	printf("����һ��Ϊֹ����������:%d\n", sum);
//
//	return 0;
//}
//int all_days(int year, int month, int day) {
//	int sum = 0;
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
//		//�����꣬2��29��
//		sum += 1;
//	}
//	for (int i = 0; i < month-1; i++) {
//		sum += months[i].day;
//	}
//	sum += day;
//	return sum;
//}


//������: �޸�ͼ��Ŀ¼����
//#define SIZE 30
//#define MAXBOOK 20
//typedef struct {
//	char book_title[SIZE];
//	char author[SIZE];
//	float price;
//}BOOK;
//void print(BOOK* p,int n);
//void price(BOOK* p, int n);
//char* s_gets(char*, int);
//int main(void) {
//	BOOK library[MAXBOOK];	//�ṹ����
//	printf("����ͼ������:\n");
//	int count = 0;
//	while (count < MAXBOOK && s_gets(library[count].book_title, SIZE) != NULL
//		&& library[count].book_title[0] != '\0') {
//		printf("��������������:\n");
//		s_gets(library[count].author, SIZE);
//		printf("������ͼ��۸�:\n");
//		scanf("%f", &library[count].price);	
//		//���������
//		while (getchar()!= '\n')
//			continue;
//		if (count < MAXBOOK)
//			printf("��������һ�������Ϣ:\n");
//		count++;
//	}
//	//�ж���û�������鼮
//	//��������˳������
//	if (count > 0) {
//		printf("��������鼮��:\n");
//		for (int i = 0; i < count; i++) {
//			printf("%s by %s is %.3f\n", library[i].book_title, library[i].author, library[i].price);
//		}
//	}
//	else {
//		printf("��û�������鼮!\n");
//	}
//	print(&library, count);	//��ĸ˳��
//	price(&library, count);	//�鼮�۸�
//
//	return 0;
//}
//void print(BOOK* p,int n) {
//	//Ϊ�˲��ı�ԭ�����ͼ��˳��Ӧ��ʹ�ú�������ʽ������һ�ݸ���
//	//������������ĸ��˳��
//	char* pbook[MAXBOOK];
//	char* temp;
//	for (int i = 0; i < n; i++) {
//		pbook[i] = p[i].book_title;	//�洢ͼ�������
//	}
//	for (int i = 0; i <  n- 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (strcmp(pbook[j],pbook[j+1])<0) {
//				//���ǰ���Ԫ��С�ں����Ԫ�أ����ظ�ֵ
//				//���մӴ�С��˳��
//				temp = pbook[j];
//				pbook[j] = pbook[j + 1];
//				pbook[j + 1] = temp;
//			}
//		}
//	}
//	pbook[n] = '\0';
//	//��ӡͼ��
//	printf("\n���ǰ���ͼ����ĸ����˳�������:\n");
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (strcmp(pbook[i], p[j].book_title) == 0) {
//				//���ͼ���������
//				printf("%s by %s is %.3f\n", p[j].book_title, p[j].author, p[j].price);
//			}
//		}
//	}
//}
//
//
//void price(BOOK* p, int n) {
//	//���ռ۸�����,��С����
//	float temp[MAXBOOK];
//	int wois;
//
//	for (int i = 0; i < n; i++) {
//		temp[i] = p[i].price;	//�����۸�
//	}
//	//ѡ������
//	int minIdx;
//	for (int i = 0; i < n - 1; i++) {
//		minIdx = i;
//		for (int j = i+1; j < n; j++) {
//			minIdx = (temp[j]<temp[minIdx]) ? j : minIdx;
//			//�����ֵС��ǰ���ֵ�����С�򽻻�����С����
//		}
//		wois = temp[i];
//		temp[i] = temp[minIdx];
//		temp[minIdx] = wois;
//	}
//	temp[n] = '\0';
//	//����
//	printf("\n���ǰ��ռ۸�˳�������:\n");
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (temp[i]==p[j].price) {
//				printf("%s by %s is %.3f\n", p[j].book_title, p[j].author, p[j].price);
//			}
//		}
//	}
//}
//
//char* s_gets(char* str, int n) {
//	//����ͼ����Ϣ����
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


//������
//#define NAME_SIZE 20
//typedef struct {
//	char fname[NAME_SIZE];
//	char mname[NAME_SIZE];
//	char lname[NAME_SIZE];
//}NAME;
//typedef struct {
//	long number;
//	NAME name;
//}PEOPLE;
//void print(PEOPLE* p);
//void value(PEOPLE);
//int main(void) {
//	PEOPLE people[5] = {
//		{100,{"aa","bb","cc"}},
//		{200,{"dd","uu","ff"}},
//		{150,{"da","da","dw"}},
//		{250,{"io","ok","pk"}},
//		{300,{"wo","oj","okc"}}
//	};	//��������ʼ��
//	//����ַ
//	print(&people);
//	return 0;
//}
//void print(PEOPLE* p) {
//	//���ݽṹ�ĵ�ַ
//	//��ӡָ����Ϣ
//	for (int i = 0; i < 5; i++) {
//		//�ж���û���м���
//		if (p[i].name.mname != '\0')
//			printf("%s,%s %s.-- %ld\n", p[i].name.fname, p[i].name.lname,
//				p[i].name.mname, p[i].number);
//		else
//			//û���м���
//			printf("%s,%s -- %ld\n", p[i].name.fname, p[i].name.lname,
//				p[i].number);
//	}
//}


//������: 
//#define NAME_SIZE 20
//#define CSIZE 4
//typedef struct {
//	char fname[NAME_SIZE];
//	char lname[NAME_SIZE];
//}NAME;
//typedef struct {
//	NAME name;
//	float grade[3];
//	float av_num;
//}PEOPLE;
//char* s_gets(char* str, int n);
//
//void write(PEOPLE* p,int n);
//void av_struct(PEOPLE* p,int n);
//void av_all(PEOPLE* p,int n);
//void print(PEOPLE* p);
//int main(void) {
//	PEOPLE student[CSIZE];
//
//	write(student,CSIZE);
//	av_struct(student, CSIZE);
//	//��ӡ
//	print(student, CSIZE);
//	av_all(student, CSIZE);
//	return;
//}
//void write(PEOPLE* p,int n) {
//	//����ѧ����Ϣ
//	char name[NAME_SIZE];
//	int i = 0;
//	for (int i = 0; i < n; i++) {
//		printf("�������%d��ѧ�����պ���:\n",i+1);
//		scanf("%s %s", &p[i].name.fname, &p[i].name.lname);
//		printf("�������%d��ѧ���ĳɼ���Ϣ:\n",i+1);
//		printf("����: ");
//		scanf("%f", &p[i].grade[0]);
//		getchar();
//		printf("��ѧ: ");
//		scanf("%f", &p[i].grade[1]);
//		getchar();
//		printf("Ӣ��: ");
//		scanf("%f", &p[i].grade[2]);
//		getchar();
//	}
//
//}
//void av_struct(PEOPLE* p,int n) {
//	//����ѧ����ƽ����
//	float num=0;
//	float av_num = 0;
//	for (int i = 0; i < n; i++) {
//		num = p[i].grade[0] + p[i].grade[1] + p[i].grade[2];
//		p[i].av_num = num / 3;
//	}
//}
//void av_all(PEOPLE* p,int n) {
//	//�༶ƽ����,���нṹ����ֵ��Ա��ƽ��ֵ
//	float sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += p[i].av_num;
//	}
//	printf("��ƽ����:%.2f\n", sum / n);
//}
//void print(PEOPLE* p,int n) {
//	//��ӡ��Ϣ
//	printf("����\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\tƽ����\n");
//	for (int i = 0; i < n; i++) {
//		printf("%s %s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", p[i].name.fname, 
//			p[i].name.lname,p[i].grade[0], p[i].grade[1], p[i].grade[2],
//			p[i].av_num);
//	}
//}
//char* s_gets(char* str, int n) {
//	char* ret_val;
//	char* find;
//	ret_val = fgets(str, n,stdin);
//	if (ret_val) {
//		find = strchr(str, '\n');
//		if (find) {
//			*find = '\0';
//		}
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}


//���˺��չ�˾��λԤ������
//#define NAME_SIZE 20
//typedef struct {
//	char fname[NAME_SIZE];
//	char lname[NAME_SIZE];
//	int booked;
//	int id;
//}PEOPLE;
//void menu(void);
//void get_empty(PEOPLE* p);
////��ʾ������λ����
//void show_empty(PEOPLE* p);
////��ʾ������λ�����Ϣ
//void show_booked(PEOPLE* p);
////��ʾ�Ѿ�Ԥ������λ��Ϣ�Ϳͻ���Ϣ
//void book_seat(PEOPLE* p);
////Ԥ����λ
//void cancel_bookd(PEOPLE* p);
////ȡ��Ԥ��
//int main(void) {
//	PEOPLE ticket[12];
//	char ch;
//	menu();
//	while ((ch = getchar()) != 'f') {
//		switch (ch) {
//		case 'a':get_empty(ticket); break;
//		case 'b':show_empty(ticket); break;
//		case 'c':show_booked(ticket); break;
//		case 'd':book_seat(ticket); break;
//		case 'e':book_seat(ticket); break;
//		default:break;
//		}
//	}
//	while (getchar() != '\n')
//		continue;
//	menu();
//	return 0;
//}
//void menu(void) {
//	printf("*************************************************\n");
//	printf("ѡ��һ������:\n");
//	puts("a. ��ʾ����λ������");
//	puts("b. ��ʾ����λ���б�");
//	puts("c. ����λ����ĸ˳������");
//	puts("d. Ϊ�û�����һ����λ");
//	puts("e. ɾ���������λ");
//	puts("f. �˳�");
//	printf("*************************************************\n");
//}
//void get_empty(PEOPLE* p) {
//	//��ʾ������λ����
//	int sum = 0;
//	for (int i = 0; i < 12; i++) {
//		if (p[i].booked == 0)
//			sum++;
//	}
//	printf("����λ����: %d\n", sum);
//
//}
//void show_empty(PEOPLE* p) {
//	//��ʾ������λ�����Ϣ
//	printf("����λ����б�:\n");
//	for (int i = 0; i < 12; i++) {
//		if (p[i].booked == 0)
//			printf("%d\n", (i + 1));
//	}
//	putchar('\n');
//}
//void show_booked(PEOPLE* p) {
//	//��ʾ�Ѿ�Ԥ������λ��Ϣ�Ϳͻ���Ϣ
//	PEOPLE* pst[12];
//	for (int i = 0; i < 12; i++) {
//		pst[i] = &p[i];
//	}
//	PEOPLE* temp;
//	for (int i = 0; i < 12 - 1; i++) {
//		for (int j = 0; j < 12 - i - 1; j++) {
//			if (strcmp(pst[j]->fname, pst[j + 1]->fname) > 0) {
//				//������ĸ��С��������
//				temp = pst[j];
//				pst[j] = pst[j + 1];
//				pst[j + 1] = temp;
//			}
//		}
//	}
//	puts("�����б�:");
//	for (int i = 0; i < 12; i++) {
//		if (pst[i]->booked == 1) {
//			printf("��λ���: %d Ԥ����:%s%s\n", pst[i]->id, pst[i]->fname,
//				pst[i]->lname);
//		}
//	}
//}
//void book_seat(PEOPLE* p) {
//	//Ԥ����λ
//	int id;
//	char fname[NAME_SIZE], lname[NAME_SIZE];
//	show_empty(p);
//	printf("����ѡ��λ: \n");
//	scanf("%d", &id);
//	if (p[id - 1].booked == 1) {
//		printf("��ѡ����\n");
//		return;
//	}
//	p[id - 1].id = id;
//	printf("����������պ���:");
//	scanf("%s %s", fname, lname);
//	strcpy(p[id].fname, fname);
//	strcpy(p[id].lname, lname);
//	p[id].booked = 1;
//	printf("Ԥ���ɹ�!\n");
//}
//void cancel_bookd(PEOPLE* p) {
//	//ȡ��Ԥ��
//	show_booked(p);
//	int id;
//	printf("������Ҫȡ������λ���: ");
//	scanf("%d", &id);
//	if (p[id - 1].booked == 0) {
//		puts("ѡ�����");
//		return;
//	}
//	p[id - 1].booked = 0;
//}


/*
************��������**********
*/
//struct func {
//	int n;
//	int ar[0];
//};
//int main(void) {
//	struct func* fa = (struct func*)malloc(sizeof(struct func*) + 5 * sizeof(int));
//	//�������飬Ϊ�ṹ������������ڴ��ַ
//	for (int i = 0; i < 5; i++) {
//		fa->ar[i] = i;
//	}
//	for (int i = 0; i < 5; i++)
//		printf("%d  ", fa->ar[i]);
//	free(fa);	//ֻ��Ҫ�ͷ�һ�Σ���Ϊ��������
//	return 0;
//}

//��ʹ���������飬Ϊָ�����ռ�
//struct func {
//	int n;
//	int* p;	//��Աָ��
//};
//int main(void) {
//	//����Ϊ�ṹ���Ա�����ڴ�
//	struct func* fa = (struct func*)malloc(sizeof(struct func));
//	//��Ϊָ������ַ
//	int* ptr = (int*)malloc(5 * sizeof(int));
//	for (int i = 0; i < 5; i++)
//		*(ptr + i) = i;
//	for (int i = 0; i < 5; i++)
//		printf("%d  ", *(ptr + i));
//	free(ptr);
//	free(fa);
//	return 0;
//}


//�������Ϸ��ʲ�ͬλ�õ�ֵ
//#define SIZE 20
//struct name1 {
//	char fname1[SIZE];
//	char lname1[SIZE];
//};
//struct name2 {
//	char fname2[SIZE];
//	char lnmae2[SIZE];
//};
//struct NAME {
//	enum {choice1,choice2} types;
//	union {
//		struct name1 people1;
//		struct name2 people2;
//	}PEOPLE;
//	int n;
//};