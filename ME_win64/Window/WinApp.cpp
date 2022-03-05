#include "../Win64PCH.h"
#include "WinApp.h"
#ifdef ME_PLATFORM_WINDOWS

namespace Mortal {
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
	 	switch (message)
	 	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

				EndPaint(hWnd, &ps);
			}
			return 0;
		}
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	WindowWindows::WindowWindows(const WindowInfo& _info)
	{
		InitWindow(_info);
	}
	WindowWindows::~WindowWindows()
	{
	}

	ATOM WindowWindows::MyRegisterClass()
	{
		WNDCLASSEX wcex = { 0 };

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = &WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = GetModuleHandle(NULL);
		wcex.hIcon = ::LoadIcon(GetModuleHandle(NULL), NULL);
		wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = NULL;
		auto name = m_data.m_info.WndTitle.c_str();
		wcex.hIconSm = ::LoadIcon(GetModuleHandle(NULL), NULL);
		wcex.lpszClassName = name;

		return RegisterClassEx(&wcex);
	}

	BOOL WindowWindows::InitWindow(const WindowInfo& _info)
	{
		m_data.m_info = _info;
		MyRegisterClass();
		RECT windowSize = { 0,0,m_data.m_info.WndWidth,m_data.m_info.WndHeight };
		AdjustWindowRectEx(&windowSize, WS_OVERLAPPEDWINDOW, NULL, NULL);
		auto name = m_data.m_info.WndTitle.c_str();
		m_hwnd = CreateWindowW(name, L"Mortal Editor", WS_EX_TOPMOST | WS_POPUP,
			0, 0, windowSize.right - windowSize.left, windowSize.bottom - windowSize.top, nullptr, nullptr, NULL, nullptr);

		if (m_hwnd==NULL || m_hwnd==nullptr)
		{
			ME_CORE_ERROR("Failed to create Window");
			DWORD error;
			error = GetLastError();
			return FALSE;
		}

		ShowWindow(m_hwnd, 10);
		UpdateWindow(m_hwnd);

		return TRUE;
	}

	int WindowWindows::Update()
	{
		/*if (PeekMessage(&m_msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&m_msg);
			DispatchMessage(&m_msg);
			if (m_msg.message == WM_QUIT)
				return -1;
		}*/
		MSG msg = { };
		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return 0;
	}

}


#endif // ME_PLATFORM_WINDOWS