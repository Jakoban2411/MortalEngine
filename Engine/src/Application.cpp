#include "Application.h"

namespace Mortal{
	extern Window* CreateWndw(const WindowInfo& props);
	Application::Application(std::wstring WinTitle=L"MortalEngine",int Width = 1920, int Height = 1080, bool VSync = false)
	{
		WindowInfo WndwInfo(WinTitle, Width, Height, VSync);
		m_Window = std::unique_ptr<Window>(CreateWndw(WndwInfo));
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		while (true)
		{
			m_Window->Update();
		}
	}
}