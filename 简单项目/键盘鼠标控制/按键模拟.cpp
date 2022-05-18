#include <stdio.h>
#include <Windows.h>

//模拟单个键盘函数
void ControlKeyBd(BYTE key) {

	//键值，垃圾值，操作(0 按下 2 弹起),垃圾值
	keybd_event(key, 0, 0, 0);
	Sleep(30);	//设置缓冲
	keybd_event(key, 0, 2, 0);
	Sleep(30);
}

//多个按键模拟
void MoreControlKeyBd(BYTE key1, BYTE key2) {
	keybd_event(key1, 0, 0, 0);
	Sleep(30);
	keybd_event(key2, 0, 0, 0);
	Sleep(30);	//设置缓冲
	keybd_event(key2, 0, 2, 0);
	Sleep(30);
	keybd_event(key1, 0, 2, 0);
	Sleep(30);

}
int main(void) {
	//按键模拟 
	/*
	首先要获取窗口
	按下某一个键
	弹开某一个键
	*/

	//鼠标模拟
	/*
	和键盘一样
	*/
	HWND hwnd = FindWindow("MainView_9F956014-12FC-42d8-80C7-9A90D4D567E3", "QQ水浒");
	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = 1920;
	rect.bottom = 1080;
	ClipCursor(&rect);
	SetWindowPos(hwnd, 0, 0, 0, 1920,1080, 0);
	SetForegroundWindow(hwnd);		//设置某个窗口为最前面
	SetCursorPos(965, 190);	//鼠标移动到某个位置
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0,0);
	Sleep(2000);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);	
	Sleep(2000);

	SetCursorPos(660, 301);	//鼠标移动到某个位置
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(2000);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);




















	/*ControlKeyBd('Y');
	ControlKeyBd('U');
	ControlKeyBd('L');
	ControlKeyBd('I');
	ControlKeyBd('A');
	ControlKeyBd('N');
	ControlKeyBd('G');
	ControlKeyBd('H');
	ControlKeyBd('A');
	ControlKeyBd('O');
	ControlKeyBd(VK_SPACE);
	ControlKeyBd(VK_RETURN);*/
	return 0;
}