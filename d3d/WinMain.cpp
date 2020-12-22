#include "Window.h"
//#include "WindowsMessageMap.h"

//链接 子系统 windows 时 入口函数是WinMain
int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) 
{
	//创建窗口
	Window wnd(800, 300, "Donkey Fart Box");

	//创建窗口
	Window wnd2(800, 300, "Donkey Fart Box2");

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg,nullptr,0,0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1){
		return -1;
	}

	return msg.wParam;
}