#include <MreshEngine.h>


class Sandbox : public MreshEngine::Application 
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

private:

};

MreshEngine::Application* MreshEngine::CreateApplication()
{
	return new Sandbox();
}