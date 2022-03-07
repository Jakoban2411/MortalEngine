#pragma once
#include "EnginePCH.h"
#include "src/Events/Events.h"

namespace Mortal {
	
	struct WindowInfo {
		std::wstring WndTitle;
		unsigned int WndWidth, WndHeight;
		bool Vsync;
		WindowInfo(std::wstring Title = L"Mortal Engine", unsigned int Width = 1920, unsigned int Height = 1080, bool enableVSync = false) : WndTitle(Title), WndWidth(Width), WndHeight(Height),Vsync(enableVSync)
		{}
	};

	class ME_ENGINE_API Window
	{
	public:
		using EventCallback = std::function<void(Event&)>;
		
		virtual ~Window() {}
		
		virtual int Render()=0;
		
		virtual inline unsigned int GetWidth() const = 0;
		virtual inline unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallback& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool isVSync() = 0;

	};

	Window* CreateWndw(const WindowInfo& props);
}
