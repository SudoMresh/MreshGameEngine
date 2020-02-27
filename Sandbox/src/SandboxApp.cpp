#include <MreshEngine.h>

class ExampleLayer : public MreshEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		ME_INFO("ExampleLayer::Update");
	}

	void OnEvent(MreshEngine::Event& event) override
	{
		ME_TRACE("{0}", event);
	}
};

class Sandbox : public MreshEngine::Application 
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
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