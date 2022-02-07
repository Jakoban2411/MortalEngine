#include <Engine/ME.h>
class Sandbox : public Mortal::Application
{public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Mortal::Application* Mortal::CreateApplication()
{
	return new Sandbox();
}
