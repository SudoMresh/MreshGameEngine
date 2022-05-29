#include <MreshEngine.h>
#include <MreshEngine/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "Sandbox3D.h"

class Sandbox : public MreshEngine::Application
{
public:
	Sandbox(MreshEngine::ApplicationCommandLineArgs args)
		: Application("Sandbox", args)
	{
		//PushLayer(new Sandbox3D());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

MreshEngine::Application* MreshEngine::CreateApplication(ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}
