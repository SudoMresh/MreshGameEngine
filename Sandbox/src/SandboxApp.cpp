#include <MreshEngine.h>
#include <MreshEngine/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public MreshEngine::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

MreshEngine::Application* MreshEngine::CreateApplication()
{
	return new Sandbox();
}
