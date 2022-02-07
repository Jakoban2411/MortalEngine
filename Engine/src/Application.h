#pragma once
#include "Core.h"
namespace Mortal {
	class ME_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	Application* CreateApplication();
}
