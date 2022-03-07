#pragma once
#include <EnginePCH.h>
#include "src/Window/Window.h"
#include <Renderer.h>
#include "Events/Events.h"
#ifdef ME_PLATFORM_WINDOWS
#include "../../ME_win64/Window/WinApp.h"
#ifdef ME_D3D12_API

#endif // ME_D3D12_API
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
		std::unique_ptr<Renderer> m_Renderer;
		bool m_running = true;
		UINT64 m_framecount;
		long double m_elapsedseconds;
		std::chrono::high_resolution_clock m_clock;
	};

	Application* CreateApplication(int Width,int Height,int VSync);
}
