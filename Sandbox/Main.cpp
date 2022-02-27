#include <Engine/ME.h>
class Sandbox : public Mortal::Application
{
public:
	Sandbox(std::wstring WinTitle=L"SandboxApp",int Width = 1920, int Height = 1080, bool VSync = false) :Application(WinTitle,Width, Height, VSync)
	{
	}
	~Sandbox()
	{
	}
};

Mortal::Application* Mortal::CreateApplication(int Width, int Height, int VSync)
{
	return new Sandbox(L"Sandbox",Width, Height, VSync);
}

// LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
// {
// 	switch (message)
// 	{
// 	case WM_COMMAND:
// 	{
// 		return DefWindowProc(hWnd, message, wParam, lParam);
// 	}
// 	break;
// 	case WM_PAINT:
// 	{
// 		PAINTSTRUCT ps;
// 		HDC hdc = BeginPaint(hWnd, &ps);
// 		EndPaint(hWnd, &ps);
// 	}
// 	break;
// 	case WM_DESTROY:
// 		PostQuitMessage(0);
// 		break;
// 	default:
// 		return DefWindowProc(hWnd, message, wParam, lParam);
// 	}
// 	return 0;
// }