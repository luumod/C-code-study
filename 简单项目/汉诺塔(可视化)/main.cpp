/* Includes -----------------------------------------------------------*/
#include <stdio.h>
#include <graphics.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/* Macro ---------------------------------------------------------------*/

#define  TRUE           1
#define  FALSE          0

//��ı��
#define  FIRST_NEEDLE   1		//��һ����
#define  SECOND_NEEDLE  2       //�ڶ�����
#define  THIRD_NEEDLE   3		//��������

//���ӵ���Ϣ
#define  DISH_NUM       20		//��������
#define  DISH_HIGH      10		//�������Ӹ߶�
#define  NEEDLE_HIGH    (DISH_HIGH*DISH_NUM*2)		//��ĸ߶�

//���ڴ�С
#define  X_GUI_PIX      (20*DISH_NUM*3+200)
#define  Y_GUI_PIX      (NEEDLE_HIGH+100)

/* Typedef ------------------------------------------------------------*/

//���ӵ�λ����Ϣ
typedef struct  DISH_LOCATION
{
	int   needle_num ;
	int   needle_location ;
} Dish_Location ;

//����ֵ
typedef  int  BOOL ;

//���ӵ���Ϣ
typedef struct  DISH
{
	int   dish_rad ;
	Dish_Location  dish_location ;
	
} Dish;

/* Variables ----------------------------------------------------------*/
Dish  dish[DISH_NUM] ;
int   move_speed = 7000 ;

/* Function prototypes ------------------------------------------------*/
void  InitHanoiTower(void) ;
void  DrawGUI(void) ;
void  DrawDish(Dish a,BOOL disable) ;
void  MoveHanoiTower(int move_num , int start_needle , int finish_needle) ;
void  MoveBaseDish(int move_num , int start_needle , int finish_needle);

/************************************************************************
* Function Name			   : main
* Create Date			   : 2016/07/15
* Author				   : Panda_Xiao
* Description			   : Main Program
* Param                    : None
* Return Code              : None
* Global Variable          : None
* File Static Variable     : None
* Function Static Variable : None
************************************************************************/
int main(void)
{
	initgraph(X_GUI_PIX,Y_GUI_PIX) ;		//��ʼ�����ڴ�С
	cleardevice() ;							//����
	HWND  hWnd = GetHWnd() ;				//���ô��ڱ���
	SetWindowText(hWnd,"��ŵ��") ;

	InitHanoiTower() ;						//��ʼ����ŵ��
	DrawGUI() ;								//��������

	getch() ;								//���������ʼ
	
	MoveHanoiTower(DISH_NUM,FIRST_NEEDLE,THIRD_NEEDLE) ;		//�����Ӵӵ�һ����ᵽ��������
	
	getch();								//��������˳�����
	
	return 0 ;
}

/************************************************************************
* Function Name			   : InitHanoiTower
* Create Date			   : 2016/07/15
* Author				   : Panda_Xiao
* Description			   : ��ʼ����ŵ��
* Param                    : None
* Return Code              : None
* Global Variable          : dish[DISH_NUM]
* File Static Variable     : None
* Function Static Variable : None
************************************************************************/
void  InitHanoiTower(void)
{
	int i ;

	//��ʼ�����ӵĴ�С�������������Ӱ�����С�����ķ�ʽ���ڵ�һ������
	for(i=0;i<DISH_NUM;i++)
	{
		dish[i].dish_rad = 10*(i+1) ;
		dish[i].dish_location.needle_location = DISH_NUM-i ;
		dish[i].dish_location.needle_num = FIRST_NEEDLE ;
	}

}

/************************************************************************
* Function Name			   : DrawGUI
* Create Date			   : 2016/07/15
* Author				   : Panda_Xiao
* Description			   : ��������
* Param                    : None
* Return Code              : None
* Global Variable          : dish[DISH_NUM]
* File Static Variable     : None
* Function Static Variable : None
************************************************************************/
void  DrawGUI(void)
{
	int i ;

	//���û��ߵ���ɫ�͸�ʽ
	setlinecolor(WHITE) ;
	setlinestyle(PS_SOLID,1) ;

	//����������
	line(50+DISH_NUM*10,Y_GUI_PIX-NEEDLE_HIGH,50+DISH_NUM*10,Y_GUI_PIX) ;
	line(100+DISH_NUM*30,Y_GUI_PIX-NEEDLE_HIGH,100+DISH_NUM*30,Y_GUI_PIX) ;
	line(150+DISH_NUM*50,Y_GUI_PIX-NEEDLE_HIGH,150+DISH_NUM*50,Y_GUI_PIX) ;

	//������������
	for(i=0;i<DISH_NUM;i++)
	{
		DrawDish(dish[i],TRUE) ;
	}

}

/************************************************************************
* Function Name			   : DrawDish
* Create Date			   : 2016/07/15
* Author				   : Panda_Xiao
* Description			   : ��������
* Param                    : None
* Return Code              : None
* Global Variable          : dish[DISH_NUM]
* File Static Variable     : None
* Function Static Variable : None
************************************************************************/
void DrawDish(Dish a,BOOL disable)
{
	int  color ;

	//��disable = TRUE��������ɫΪ��ɫ������������ɫΪ��ɫ�����������ӣ�
	disable ?( color=LIGHTBLUE) : (color=BLACK );

	setlinecolor(color) ;
	setlinestyle(PS_SOLID,1) ;

	//�������ӵ�λ�úͰ뾶��С��Ϣ��������
	switch(a.dish_location.needle_num)
	{
	case FIRST_NEEDLE : 
		rectangle(50+DISH_NUM*10-a.dish_rad,Y_GUI_PIX-DISH_HIGH*a.dish_location.needle_location+1,50+DISH_NUM*10+a.dish_rad,Y_GUI_PIX-DISH_HIGH*(a.dish_location.needle_location-1)-1) ;
		break ;
	case SECOND_NEEDLE :
		rectangle(100+DISH_NUM*30-a.dish_rad,Y_GUI_PIX-DISH_HIGH*a.dish_location.needle_location+1,100+DISH_NUM*30+a.dish_rad,Y_GUI_PIX-DISH_HIGH*(a.dish_location.needle_location-1)-1) ;
		break ;
	case THIRD_NEEDLE :
		rectangle(150+DISH_NUM*50-a.dish_rad,Y_GUI_PIX-DISH_HIGH*a.dish_location.needle_location+1,150+DISH_NUM*50+a.dish_rad,Y_GUI_PIX-DISH_HIGH*(a.dish_location.needle_location-1)-1) ;
		break ;
	}
}

/************************************************************************
* Function Name			   : MoveHanoiTower
* Create Date			   : 2016/07/15
* Author				   : Panda_Xiao
* Description			   : �ƶ���ŵ��
* Param                    : move_num
							 start_needle
							 finish_needle
* Return Code              : None
* Global Variable          : dish[DISH_NUM]
							 move_speed
* File Static Variable     : None
* Function Static Variable : None
************************************************************************/
void  MoveHanoiTower(int move_num , int start_needle , int finish_needle)
{
	int i,trans_needle ;

	//����Դͷ����յ����ҳ���ת��
	for(i=FIRST_NEEDLE;i<=THIRD_NEEDLE;i++)
	{
		if(start_needle!=i&&finish_needle!=i)
			trans_needle = i ;
	}
	
	//���Ҫ�ƶ�����������Ϊһ������ִ���ƶ����ӵĺ���
	if(move_num == 1)
	{
		MoveBaseDish(move_num,start_needle,finish_needle) ;
		return ;
	}
	//���򣬵ݹ���ô˺���
	else
	{
		MoveHanoiTower(move_num-1,start_needle,trans_needle) ;		//��move_num-1�����Ӵ�Դͷ���ƶ�����ת��
		MoveBaseDish(move_num,start_needle,finish_needle) ;			//��move_num������������µ����Ӵ�Դͷ���ƶ����յ���
		MoveHanoiTower(move_num-1,trans_needle,finish_needle) ;		//��move_num-1�����Ӵ���ת���ƶ����յ���
		return ;
	}

}

/************************************************************************
* Function Name			   : MoveBaseDish
* Create Date			   : 2016/07/15
* Author				   : Panda_Xiao
* Description			   : �ƶ�һ������
* Param                    : move_num
							 start_needle
							 finish_needle
* Return Code              : None
* Global Variable          : dish[DISH_NUM]
							 move_speed
* File Static Variable     : None
* Function Static Variable : None
************************************************************************/
void MoveBaseDish(int move_num , int start_needle , int finish_needle)
{
	int i,j ;
	j = 1 ;
	int userHitChar ;

	//�����յ��������ӵ��������㽫Ҫ�ƶ����������ӵ�λ��
	for(i=0;i<DISH_NUM;i++)
	{
		if(dish[i].dish_location.needle_num == finish_needle)
			j++;
	} 

	if(kbhit())
	{
		//�Ӽ��̻�ȡһ���ַ�
		userHitChar = getch() ;
	
		switch(userHitChar)
		{
		case 'w' : 
			if(move_speed>=500 && move_speed <= 20000)
				move_speed -= 500 ;
			break ;
		case 's' :
            if(move_speed>=0 && move_speed <= 19500)
				move_speed += 500 ;
			break ;

		case 'q' : 
			while(1)
			{
				if(getch()=='q')
					break;	
			}
			break ;
		default : break ;
		}

	}
	
	//ԭλ�õ�������ʧ
	for(i=0;i<=move_speed;i++)
		DrawDish(dish[move_num-1],FALSE);

	//��Ҫ�ƶ��������µ�λ����Ϣ
	dish[move_num-1].dish_location.needle_num = finish_needle ;
	dish[move_num-1].dish_location.needle_location = j ;

	//��ʾ�ƶ��������
	for(i=0;i<=move_speed;i++)
		DrawDish(dish[move_num-1],TRUE);

}






	      