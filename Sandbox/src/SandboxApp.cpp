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
		if (MreshEngine::Input::IsKeyPressed(ME_KEY_TAB))
			ME_TRACE("Tab key is pressed");
	}

	void OnEvent(MreshEngine::Event& event) override
	{
		if (event.GetEventType() == MreshEngine::EventType::KeyPressed)
		{
			MreshEngine::KeyPressedEvent& keyEvent = (MreshEngine::KeyPressedEvent&)event;
			ME_TRACE("{0}", (char)keyEvent.GetKeyCode());
		}
	}
};

class Sandbox : public MreshEngine::Application 
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new MreshEngine::ImGuiLayer());
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