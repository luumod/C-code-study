/*
		结构体的内存对齐
*/
#include <stdio.h>
#include <string.h>
#include <stddef.h>
/*
* 1. 第一个成员在与结构体变量偏移量为0的地址处。
2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
VS中默认的值为8
3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。
* 
* 
*/

//char 一字节
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//int main(void) {
//	printf("%d\n", sizeof(struct S2));
//
//	return 0;
//}


//练习1
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//int main(void) {
//	printf("%d\n", sizeof(struct S1));	//12字节
//	return 0;
//}


//练习2
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//int main(void) {
//	printf("%d\n", sizeof(struct S2));	//8字节
//	return 0;
//}
 

//练习3
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//int main(void) {
//	printf("%d\n", sizeof(struct S3));	//16字节
//	return 0;
//}

//练习4-结构体嵌套问题
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//int main(void) {
//	printf("%d\n", sizeof(struct S4));	//32字节
//	return 0;
//}


//选择合适的排序节省内存
//struct S{
//	char a;
//	int b;
//	char c;
//};	//12字节	
//struct S1 {
//	char a;
//	char c;
//	int b;
//};	//8字节
//int main(void) {
//	printf("%d\n%d", sizeof(struct S), sizeof(struct S1));
//	return 0;
//}

/*
总结:
1.第一个成员直接排，0偏移
2.往后的成员先找到 对齐数 的倍数的位置开始排
3.结构总体应满足是 最大对齐数 的倍数
4.嵌套结构应对齐到 自身最大对齐数 的倍数位置处

对齐数: 成员本身字节 与 默认对齐数(8) 的最小值
*/


//使用 宏pragma修改对齐数
//#pragma pack(8)//设置默认对齐数为8
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};	//16字节
//#pragma pack()//取消设置的默认对齐数，还原为默认
//
//#pragma pack(1)//设置默认对齐数为1,不对齐
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};	//6字节
//#pragma pack()//取消设置的默认对齐数，还原为默认
//
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	return 0;
//}



//offsetof计算某成员偏移起始位置的偏移量
struct S2
{
	char c1;
	int i;
	char c2;
};	
int main(void) {
	//计算偏移量
	printf("%d\n", offsetof(struct S2, c1));
	printf("%d\n", offsetof(struct S2, i));
	printf("%d\n", offsetof(struct S2, c2));
	return 0;
}