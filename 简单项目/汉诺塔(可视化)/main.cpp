/* Includes -----------------------------------------------------------*/
#include <stdio.h>
#include <graphics.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/* Macro ---------------------------------------------------------------*/

#define  TRUE           1
#define  FALSE          0

//针的标号
#define  FIRST_NEEDLE   1		//第一根针
#define  SECOND_NEEDLE  2       //第二根针
#define  THIRD_NEEDLE   3		//第三根针

//盘子的信息
#define  DISH_NUM       20		//盘子数量
#define  DISH_HIGH      10		//单个盘子高度
#define  NEEDLE_HIGH    (DISH_HIGH*DISH_NUM*2)		//针的高度

//窗口大小
#define  X_GUI_PIX      (20*DISH_NUM*3+200)
#define  Y_GUI_PIX      (NEEDLE_HIGH+100)

/* Typedef ------------------------------------------------------------*/

//盘子的位置信息
typedef struct  DISH_LOCATION
{
	int   needle_num ;
	int   needle_location ;
} Dish_Location ;

//布尔值
typedef  int  BOOL ;

//盘子的信息
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
	initgraph(X_GUI_PIX,Y_GUI_PIX) ;		//初始化窗口大小
	cleardevice() ;							//清屏
	HWND  hWnd = GetHWnd() ;				//设置窗口标题
	SetWindowText(hWnd,"汉诺塔") ;

	InitHanoiTower() ;						//初始化汉诺塔
	DrawGUI() ;								//画出界面

	getch() ;								//按任意键开始
	
	MoveHanoiTower(DISH_NUM,FIRST_NEEDLE,THIRD_NEEDLE) ;		//将盘子从第一根针搬到第三根针
	
	getch();								//按任意键退出窗口
	
	return 0 ;
}

/************************************************************************
* Function Name			   : InitHanoiTower
* Create Date			   : 2016/07/15
* Author				   : Panda_Xiao
* Description			   : 初始化汉诺塔
* Param                    : None
* Return Code              : None
* Global Variable          : dish[DISH_NUM]
* File Static Variable     : None
* Function Static Variable : None
************************************************************************/
void  InitHanoiTower(void)
{
	int i ;

	//初始化盘子的大小，并把所有盘子按上面小下面大的方式放在第一根针上
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
* Description			   : 画出界面
* Param                    : None
* Return Code              : None
* Global Variable          : dish[DISH_NUM]
* File Static Variable     : None
* Function Static Variable : None
************************************************************************/
void  DrawGUI(void)
{
	int i ;

	//设置画线的颜色和格式
	setlinecolor(WHITE) ;
	setlinestyle(PS_SOLID,1) ;

	//画出三根针
	line(50+DISH_NUM*10,Y_GUI_PIX-NEEDLE_HIGH,50+DISH_NUM*10,Y_GUI_PIX) ;
	line(100+DISH_NUM*30,Y_GUI_PIX-NEEDLE_HIGH,100+DISH_NUM*30,Y_GUI_PIX) ;
	line(150+DISH_NUM*50,Y_GUI_PIX-NEEDLE_HIGH,150+DISH_NUM*50,Y_GUI_PIX) ;

	//画出所有盘子
	for(i=0;i<DISH_NUM;i++)
	{
		DrawDish(dish[i],TRUE) ;
	}

}

/************************************************************************
* Function Name			   : DrawDish
* Create Date			   : 2016/07/15
* Author				   : Panda_Xiao
* Description			   : 画出盘子
* Param                    : None
* Return Code              : None
* Global Variable          : dish[DISH_NUM]
* File Static Variable     : None
* Function Static Variable : None
************************************************************************/
void DrawDish(Dish a,BOOL disable)
{
	int  color ;

	//若disable = TRUE，盘子颜色为蓝色，否则盘子颜色为黑色（即移走盘子）
	disable ?( color=LIGHTBLUE) : (color=BLACK );

	setlinecolor(color) ;
	setlinestyle(PS_SOLID,1) ;

	//根据盘子的位置和半径大小信息画出盘子
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
* Description			   : 移动汉诺塔
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

	//根据源头针和终点针找出中转针
	for(i=FIRST_NEEDLE;i<=THIRD_NEEDLE;i++)
	{
		if(start_needle!=i&&finish_needle!=i)
			trans_needle = i ;
	}
	
	//如果要移动的盘子数量为一个，则执行移动盘子的函数
	if(move_num == 1)
	{
		MoveBaseDish(move_num,start_needle,finish_needle) ;
		return ;
	}
	//否则，递归调用此函数
	else
	{
		MoveHanoiTower(move_num-1,start_needle,trans_needle) ;		//将move_num-1个盘子从源头针移动到中转针
		MoveBaseDish(move_num,start_needle,finish_needle) ;			//将move_num个盘子中最底下的盘子从源头针移动到终点针
		MoveHanoiTower(move_num-1,trans_needle,finish_needle) ;		//将move_num-1个盘子从中转针移动到终点针
		return ;
	}

}

/************************************************************************
* Function Name			   : MoveBaseDish
* Create Date			   : 2016/07/15
* Author				   : Panda_Xiao
* Description			   : 移动一个盘子
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

	//根据终点针上盘子的数量计算将要移动过来的盘子的位置
	for(i=0;i<DISH_NUM;i++)
	{
		if(dish[i].dish_location.needle_num == finish_needle)
			j++;
	} 

	if(kbhit())
	{
		//从键盘获取一个字符
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
	
	//原位置的盘子消失
	for(i=0;i<=move_speed;i++)
		DrawDish(dish[move_num-1],FALSE);

	//给要移动的盘子新的位置信息
	dish[move_num-1].dish_location.needle_num = finish_needle ;
	dish[move_num-1].dish_location.needle_location = j ;

	//显示移动后的盘子
	for(i=0;i<=move_speed;i++)
		DrawDish(dish[move_num-1],TRUE);

}






	      