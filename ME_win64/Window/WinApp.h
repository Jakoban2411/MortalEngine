#pragma once
#include "../Win64PCH.h"
#ifdef ME_PLATFORM_WINDOWS
#include "../../Engine/src/Window/Window.h"
namespace Mortal {
	
	//extern HINSTANCE hinst;

	class ME_WIN64_API WindowWindows : public Mortal::Window
	{
	public:
		WindowWindows(const WindowInfo& info);
		~WindowWindows();
		int Update() override;

		inline void SetEventCallback(const EventCallback& callback) override { m_data.EvntCbck = callback; }

		inline unsigned int GetHeight() const override { return m_data.m_info.WndHeight; }
		inline unsigned int GetWidth() const override { return m_data.m_info.WndWidth; }
		
		void SetVSync(bool VSync) { m_VSync = VSync; }
		bool isVSync() { return m_VSync; }
	private:
		MSG m_msg;
		ATOM MyRegisterClass();
		BOOL InitWindow(const WindowInfo& _info);
		void Shutdown();
		bool m_VSync;
		HWND m_hwnd;
		struct WindowData {
			WindowInfo m_info;
			EventCallback EvntCbck;
		}m_data;

	};
	Window* CreateWndw(const Mortal::WindowInfo& _info)
	{
		return new WindowWindows(_info);
	}
}

#endif // ME_PLATFORM_WINDOWS

