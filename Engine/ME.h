#pragma once
#ifdef ME_PLATFORM_WINDOWS

#include "src/Application.h"
#include "src/MELogger.h"

extern Mortal::Application* Mortal::CreateApplication();

int main(int argc, char** argv)
{
	Mortal::MELogger::Init();
	ME_CORE_WARN("I RAN DOWN THE RAMP");
	ME_CLIENT_WARN("I LOOKED VERY HANDSOME");
	Mortal::Application* myApp = Mortal::CreateApplication();
	myApp->Run();
	delete myApp;
}

#endif // ME_PLATFORM_WINDOWS