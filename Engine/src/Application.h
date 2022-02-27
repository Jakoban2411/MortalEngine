#pragma once
#include <Core.h>
#include <MELogger.h>
#include "src/Window/Window.h"
#include "Events/Events.h"
#ifdef ME_PLATFORM_WINDOWS
#include "../../ME_win64/Window/WinApp.h"
#endif 

namespace Mortal {
	
	class ME_ENGINE_API Application
	{
	public:
		Application(std::wstring WinTitle,int Width, int Height, bool VSync);
		virtual ~Application();
		virtual void Run();
		inline const std::unique_ptr<Window> &GetWindow() { return m_Window; }
	private:
		std::unique_ptr<Window> m_Window;
		bool m_running = true;
	};

	Application* CreateApplication(int Width,int Height,int VSync);
}
