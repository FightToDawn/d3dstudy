#include <Windows.h>

//���� ��ϵͳ windows ʱ ��ں�����WinMain
int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) 
{
	const auto pClassName = "d3dwindow";
	//ע�ᴦ������
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;			//�Լ����ƵĴ���
	wc.lpfnWndProc = DefWindowProc;	//Ĭ�ϵĴ��ڹ���
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	//��������ʵ��


	return 0;
}