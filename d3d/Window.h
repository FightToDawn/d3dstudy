#pragma once

#include "ChiliWin.h"
#include "ChiliException.h"
#include "Keyboard.h"
#include "Mouse.h"
#include <optional>
#include <memory>
#include <string>
#include <vector>

class Window
{
public:
	class Exception : public ChiliException 
	{
	public:
		Exception(int line, const char* file, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		virtual const char* GetType() const noexcept;
		static std::string TranslateErrorCode(HRESULT hr) noexcept;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorString() const noexcept;
	private:
		HRESULT hr;
	};
private:
	//WindowClass类 单例管理注册/销毁窗口类
	class WindowClass {
	public:
		static const char* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr const char* wndClassName = "Chili Direct3D Engine Window";
		static WindowClass wndClass;	//单例
		HINSTANCE hInst;
	};
public:
	//如果加了noexcept 则表示我们知道这个函数不会抛出异常 
	//直接告诉编译器不要在这个函数的调用堆栈里做异常相关的代码了 这样就能优化目标程序
	//但是如果这个函数里还是发生了异常 则程序就会直接调用std::abort崩溃
	Window(int width, int height, const char* name) /*noexcept*/;
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	void SetTitle(const std::string& title);
	//void EnableCursor() noexcept;
	//void DisableCursor() noexcept;
	//bool CursorEnabled() const noexcept;
	//static std::optional<int> ProcessMessages() noexcept;
private:
	//void ConfineCursor() noexcept;
	//void FreeCursor() noexcept;
	//void ShowCursor() noexcept;
	//void HideCursor() noexcept;
	//void EnableImGuiMouse() noexcept;
	//void DisableImGuiMouse() noexcept;
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
public:
	Keyboard kbd;
	Mouse mouse;
private:
	//bool cursorEnabled = true;
	int width;
	int height;
	HWND hWnd;
	//std::vector<BYTE> rawBuffer;
	//std::string commandLine;
};

#define CHWND_EXCEPT(hr) Window::Exception(__LINE__,__FILE__,hr)
#define CHWND_LAST_EXCEPT() Window::Exception( __LINE__,__FILE__,GetLastError() )