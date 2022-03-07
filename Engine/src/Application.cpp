#include "EnginePCH.h"
#include "Application.h"

namespace Mortal{
	extern Window* CreateWndw(const WindowInfo& props);
	Application::Application(std::wstring WinTitle=L"MortalEngine",int Width = 1920, int Height = 1080, bool VSync = false) : m_framecount(0),m_elapsedseconds(0)
	{
		WindowInfo WndwInfo(WinTitle, Width, Height, VSync);
		m_Window = std::make_unique<Window>(CreateWndw(WndwInfo));//std::unique_ptr<Window>(CreateWndw(WndwInfo));
		m_Renderer = std::make_unique<Renderer>(CreateRenderer());
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		while (true)
		{
			//Update engine physics,etc
			static auto t0 = m_clock.now();
			m_Window->Render();
			++m_framecount;
			static auto t1 = m_clock.now();
			auto dt = t1 - t0;
			t0 = t1;
			m_elapsedseconds += dt.count() * 1e-9;
			//Refactor to UI Rendering
			{
				if (m_elapsedseconds > 1.0)
				{
					auto fps = m_framecount / m_elapsedseconds;
					std::wstring buffer = L"FPS: ";
					buffer.append(std::to_wstring(fps));
					OutputDebugString(buffer.c_str());
					m_framecount = 0;
					m_elapsedseconds = 0.0;
				}
			}
		}
	}
}