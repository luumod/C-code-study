/*
		�ṹ����ڴ����
*/
#include <stdio.h>
#include <string.h>
#include <stddef.h>
/*
* 1. ��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ����
2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
VS��Ĭ�ϵ�ֵΪ8
3. �ṹ���ܴ�СΪ����������ÿ����Ա��������һ��������������������
4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ�����������������������
�ṹ��������С��������������������Ƕ�׽ṹ��Ķ�����������������
* 
* 
*/

//char һ�ֽ�
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


//��ϰ1
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//int main(void) {
//	printf("%d\n", sizeof(struct S1));	//12�ֽ�
//	return 0;
//}


//��ϰ2
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//int main(void) {
//	printf("%d\n", sizeof(struct S2));	//8�ֽ�
//	return 0;
//}
 

//��ϰ3
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//int main(void) {
//	printf("%d\n", sizeof(struct S3));	//16�ֽ�
//	return 0;
//}

//��ϰ4-�ṹ��Ƕ������
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
//	printf("%d\n", sizeof(struct S4));	//32�ֽ�
//	return 0;
//}


//ѡ����ʵ������ʡ�ڴ�
//struct S{
//	char a;
//	int b;
//	char c;
//};	//12�ֽ�	
//struct S1 {
//	char a;
//	char c;
//	int b;
//};	//8�ֽ�
//int main(void) {
//	printf("%d\n%d", sizeof(struct S), sizeof(struct S1));
//	return 0;
//}

/*
�ܽ�:
1.��һ����Աֱ���ţ�0ƫ��
2.����ĳ�Ա���ҵ� ������ �ı�����λ�ÿ�ʼ��
3.�ṹ����Ӧ������ �������� �ı���
4.Ƕ�׽ṹӦ���뵽 ������������ �ı���λ�ô�

������: ��Ա�����ֽ� �� Ĭ�϶�����(8) ����Сֵ
*/


//ʹ�� ��pragma�޸Ķ�����
//#pragma pack(8)//����Ĭ�϶�����Ϊ8
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};	//16�ֽ�
//#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
//
//#pragma pack(1)//����Ĭ�϶�����Ϊ1,������
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};	//6�ֽ�
//#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
//
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	return 0;
//}



//offsetof����ĳ��Աƫ����ʼλ�õ�ƫ����
struct S2
{
	char c1;
	int i;
	char c2;
};	
int main(void) {
	//����ƫ����
	printf("%d\n", offsetof(struct S2, c1));
	printf("%d\n", offsetof(struct S2, i));
	printf("%d\n", offsetof(struct S2, c2));
	return 0;
}