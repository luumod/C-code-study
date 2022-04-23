
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
//	EX* px = &x;	//结构指针
//	//访问指针
//	//px是一个指针变量，不存在间接访问操作，因此其作为右值就是px的内容
//	//作为左值是一个地址
//	
//	//访问结构
//	//*px作为右值是一个值，指向整个结构
//	//*px作为左值表示将接受一个新值
//
//	//访问结构成员
//	//px->a得到a的成员值
//	//px被声明为指向结构的指针，*px的结果是整个结构,不是第一个成员的值
//
//	/*
//	int* pi;   能否让pi指向整形成员a? 
//	pi=px;	非法
//	pi=(int*) px;	危险
//	pi=&px->a;	安全
//	*/
//
//	//px->b 
//
//	//访问嵌套的结构
//	//px->访问结构，
//	//只能使用结构的指针使用->运算符
//
//	//访问指针成员要注意结构内指针不能指向NULL
//
//
//	return 0;
//}


//5 用户提供月号，返回一年中到目前为止的总天数
//#define SIZE 20
//typedef struct {
//	char month_name[SIZE];
//	char month[SIZE];
//	int day;
//	int month_num;
//}MONTH;	//声明结构模板
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
//	};	//创建结构数组，存储12个月信息
//	int sum = 0;
//	int n;
//	printf("输入月份号:");
//	scanf("%d", &n);
//	sum = all_days(months, n);
//	printf("总天数是:%d\n", sum);
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


//第六题
//typedef struct {
//	float foclen;
//	float fstop;
//	char brand[30];
//}LEN;
//
//int main(void) {
//	LEN fun[10];	//10个指定结构的数组
//	fun[2].foclen = 500;
//	fun[2].fstop = 2.0;
//	//fun[2].brand = "Remarkata";	//不能这样初始化字符串
//	strcpy(fun[2].brand, "Remarkata");
//
//	LEN func[10] = { 500,2.0,"Remarkata" };	//初始化器
//	return 0;
//}


//第七题
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
//struct bem deb = {	//声明结构变量
//	6,{"woaini","yulianghao"},"woshishuabi"
//};
//
////pb = &deb;	//pb结构指针指向deb的结构
//
//void print(struct bem* px);
////输出内容
//int main(void) {
//	//打印指定内容，传入结构地址
//	print(&deb);
//
//	return 0;
//}
//void print(struct bem* px) {
//	printf("%s %s is a %d-limbed %s\n",
//		px->title.fname, px->title.lname, px->limbs, px->type);
//
//}


//第八题
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
//};	//创建结构变量
//struct bard* p = &will;
//int main(void) {
//	//读入born成员值,用结构
//	scanf("%d", &will.born);
//	//用指针读入born
//	scanf("%d", &p->born);
//	scanf("%s", &will.name.fname);
//	scanf("%s", &p->name.lname);
//	printf("%c\n", will.name.lname[3]);
//	printf("%d\n", strlen(will.name.fname) + strlen(p->name.lname));
//
//	return 0;
//}


//声明枚举
//enum lab{no,yes,maybe};
//int main(void) {
//	printf("%d %d %d", no, yes, maybe);
//	return 0;
//}

//1.用月份名代替月份号
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
//};	//初始化结构模板
//int all_days(char*);
//int main(void) {
//	int sum = 0;
//	char chars[SIZE];
//	printf("输入月份名缩写:");
//	scanf("%s", chars);
//	sum = all_days(chars);
//	printf("总天数是:%d\n", sum);
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


//第二题：
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
//};	//初始化结构模板
//int all_days(int, int, int);
//int main(void) {
//	int day, month, year;
//	printf("请输入年月日:");
//	scanf("%d %d %d", &year, &month, &day);
//	int sum = all_days(year, month, day);
//	printf("到这一天为止，总天数是:%d\n", sum);
//
//	return 0;
//}
//int all_days(int year, int month, int day) {
//	int sum = 0;
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
//		//是闰年，2月29天
//		sum += 1;
//	}
//	for (int i = 0; i < month-1; i++) {
//		sum += months[i].day;
//	}
//	sum += day;
//	return sum;
//}


//第三题: 修改图书目录程序
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
//	BOOK library[MAXBOOK];	//结构数组
//	printf("输入图书名字:\n");
//	int count = 0;
//	while (count < MAXBOOK && s_gets(library[count].book_title, SIZE) != NULL
//		&& library[count].book_title[0] != '\0') {
//		printf("请输入作者姓名:\n");
//		s_gets(library[count].author, SIZE);
//		printf("请输入图书价格:\n");
//		scanf("%f", &library[count].price);	
//		//会产生空行
//		while (getchar()!= '\n')
//			continue;
//		if (count < MAXBOOK)
//			printf("请输入下一本书的信息:\n");
//		count++;
//	}
//	//判断有没有输入书籍
//	//按照输入顺序排序
//	if (count > 0) {
//		printf("您输入的书籍有:\n");
//		for (int i = 0; i < count; i++) {
//			printf("%s by %s is %.3f\n", library[i].book_title, library[i].author, library[i].price);
//		}
//	}
//	else {
//		printf("你没有输入书籍!\n");
//	}
//	print(&library, count);	//字母顺序
//	price(&library, count);	//书籍价格
//
//	return 0;
//}
//void print(BOOK* p,int n) {
//	//为了不改变原输入的图书顺序，应该使用函数的形式，拷贝一份副本
//	//按照书名首字母的顺序
//	char* pbook[MAXBOOK];
//	char* temp;
//	for (int i = 0; i < n; i++) {
//		pbook[i] = p[i].book_title;	//存储图书的名字
//	}
//	for (int i = 0; i <  n- 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (strcmp(pbook[j],pbook[j+1])<0) {
//				//如果前面的元素小于后面的元素，返回负值
//				//按照从大到小的顺序
//				temp = pbook[j];
//				pbook[j] = pbook[j + 1];
//				pbook[j + 1] = temp;
//			}
//		}
//	}
//	pbook[n] = '\0';
//	//打印图书
//	printf("\n这是按照图书字母倒序顺序排序的:\n");
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (strcmp(pbook[i], p[j].book_title) == 0) {
//				//如果图书名字相等
//				printf("%s by %s is %.3f\n", p[j].book_title, p[j].author, p[j].price);
//			}
//		}
//	}
//}
//
//
//void price(BOOK* p, int n) {
//	//按照价格排序,从小到大
//	float temp[MAXBOOK];
//	int wois;
//
//	for (int i = 0; i < n; i++) {
//		temp[i] = p[i].price;	//拷贝价格
//	}
//	//选择排序
//	int minIdx;
//	for (int i = 0; i < n - 1; i++) {
//		minIdx = i;
//		for (int j = i+1; j < n; j++) {
//			minIdx = (temp[j]<temp[minIdx]) ? j : minIdx;
//			//后面的值小于前面的值吗，如果小则交换，从小到大
//		}
//		wois = temp[i];
//		temp[i] = temp[minIdx];
//		temp[minIdx] = wois;
//	}
//	temp[n] = '\0';
//	//排序
//	printf("\n这是按照价格顺序排序的:\n");
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
//	//输入图书信息函数
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


//第四题
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
//	};	//创建并初始化
//	//传地址
//	print(&people);
//	return 0;
//}
//void print(PEOPLE* p) {
//	//传递结构的地址
//	//打印指定信息
//	for (int i = 0; i < 5; i++) {
//		//判断有没有中间名
//		if (p[i].name.mname != '\0')
//			printf("%s,%s %s.-- %ld\n", p[i].name.fname, p[i].name.lname,
//				p[i].name.mname, p[i].number);
//		else
//			//没有中间名
//			printf("%s,%s -- %ld\n", p[i].name.fname, p[i].name.lname,
//				p[i].number);
//	}
//}


//第五题: 
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
//	//打印
//	print(student, CSIZE);
//	av_all(student, CSIZE);
//	return;
//}
//void write(PEOPLE* p,int n) {
//	//输入学生信息
//	char name[NAME_SIZE];
//	int i = 0;
//	for (int i = 0; i < n; i++) {
//		printf("请输入第%d个学生的姓和名:\n",i+1);
//		scanf("%s %s", &p[i].name.fname, &p[i].name.lname);
//		printf("请输入第%d个学生的成绩信息:\n",i+1);
//		printf("语文: ");
//		scanf("%f", &p[i].grade[0]);
//		getchar();
//		printf("数学: ");
//		scanf("%f", &p[i].grade[1]);
//		getchar();
//		printf("英语: ");
//		scanf("%f", &p[i].grade[2]);
//		getchar();
//	}
//
//}
//void av_struct(PEOPLE* p,int n) {
//	//计算学生的平均分
//	float num=0;
//	float av_num = 0;
//	for (int i = 0; i < n; i++) {
//		num = p[i].grade[0] + p[i].grade[1] + p[i].grade[2];
//		p[i].av_num = num / 3;
//	}
//}
//void av_all(PEOPLE* p,int n) {
//	//班级平均分,所有结构的数值成员的平均值
//	float sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += p[i].av_num;
//	}
//	printf("总平均分:%.2f\n", sum / n);
//}
//void print(PEOPLE* p,int n) {
//	//打印信息
//	printf("姓名\t语文成绩\t数学成绩\t英语成绩\t平均分\n");
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


//巨人航空公司座位预定程序
//#define NAME_SIZE 20
//typedef struct {
//	char fname[NAME_SIZE];
//	char lname[NAME_SIZE];
//	int booked;
//	int id;
//}PEOPLE;
//void menu(void);
//void get_empty(PEOPLE* p);
////显示空余座位数量
//void show_empty(PEOPLE* p);
////显示空余座位编号信息
//void show_booked(PEOPLE* p);
////显示已经预定的座位信息和客户信息
//void book_seat(PEOPLE* p);
////预定座位
//void cancel_bookd(PEOPLE* p);
////取消预定
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
//	printf("选择一个功能:\n");
//	puts("a. 显示空座位的数量");
//	puts("b. 显示空座位的列表");
//	puts("c. 将座位按字母顺序排序");
//	puts("d. 为用户分配一个座位");
//	puts("e. 删除分配的座位");
//	puts("f. 退出");
//	printf("*************************************************\n");
//}
//void get_empty(PEOPLE* p) {
//	//显示空余座位数量
//	int sum = 0;
//	for (int i = 0; i < 12; i++) {
//		if (p[i].booked == 0)
//			sum++;
//	}
//	printf("空座位数量: %d\n", sum);
//
//}
//void show_empty(PEOPLE* p) {
//	//显示空余座位编号信息
//	printf("空座位编号列表:\n");
//	for (int i = 0; i < 12; i++) {
//		if (p[i].booked == 0)
//			printf("%d\n", (i + 1));
//	}
//	putchar('\n');
//}
//void show_booked(PEOPLE* p) {
//	//显示已经预定的座位信息和客户信息
//	PEOPLE* pst[12];
//	for (int i = 0; i < 12; i++) {
//		pst[i] = &p[i];
//	}
//	PEOPLE* temp;
//	for (int i = 0; i < 12 - 1; i++) {
//		for (int j = 0; j < 12 - i - 1; j++) {
//			if (strcmp(pst[j]->fname, pst[j + 1]->fname) > 0) {
//				//按照字母从小到大排序
//				temp = pst[j];
//				pst[j] = pst[j + 1];
//				pst[j + 1] = temp;
//			}
//		}
//	}
//	puts("排序列表:");
//	for (int i = 0; i < 12; i++) {
//		if (pst[i]->booked == 1) {
//			printf("座位编号: %d 预定人:%s%s\n", pst[i]->id, pst[i]->fname,
//				pst[i]->lname);
//		}
//	}
//}
//void book_seat(PEOPLE* p) {
//	//预定座位
//	int id;
//	char fname[NAME_SIZE], lname[NAME_SIZE];
//	show_empty(p);
//	printf("请挑选座位: \n");
//	scanf("%d", &id);
//	if (p[id - 1].booked == 1) {
//		printf("挑选错误\n");
//		return;
//	}
//	p[id - 1].id = id;
//	printf("请输入你的姓和名:");
//	scanf("%s %s", fname, lname);
//	strcpy(p[id].fname, fname);
//	strcpy(p[id].lname, lname);
//	p[id].booked = 1;
//	printf("预定成功!\n");
//}
//void cancel_bookd(PEOPLE* p) {
//	//取消预定
//	show_booked(p);
//	int id;
//	printf("请输入要取消的座位编号: ");
//	scanf("%d", &id);
//	if (p[id - 1].booked == 0) {
//		puts("选择错误");
//		return;
//	}
//	p[id - 1].booked = 0;
//}


/*
************柔性数组**********
*/
//struct func {
//	int n;
//	int ar[0];
//};
//int main(void) {
//	struct func* fa = (struct func*)malloc(sizeof(struct func*) + 5 * sizeof(int));
//	//柔性数组，为结构体分配连续的内存地址
//	for (int i = 0; i < 5; i++) {
//		fa->ar[i] = i;
//	}
//	for (int i = 0; i < 5; i++)
//		printf("%d  ", fa->ar[i]);
//	free(fa);	//只需要释放一次，因为是连续的
//	return 0;
//}

//不使用柔性数组，为指针分配空间
//struct func {
//	int n;
//	int* p;	//成员指针
//};
//int main(void) {
//	//首先为结构体成员分配内存
//	struct func* fa = (struct func*)malloc(sizeof(struct func));
//	//再为指针分配地址
//	int* ptr = (int*)malloc(5 * sizeof(int));
//	for (int i = 0; i < 5; i++)
//		*(ptr + i) = i;
//	for (int i = 0; i < 5; i++)
//		printf("%d  ", *(ptr + i));
//	free(ptr);
//	free(fa);
//	return 0;
//}


//利用联合访问不同位置的值
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