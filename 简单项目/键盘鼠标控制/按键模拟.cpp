#include <stdio.h>
#include <Windows.h>

//ģ�ⵥ�����̺���
void ControlKeyBd(BYTE key) {

	//��ֵ������ֵ������(0 ���� 2 ����),����ֵ
	keybd_event(key, 0, 0, 0);
	Sleep(30);	//���û���
	keybd_event(key, 0, 2, 0);
	Sleep(30);
}

//�������ģ��
void MoreControlKeyBd(BYTE key1, BYTE key2) {
	keybd_event(key1, 0, 0, 0);
	Sleep(30);
	keybd_event(key2, 0, 0, 0);
	Sleep(30);	//���û���
	keybd_event(key2, 0, 2, 0);
	Sleep(30);
	keybd_event(key1, 0, 2, 0);
	Sleep(30);

}
int main(void) {
	//����ģ�� 
	/*
	����Ҫ��ȡ����
	����ĳһ����
	����ĳһ����
	*/

	//���ģ��
	/*
	�ͼ���һ��
	*/
	HWND hwnd = FindWindow("MainView_9F956014-12FC-42d8-80C7-9A90D4D567E3", "QQˮ�");
	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = 1920;
	rect.bottom = 1080;
	ClipCursor(&rect);
	SetWindowPos(hwnd, 0, 0, 0, 1920,1080, 0);
	SetForegroundWindow(hwnd);		//����ĳ������Ϊ��ǰ��
	SetCursorPos(965, 190);	//����ƶ���ĳ��λ��
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0,0);
	Sleep(2000);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);	
	Sleep(2000);

	SetCursorPos(660, 301);	//����ƶ���ĳ��λ��
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