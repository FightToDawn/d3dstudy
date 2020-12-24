#pragma once
#include "Window.h"
#include "ChiliTimer.h"
#include "ImguiManager.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
	~App();
private:
	void DoFrame();
private:
	ImguiManager imgui; //定义时会初始化imgui环境
	Window wnd;	//定义Window时会在构造函数里创建窗口
	ChiliTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	bool show_demo_window = true;
	static constexpr size_t nDrawables = 180;
};