#include "App.h"
#include <sstream>
#include <iomanip>

App::App():wnd(800,600,"The Donkey Fart Box")
{}

int App::Go()
{
	//MSG msg;
	//BOOL gResult;
	////GetMessage is blocked, if there is no message,it will be wait for ever.
	//while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	//{
	//	// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
	//	TranslateMessage(&msg);
	//	DispatchMessage(&msg);
	//	OutputDebugString("2");
	//	DoFrame();
	//}

	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().EndFrame();
}
