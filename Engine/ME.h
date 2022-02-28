#pragma once

#include "src/Application.h"

extern Mortal::Application* Mortal::CreateApplication(int Width, int Height, int VSync);

#ifdef ME_PLATFORM_WINDOWS

//HINSTANCE hinst;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	Mortal::MELogger::Init();
	ME_CORE_WARN("I RAN DOWN THE RAMP");
	ME_CLIENT_WARN("I LOOKED VERY HANDSOME");
	//hinst = hInstance;
	Mortal::Application* myApp = Mortal::CreateApplication(1920,1080,false);
	myApp->Run();
	delete myApp;
}
#else
 int main(int argc, char** argv)
 {
 	Mortal::MELogger::Init();
 	ME_CORE_WARN("I RAN DOWN THE RAMP");
 	ME_CLIENT_WARN("I LOOKED VERY HANDSOME");
 	Mortal::Application* myApp = Mortal::CreateApplication(1920,1080,false);
 	myApp->Run();
 	delete myApp;
 }
#endif 