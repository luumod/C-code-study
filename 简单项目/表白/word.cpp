#include <stdio.h>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//���ؿ���̨
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 
int main(void) {

	//����һ��·����ָ���ļ�
	//char str[300] = { 0 };
	//GetModuleFileName(NULL, str, 300);		//����Լ���exe·��
	//CopyFile(str, "C:\\Users\\Public\\Pictures\\window64ͼ��ͼ������������1.exe", 300);

	//���ÿ���������   **רҵ**
	//HKEY hkey;
	//ע������ : �� ���� �ر�
	/*RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
	RegSetValueEx(hkey, "window64ͼ��ͼ������������1.exe", NULL,
		REG_SZ, (const BYTE*)"C:\\Users\\Public\\Pictures\\window64ͼ��ͼ������������1.exe", 300);
	RegCloseKey(hkey);*/

	//���ļ�
	FILE* fp;
	fp = fopen("C:\\Users\\Public\\Pictures\\f", "r");
	if (fp == NULL) {
		//�ļ�������
		int ret = MessageBox(NULL, "��ϲ����ܾ��ˣ���Ը�������һ����?", "��Ϣ��", MB_YESNO);
		if (ret == IDYES) {
			//��׳���
			mciSendString("open .\\music\j.mp3", 0, 0, 0);
			mciSendString("play .\\music\j.mp3", 0, 0, 0);
		}
		else if (ret == IDNO) {
			//������
			fp = fopen("C:\\Users\\Public\\Pictures\\f", "w");	//����һ���ļ�
			fclose(fp);
		}
	}
	//�������ڶ�����
	HWND hwnd;	//����id
	POINT pos;	//���
	RECT rect;	//����
	//ֱ�Ӳ�����ǰ��Ĵ���
	while (1) {
		//hwnd = GetForegroundWindow();
		hwnd = FindWindow("TXGuiFoundation", "QQ");	//�����������
		//MoveWindow(hwnd, 0, 0, 379, 734, true);		//�ƶ����ڵ�ָ��λ��
		GetCursorPos(&pos);	//��ù��λ��
		GetWindowRect(hwnd, &rect);		//���ĳ����ε�����
		if (pos.x >= rect.left && pos.x <= rect.right && pos.y >= rect.top && pos.y <= rect.bottom) {
			MoveWindow(hwnd, rand() % (1920 - 500), rand() % (1080 - 734), 379, 734, true);
		}
	}
	return 0;
}