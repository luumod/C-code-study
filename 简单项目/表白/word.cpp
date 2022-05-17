#include <stdio.h>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//隐藏控制台
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 
int main(void) {

	//拷贝一份路径到指定文件
	//char str[300] = { 0 };
	//GetModuleFileName(NULL, str, 300);		//获得自己的exe路径
	//CopyFile(str, "C:\\Users\\Public\\Pictures\\window64图形图像核心运行组件1.exe", 300);

	//设置开机自启动   **专业**
	//HKEY hkey;
	//注册表操作 : 打开 设置 关闭
	/*RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
	RegSetValueEx(hkey, "window64图形图像核心运行组件1.exe", NULL,
		REG_SZ, (const BYTE*)"C:\\Users\\Public\\Pictures\\window64图形图像核心运行组件1.exe", 300);
	RegCloseKey(hkey);*/

	//打开文件
	FILE* fp;
	fp = fopen("C:\\Users\\Public\\Pictures\\f", "r");
	if (fp == NULL) {
		//文件不存在
		int ret = MessageBox(NULL, "我喜欢你很久了，你愿意和我在一起吗?", "消息框", MB_YESNO);
		if (ret == IDYES) {
			//表白程序
			mciSendString("open .\\music\j.mp3", 0, 0, 0);
			mciSendString("play .\\music\j.mp3", 0, 0, 0);
		}
		else if (ret == IDNO) {
			//恶搞程序
			fp = fopen("C:\\Users\\Public\\Pictures\\f", "w");	//创建一个文件
			fclose(fp);
		}
	}
	//创建窗口恶搞程序
	HWND hwnd;	//窗口id
	POINT pos;	//光标
	RECT rect;	//矩形
	//直接捕获最前面的窗口
	while (1) {
		//hwnd = GetForegroundWindow();
		hwnd = FindWindow("TXGuiFoundation", "QQ");	//类名与标题名
		//MoveWindow(hwnd, 0, 0, 379, 734, true);		//移动窗口到指定位置
		GetCursorPos(&pos);	//获得光标位置
		GetWindowRect(hwnd, &rect);		//获得某块矩形的区域
		if (pos.x >= rect.left && pos.x <= rect.right && pos.y >= rect.top && pos.y <= rect.bottom) {
			MoveWindow(hwnd, rand() % (1920 - 500), rand() % (1080 - 734), 379, 734, true);
		}
	}
	return 0;
}