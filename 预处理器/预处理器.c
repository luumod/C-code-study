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
//#define ��ϲ���� for(;;)
//#define ������ int
//#define ����� long
//#define �Ǵ�˧�� a
//#define û��˧ b
//#define ������˵������� printf("%d\n",�Ǵ�˧��);
//#define �����˵���ǵܵ�  printf("%d\n",û��˧);
//#define ������˵�Բ۲�������� scanf("%d",&�Ǵ�˧��);
//#define ����俶�������˵ţ�� scanf("%ld",&û��˧);
//#define ���ǵܵ� printf("���ǲ�������ǵܵ�\n");
//#define ������� printf("�����������������\n");
//
//
////�궨��
//#define MAX(a,b) ((a)>(b))?(a):(b)
////#undef MAX			//�Ƴ�MAX�ĺ궨��
//
//
///*
//��������
//*/
//#define SIZE 100
//#undef SIZE		//undef����ȡ��ǰ��Ķ���
//
//#ifdef SIZE		//���������SIZE���ţ���ִ����������
//#define A 10
//#define B 20
//#else			//����ִ����������
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
//���һ�����Ƿ��Ѿ�������
//*/
//#ifndef IUO
//#define IUO 100
//#endif // !IUO
//
//
///*
//����ʹ��if  elif else��ѡ��ͬ�Ĺ��ܳ���
//*/ 
//
///*
//Ԥ�����
//__DATE__		Ԥ���������
//__FILE__		����ǰ�ļ����ַ���������
//__LINE__		��ǰ�ļ����к�
//__STDC__		����Ϊ1,����ʵ��C��׼
//__TIME__		��������ʱ��
//*/
//
//
//int main(void) {
//	//print("%d", 3);
//	/*������ �Ǵ�˧��;
//	����� û��˧;
//	������˵�Բ۲��������
//	����俶�������˵ţ��
//	�����˵���ǵܵ�
//	������˵������� 
//	���ǵܵ�
//	�������*/
//
//	//int x = 5, y = 8;
//	//int z = MAX(x++, y++);
//	//printf("x=%d,y=%d,z=%d\n", x, y, z);
//	//DEBUG;
//
//	int total = 0;
//	//ifdef ��endif 
//	
//	for (int i = 0; i < 5; i++) {
//		total += i;
//#ifdef JUST
//		printf("JUST=%d,i=%d\n", JUST, i);
//#endif
//
//#if CATE 	//Ƕ����������
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
����ѡ��
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
��������(Ŀ���Ǳ��⺯���Ľ������� ���ݲ��� ��ת�����ڲ��Ŀ���)
*/

/*inline static void eatline()*/	//���������Ķ���ԭ��
//�������������ڲ�����

//����˵����:  inline(����) _Noerturn(����ִ����Ϻ󲻻᷵��exit())
//



/*
����ѡ����㲻ͬ���ȵ�ƽ����
*/

/*
�������ͺ꣡������������������������������������������������������������������������
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
//	//��ͬ�������о�����ʧ
//	long double z = SIN(x);
//	long double zz = SIN(xx);
//	long double zzz = SIN(xxx);
//	//��ͬ�������о�����ʧ
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
exit��atexit����
*/
//void print(void);
//void exit1(void);
//int main(void) {
//	int a;
//
//	atexit(print);
//	puts("���ǳ�������!!!\n");
//	puts("���ǳ�������!!!\n");
//	puts("���ǳ�������!!!\n");
//	atexit(exit1);
//	//ע�ắ�����������ִ��
//
//	puts("����a��ֵ:");
//	if (scanf("%d", &a) != 1) {
//		printf("a���Ǹ�����\n");
//		exit(EXIT_FAILURE);
//	}
//
//	/*
//	�������˳�ʱ���Ż�ִ��atexitע��ĺ���,����ִ�з�ʽ�ǴӺ���ǰ
//	*/
//	return 0;
//}
//void print(void) {
//	printf("�����˳�1\n");
//}
//void exit1(void) {
//	printf("�����˳�2\n");
//}


/*
������Ϣ : assert ������ʽΪ�٣����ڱ�׼������strerrorд��һ��������Ϣ
*/

//int main(void) {
//	int a = 5, b;
//	//�������Ϊ�٣�����ֹ���򲢷��ش�����Ϣ	
//	//assert(a != 5);
//	printf("�������ּ������������:");
//	if (scanf("%d %d", &a, &b) == 2) {
//		//������Ϊ��  �Ƿ�...  Ӧ��������д������Ϊ��ȷ����Ϣ
//		assert(a != 0 && b != 0);
//		printf("%f\n", (float) (a / b));
//	}
//	return 0;
//}



/*
stdarg.h �ɱ����

va_list	 �����洢�����Ķ���
va_start  ��ʼ��Ϊ�����б�
va_arg    �����ڼ�������
va_end    ������
*/


