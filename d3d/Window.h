#pragma once

#include "ChiliWin.h"
#include <optional>
#include <memory>
#include <string>
#include <vector>

class Window
{
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
	Window(int width, int height, const char* name);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	//void SetTitle(const std::string& title);
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
	//Keyboard kbd;
	//Mouse mouse;
private:
	//bool cursorEnabled = true;
	int width;
	int height;
	HWND hWnd;
	//std::vector<BYTE> rawBuffer;
	//std::string commandLine;
};

