#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <assert.h>
//#define SIZE 100
//#define malloc
//#define MALLOC(num,type) (type*) alloc((num)*sizeof(type))
//extern void* alloc(size_t size);
//#define reg register
//#define 我喜欢你 for(;;)
//#define 于良浩 int
//#define 蔡联淇 long
//#define 是大帅哥 a
//#define 没我帅 b
//#define 于良浩说我是你爹 printf("%d\n",是大帅哥);
//#define 蔡联淇说我是弟弟  printf("%d\n",没我帅);
//#define 于良浩说卧槽蔡联淇来了 scanf("%d",&是大帅哥);
//#define 蔡联淇对于良浩说牛逼 scanf("%ld",&没我帅);
//#define 我是弟弟 printf("我是蔡联淇我是弟弟\n");
//#define 我是你爹 printf("我是于良浩我是你爹\n");
//
//
////宏定义
//#define MAX(a,b) ((a)>(b))?(a):(b)
////#undef MAX			//移除MAX的宏定义
//
//
///*
//条件编译
//*/
//#define SIZE 100
//#undef SIZE		//undef可以取消前面的定义
//
//#ifdef SIZE		//如果定义了SIZE符号，则执行下面的语句
//#define A 10
//#define B 20
//#else			//否则，执行下面的语句
//#define A 20
//#define B 30
//#endif // SIZE
//
//
//#define JUST 200
//#undef JUST
//#define CATE 100
//#undef CATE
//
///*
//检查一个宏是否已经被定义
//*/
//#ifndef IUO
//#define IUO 100
//#endif // !IUO
//
//
///*
//可以使用if  elif else来选择不同的功能程序
//*/ 
//
///*
//预定义宏
//__DATE__		预处理的日期
//__FILE__		处理当前文件的字符串字面量
//__LINE__		当前文件的行号
//__STDC__		设置为1,表明实现C标准
//__TIME__		翻译代码的时间
//*/
//
//
//int main(void) {
//	//print("%d", 3);
//	/*于良浩 是大帅哥;
//	蔡联淇 没我帅;
//	于良浩说卧槽蔡联淇来了
//	蔡联淇对于良浩说牛逼
//	蔡联淇说我是弟弟
//	于良浩说我是你爹 
//	我是弟弟
//	我是你爹*/
//
//	//int x = 5, y = 8;
//	//int z = MAX(x++, y++);
//	//printf("x=%d,y=%d,z=%d\n", x, y, z);
//	//DEBUG;
//
//	int total = 0;
//	//ifdef 和endif 
//	
//	for (int i = 0; i < 5; i++) {
//		total += i;
//#ifdef JUST
//		printf("JUST=%d,i=%d\n", JUST, i);
//#endif
//
//#if CATE 	//嵌套条件编译
//		printf("%d\n", i * 2);
//#else
//		printf("%d\n", i * 2 * 2);
//#endif // !CATE
//
//	}
//	printf("IUO=%d\n", IUO);
//	printf("A=%d,B=%d\n", A, B);
//
//	return 0;
//}



/*
泛型选择
*/
//#define MYTYPE(X) _Generic((X),\
//int: "int",\
//float: "float",\
//double: "double",\
//default: "other"\
//)
//int main(void) {
//	int d = 5;
//	float f = 20.2;
//	int* a = &d;
//	printf("%s\n", MYTYPE(d));
//	printf("%s\n", MYTYPE(2.0*d));
//	printf("%s\n", MYTYPE(f));
//	printf("%s\n", MYTYPE(a));
//	return 0;
//}


/*
内联函数(目的是避免函数的建立调用 传递参数 跳转函数内部的开销)
*/

/*inline static void eatline()*/	//内联函数的定义原型
//内联函数具有内部链接

//函数说明符:  inline(内联) _Noerturn(函数执行完毕后不会返回exit())
//



/*
泛型选择计算不同精度的平方根
*/

/*
创建泛型宏！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
*/
//#define SQRT(X) _Generic((X),\
//long double :sqrtl,\
//float:sqrtf,\
//default:sqrt)(X)
//
//#define SIN(X) _Generic((X),\
//long double:sinl,\
//float: sinf,\
//default:sin)(X)
//
//int main(void) {
//	long double x = 45.0L;
//	float xx = 45.0f;
//	double xxx = 45.0;
//
//	long double y = SQRT(x);
//	long double yy = SQRT(xx);
//	long double yyy = SQRT(xxx);
//	//不同的类型有精度损失
//	long double z = SIN(x);
//	long double zz = SIN(xx);
//	long double zzz = SIN(xxx);
//	//不同的类型有精度损失
//	printf("long double y=%.17lf\n", y);
//	printf("long double yy=%.17lf\n", yy);
//	printf("long double yyy=%.17lf\n", yyy);
//
//	printf("long double z=%.17lf\n", z);
//	printf("long double zz=%.17lf\n", zz);
//	printf("long double zzz=%.17lf\n", zzz);
//	return 0;
//}


/*
exit和atexit函数
*/
//void print(void);
//void exit1(void);
//int main(void) {
//	int a;
//
//	atexit(print);
//	puts("我是程序主体!!!\n");
//	puts("我是程序主体!!!\n");
//	puts("我是程序主体!!!\n");
//	atexit(exit1);
//	//注册函数，但是最后执行
//
//	puts("输入a的值:");
//	if (scanf("%d", &a) != 1) {
//		printf("a不是个数字\n");
//		exit(EXIT_FAILURE);
//	}
//
//	/*
//	当程序退出时，才会执行atexit注册的函数,并且执行方式是从后往前
//	*/
//	return 0;
//}
//void print(void) {
//	printf("操作退出1\n");
//}
//void exit1(void) {
//	printf("操作退出2\n");
//}


/*
错误信息 : assert 如果表达式为假，就在标准错误流strerror写入一条错误信息
*/

//int main(void) {
//	int a = 5, b;
//	//如果条件为假，会终止程序并返回错误信息	
//	//assert(a != 5);
//	printf("输入数字计算两个数相除:");
//	if (scanf("%d %d", &a, &b) == 2) {
//		//除数不为零  是否...  应该在括号写入你认为正确的信息
//		assert(a != 0 && b != 0);
//		printf("%f\n", (float) (a / b));
//	}
//	return 0;
//}



/*
stdarg.h 可变参数

va_list	 声明存储参数的对象
va_start  初始化为参数列表
va_arg    检索第几个参数
va_end    清理工作
*/


